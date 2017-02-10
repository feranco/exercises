#include <iostream>

typedef int Item;

struct Node {
  Item  item;
  Node* next;
  Node() { item = 0; next = 0; }
  Node(int i, Node* n) { item = i; next = n; }
};

typedef Node* Link;

//utilities
void addInFront(Link& n, Item x);
void dumpList(Link list);
int  lenght(Link list);
void padInFront(Link list, Item p, int len);

//functions
void removeDuplicate (Link head);
Link findKtoLast(Link head, int k);
int findKtoLastRec(Link head, Link& kToLast, int k);
void partition(Link& head, Item v);
Link sumLists(Link op1, Link op2);
Link sumListsReverse(Link op1, Link op2);
Link sumListsReverseRec(Link op1, Link op2, int& co);


