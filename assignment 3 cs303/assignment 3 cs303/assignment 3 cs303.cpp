
#include "main.h"

int main() {
    queue<int> example;

    insertQueue(example, 1); //
    insertQueue(example, 2); //
    insertQueue(example, 3); // Inserting elements into queue
    insertQueue(example, 4); //
    insertQueue(example, 5); //

    printQueue(example);

    cout << "Front Element Removed: " << removeQueue(example) << endl; //Front Element of Queue removed
    cout << "Front element of current queue: " << frontQueue(example) << endl; //Front element popped but not sure why it's not printing
    printQueue(example);
    cout << "Queue Empty? " << (emptyQueue(example) ? "Yes" : "No") << endl; //bool for empty queue or not
    cout << "Size Of Queue: " << totalQueue(example) << endl; //total sum of elements in queue

    string InfixExp;//declaring infix variabel

    cout << "\nEnter the infix expression: ";
    getline(cin, InfixExp);

    if (balanced(InfixExp)) {
        string PostfixExp = InToPost(InfixExp);
        cout << "Postfix Expression: " << PostfixExp << endl;
    }
    else {
        cout << "The expression is invalid or unbalanced." << endl;
    }

    return 0;
}
