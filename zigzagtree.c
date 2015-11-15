#include <stdio.h>
struct tree{
	int data;
	struct tree *right;
	struct tree *left;
	int level;
};
struct node{
	int data;
	struct node *prev;
	struct node *next;
	struct tree *this;
};
struct node *head=NULL;
struct node *tail=NULL;
//int treelevel=1;
struct node* createnode(struct node **head,struct node **tail,struct node*root){
	struct node* newnode=NULL;
	if(root==NULL)
		return;
	if(root==NULL)
		return;
	if(*head==NULL){
		struct node* newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=root->data;
		newnode->prev=NULL;
		newnode->next=NULL;
		newnode->this=root;
		*head=newnode;
		*tail=*head;
		//printf("tail data set %d with head =%d\n",*tail,*head);
		//return head;
	}
	else{	
		//printf("in else for %d with tail as %d\n",root->data,*tail);
		struct node* newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=root->data;
		newnode->this=root;
		newnode->prev=*tail;
		newnode->prev->next=newnode;
		//printf("tail is %d\n",temp->next->data);
		newnode->next=NULL;
		*tail=newnode;
		//printf("new tail is %d\n",*tail);
		//return tail;
	}
}

void addnodetohead(struct node **head,struct node **tail,struct node*root){
	if (root==NULL)
		return;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=root->data;
	newnode->this=root;
	newnode->next=*head;
	newnode->next->prev=newnode;
	newnode->prev=NULL;
	*head=newnode;
}
void removetail(struct node **tail){
		
	
}
void zigzag(struct tree* root){
	if(root==NULL)
		return;
	
	if(head==NULL)
		createnode(&head,&tail,root);
	//printf("in zigzag with head == %d\n",head->data);
	
		while(head!=NULL){
			if(head->this->level==1){
				struct tree*tem=head->this;
				//printf("list nodes are %d with tail %d and head = %d\n",tem->left->data,tail,head);
				createnode(&head,&tail,tem->left);
				createnode(&head,&tail,tem->right);
				//printf("list nodes are %d\n",tem->right->data);
				//printf("tree is %d\n",head->data);
				struct node *temp=head;
				head=head->next;
				//printf("%d\n",head->data);
				printf("%d\n",temp->data);
				free(temp);
				//printf("head removed");
			}
		
			else if((head->this->level)%2==0 && (tail->this->level>=head->this->level)){
				//printf("in else if\n");	
				struct tree*tem=head->this;
				createnode(&head,&tail,tem->left);		
				createnode(&head,&tail,tem->right);
				//printf("%d\n",head->data);
				struct node *temp=head;
				head=head->next;
				printf("%d\n",temp->data);
				free(temp);
			}
		
			else if((tail->this->level)%2!=0){
				struct tree*tem=tail->this;
				addnodetohead(&head,&tail,tem->right);
				addnodetohead(&head,&tail,tem->left);
				//printf("%d\n",tail->data);
				struct node *temp=tail;
				tail=tail->prev;
				printf("%d\n",temp->data);
				free(temp);
			}
			else
				return;
		}

}
struct tree* createtree(int data){
	
	struct tree* root=(struct tree*)malloc(sizeof(struct tree));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	//root->level=level;
	return root;
}
void printtree(struct tree *root){
	if(root==NULL)
		return;
	printf("%d\n",root->data);
	printtree(root->left);
	printtree(root->right);
}
void calculateheight(struct tree * root,int data){
	if(root==NULL)
		return;
	root->level=data;
	calculateheight(root->left,root->level+1);
	calculateheight(root->right,root->level+1);
}
void main(){
struct tree *root=NULL;
	root=createtree(100);
	root->left=createtree(50);
	root->left->left=createtree(20);
	calculateheight(root,1);
struct tree*temp=root;
//printtree(root);
zigzag(root);
}
