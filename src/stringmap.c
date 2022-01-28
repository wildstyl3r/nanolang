#include <stringmap.h>


uint64_t strhash(string s)
{
    uint64_t h = 0;
    for(size_t i = 0; s[i] != '\0'; ++i) {
        int t = s[i] - ' '; // '!' == 33, ' ' == 32; '!' is acceptable, ' ' is not
        h = h * 227 + t;
    }
    return h;
}


func_num map_find(fmap m, string s, uint64_t hs)
{
    if (m == NULL){
        puts("ERROR: unknown function name");
        exit(EXIT_FAILURE);
    }
    if (hs == 0) hs = strhash(s);
    if (m->hash_val == hs && strcmp(s, m->key) == 0){
        return m->f;
    } else {
        if (m->hash_val < hs) {
            return map_find(m->left, s, hs);
        } else {
            return map_find(m->right, s, hs);
        }
    }
}

void map_insert(fmap* m, string s, func_num f, uint64_t hs)
{
    if (hs == 0) hs = strhash(s);
    fmap t = *m;
    if (t == NULL){
        *m = t = malloc(sizeof (struct HashTreeNode));
        t->f = f;
        size_t l = strlen(s);
        t->key = malloc(l+1);
        strncpy(t->key, s, l);
        t->left = t->right = NULL;
        t->hash_val = hs;
        return;
    }
    if (hs > t->hash_val) {
        map_insert(&t->left, s, f, hs);
    } else {
        map_insert(&t->right, s, f, hs);
    }
}
