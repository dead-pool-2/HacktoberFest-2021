#include <iostream>
using namespace std;

struct Node {
   int data;
   struct Node *next;
};

struct Node* head = NULL;
void insertAtFront(int new_data) {
   Node *temp=new Node();
   temp->data = new_data;
   temp->next = head;
   head = temp;
}

void insertAtLast(int new_data)
{

    Node* new_node = new Node();
    Node *last = head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (head== NULL)
    {
        head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

int main() {
        insertAtFront(10);
        insertAtFront(20);
        insertAtLast(30);
        insertAtFront(40);
        insertAtLast(50);

   cout<<"The linked list is: ";
   display();

   return 0;
}
