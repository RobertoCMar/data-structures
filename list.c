#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct List {
	int len;
	int capacity;
	int* data;
} List;

struct List* newList(){
	int* arr = (int*)calloc(50, sizeof(int));
	if(arr == NULL){
		printf("Error inicalizando arr en Lista\n");
		exit(EXIT_FAILURE);
	}
	List* l = (List*)malloc(sizeof(List));
	if(l == NULL){
		printf("Error inicalizando Lista\n");
		exit(EXIT_FAILURE);
	}
	l->len = 0;
	l->capacity = 50;
	l->data = arr;
	return l;
}

void freeList(List* l){
	free(l->data);
	free(l);
}

void printList(List* l){
	for(int i = 0; i < l->len; i++){
		printf("%d ", l->data[i]);
	}
	printf("\n");
}

void copyData(List* l){
	int* arr = (int*)calloc(l->capacity*2, sizeof(int));
	memcpy(arr, l->data, sizeof(int) * l->len);
	free(l->data);
	l->data = arr;
	l->capacity *= 2;
}

void append(List* l, int n){
	if (l->len >= l->capacity){
		copyData(l);
	}
	l->data[l->len] = n;
	l->len++;
}

void insertAt(List* l, int n, int index){
	if( l->len >= l->capacity){
		copyData(l);
	}
	if(index > l->len){
		l->data[index] = n;
	}
	int temp;
	for(int i = index; i <= l->len; i++){
		if(i != l->len){
			temp = l->data[i];
		}
		l->data[i] = n;
		n = temp;
	}
	l->len++;
}


int main(){
	List* l = newList();
	printList(l);
	append(l, 3);
	printList(l);
	for(int i = 0; i < 200; i++){
		append(l, i);
	}
	printList(l);
	insertAt(l, 86, 1);
	printList(l);
	freeList(l);
	printf("Aa\n");
	printf("a\n");
	return 0;
}

