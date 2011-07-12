#include "LinkedList.h"
#include <assert.h>

LinkedList CreateList()
{
	LinkedList list = (LinkedList)malloc(sizeof(struct ListNode));
	list->Next = NULL;
	return list;
}

void Append(LinkedList list, ElementType value)
{
	assert(list != NULL);
	
	Position newElement = malloc(sizeof(struct ListNode));
	if(newElement){
		newElement->Value = value;
		newElement->Next = NULL;
	}else{
		return;
	}
	Position current = list;
	while(current->Next)
		current = current->Next;
	current->Next = newElement;
}

Position FindPrev(LinkedList list, ElementType value)
{
	assert(list != NULL);
	
	Position current = list;
	while(current->Next != NULL)
	{
		if(current->Next->Value == value)
			return current;
		current = current->Next;
	}
	return NULL;
}

Position Find(LinkedList list, ElementType value)
{
	Position prev = FindPrev(list, value);
	if(prev != NULL)
		return prev->Next;
	return NULL;
}

BOOL Delete(LinkedList list, ElementType value)
{
	assert(list != NULL);
	
	Position target;
	Position prev = FindPrev(list, value);
	if(prev != NULL)
	{
		target = prev->Next;
		prev->Next = target->Next;
		free(target);
		return TRUE;	
	}
	return FALSE;
}

int Length(LinkedList list)
{
	assert(list != NULL);
	
	int len = 0;
	Position current = list;
	while(current->Next != NULL)
	{	
		++len;
		current = current->Next;
	}
	return len;
}

void Print(LinkedList list)
{
	assert(list != NULL);
	
	printf("Elements of list: \n");
	Position current = list;
	while(current->Next != NULL)
	{
		current = current->Next;
		printf("%d \n",current->Value);
	}
}
