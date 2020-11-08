#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

typedef struct node {
	int data;
	struct node *left, *right;
}Tree;

Tree *insert(int value, Tree *r) {
	if (r) {
		if (value < r->data) r->left = insert(value, r->left);
		else r->right = insert(value, r->right);
		
		return r;
	} else {
		Tree *new = (Tree *)malloc(sizeof(Tree));
		new->data = value;
		new->left = NULL;
		new->right = NULL;
		return new;
	}
}
void show(Tree *r, int level) {
	if (r) {
		show(r->right, level + 1);
		
		int i;
		for (i = 0; i < level; i++) {
			printf("   ");
		}
		printf("(%d)%d\n", level, r->data);
		
		show(r->left, level + 1);
	}
}

Tree *search(int value, Tree *r){
	if (r) {
		if (value == r->data) return r;
		if (value < r->data) return search(value, r->left);
		return search(value, r->right);
	}
	return NULL;
}

int searchLevel(int value, Tree *r) {
	if (r) {
		if (value == r->data) return 0;
		if (value < r->data)  {
			int level = searchLevel(value, r->left);
			if (level == -1) return -1;
			else return level + 1;
		} else {
			int level = searchLevel(value, r->right);
			if (level == -1) return -1;
			else return level + 1;
		}
	}
	return -1;
}


int countNode(Tree *r) {
	if (r) {
		return 1 + countNode(r->left) + countNode(r->right);
	}
	return 0;
}

int countNodeLeaf(Tree *r) {
	if (r) {
		if (!r->left && !r->right) {
			return 1;
		}
		return  0 + countNodeLeaf(r->left) + countNodeLeaf(r->right);
	}
	return 0;
}

int countNodeWithoutLeaf(Tree *r) {
	if (r) {
		if (!r->left && !r->right) {
			return 0;
		}
		return 1 + countNodeWithoutLeaf(r->left) + countNodeWithoutLeaf(r->right);
	}
	return 0;
}

void showNodeLeaf(Tree *r) {
	if (r) {
		showNodeLeaf(r->left);

		if (!r->left && !r->right) {
			printf("%d\t",r->data);
		} 
		showNodeLeaf(r->right);
	}
}

int sumNode(Tree *r) {
	if (r) {
		return r->data + sumNode(r->right) + sumNode(r->left);
	}
	return 0;
}

int height(Tree *r) {
	if (r) {
		int leftHeight = height(r->left);
		int rightHeight = height(r->right);
		
		if (leftHeight > rightHeight) return 1 + leftHeight;
		return 1 + rightHeight;
	}
	return 0;
}

int main() {
	Tree *root = NULL;
	int i, value;
	srand(time(NULL));
	
	printf("generate random numbers\n");
	for (i = 0; i < TAM; i++){
		value = rand() % 100;
		root = insert(value, root);
	}
	
	printf("display tree from level 0\n");
	show(root, 0);

	printf("the height of the tree is: %d\n", height(root));
	printf("total count node leafs: %d\n", countNodeLeaf(root));
	showNodeLeaf(root);
	
	printf("\nenter a number to search in the tree: ");
	scanf("%d", &value);
	
	printf("level %d in the tree: %d\n", value, searchLevel(value, root));
	
	return 1;
}
