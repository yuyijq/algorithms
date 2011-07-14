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

void test_should_find_prev_node()
{
	LinkedList list = CreateList();
	Append(list, 5);
	Append(list, 8);
	
	assert(FindPrev(list, 8)->Value == 5);
}

void test_should_delete_given_element()
{
	LinkedList list = CreateList();
	Append(list, 5);
	Append(list, 8);
	
	Delete(list, 5);
	
	assert(list->Next->Value == 8);
}

void test_should_find_given_element()
{
	LinkedList list = CreateList();
	Append(list, 5);
	Append(list, 8);
	
	Position target = Find(list, 5);
	
	assert(target == list->Next);
}

int main()
{
	test_should_create_empty_list();
	test_should_return_length_1_given_empty_list();
	test_should_return_right_length();
	test_should_append_node_to_given_list();
	test_should_find_prev_node();
	test_should_delete_given_element();
	test_should_find_given_element();
	printf("tests for LinkedList run successful \n");
	return 0;
}
