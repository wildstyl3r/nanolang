#ifndef STRINGMAP_H
#define STRINGMAP_H

#include "nano.h"
#include <string.h>

typedef struct HashTreeNode* hashnode_ptr;
typedef hashnode_ptr fmap;


struct HashTreeNode
{
    uint64_t hash_val;
    hashnode_ptr left;
    hashnode_ptr right;
    string key;
    func_num f;
};

#endif // STRINGMAP_H
