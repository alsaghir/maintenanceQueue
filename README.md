# maintenanceQueue
Simple usage of Queue implementation class

/*** DESCRIPTION ***

* This is a simple console application that simply simulates queuing system in a workshop.
There are three workshops basically and each got a queue in which cars enters and then
get out in order. Some additional options are added like searching, checking..etc.

***Considerations & Edits***

* The class workshop was inheriting class (super class) so children classes could have their own
implementation of some function(s) and owning some shared attributes/functions. Due the low number of
unique methods and attributes, edit has been made and WorkShop is now one class representing the workshop.

* Functions
	bool getOrder(std::string); which check the car's order in specefic workshop
	void printAll(); which prints all the car's in specefic workshop in order
  where in the main file but moved to WorkShop class since they are work on the Workshop class level

***Ideas (not implemented yet)***

* LuckyCar -> randomly selecting a car currently in a workshop for winning price or special offer !
* Adding the client's (car owners) data to be stored as linked list permanently on external files (like simple database)

*** END OF DOC***/
