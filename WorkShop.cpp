#include "WorkShop.h"
#include <string>


WorkShop::WorkShop(std::string Name)
{
	mName = Name;
}

std::string WorkShop::getName() const {
	return mName;
}

void WorkShop::setName(std::string Name) {
	mName = Name;
}

void WorkShop::addCar(std::string carNum)
{
	mQueue.enqueue(carNum);
	mOperation.clear();
	mOperation = mOperation.append("\nCar number ").append(carNum).append(" added to the queue of workshop ").append(mName).append("\n");
}

void WorkShop::remCar(std::string & carNum)
{
	if (mQueue.queueIsEmpty()) {
		std::cout << "\nThere is no cars at workshop " << mName << std::endl;
		mOperation.clear();
	}
	else {
		mQueue.dequeue(carNum);
		mOperation.clear();
		mOperation = mOperation.append("\nCar number ").append(carNum).append(" removed from queue of workshop ").append(mName).append("\n");
	}
}

std::string WorkShop::getOperation() const
{

	return mOperation;
}

bool WorkShop::WorkshopIsClean() const {
	return mQueue.queueIsEmpty();
}


bool WorkShop::getOrder(std::string carNumber) {
	WorkShop temp;
	temp = *this;
	std::string tempnumber;
	int counter = 0;

	while (!temp.WorkshopIsClean()) {
		temp.remCar(tempnumber);
		if (!carNumber.compare(tempnumber)) {
			std::cout << "\n==========\n" << "Found in " << getName()
				<< " and has " << counter << " cars in front of it"
				<< "\n==========\n";
			return true;
		}
		counter++;
	}
	std::cout << "\n==========\n" << "Not in " << getName() << "\n==========\n";
	return false;
}

void WorkShop::printAll() {
	WorkShop temp;
	temp = *this;
	std::string tempnumber;

	if (temp.WorkshopIsClean()) {
		std::cout << "\n==========\n" << "Workship is empty" << "\n==========\n";
		return;
	}

	std::cout << "\n==========\n";

	while (!temp.WorkshopIsClean()) {
		temp.remCar(tempnumber);
		std::cout << tempnumber << std::endl;
	}
	std::cout << "\n==========\n";
}