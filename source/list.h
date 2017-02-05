#include <iostream>

typedef int Item;

struct Node {
  Item  item;
  Node* next;
  Node() { item = 0; next = 0; }
  Node(int i, Node* n) { item = i; next = n; }
};

typedef Node* Link;
void removeDuplicate (Link head);
Link findKtoLast(Link head, int k);

int findKtoLastRec(Link head, Link& kToLast, int k);
