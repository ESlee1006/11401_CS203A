# Assignment IV: Hash Function Design & Observation (c/c++)
developer: 李懿宸
email: easonlee1006@gmail.com 

## Hash Function ##
### Integer Key ###
- Formula / pseudocode:
```
    int myHashInt(int key, int m) 
{
    return ((key * 2654435761u) ^ (key >> 16)) % m;
}
```
一開始還想不到適合的hash function，直到藉由AI的建議知道了Knuth multiplier，它具有以下優點：
- 可讓 key 在 mod 空間中分散得很好
- 只要 bucket 是 2 的次方，分佈會非常完美
- 避免 key 之間的模式互相干擾
    

### Non-Integer Key ###
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
和Integer Key一樣，藉由AI的建議知道了Knuth multiplier，FNV
