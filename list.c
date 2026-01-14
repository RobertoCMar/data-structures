#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

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

void pop(List* l){
	l->len--;
	l->data[l->len] = 0;
}

int get(List* l, int index){
	if (index < 0 || index >= l->len){
		printf("Error fuera de los limites de la lista\n");
		exit(EXIT_FAILURE);
	}
	return l->data[index];
}

void deleteAt(List* l, int index){
	if(index >= l->len){
		printf("Error fuera de los limites de la lista\n");
		exit(EXIT_FAILURE);
	}
	for(int i = index; i < l->len-1; i++){
		l->data[i] = l->data[i+1];
	}
	l->data[l->len-1] = 0;
	l->len--;
}

void insertAt(List* l, int n, int index){
	if( l->len >= l->capacity){
		copyData(l);
	}
	if(index > l->len){	
		printf("Error fuera de los limites de la lista\n");
		exit(EXIT_FAILURE);
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

int indexOf(List* l, int value){
	// Retorna el index de la primera ocurrencia del valor pasado como parametro
	// Si no se encuentra ninguna ocurrencia, retorna -1
	for(int i = 0; i < l->len;i++){
		if( l->data[i] == value){
			return i;
		}
	}
	return -1;
}

bool deleteOne(List* l, int value){
	//Remueve de la lista el primer numero con el valor value
	int i = indexOf(l, value);
	if (i == -1) {
		return false;
	}
	deleteAt(l, i);
	return true;
}



