#pragma once

#include <string>
#include <iostream>
#include <stack>

using namespace std;


struct Node { //setting up struct for linked list
	int num_items;
	Node* nextPtr;
	Node* prevPtr;

	Node(int item, Node* prev = nullptr, Node* next = nullptr) : num_items(item), prevPtr(prev), nextPtr(next) {}
};

class Single_Linked_List { //defining linked list class
private:
	Node* headPtr;
	Node* tailPtr;
	int num_items;

public:
	Single_Linked_List() : headPtr(nullptr), tailPtr(nullptr), num_items(0) {}
	void push_front(const int& item) { 
		headPtr = new Node(item, nullptr, headPtr);
		if (headPtr->nextPtr != nullptr) {
			headPtr->nextPtr->prevPtr = headPtr;
		}
		else
			tailPtr = headPtr;
		num_items++;
	}
	void push_back(const int& item) {
		if (tailPtr != NULL) {
			tailPtr->nextPtr = new Node(item, tailPtr, NULL);
			tailPtr = tailPtr->nextPtr;
			num_items++;
		}
		else {
			push_front(item);
		}
	}
	void pop_front() { //to pop the object in front
		if (headPtr == NULL)
			throw invalid_argument("Cannot execute pop_front on empty list");
		Node* removed_node = headPtr;
		headPtr = headPtr->nextPtr;
		delete removed_node;
		if (headPtr != NULL)
			headPtr->prevPtr = NULL;
		else
			tailPtr = NULL;
	}
	void pop_back() { //to pop the object in back
		if (tailPtr == NULL)
			throw invalid_argument("Cannot execute pop_back on empty list");
		Node* removed_node = tailPtr;
		tailPtr = tailPtr->prevPtr;
		delete removed_node;
		if (tailPtr != NULL)
			tailPtr->nextPtr = NULL;
		else
			headPtr = NULL;
	}
	bool empty() { //check to see if empty
		return num_items == 0;
	}
	void insert(size_t i, const int& item) { //function to insert object at a specific index
		Node* nNode = new Node(item);
		if (headPtr == nullptr) {
			headPtr = nNode;
			return;
		}
		if (i == 0) {
			nNode->nextPtr = headPtr;
			headPtr = nNode;
		}
		else {
			Node* current = headPtr;
			size_t CI = 0;

			while (current->nextPtr != nullptr && CI < i - 1) {
				current = current->nextPtr;
				CI++;
			}
			nNode->nextPtr = current->nextPtr;
			current->nextPtr = nNode;
		}
	}

	bool remove(size_t i) {  //to remove an object at specific index
		if (headPtr == nullptr || i < 0) {
			return false;
		}
		if (i == 0) {
			Node* temp = headPtr;
			headPtr = headPtr->nextPtr;
			delete temp;
			return true;
		}
		Node* current = headPtr;
		size_t currentIndex = 0;

		while (current != nullptr && currentIndex < i - 1) {
			current = current->nextPtr;
			currentIndex++;
		}
		if (current == nullptr || current->nextPtr == nullptr) {
			return false;
		}
		Node* temp = current->nextPtr;
		current->nextPtr = temp->nextPtr;
		delete temp;
		return true;
	}

	size_t find(const int& item) { //to find the index position of the object you're finding
		Node* current = headPtr;
		size_t i = 0;
		while (current != nullptr) {
			if (current->num_items == item) {
				return i;
			}
			current = current->nextPtr;
			i++;
		}
		return i;
	}
};

class Employee { //question 2 - declaring class for employee
protected:
	string name;
	int employeeID;

public:
	Employee(const string& name, int employeeID) : name(name), employeeID(employeeID) {}

	virtual double calculateWeeklySalary() const = 0;
	virtual double calculateHealthCareContributions() const = 0;
	virtual int calculateVacationDays() const = 0;

	void displayInfo() const;
};

class Professional : public Employee { //classification if professional
private:
	double monthlySalary;
	int vacationDays;

public:
	Professional(const string& name, int employeeID, double monthlySalary, int vacationDays) : Employee(name, employeeID), monthlySalary(monthlySalary), vacationDays(vacationDays) {
	}
	double calculateWeeklySalary() const override {
		return monthlySalary / 4;
	}
	double calculateHealthCareContributions() const override {
		return 10.0;
	}
	int calculateVacationDays() const override {
		return vacationDays;
	}
};

class Nonprofessional : public Employee { //classification if nonprofessional
private:
	double hourlyRate;
	double hoursWorked;

public:
	Nonprofessional(const string& name, int employeeID, double hourlyRate, double hoursWorked) : Employee(name, employeeID), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {
	}
	double calculateWeeklySalary() const override {
		return hourlyRate * hoursWorked;
	}

	double calculateHealthCareContributions() const override {
		return 15.0;
	}
	int calculateVacationDays() const override {
		return static_cast<int>(hoursWorked / 40); // 40h per 1 vacation day
	}
};

void Employee::displayInfo() const {
	cout << "Name: " << name << endl;
	cout << "Employee ID: " << employeeID << endl;
	cout << "Weekly Salary: $" << calculateWeeklySalary() << endl;
	cout << "Health Care Contributions: $" << calculateHealthCareContributions() << endl;
	cout << "Vacation Days Earned: " << calculateVacationDays() << " days" << endl;
}