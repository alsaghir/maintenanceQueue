#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"
#include <iostream>

template<typename T>
Queue<T>::Queue() {
	front = NULL;
	rear = NULL;
	count = 0;
}

template<typename T>
Queue<T>::~Queue() {
	if (!queueIsEmpty()) {
		node *p = front;
		while (p != NULL) {
			p = front->next;
			delete front;
			front = p;
			count--;
		}
	}
}

template<typename T>
void Queue<T>::enqueue(T v) {
	node *pnew = new node();
	pnew->data = v;
	if (queueIsEmpty())  //Both rear and front should point to the same one node
	{
		front = pnew;
		rear = pnew;
		pnew->next = NULL;
	}
	else //normal inserting from the rear side
	{
		rear->next = pnew;
		rear = pnew;
		rear->next = NULL;
	}

	count++;
}

template<typename T>
void Queue<T>::dequeue(T &v) {
	node *pnew;
	if (queueIsEmpty())
		std::cout << "Queue is Empty" << std::endl;
	else {
		v = front->data;
		pnew = front;
		front = front->next;
		delete pnew;
		count--;
		if (!front)  //Last node deleted so rear must pont to NULL now since the queue is empty
			rear = NULL;
	}
}

template<typename T>
void Queue<T>::queueFront(T &v) const {
	if (queueIsEmpty()) std::cout << "Queue is Empty" << std::endl;
	else { v = front->data; }
}

template<typename T>
void Queue<T>::queueRear(T &v) const {
	if (queueIsEmpty()) std::cout << "Queue is Empty" << std::endl;
	else { v = rear->data; }
}

template<typename T>
bool Queue<T>::queueIsEmpty() const {
	return (count == 0);
}

template<typename T>
int Queue<T>::queueLength() const {
	return count;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &q) {

	while (!queueIsEmpty()) {  //empty this queue
		T drop;
		dequeue(drop);
	}

	if (!q.queueIsEmpty()) {
		front = new node();
		front->data = q.front->data;
		count++;
		if (q.front == q.rear) { //if only one node is there
			rear = front;
		}
		else {
			//create first node and some pointers to walk on nodes
			node *fold = q.front->next;
			node *fnew = NULL;
			node *fnewhelper = front;

			//from the second node to the end, creating nodes and copying the data
			while (fold != NULL) {
				fnew = new node();
				fnew->data = fold->data;
				fold = fold->next;
				fnewhelper->next = fnew;
				fnewhelper = fnew;
				count++;
			}
			//creating last node and linking it
			rear = fnew;
		}
	}
	return *this;
}

#endif // !QUEUE_CPP