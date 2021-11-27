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
struct dnode * last;
long count;          } dlist;
*/



dlist * dlist_init(){//создание двусвязанного списка
dlist * p = (dlist *)malloc(sizeof(dlist)); 
if (!p) return NULL;
p->count=0;
p->head=NULL;
p->last=NULL;
return p;
}


bool dlist_is_empty(dlist * list){
if (!list->head&&!list->last) return false;
return true;
}

int dlist_add(dlist*list,dnode * node){//добавление узла в конец
if (dlist_is_empty(list)){
list->head=node;
list->last=node;
}  else {
node->prev=list->head;
list->head=node;}
list->count++;
node->list=list;
return list->count;
}

int dlist_ins(dlist * list, dnode * node){ //вставка узла в начало
if (dlist_is_empty(list)){
list->head=node;
list->last=node;
} else {node->next=list->last;
list->last=node;}
list->count++;
node->list=list;
return list->count;
}


int dlist_list(dlist * list){//вывод узлов
dnode * n=list->head;
printf("list=%p n=%p n->next%p n->prev=%p \n",(void*)list,(void*)n,(void*)n->next,(void*)n->prev);
long c=0;
 while (n->next) {
 c++;
 printf("point-%12p data-%5i count-%5li\n",(void*)n, n->data,c);
 n=n->prev;}
return c;}

dnode * dlist_remove(dnode * node){//удаление узла
node->list->count--;
if (node->list->head!=node) 
node->prev->next=node->next->prev;
 else node->list->head=node->prev;
 if (node->list->last==node) { 
        if (node->list->count!=0) 
      	printf("Warning! Count mismatch with dlist is empty. %li nodes is orphaned!",node->list->count);
  			node->list->last=NULL;}
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


