# Assignment IV: Hash Function Design & Observation (c/c++)
developer: 李懿宸
email: easonlee1006@gmail.com 

## Hash Function ##
### Integer Key ###
#### Formula / pseudocode: ####
```
    int myHashInt(int key, int m) 
{
    return ((key * 2654435761u) ^ (key >> 16)) % m;
}
```
一開始還想不到適合的hash function，直到藉由AI的建議知道了Knuth multiplier，並以XOR發散，Knuth multiplier它具有以下優點：
- 可讓 key 在 mod 空間中分散得很好
- 只要 bucket 是 2 的次方，分佈會非常完美
- 避免 key 之間的模式互相干擾
    

### Non-Integer Key ###
#### Formula / pseudocode: ####
```
    int myHashString(const std::string& str, int m)
{
    uint32_t hash = 2166136261u;
    for (unsigned char c : str){
        hash ^= c;
        hash *= 16777619u;
    }
    return static_cast<int>(hash % m);
}
```
和Integer Key一樣，藉由AI的建議知道了FNV，以XOR+乘法進行演算，碰撞率和分布較普通hash function優

## Experimental Setup ##
- Table sizes : 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results

### Integer
| Table Size (m) |                             Index Sequence                               |     Observation      |
|----------------|--------------------------------------------------------------------------|----------------------|
| 10             | 5, 2, 4, 9, 1, 6, 8, 3, 9, 8, 6, 2, 9, 7, 0, 6, 3, 9, 6, 4               |範圍介於0 ~ m-1, 無規律, collision發生機率大|
| 11             | 3, 1, 4, 7, 8, 5, 8, 7, 6, 7, 2, 10, 4, 0, 7, 3, 10, 7, 4, 1             |範圍介於0 ~ m-1, 無規律, index重複高, collision發生機率大|
| 37             | 29, 3, 33, 10, 2, 14, 10, 8, 6, 33, 2, 28, 27, 23, 15, 16, 7, 15, 26, 13 |範圍介於0 ~ m-1, 無規律, index重複低, collision發生機率小|

### String
| Table Size (m) |                             Index Sequence                           |     Observation      |
|----------------|----------------------------------------------------------------------|----------------------|
|10              | 1, 7, 8, 8, 0, 5, 9, 4, 7, 0                                         |範圍介於0 ~ m-1, index重複較高, collision發生頻率|
|11              | 4, 0, 3, 10, 9, 5, 4, 9, 1, 8                                        |範圍介於0 ~ m-1, index重複較低, collision發生頻率較小|
|37              | 21, 14, 0, 14, 14, 0, 30, 5, 7, 18                                   |範圍介於0 ~ m-1, index重複低, collision發生頻率小|

## Compilation, Build, Execution, and Output ##
### Compilation ###
```
# c++
g++ .\AssignmentIV\CXX\hash_fn.c .\AssignmentIV\CXX\hash_fn.h .\AssignmentIV\CXX\main.c -o AssignmentIV_CXX.exe
# C
g++ -g .\AssignmentIV\C\hash_fn.c .\AssignmentIV\C\hash_fn.h .\AssignmentIV\C\main.c -o AssignmentIV_C.exe
```
```
  === Hash Function Observation (C++ Version) ===

=== Table Size m = 10 ===
Key     Index
-----------------
21      5
22      2
23      4
24      9
25      1
26      6
27      8
28      3
29      9
30      8
51      6
52      2
53      9
54      7
55      0
56      6
57      3
58      9
59      6
60      4

=== Table Size m = 11 ===
Key     Index
-----------------
21      3
22      1
23      4
24      7
25      8
26      5
27      8
28      7
29      6
30      7
51      2
52      10
53      4
54      0
55      7
56      3
57      10
58      7
59      4
60      1

=== Table Size m = 37 ===
Key     Index
-----------------
21      29
22      3
23      33
24      10
25      2
26      14
27      10
28      8
29      6
30      33
51      2
52      28
53      27
54      23
55      15
56      16
57      7
58      15
59      26
60      13

=== String Hash (m = 10) ===
Key     Index
-----------------
cat     1
dog     7
bat     8
cow     8
ant     0
owl     5
bee     9
hen     4
pig     7
fox     0

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     4
dog     0
bat     3
cow     10
ant     9
owl     5
bee     4
hen     9
pig     1
fox     8

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     21
dog     14
bat     0
cow     14
ant     14
owl     0
bee     30
hen     5
pig     7
fox     18
```
