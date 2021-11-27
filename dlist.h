#include <stdbool.h>


typedef struct dnode {
struct dnode * prev;
struct dlist * list;
int data;
struct dnode * next; } dnode;   
	        

typedef struct dlist {
struct dnode * head;
struct dnode * tail;
long count;          } dlist;
	             
	             
dlist * dlist_init();

dnode * dlist_remove(dnode * node);

int dlist_add(dlist * list,dnode * node);//добавление узла в конец

int dlist_ins(dlist * list, dnode * node);//вставка узла в начало

bool dlist_is_empty(dlist * list);

bool dlist_is_trivial(dlist * list);


unsigned long dlist_list(dlist * list);//вывод узлов

dnode * dlist_remove(dnode * node);//удаление узла

dnode * dnode_add(int data);

int dnode_print(dnode * node);
