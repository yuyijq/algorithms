#include <assert.h>
#include "LinkedList.h"

void test_should_create_empty_list()
{
	LinkedList temp = Create();
	assert(temp != NULL);
	assert(temp->Next == NULL);
}
void test_should_return_right_length()
{
	
}

main()
{
	test_should_create_empty_list();
}
