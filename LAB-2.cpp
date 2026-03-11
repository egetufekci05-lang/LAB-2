#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    string word;

    while (true) {
        cout << "Kelime (EXIT/UNDO): ";
        cin >> word;

        if (word == "EXIT") break;

        if (word == "UNDO") {
            if (head == nullptr) {
                cout << "Liste bos!" << endl;
            } else if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next->next != nullptr) temp = temp->next;
                delete temp->next;
                temp->next = nullptr;
            }
        } else {

            Node* newNode = new Node{word, nullptr};
            if (head == nullptr) head = newNode;
            else {
                Node* temp = head;
                while (temp->next != nullptr) temp = temp->next;
                temp->next = newNode;
            }
        }


        Node* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    return 0;
}
