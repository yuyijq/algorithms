#include "linked_list.c"

void print(ElementType value)
{
	printf("%d \n", value);
}

main(){
	int i;
	linked_list_t list = linked_list();
	int data[] = {5,7,10,34,45,21,44,56,8,222};
	for(i = 0;i < 10; ++i){
		append(list, data[i]);
	}
	foreach(list->iterator, &print);
}