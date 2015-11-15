#include<stdio.h>
#define TRUE 1
#define FALSE 0

struct node{
	int data;
	struct node *left,*right;
};
struct node* newNode(int);
int sumtree(struct node* ,int *);

int sumtree(struct node* root,int *flag){

if(root==NULL)
	return TRUE; 
if(root->left==NULL && root->right==NULL){
	*flag=1;
 	return TRUE;
}
if((sumtree(root->left,flag)) && (sumtree(root->right,flag))){
	//printf("\nin here%d",root->data);
	if(*flag==1 && (root->data==((root->left)?(root->left->data):0) +((root->right)?(root->right->data):0))){	
		*flag=0;
		//printf("\nleaf node %d",root->data);	
		return TRUE;	
}
	else if (*flag==0 && root->data==2*(root->left->data + root->right->data)){ 
		//printf("\nnot leaf node %d",root->data);
		return TRUE;
	
	}
	else 
		return FALSE;
}
else
	return FALSE;


	
}


struct node* newNode(int data){

	struct node* root=(struct node*)malloc(sizeof(struct node*));
	root->data=data;	
	root->left=NULL;
	root->right=NULL;
		return root;
}
void main(){
int flag;
struct node* root=newNode(25);
root->left=newNode(10);
root->right=newNode(3);
root->left->left=newNode(4);
root->left->right=newNode(6);
//root->right->left=newNode(0);
root->right->right=newNode(3);
if(sumtree(root,&flag))
	printf(" TREE IS SUM TREE");
}
