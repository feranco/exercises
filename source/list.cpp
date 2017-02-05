#include "list.h"
#include <iostream>
void removeDuplicate (Link head) {
    Link ptr1, ptr2;
    ptr1 = head;

    while (ptr1 != 0) {
      ptr2 = ptr1;
      while (ptr2->next != 0) {
	if (ptr2->next->item == ptr1->item) {
	  Link tmp = ptr2->next;
	  ptr2->next = tmp->next;
	  delete tmp;
	}
	else {
	ptr2 = ptr2->next;
	}
      }
      ptr1 = ptr1->next;
    }
}

//If the List is empty or contain less than k Nodes
//the function return a null Link, otherwise return 
//a Link to the k-th to Last element
Link findKtoLast(Link head, int k) {
  Link ptr1 = head;
  Link ptr2 = ptr1;

  //This check save time needed to traverse the list if k is not valid
  if (k <= 0) return 0; 

  while (ptr2 && --k >= 0) ptr2 = ptr2->next;

  if (!ptr2 && k > 0) return 0;

  while (ptr2 != 0) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  return ptr1;
}

int findKtoLastRec(Link head, Link& kToLast, int k) {

  //This check save time needed to traverse the list if k is not valid
  if (head == 0) return 0; 

  int tmp = 1 + findKtoLastRec (head->next, kToLast, k);

  std::cout << tmp << std::endl;

  if (tmp == k) {
    std::cout << head->item << std::endl;
    kToLast = head;
    std::cout << kToLast->item << std::endl;
  }

  return tmp;
}
