#include "dlist.h"
#include <stdio.h>
#include <time.h>


void foo(dnode*node){printf("nodded by function COUNT = %li \n",node->list->count);node->list->count--;}

int main(int argc,char * argv[]){

dlist * dl = dlist_init();

printf("%p\n\n\n",(void*)dl);

srand(time(NULL));
			puts("add");
for (int i=0;i<20;i++){
printf("count- %i ",dlist_add(dl,dnode_add(i)));
printf("tail-%p head-%p\n",(void*)dl->tail,(void*)dl->head);}
			puts("ins");
/*for (int i=21;i<40;i++){
printf("count-%i ",dlist_ins(dl,dnode_add(rand()%100)));
printf("head-%p tail-%p\n",(void*)dl->tail,(void*)dl->head);}
puts("");
*/
printf("%i %i\n",dl->tail->data,dl->head->data);


printf("%p\n\n\n",(void*)dl);
puts("LIST_ALL");
dlist_list(dl);

puts("head");
dnode_print(dl->head);
puts("tail");
dnode_print(dl->tail);
puts("test");
dnode_print(dnode_add(104));

printf("LIST MAX COUNT = %li \n",dlist_max(dl)->list->count);
printf("LIST MIN COUNT = %li \n",dlist_min(dl)->list->count);
foo(dlist_min(dl));
foo(dlist_min(dl));
puts("/----------------------------SORT--------------------------/");

printf("list max-%p \n",(void*)dlist_max(dl));
dlist * dsl=dlist_sort(dl);
puts("/------------------------SORTED LIST----------------------/");
dlist_list(dsl);

return 0;
}
