
/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/24: Initial implementation

   Developer: ESlee1006 <s1131532@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) 
{
    return ((key * 2654435761u) ^ (key >> 16)) % m;
}

int myHashString(const char* str, int m) 
{
    unsigned long hash = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        hash = hash * 31 + str[i];
    }
    return (int)(hash % m); // basic division method
}

