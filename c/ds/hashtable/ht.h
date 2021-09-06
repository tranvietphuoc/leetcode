/*
 * copied from benhoyt
 * */

#ifndef _HT_H
#define _HT_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// hash table entry (slot may be filled or empty)
typedef struct {
    const char *key;
    void *value;
} ht_entry;

// hash table struture; created with ht_create, free with ht_destroy
struct ht {
    ht_entry *entries; // hash slots
    size_t capacity;   // size of _entries array
    size_t length;     // number of items in hash table
};

typedef struct ht ht;

#define INITIAL_CAPACITY 16
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// create hash table and return pointer to it, or NULL if it out of memory
ht *ht_create(void);

// free memory allocated for hash table, including allocated keys
void ht_destroy(ht *table);

// get item with given key(NULL-terminated) from hash table.
// return value, or NULL if key not found
void *ht_get(ht *table, const char *key);

// set item with given key (NULL-terminated) to valued. if not already
// present in table, key is copied to newly allocated memory. return address of
// copied key, or NULL if it out of memory
const char *ht_set(ht *table, const char *key, void *value);

// return number of  items in hash table
size_t ht_length(ht *table);

// hash table iterator: created with ht_iterator, iterate with ht_next
typedef struct {
    const char *key; // current key
    void *value;     // current value

    // don;t use  these fields directly
    ht *_table;    // reference to hash table being iterated
    size_t _index; // current index into ht._entries
} hti;

// return new hash table iterator
hti ht_iterator(ht *table);

// move iterator to next item in hash table,
// update iterator's key and value to current item, and return true.
// if there're no more items, return false
bool ht_next(hti *it);

#endif
