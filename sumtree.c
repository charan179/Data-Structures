#include<stdio.h>
#define TRUE 1
#define FALSE 0
struct node{
int data;
struct node* left;
struct node* right;
};
struct node* newNode(int );
struct node* sum(struct node *);
struct node * print(struct node *);
struct node * checksum(struct node *);



struct node * checksum(struct node * root){
if(root==NULL)
	return TRUE;
if(root->left == NULL && root->right==NULL)
	return TRUE;
printf("\nin\n");
if((checksum(root->left)) && (checksum(root->right))){
	printf("inside %d\n",root->data);
if(root->data==(root->left->data + ((root->right)?root->right->data:0)))
	{
	printf("\n\n\nhi %d ",root->data);
	return TRUE;
	}

	return FALSE;
}
	
}


struct node* sum(struct node * root){
if (root->left==NULL && root->right==NULL)
	return;
if(root->data < (root->left->data + root->right->data))
	root->data=root->left->data + root->right->data;
if((sum(root->left)) && (sum(root->right)))
	return;

}
struct node *newNode(int data){
struct node *root=(struct node *)malloc(sizeof(struct node));
root->data=data;
root->left=NULL;
root->right=NULL;
return root;
}
struct node* print(struct node * root){

if(root==NULL)
	return;
printf("\n%d",root->data);
print(root->left);
print(root->right);
}
void main(){
struct node *root =newNode(8);

root->left=newNode(5);
root->right=newNode(3);
root->left->left=newNode(3);
root->left->right=newNode(2);
root->right->left=newNode(3);
root->right->right=newNode(0);
//sum(root);
//print(root);
if(checksum(root))
	printf("ROot is sum tree");
}
