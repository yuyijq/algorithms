#ifndef _ASSERT_C_

#define _ASSERT_C_

#include <assert.h>
#include <stdio.h>

#define assertThat(actual, expected) \
{										 \
	if(actual != expected){				 \
		printf("expected is: %d, but actual is: %d \n", (expected), (actual)); \
	}				\
	assert(actual == expected); \
}

#endif