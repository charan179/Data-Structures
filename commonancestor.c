#include<stdio.h>
struct node{
int data;
struct node* left;
struct node* right;
};
struct node* newNode(int );
int commonancesor(struct node*,int,int);
int sametree(struct node*,int);
int sametree(struct node* root,int data){
if(root==NULL)
	return 0;
if(root->data==data)
	return 1;
else{
	if((sametree(root->left,data))||(sametree(root->right,data)))
		return 1;
	}
}
int commonancestor(struct node* root,int i,int j){

if((sametree(root->left,i)) & (sametree(root->left,j)))
	  commonancestor(root->left,i,j);
else if((sametree(root->right,i)) & (sametree(root->right,j)))
	 commonancestor(root->right,i,j);
else 
	return root->data;
}

struct node *newNode(int data){
struct node *root=(struct node *)malloc(sizeof(struct node));
root->data=data;
root->left=NULL;
root->right=NULL;
return root;
}
void main(){
struct node *root =newNode(1);

root->left=newNode(2);
root->right=newNode(3);
root->left->left=newNode(4);
root->left->right=newNode(5);
root->right->left=newNode(6);
root->right->right=newNode(7);
int i;
i=commonancestor(root,6,7);
printf("\n%d\n",i);

}
