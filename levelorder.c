#include <stdio.h>

struct node{
int data;
struct node *left;
struct node *right;
};
struct queue{
int data;
struct node* this;
struct queue *next;
int height;
};
struct queue* head;
int height_check = 0;
void insert(struct node*root, int height){
	//struct queue* head;
	if(head==NULL){
		//struct queue *head;
		head=(struct queue*)malloc(sizeof(struct queue)); 
		head->data=root->data;
		head->this=root;
		head->height = height;
		head->next=NULL;
		//printf("\ninside insert head is %d",head->data);
		//return head;
		}
	else{
		//printf("\n entered else ");
		struct queue *temp=head;
		struct queue *prev;
		while(temp!=NULL){
			prev=temp;
			temp=temp->next;
		}
		temp = (struct queue*)malloc(sizeof(struct queue));
		prev->next = temp;
		temp->data = root->data;
		//printf("\nNewly added data node is %d ",temp->data);
		temp->this=root;
		temp->height = height;
		temp->next=NULL;
		
		}
}

void levelorder(struct node* root){
	height_check = 1;
	struct node *temp;
	if(root==NULL)
		return;
	insert(root, 1);
	//printf("\n insert called");
	while(head!=NULL){
		//printf("\n inside while loop");
		//printf("\n New head is %d", head->data);
		temp = head->this;
		if(temp->left != NULL)
			insert(temp->left, (head->height)+1);
		if(temp->right != NULL)
			insert(temp->right, (head->height)+1);
		//printf("height is %d and heightcheck is %d\n", head->height, height_check);
		if(head->height != height_check)
			{
				printf("\n");
				height_check++;
			}
		temp = head;
		head=head->next;
		printf("%d ",temp->data);
		//printf("\nNew head data is %d",head->data);
		free(temp);
	}
	printf("\n");
}
struct node *createnode(int data){
	struct node *root=(struct node*)malloc(sizeof(struct node));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}


void main(){
struct node *root=createnode(1);
//printf("%x\n",&root);
//printf("%x\n",&root->data);


root->left=createnode(2);
printf("%x\n",&root->left);
printf("%x\n",root->left);
root->right=createnode(3);
root->left->left=createnode(4);
root->left->right=createnode(5);
root->right->left=createnode(6);
root->right->right=createnode(7);
//printf("root is %d",root->data);
//printf("root left is %d",root->left->data);
//printf("root right is %d",root->right->data);
levelorder(root);
}
