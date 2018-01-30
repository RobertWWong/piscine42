#include <stdio.h>
#include "rowong/ex00/btree_create_node.c"
#include "rowong/ex01/btree_apply_prefix.c"
#include "rowong/ex02/btree_apply_infix.c"
#include "rowong/ex03/btree_apply_suffix.c"
#include "rowong/ex04/btree_insert_data.c"

t_btree 	*insert_bst(t_btree *root, int val)
{
	if (root == NULL)
		return btree_create_node(&val);

	if (val < (int) root->item)
		root->left = insert_bst(root->left, val);
	else if (val > (int) root->item)
		root->right = insert_bst(root->right, val);
	printf("%d\n", (int) root->item);
	return root;
}

void print_val(void *item)
{
	printf("%d\n", (int)item );
}


int cmp (void *a, void *b)
{
	return (*((int *)a)) - (*((int *)b));
}

int main()
{
	int one = 1;
	int two = 2;
	int three = 3;
	t_btree **what = (t_btree **) malloc(sizeof(t_btree*));

	t_btree *root = btree_create_node(&one);
	root = *what;
	// root->right = btree_create_node(&three);


	

	// printf("%d\n", (int)root->item);

	// printf("%d\n", (int)root->left->item);


	// t_btree *root2;
	btree_insert_data(&root, &two, &cmp);
	btree_insert_data(&root, &three, &cmp);

	printf("%d\n",*((int*)(root->left->item)) );

	// btree_apply_prefix(root, print_val);

	return 0;
}

	