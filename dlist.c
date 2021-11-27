#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
typedef struct dnode {
struct dnode * prev;
struct dlist * list;
int data;
struct dnode * next; } dnode;   
	        

typedef struct dlist {
struct dnode * head;
struct dnode * tail;
long count;          } dlist;
*/



dlist * dlist_init(){//создание двусвязанного списка
dlist * p = (dlist *)malloc(sizeof(dlist)); 
if (!p) return NULL;
p->count=0;
p->head=NULL;
p->tail=NULL;
return p;
}


bool dlist_is_empty(dlist * list){
if (!list->head&&!list->tail) return true;
return false;
}

int dlist_add(dlist*list,dnode * node){//добавление узла в конец
if (dlist_is_empty(list)){//puts("empty");
list->head=node;
list->tail=node;
}  else {
node->prev=list->head;
node->prev->next=node;
list->head=node;}
list->count++;
node->list=list;
return list->count;
}

int dlist_ins(dlist * list, dnode * node){ //вставка узла в начало
if (dlist_is_empty(list)){//puts("empty");
list->head=node;
list->tail=node;
} else {node->next=list->tail;
node->next->prev=node;
list->tail=node;}
list->count++;
node->list=list;
return list->count;
}


unsigned long dlist_list(dlist * list){//вывод узлов
unsigned long c=0;
dnode * p = list->tail;
while(p) {c++;
	dnode_print(p);
	p=p->next;}
return c;}

int dnode_print(dnode * node){

printf("prev-%12p next-%12p data-%8i list-%12p\n",(void*)node->prev,
		(void*)node->next,
				node->data,(void*)node->list);

return 0;
}


dnode * dlist_remove(dnode * node){//удаление узла
node->list->count--;
if (node->list->head!=node) 
node->prev->next=node->next->prev;
 else node->list->head=node->prev;
 if (node->list->tail==node) { 
        if (node->list->count!=0) 
      	printf("Warning! Count mismatch with dlist is empty. %li nodes is orphaned!",node->list->count);
  			node->list->tail=NULL;}
node->list=NULL;
return node;
}

dnode * dnode_add(int data){
dnode * p = (dnode*)malloc(sizeof(dnode));
if (!p) return NULL;
p->data=data;
p->prev=NULL;
p->next=NULL;
p->list=NULL;
return p;}


