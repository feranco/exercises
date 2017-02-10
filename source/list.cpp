#include "list.h"
#include <iostream>

void addInFront(Link& n, Item x) {
	Link tmp = new Node(x, 0);
	if (n) tmp->next = n;
	n = tmp;
}

void dumpList(Link list) {
	for (Link t = list; t != 0; t = t->next) {
		std::cout << t->item << " -> ";
	}
	std::cout << std::endl;
}

int lenght(Link list) {
  int len;
  for (Link t = list; t != 0; t = t->next) ++len;
  return len;
}

void padInFront(Link list, Item p, int len) {
  for int i = 0; i < len; ++i) addInFront(list,p);
}

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

void partition(Link& head, Item v) {
	Node headA(0, 0);
	Node headB(0, 0);
	Link a = &headA;
	Link b = &headB;

	for (Link t = head; t != 0; t = t->next) {
		if (t->item < v) {
			a->next = t;
			a = a->next;
		}
		else {
			b->next = t;
			b = b->next;
		}
	}

	a->next = headB.next;
	b->next = 0;
	head = headA.next;
}

Link sumLists(Link op1, Link op2) {
	Link sum = 0;
	int  co = 0;	//amount carried over

	while (op1 && op2) {
		int tmp = op1->item + op2->item + co;
		if (tmp > 9) {
			tmp -= 10;
			addInFront(sum, tmp);
			co = 1;
		}
		else {
			addInFront(sum, tmp);
			co = 0;
		}
		op1 = op1->next;
		op2 = op2->next;
	}

	while (op1) {
		addInFront(sum, op1->item + co);
		co = 0;
		op1 = op1->next;
	}

	while (op2) {
		addInFront(sum, op2->item + co);
		co = 0;
		op2 = op2->next;
	}
	return sum;
}

Link sumListsReverse(Link op1, Link op2) {

  int len1 = lenght(op1);
  int len2 = lenght(op2);
  
  if(len1 < len2) padInFront(op1, 0, len2-len1);
  if(len2 < len1) padInFront(op2, 0, len1-len2);
  Link sumListsReverseRec(op1, op2);
}

Link sumListsReverseRec(Link op1, Link op2, int& co) {
  if (!op1 || !op2) return 0;
  Link sum = sumListsReverseRec(op1, op2, co);
  int tmp = op1->item + op2->item + co;
  if (tmp > 9) {
    co = 1;
    tmp-=10;
  }
  else {
    co = 0;
  }
  addInFront(sum, tmp);
  return sum;
}

