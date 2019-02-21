#ifndef LIST_H
#define LIST_H
struct Node{
	Planet* data;
	Node *next;
	Node *previous;
	
};

class List{
	private:
		Node *head;
		Node *tail;
	public:
		List();
		~List();
		void insert(int index, Planet * p);
		Planet* read (int index);
		unsigned size();
};


#endif

