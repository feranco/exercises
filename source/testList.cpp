#include "testList.h"
#include "list.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

void testRemoveduplicate(int n) {
  srand(time(0));
  Link head = new Node (0,0);
  Link tmp = head;
  head->next = 0;

  for (int i = 0; i < n; ++i) {
    tmp->next = new Node(rand() % 10, 0);
    tmp = tmp->next;
  }

  dumpList(head->next);
  removeDuplicate(head->next);
  dumpList(head->next);
}

void testFindKtoLast(int n, int k) {
  srand(time(0));

  Link head = new Node();
  Link tmp = head;
  for (int i = 0; i < n; ++i) {
    tmp->next = new Node(rand() % 1000, 0);
    tmp = tmp->next;
  }

  dumpList(head->next);
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

  dumpList(head->next);
  Link pippo = new Node (34,0);
  findKtoLastRec(head->next, pippo, k);
  
  if (pippo) {
    std::cout << "k to last: " << pippo->item << std::endl;
  }
  else {
    std::cout << "less than k elements!" << std::endl;
  }		
}

void testPartition(int n) {
  srand(time(0));
  Link list = new Node(rand() % 1000, 0);
  Link tmp = list;

  for (int i = 0; i < n; ++i) {
    tmp->next = new Node(rand() % 1000, 0);
    tmp = tmp->next;
  }
  //before partition
  dumpList(list);

  int v = rand() % 1000;
  partition(list, v);
  
  std::cout << "Partition around " << v << std::endl;
  //after partition
  dumpList(list);
}

void testSumLists(void) {
  std::string s1, s2;
  Link op1, op2, sum;
  op1 = op2 = 0;
  std::cout << "Insert operators: " << std::endl;
  std::cin >> s1 >> s2;

  for (std::string::iterator it = s1.begin(); it < s1.end(); ++it) addInFront(op1, *it-'0');
  for (std::string::iterator it = s2.begin(); it < s2.end(); ++it) addInFront(op2, *it-'0');

  sum = sumLists(op1, op2);
  dumpList(sum);
}

void testSumListsReverse(void) {
  std::string s1, s2;
  Link op1, op2, sum;
  op1 = op2 = 0;
  std::cout << "Insert operators: " << std::endl;
  std::cin >> s1 >> s2;

  for (std::string::reverse_iterator it = s1.rbegin(); it < s1.rend(); ++it) addInFront(op1, *it-'0');
  for (std::string::reverse_iterator it = s2.rbegin(); it < s2.rend(); ++it) addInFront(op2, *it-'0');

  sum = sumListsReverse(op1, op2);
  dumpList(sum);
}
