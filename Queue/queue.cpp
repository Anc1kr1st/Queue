//12.11
// queue.cpp - metody tridy Customer a Queue
#include "queue.h"
#include <cstdlib> 		// pro rand()
// metody tridy Queue
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != NULL)	// dokud fronta neni prazdna
	{
		temp = front;		// ulozi adresu prvni polozky
		front = front->next;	// nastavi ukazatel na dalsi polozku 
		delete temp;		// zrusi puvodni prvni polozku
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

// Add item to queue
bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node;	// vytvori polozku
	if (add == NULL)
		return false;		// navrat pri chybe
	add->item = item;		// nastavi ukazatele polozky
	add->next = NULL;
	items++;
	if (front == NULL) 		// pokud je fronta prazdna
		front = add;		// umisti polozku na zacatek
	else
		rear->next = add;	// jinak na konec
	rear = add;
	return true;
}

// Umisti prvni polozku do promenne item a odebere z fronty
bool Queue::dequeue(Item& item)
{
	if (front == NULL)
		return false;
	item = front->item;	// nastavi ukazatel na prvni polozku fronty
	items--;
	Node* temp = front;	// ulozi adresu prvni polozky
	front = front->next;	// nastavi ukazatel front na dalsi polozku 
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}

// metoda tridy Customer

// kdyz zakaznik prijde, nastavi se
// cas prichodu do promenne when a do promenne predstavujici 
// dobu odbaveni se nastavi nahodna hodnta v rozsahu 1 - 3.
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
