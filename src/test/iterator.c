#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef char BOOL;
typedef int ElementType;

#define TRUE 1
#define FALSE 0

struct iterator_s;
typedef struct iterator_s *iterator_t;
typedef BOOL (*has_next_fp)(iterator_t);
typedef void (*move_next_fp)(iterator_t);
typedef void (*action_fp)(ElementType);

struct iterator_s{
	has_next_fp has_next; 
	move_next_fp move_next;
	ElementType current;
	void *cursor;
};

void foreach(iterator_t iterator, action_fp action)
{
	while(iterator->has_next(iterator)){
		iterator->move_next(iterator);
		action(iterator->current);
	}
}