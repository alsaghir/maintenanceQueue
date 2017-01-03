#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();

	void enqueue(T);		// Add to rear
	void dequeue(T &);		// Remove from front
	void queueFront(T &) const;	// Retrieve front
	void queueRear(T &) const;	// Retrieve rear
	bool queueIsEmpty() const;		// Test for Empty queue
	int queueLength() const;		// Queue Length

	Queue<T> & operator=(const Queue<T> &q);

private:
	class node {
	public:
		T data;
		node *next;
	};
	node *front, *rear;
	int count;

};

#endif // !QUEUE_H