/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/23: Initial implementation

   Developer: ESlee1006 <s1131532@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) 
{
   unsigned int xkey = static_cast<unsigned int>(key);
   xkey * 2654435761U;
   xkey ^ (xkey >> 16);
    return static_cast<int> (xkey % m);       // Knuth multiplier
}

int myHashString(const std::string& str, int m)
{
    uint32_t hash = 2166136261u;      // FNV offset basis
    for (unsigned char c : str){
        hash ^= c;
        hash *= 16777619u;            // FNV prime
    }
    return static_cast<int>(hash % m);
}
