#include <stdio.h>
#include <stdlib.h>

struct node{
    int indx;
    struct node* next;
};


int print_reverse(struct node * strt){
	struct node* nd=strt;
	if (strt->next==NULL){
		printf("%d ", nd->indx);		
		return 0;
	}
	print_reverse(nd->next);
	printf("%d ", nd->indx);
}


void insert(struct node * strt, int x){
	struct node* nd=strt;
        struct node* nd_new;
	while (nd->next!=NULL){
		nd=nd->next;
	}
	nd_new=malloc(sizeof(struct node));
	nd_new->indx=x;
	nd_new->next=NULL;
	nd->next=nd_new;
}


void print(struct node* strt){
	struct node*nd;
	nd=strt;
	while(nd->next!=NULL){
		printf("%d ", nd->indx);
		nd=nd->next;
	}
	printf("%d \n", nd->indx);
}


void search(struct node* strt, int x){
	struct node* nd, *nd_prev;
	nd=strt;
	while(nd->indx!=x){
		nd_prev=nd;
		nd=nd->next;
	}
	printf("%d \n", nd->indx);
	printf("%p", &nd);
}


void reverse(struct node* strt){
	struct node* nd=strt->next, *nd_1, *nd_2, *nd_prev;
	nd_1=nd->next;
	nd_2=nd_1->next;
	nd_prev=nd;
	nd->next=NULL;
	while (nd_2->next!=NULL){
		nd_1->next=nd;
		strt->next=nd_2;
		nd=nd_1;
		nd_1=nd_2;
		nd_2=nd_1->next;	
	}
	nd_1->next=nd;
	nd_2->next=nd_1;
	strt->next=nd_2;
}


int main(){
	int i=1;
	struct node *strt, *n;
	n=malloc(sizeof(struct node));
   	n->next=NULL;
    	strt=n;
	for(i; i<14; i++){
		insert(strt, i);
	}
	print(strt);
	printf("\n");
	//print_reverse(strt);
	printf("\n");
	reverse(strt);
	print(strt);
	return 0;
}
