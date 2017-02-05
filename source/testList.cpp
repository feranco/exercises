#include "testList.h"
#include "list.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

void testRemoveduplicate(int n) {
  srand(time(0));
  Link head = new Node (0,0);
  Link tmp = head;
  head->next = 0;

  for (int i = 0; i < n; ++i) {
    tmp->next = new Node(rand() % 10, 0);
    tmp = tmp->next;
  }

  for (Link t = head->next; t != 0; t = t->next) {
    std::cout << t->item << " ";
  }
  std::cout << std::endl;

  removeDuplicate(head->next);

  for (Link t = head->next; t != 0; t = t->next) {
    std::cout << t->item << " ";
  }
  std::cout << std::endl;
}

void testFindKtoLast(int n, int k) {
  srand(time(0));

  Link head = new Node();
  Link tmp = head;
  for (int i = 0; i < n; ++i) {
    tmp->next = new Node(rand() % 1000, 0);
    tmp = tmp->next;
  }

  for (tmp = head->next; tmp != 0; tmp = tmp->next) std::cout << tmp->item << " ";
  std::cout << std::endl;
  tmp = findKtoLast(head->next, k);
  if (tmp) {
    std::cout << "k to last: " << tmp->item << std::endl;
  }
  else {
    std::cout << "less than k elements!" << std::endl;
  }		
}

void testFindKToLastRec(int n, int k) {
   srand(time(0));

  Link head = new Node();
  Link tmp = head;
  for (int i = 0; i < n; ++i) {
    tmp->next = new Node(rand() % 1000, 0);
    tmp = tmp->next;
  }

  for (tmp = head->next; tmp != 0; tmp = tmp->next) std::cout << tmp->item << " ";
  std::cout << std::endl;
  Link pippo = new Node (34,0);
  findKtoLastRec(head->next, pippo, k);
  
  if (pippo) {
    std::cout << "k to last: " << pippo->item << std::endl;
  }
  else {
    std::cout << "less than k elements!" << std::endl;
  }		
}
