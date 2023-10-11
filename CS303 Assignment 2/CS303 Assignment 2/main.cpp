#include "main.h"

int main() {
	//making profiles with names and printing out the info on console.
	Professional profEmployee("John Smith", 1, 5000.0, 10);
	Nonprofessional nonProfEmployee("Britney Spears", 2, 15.0, 45);
	cout << "Professional Employee Information:" << endl;
	profEmployee.displayInfo();
	cout << "Nonprofessional Employee Information :" << endl;
	nonProfEmployee.displayInfo();

	return 0;
}