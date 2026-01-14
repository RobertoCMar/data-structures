#include <stdio.h>
#include <stdbool.h>
#include "list.h"

int main(){
	List* l = newList();
	printf("Lista vacia\n");
	printList(l);
	append(l, 3);
	printf("Lista con un 3:\n");
	printList(l);
	for(int i = 0; i < 200; i++){
		append(l, i);
	}
	printf("Lista con un 3 y numeros del 0 al 199:\n");
	printList(l);
	insertAt(l, 86, 1);
	printf("Lista con un 3, un 86 y numeros del 0 al 199:\n");
	printList(l);
	deleteAt(l, 1);
	printf("Lista con un 3 y numeros del 0 al 199:\n");
	printList(l);
	printf("Lista con un 3 y numeros del 0 al 199 y un 67:\n");
	insertAt(l, 67, l->len);
	printList(l);
	printf("Lista con un 3 y numeros del 0 al 199:\n");
	pop(l);
	printList(l);
	printf("Lista con un 3 y numeros del 0 al 198:\n");
	deleteOne(l, 199);
	printList(l);

	freeList(l);
	return 0;
}
