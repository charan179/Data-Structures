#include <stdio.h>
#define TRUE 1
#define FALSE 0
struct node{
int data;
struct node*left;
struct node *right;
};
int MAX=1000;
int MIN=-1000;
int bst(struct node *root,int MIN,int MAX){
	if(root==NULL)
		return TRUE;
	if((root->data>MIN) && (root->data<MAX) && bst(root->left,MIN,root->data) && bst(root->right,root->data,MAX))
			return TRUE;
	else 
			return FALSE;



}

struct node* createnode(int data){
	struct node * root=(struct node*)malloc(sizeof(struct node));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
}
struct node *find(struct node *root,int data){
	printf("%d\n\n\n",root->data);
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		return;
	if(root->data==data)
		return root;
	else 
		return find(root->left,data) || find(root->right,data);
	
}
void delete(struct node * root,int data){
	struct node *root1=find(root,data);
	printf("%d\n",root1->data);







}
void main(){
struct node *root=NULL;
root=createnode(7);
root->left=createnode(4);
root->right=createnode(10);
root->left->left=createnode(1);
root->left->right=createnode(5);
root->right->left=createnode(8);
root->right->right=createnode(11);
delete(root,10);
if(bst(root,MIN,MAX))
	printf("tree is bst\n");
else
	printf("tree is not bst\n");
}
