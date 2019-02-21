#include "List.h"
#include <iostream>
#include <cstdlib>

using namespace std;

List::List(){
	this->head=NULL;
	this->tail=NULL; 
}

~List(){
	Node *next= head;
	while(next){
	Node *deleted=next;
	next=next->next;
	delete deleted;
	}
}

void List:: insert(int index, Planet * p){ 

Node *preNode=new Node;
    Node *currentNode=new Node;
    Node *tempNode=new Node;
    currentNode=head;
    for(int i=1;i<index;i++)
    {
      preNode=currentNode;
      currentNode=currentNode->next;
	if(currentNode==NULL){
	Node * new_node= new Node(p);
	tail->next= new_node;
	
	}
    }
    tempNode->data=p;
    preNode->next=tempNode;	
    tempNde->next=currentNode;

}

Planet* List:: read(int index){
Node*tempNode= New Node;
tempNode=NULL;
int counter=0;
while(head!=NULL){
counter++;
if(counter==index){
tempNode=head;
}
else {
head=head->next;
}
}
return tempNode;

}

bool List:: remove(int index){
Node *tempNode= NULL;
Node *tempNodePrev=NULL;
int counter=0;
while(head!=NULL){
counter++;
if(counter==index){
tempNode= head->next;
tempNodePrev=tempNode->next;
head->next=tempNode->next;
tempNodePrev->previous=head;
return true;
}
else{
head=head->next;
}
return false;
}

unsigned List:: size(){
int counter=0;
while(head!=NULL){
counter++;
head=head->next;
}
return counter;
} 
