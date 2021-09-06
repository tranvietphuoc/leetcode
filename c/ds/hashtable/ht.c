/*
 * copied from benhoyt
 * */

#include "ht.h"

ht *ht_create(void) {
    // allocate space for hash table struct
    ht *table = malloc(sizeof(ht));
    if (!table)
        return NULL;
    table->length   = 0;
    table->capacity = INITIAL_CAPACITY;

    // allocate space for entry buckets.
    table->entries = calloc(table->capacity, sizeof(ht_entry));
    if (!table->entries) {
        free(table);
        return NULL;
    }
    return table;
};

void ht_destroy(ht *table) {
    // first free allocated keys
    for (size_t i = 0; i < table->capacity; i++) {
        if (table->entries[i].key)
            free((void *)table->entries[i].key);
    }
    // then free entries array and table itself
    free(table->entries);
    free(table);
}

// return 64-bit FNV-1a hash for key (NULL-terminated)
static uint64_t hashed(const char *key) {
    uint64_t hash = FNV_OFFSET;
    for (const char *p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

void *ht_get(ht *table, const char *key) {
    // and hash with  capacity-1 ensure it's within entries array
    uint64_t hash = hashed(key);
    size_t index  = (size_t)(hash & (uint64_t)(table->capacity - 1));

    // loop till we find an empty entry.
    while (table->entries[index].key) {
        if (strcmp(key, table->entries[index].key) == 0)
            return table->entries[index].value; // found key, return value

        // key wasn't in this slot, move to next(linear probling)
        index++;
        if (index >= table->capacity) {
            // at end of entries array, wrap around
            index = 0;
        }
    }
    return NULL;
}

// internal function to set an entry (without expanding false).
static const char *ht_set_entry(ht_entry *entries, size_t capacity,
                                const char *key, void *value, size_t *plength) {
    // and hash with capacity-1 to ensure it's within entries array.
    uint64_t hash = hashed(key);
    size_t index  = (size_t)(hash & (uint64_t)(capacity - 1));

    // loop till we find an empty entry.
    while (entries[index].key) {
        if (strcmp(key, entries[index].key) == 0) {
            // found key, update value
            entries[index].value = value;
            return entries[index].key;
        }

        // key wasn't in this slot, move to next
        index++;
        if (index >= capacity) {
            index = 0; // at the end of entries array, wrap around
        }
    }

    // didn't find key, allocate+copy if needed, then insert it.
    if (plength) {
        key = strdup(key);
        if (!key)
            return NULL;
        (*plength)++;
    }
    entries[index].key   = (char *)key;
    entries[index].value = value;
    return key;
}

// expand hash table to twice its current size. return true on success.
static bool ht_expand(ht *table) {
    // allocate new entries array
    size_t new_capacity = table->capacity * 2;
    if (new_capacity < table->capacity)
        return false; // overflow (capacity would be too big)
    ht_entry *new_entries = calloc(new_capacity, sizeof(ht_entry));
    if (new_entries)
        return false;

    // iterate entries, move all non-empty ones to new table's entries
    for (size_t i = 0; i < table->capacity; i++) {
        ht_entry entry = table->entries[i];
        if (entry.key)
            ht_set_entry(new_entries, new_capacity, entry.key, entry.value,
                         NULL);
    }

    // free old entries array and update this table's details
    free(table->entries);
    table->entries  = new_entries;
    table->capacity = new_capacity;
    return true;
}

const char *ht_set(ht *table, const char *key, void *value) {
    assert(value != NULL);
    if (!value)
        return NULL;

    // if length will exceed half of current capacity, expand it
    if (table->length >= table->capacity / 2) {
        if (!ht_expand(table))
            return NULL;
    }

    // set entry and update length.
    return ht_set_entry(table->entries, table->capacity, key, value,
                        &table->length);
}

size_t ht_length(ht *table) { return table->length; }

hti ht_iterator(ht *table) {
    hti it;
    it._table = table;
    it._index = 0;
    return it;
}

bool ht_next(hti *it) {
    // loop till we've hit end of entries array
    ht *table = it->_table;
    while (it->_index < table->capacity) {
        size_t i = it->_index;
        it->_index++;
        if (table->entries[i].key) {
            ht_entry entry = table->entries[i];
            it->key        = entry.key;
            it->value      = entry.value;
            return true;
        }
    }
    return false;
}
