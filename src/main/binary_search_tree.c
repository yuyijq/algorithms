#include "binary_search_tree.h"

binary_search_tree rotate_right_with_right(binary_search_tree k1)
{	
	binary_search_tree k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	
	return k2;
}

binary_search_tree rotate_right_with_left(binary_search_tree k1)
{
	binary_search_tree rotate_left_with_left(binary_search_tree);
	k1->right = rotate_left_with_left(k1->right);
	return rotate_right_with_right(k1);
}

binary_search_tree rotate_left_with_right(binary_search_tree k1)
{
	binary_search_tree rotate_left_with_left(binary_search_tree);
	
	k1->left = rotate_right_with_right(k1->left);
	
	return rotate_left_with_left(k1);
}

binary_search_tree rotate_left_with_left(binary_search_tree k1)
{
	binary_search_tree k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	
	return k2;
}

int max(int left, int right)
{
	return left > right ? left : right;
}

int height(binary_search_tree tree)
{
	if(tree == NULL) return 0;
	return tree->height;
}

binary_search_tree insert(binary_search_tree tree, ElementType value)
{
	if(tree == NULL){
		tree = malloc(sizeof(struct tree_node));
		tree->value = value;
		tree->left = NULL;
		tree->right = NULL;
	}else{
		if(value < tree->value){
			tree->left = insert(tree->left, value);
			//need roate
			if(height(tree->left) - height(tree->right) == 2){
				//insert into left child of left child
				if(value < tree->left->value){
					tree = rotate_left_with_left(tree);
				}else{
					tree = rotate_left_with_right(tree);
				}
			}
		}else if(value > tree->value){
			tree->right = insert(tree->right, value);
			//need rotate
			if(height(tree->right) - height(tree -> left) == 2){
				if(value > tree->right->value){
					tree = rotate_right_with_right(tree);
				}else{
					tree = rotate_right_with_left(tree);
				}
			}
		}
	}
	tree -> height = max(height(tree->left),height(tree->right)) + 1;
	return tree;	
}

position find_min(binary_search_tree tree)
{
	if(tree == NULL){
		return NULL;
	}
	if(tree->left != NULL){
		return find_min(tree->left);
	}else{
		return tree;
	}
}

binary_search_tree delete(binary_search_tree tree, ElementType value)
{
	binary_search_tree temp;
	if(tree == NULL)
		printf("There is not a node value is %d \n", value);
	else
		if(value < tree->value)
			tree->left = delete(tree->left, value);
		else if(value > tree->value)
			tree->right = delete(tree->right, value);
		else
			if(tree->left != NULL && tree->right != NULL){
				temp = find_min(tree->right);
				tree->value = temp->value;
				tree->right = delete(tree->right, temp->value);
			}else{
				temp = tree;
				if(tree -> left != NULL)
					tree = tree->left;
				else if(tree -> right != NULL)
					tree = tree->right;
				else
					tree = NULL;
				free(temp);
			}
	return tree;
}

void print(binary_search_tree tree)
{
	if(tree == NULL)return;
	print(tree->left);
	printf(" %d ", tree->value);
	print(tree->right);
}