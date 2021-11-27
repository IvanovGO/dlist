#include "dlist.h"
#include <stdio.h>


int main(int argc,char * argv[]){

dlist * dl = dlist_init();

printf("%p\n\n\n",(void*)dl);


			puts("add");
for (int i=0;i<20;i++){
printf("count- %i ",dlist_add(dl,dnode_add(i)));
printf("%p %p\n	",(void*)dl->last,(void*)dl->head);}
			puts("ins");
for (int i=21;i<40;i++){
printf("count-%i ",dlist_ins(dl,dnode_add(i)));
printf("%p %p\n	",(void*)dl->last,(void*)dl->head);}
puts("");
dlist_list(dl);

return 0;
}
