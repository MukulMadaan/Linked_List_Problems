#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void createNode(struct node **head,int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;  
	temp->next = *head;  
	*head = temp; 
}

struct node* atBegg(struct node *head,int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = head;
	head = temp;
	
	return head;
}

struct node* atEnd(struct node *head,int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *traverse = NULL;
	traverse = head;
	while(traverse->next != NULL){
		traverse = traverse->next;
	}
	temp->data = data;
	traverse->next = temp;
	temp->next = NULL;
	
	return head;
}

struct node* atPos(struct node *head, int data,int k)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *traverse = NULL;
	traverse = head;
	if(k==1){
		head = atBegg(head,data);
	} else {
		k = k-1;
		while(--k){
			traverse = traverse->next;
		}
		temp->data = data;
		temp->next = traverse->next;
		traverse->next = temp;
	}
	
	return head;
}

void printList(struct node *head)
{
	while(head != NULL){
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	struct node *head = NULL; 
	int n;
	int x;
	int i;
	int k;
	printf("Enter Size of List = ");
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&x);
		createNode(&head,x);
	}
	printf("Enter Value = ");
	scanf("%d",&x);
	printf("Enter Position = ");
	scanf("%d",&k); 
	printList(head);
	
	head = atBegg(head, x);
	printList(head);
	head = atEnd(head, x);
	printList(head);	
	head = atPos(head, x, k);
	printList(head);
}
