#ifndef _LIST_H_
#include "Common.h"

#define _LIST_H_
typedef int ElementType;
struct ListNode;
typedef struct ListNode *Position;
typedef struct ListNode *LinkedList;

LinkedList CreateList();
void Append(LinkedList list, ElementType value);
Position FindPrev(LinkedList list, ElementType value);
Position Find(LinkedList list, ElementType value);
BOOL Delete(LinkedList list, ElementType value);
int Length(LinkedList list);
void Print(LinkedList list);

struct ListNode{
	ElementType Value;
	Position Next;
};
#endif


