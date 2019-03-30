#ifndef _HASH_
#define _HASH_
typedef struct {
	char* key;
	char* value;
}ht_item;

// hash_table.h
typedef struct {
	int size;
	int count;
	ht_item** items;
}hash_table;

ht_item * ht_new_item(const char* k, const char * v);
hash_table * ht_new();
void del_hash_table(hash_table * ht);
void ht_del_item(ht_item* i);
int ht_hash(const char* s, const int a, const int m);



#endif