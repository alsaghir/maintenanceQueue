#ifndef WORKSHOP_H
#define WORKSHOP_H


#include<string>
#include "Queue.h"
#include "Queue.cpp"

class WorkShop {
private:
	Queue<std::string> mQueue;
	std::string mName;
	std::string mOperation;
public:

	WorkShop(std::string Name = "NotNamed");
	void addCar(std::string carNum);
	void remCar(std::string &carNum);
	std::string getOperation() const;
	void setName(std::string Name);
	std::string getName() const;
	bool WorkshopIsClean() const;
	bool getOrder(std::string carNumber);
	void printAll();
};

#endif // !WORKSHOP_H
