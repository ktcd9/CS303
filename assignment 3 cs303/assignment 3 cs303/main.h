#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Queue Functions //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

void printQueue(queue<int> name) {
    queue<int> temp = name;
    cout << "The current queue has: ";
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

void insertQueue(queue<int>& name, int num) {
    name.push(num);
}

int removeQueue(queue<int> name) {
    if (!name.empty()) {
        int frontElement = name.front();
        name.pop();
        return frontElement;
    }
    return -1;
}

int frontQueue(queue<int> name) {
    if (!name.empty()) {
        return name.front();
    }
    return -1;
}

bool emptyQueue(queue<int> name) {
    return name.empty();
}

int totalQueue(queue<int> name) {
    return name.size();
}

//////////////////////////////////////////////////////////////////////////////////
////////////////////////// inFix to postFix Stack ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

bool balanced(const string& exp) {
    stack<char> name;
    for (char c : exp) {
        if (c == '(' || c == '[' || c == '{') {
            name.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (name.empty() || ((c == ')' && name.top() != '(') ||
                (c == ']' && name.top() != '[') || (c == '}' && name.top() != '{'))) {
                return false;
            }
            else {
                name.pop();
            }
        }
    }
    return name.empty();
}
int getSymbol(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    else if (x == '*' || x == '/' || x == '%') {
        return 2;
    }
    return -1;
}
string InToPost(const string& exp) {
    string postfix;
    stack<char> name;
    for (char c : exp) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(' || c == '{' || c == '[') {
            name.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            while (!name.empty() && name.top() != '(' && name.top() != '{' && name.top() != '[') {
                postfix += name.top();
                name.pop();
            }
            name.pop();
        }
        else {
            while (!name.empty() && name.top() != '(' && name.top() != '{' && name.top() != '[' && getSymbol(c) <= getSymbol(name.top())) {
                postfix += name.top();
                name.pop();
            }
            name.push(c);
        }
    }
    while (!name.empty()) {
        postfix += name.top();
        name.pop();
    }
    return postfix;
}