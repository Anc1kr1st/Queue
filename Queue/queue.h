// 12.10 
// queue.h -- rozhrani tridy Queue
#ifndef QUEUE_H_
#define QUEUE_H_

// Tato fronta bude obsahovat polozky tridy Customer
class Customer
{
private:
	long arrive; 		// cas prichodu zakaznika
	int processtime;		// doba odbaveni zakaznika

public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
	// definice s platnosti uvnitr tridy
	// Node definice vnorene struktury existujici pouze uvnitr tridy
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };
	// privatni clenove tridy
	Node* front;		// ukazatel na zacatek fronty
	Node* rear;		// ukazatel na konce fronty
	int items;		// aktualni pocet polozek fronty
	const int qsize;		// maximalni pocet polozek fronty
	// preventivni definice nutne pro zamezeni verejneho kopirovani
	Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }

public:
	Queue(int qs = Q_SIZE);		// vytvori frontu s limitem qs
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);		// prida polozku na konec
	bool dequeue(Item& item);		// odebere polozku ze zacatku
};
#endif
