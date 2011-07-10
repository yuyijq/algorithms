#include "LinkedList.h"

LinkedList Create()
{
	LinkedList list = (LinkedList)malloc(sizeof(struct Node));
	list->Next = NULL;
	return list;
}

void Append(LinkedList list, ElementType value)
{
	Position newElement = malloc(sizeof(struct Node));
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
	Position current = list;
	while(current->Next != NULL)
	{
		if(current->Next->Value == value)
			return current;
		current = current->Next;
	}
	return NULL;
}

BOOL Delete(LinkedList list, ElementType value)
{
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
	printf("Elements of list: \n");
	Position current = list;
	while(current->Next != NULL)
	{
		current = current->Next;
		printf("%d \n",current->Value);
	}
}
