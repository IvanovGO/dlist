#include "dlist.h"
#include <stdio.h>


int main(int argc,char * argv[]){

dlist * dl = dlist_init();

printf("%p\n\n\n",(void*)dl);


			puts("add");
for (int i=0;i<20;i++){
printf("count- %i ",dlist_add(dl,dnode_add(i)));
printf("tail-%p head-%p\n	",(void*)dl->tail,(void*)dl->head);}
			puts("ins");
for (int i=21;i<40;i++){
printf("count-%i ",dlist_ins(dl,dnode_add(i)));
printf("head-%p tail-%p\n	",(void*)dl->tail,(void*)dl->head);}
puts("");

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


return 0;
}
