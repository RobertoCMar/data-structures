#ifndef LIST_H
#define LIST_H
typedef struct List {
	int len;
	int capacity;
	int* data;
} List;
struct List* newList();
void freeList(List* l);
void printList(List* l);
void copyData(List* l);
void append(List* l, int n);
void pop(List* l);
int get(List* l, int index);
void deleteAt(List* l, int index);
int indexOf(List *l, int value);
bool deleteOne(List* l, int value);
void insertAt(List* l, int n, int index);

#endif
