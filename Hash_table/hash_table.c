#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

ht_item * ht_new_item(const char* k, const char * v){
	ht_item* i = malloc(sizeof(ht_item));
	i->key = strdup(k);
	i->value = strdup(v);
	return i;
}

hash_table * ht_new(){
	hash_table *ht = (hash_table *) malloc(sizeof(hash_table));

	ht->size = 53;
	ht->count = 0;
	ht->items = calloc((size_t) ht->size, sizeof(ht_item));

}

void ht_del_item(ht_item* i){
	free(i->key);
	free(i->value);
	free(i);
}

void del_hash_table(hash_table * ht){
	for(int i = 0 ; i < ht->size; i++){
		ht_item* item = ht->items[i];
		if(item != NULL)
			ht_del_item(item);
	}
free(ht->items);
free(ht);
}

int ht_hash(const char* s, const int a, const int m){
	long hash = 0;
	cont int len_s = strlen(s);
	for(int i = 0; i < len_s; i++){
		hash += (long)pow(a, len_s - (i+1) * s[i]);
		hash = hash % m;
	}
	return (int)hash;
}

int ht_get_hash(const char* s, const int num_buckets, const int attempt){
	const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
	const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
	return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}


