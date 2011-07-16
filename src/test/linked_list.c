#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "iterator.c"

struct node;
typedef struct node *position;
struct linked_list_s;
typedef struct linked_list_s *linked_list_t;

struct linked_list_s{
	position head;
	iterator_t iterator;
};

struct node{
	ElementType value;
	position next;
};

BOOL list_has_next(iterator_t iterator)
{
	position current = iterator->cursor;
	return TRUE;
}

void list_move_next(iterator_t iterator)
{
	position current = iterator->cursor;
	iterator->cursor = current->next;
	current = iterator->cursor;
	iterator->current = current->value;
}

linked_list_t linked_list()
{
	linked_list_t list = malloc(sizeof(struct linked_list_s));
	iterator_t iterator = malloc(sizeof(struct iterator_s));
	list->head = malloc(sizeof(struct node));
	iterator->cursor = list->head;
	iterator->has_next = &list_has_next;
	iterator->move_next = &list_move_next;
	list->iterator = iterator;
	return list;
}

void append(linked_list_t list, ElementType value)
{
	position current = list->head;
	while(current->next){
		current = current->next;
	}
	current->next = malloc(sizeof(struct node));
	current->next->value = value;
}