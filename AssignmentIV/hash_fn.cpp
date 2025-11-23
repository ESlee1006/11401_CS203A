/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/23: Initial implementation

   Developer: ESlee1006 <s1131532@maul.yzu,edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    key *= 103;
    key += (key % 10);
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    for(int i = 0; i < str.size(); i++)
        hash = hash * 31 + str[i];
    return static_cast<int>(hash % m);  // basic division method
}
