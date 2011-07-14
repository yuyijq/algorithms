#include <assert.h>
#include "binary_search_tree.h"

void test_should_insert_element_to_empty_tree()
{
	binary_search_tree tree = NULL;
	tree = insert(tree, 5);
	
	assert(tree->value == 5);
	assert(tree->left == NULL);
	assert(tree->right == NULL);
}

void test_should_insert_less_value_to_left_tree()
{
	binary_search_tree tree = malloc(sizeof(struct tree_node));
	tree->value = 5;
	tree->left = NULL;
	tree->right = NULL;
	
	tree = insert(tree, 3);
	
	assert(tree->left->value == 3);
	assert(tree->right == NULL);
}

void test_should_insert_greater_value_to_right_value()
{
	binary_search_tree tree = malloc(sizeof(struct tree_node));
	tree->value = 5;
	tree->left = NULL;
	tree->right = NULL;
	
	tree = insert(tree, 8);
	
	assert(tree->right->value == 8);
	assert(tree->left == NULL);
}

void test_should_return_zero_height_given_empty_tree()
{
	assert(height(NULL) == 0);
}

binary_search_tree given_init_tree(int * data, int n)
{
	binary_search_tree tree = NULL;
	int i;
	for(i = 0; i < n; ++i){
		tree = insert(tree, data[i]);
	}
	return tree;
}

void test_should_rotate_left_with_left_insert()
{
	int data[] = {20,15,25,10,18};
	binary_search_tree tree = given_init_tree(data, 5);
	
	tree = insert(tree, 5);
	
	assert(tree->value == 15);
	assert(tree->left->value == 10);
	assert(tree->right->value == 20);
}

void test_should_rotate_left_with_right_insert()
{
	int data[] = {20,15,25,10,18};
	binary_search_tree tree = given_init_tree(data, 5);
	
	tree = insert(tree, 16);
	
	assert(tree->value == 18);
	assert(tree->left->value == 15);
	assert(tree->right->value == 20);
}

void test_should_rotate_right_with_right_insert()
{
	int data[] = {20,15,25,23,26};
	binary_search_tree tree = given_init_tree(data, 5);
	
	tree = insert(tree, 28);
	
	assert(tree->value == 25);
	assert(tree->left->value == 20);
	assert(tree->right->value == 26);
}

void test_should_rotate_right_with_left_insert()
{
	int data[] = {20,15,25,23,26};
	binary_search_tree tree = given_init_tree(data, 5);
	
	tree = insert(tree, 22);
	
	assert(tree->value == 23);
	assert(tree->left->value == 20);
	assert(tree->right->value == 25);
}

main()
{
	test_should_insert_element_to_empty_tree();
	test_should_insert_less_value_to_left_tree();
	test_should_insert_greater_value_to_right_value();
	test_should_return_zero_height_given_empty_tree();
	test_should_rotate_left_with_left_insert();
	test_should_rotate_left_with_right_insert();
	test_should_rotate_right_with_right_insert();
	test_should_rotate_right_with_left_insert();
	printf("tests for binary search tree are run successful! \n");
}