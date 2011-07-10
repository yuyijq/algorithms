#ifndef _LIST_H_
#include "Common.h"

#define _LIST_H_

typedef int ElementType;
typedef struct Node *Position;
typedef struct Node *LinkedList;

LinkedList Create();
void Append(LinkedList list, ElementType value);
Position FindPrev(LinkedList list, ElementType value);
BOOL Delete(LinkedList list, ElementType value);
int Length(LinkedList list);
void Print(LinkedList list);


struct Node{
	ElementType Value;
	Position Next;
};

#endif


