#include <assert.h>
#include "LinkedList.h"

void test_should_create_empty_list()
{
	LinkedList list = CreateList();
	assert(list != NULL);
}

void test_should_return_length_1_given_empty_list()
{
	LinkedList list = CreateList();
	assert(Length(list) == 0);
}
void test_should_return_right_length()
{
	LinkedList list = CreateList();
	Position newNode = malloc(sizeof(struct ListNode));
	newNode->Value = 5;
	list->Next = newNode;
	
	assert(Length(list)==1);
}

void test_should_append_node_to_given_list()
{
	LinkedList list = CreateList();
	Append(list, 5);
	Append(list, 8);
	
	assert(Length(list) == 2);
	assert(list->Next->Value == 5);
}

main()
{
	test_should_create_empty_list();
	test_should_return_length_1_given_empty_list();
	test_should_return_right_length();
	test_should_append_node_to_given_list();
	printf("tests for LinkedList run successful \n");
}
