#ifndef LIST_H
#define LIST_H
class List{
	private:
		node *head;
		node *tail;
	public:
		List();
		~List();
		void insert(int index, Planet * p);
		Planet* read (int index);
		unsigned size();
}
struct Node{
	int data;
	node *next;
	node *previous;
	
}
