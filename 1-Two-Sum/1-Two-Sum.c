/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct hast_entry{
    int index;
    int value;
    struct hast_entry* next;
} hast_entry_t;

typedef struct hash_table{
    int size;
    hast_entry_t **hashEntries;
} hash_table_t;

static int hash(int key, int size){
    return abs(key % size);
}

int hash_table_create(hash_table_t *hashTable, int size) {
    int i;

    hashTable->size = size;
    hashTable->hashEntries = (hast_entry_t **) malloc(sizeof(hast_entry_t *) * size);
    if (!hashTable->hashEntries) {
        return -1;
    }

    for (i = 0; i < size; ++i) {
        hashTable->hashEntries[i] = NULL;
    }
    
    return 0;
}

hast_entry_t* hash_table_new_node(int index, int val) {
    hast_entry_t* entry = (hast_entry_t*)malloc(sizeof(hast_entry_t));
    if (entry) {
        entry->index = index;
        entry->value = val;
        entry->next = NULL;
    }

    return entry;
}

void hash_table_free(hash_table_t *hashTable) {
    int i;
    hast_entry_t *cur, *tmp;
    
    if (!hashTable->hashEntries)
        return;
    
    for (i = 0; i < hashTable->size; ++i) {
        cur = hashTable->hashEntries[i];
        while (cur) {
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    
    free(hashTable->hashEntries);
}

void hash_table_insert(hash_table_t *hashTable, hast_entry_t *hashEntry) {
    int key;
    hast_entry_t *cur, *prev;
    
    key = hash(hashEntry->value, hashTable->size);
    cur = hashTable->hashEntries[key];
    
    if (!cur) {
        hashTable->hashEntries[key] = hashEntry;
        return;
    }
    
    prev = NULL;
    while (cur) {
        if (cur->value >= hashEntry->value) {
            if (!prev) {
                hashEntry->next = cur;
            } else {
                prev->next = hashEntry;
                hashEntry->next = cur;
            }
            return;
        }
        
        prev = cur;
        cur = cur->next;
    }
}

hast_entry_t* hash_table_find(hash_table_t *hashTable, int value) {
    int key;
    hast_entry_t *entry;
    
    key =  hash(value, hashTable->size);
    entry = hashTable->hashEntries[key];

    while (entry) {
        if (entry->value == value) {
            return entry;
        }

        entry = entry->next;
    }
    
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i;
    hash_table_t hashTable;
    hast_entry_t *hashEntry;
    int *result = NULL;

    *returnSize = 0;
    if (hash_table_create(&hashTable, 65535) < 0) {
        goto EXIT;
    }
    
    for (i = 0; i < numsSize; ++i) {
        hashEntry = hash_table_find(&hashTable, target - nums[i]);
        if (hashEntry) {
            result = (int *)malloc(sizeof(int) * 2);
            if (result) {
                result[0] = hashEntry->index;
                result[1] = i;
                *returnSize = 2;
                goto EXIT;
            }
        } else {
            hashEntry = hash_table_new_node(i, nums[i]);
            if (!hashEntry)
                goto EXIT;
            hash_table_insert(&hashTable, hashEntry);
        }
    }

EXIT:
    hash_table_free(&hashTable);
    return result;
}