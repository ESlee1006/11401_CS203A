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

## Results ##
### Integer ###
