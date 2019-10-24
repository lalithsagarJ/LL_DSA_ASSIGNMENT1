#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *link;
};

typedef struct node *NODE ;
int size=20,count=0;

NODE getnode(){
	NODE x=(NODE)malloc(sizeof(struct node));
	return x;
}

NODE startA=NULL,startB=NULL,startC=NULL,startD=NULL;

NODE insert(){
	int e,p,c=1;
	if(count>=size)
		printf("\n\nlist is full\n");
	else{
	printf("\nenter the element:");
	scanf("%d",&e);
	printf("\nenter the position:");
	scanf("%d",&p); 
	NODE temp=getnode();
	temp->data=e;
	if(p==1){
		temp->link=startA;
		startA=temp;
	}
	else{
		NODE ptr=startA;
		while(c<p-1){
			ptr=ptr->link;
			c++;			
		}
		temp->link=ptr->link;
		ptr->link=temp;
	}
	count++;
	}
}

NODE seperate(){
	NODE ptr1;
	startB=startC=startD=NULL;
	ptr1=startA;
	while(ptr1!=NULL){
		if(((ptr1->data)%2 == 0)||((ptr1->data)%5 == 0)){
			if((ptr1->data)%2 == 0){
				NODE temp=getnode();
				temp->data=ptr1->data;
				temp->link=startB;
				startB=temp;
			}
			if((ptr1->data)%5 == 0){
				NODE temp=getnode();
				temp->data=ptr1->data;
				temp->link=startC;
				startC=temp;
			}
		}
		else{
			NODE temp=getnode();
			temp->data=ptr1->data;
			temp->link=startD;
			startD=temp;
		}
		ptr1=ptr1->link;
	}
}

NODE display(){
	NODE ptrA=startA,ptrB=startB,ptrC=startC,ptrD=startD;

	printf("\n\n******Elements in list A******\n");
	if(ptrA==NULL)
		printf("\nA is empty");
	while(ptrA!=NULL){
		printf("%d ",ptrA->data);
		ptrA=ptrA->link;
	}
	
	printf("\n\n******Elements in list B******\n");
	if(ptrB==NULL)
		printf("\nB is empty");
	while(ptrB!=NULL){
		printf("%d ",ptrB->data);
		ptrB=ptrB->link;
	}
	
	printf("\n\n******Elements in list C******\n");
	if(ptrC==NULL)
		printf("\nC is empty");
	while(ptrC!=NULL){
		printf("%d ",ptrC->data);
		ptrC=ptrC->link;
	}

	printf("\n\n******Elements in list D******\n"); 
	if(ptrD==NULL)
		printf("\nD is empty");
	while(ptrD!=NULL){
		printf("%d ",ptrD->data);
		ptrD=ptrD->link;
	}
}

int main()
{
	int option;
	do
	{
		printf("\n\n1.insert\n2.seperate the list\n3.display\n0.exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:insert();
				break;
			case 2:seperate();
				break;
			case 3:display();
				break;
		}
	}while(option!=0);
	return 0;
}
