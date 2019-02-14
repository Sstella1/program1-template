#include "List.h"
#include <iostream>
#include <cstdlib>

using namespace std;

List::List(){
	this->head=NULL;
	this->tail=NULL; 
}

~List(){
}

void List:: insert(int index, Planet * p){ 

node *preNode=new node;
    node *currentNode=new node;
    node *tempNode=new node;
    currentNode=head;
    for(int i=1;i<index;i++)
    {
      preNode=currentNode;
      currentNode=currentNode->next;
	if(currentNode==NULL){
	node * new_node= new node(p);
	tail->next= new_node;
	
	}
    }
    tempNode->data=p;
    preNode->next=tempNode;	
    tempNde->next=currentNode;

}

Planet* List:: read(int index){


}

bool List:: remove(int index){

}

unsigned List:: size(){
node *headNode= new node(head);
node *endNode= new node(tail);


} 
