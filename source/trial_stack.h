#ifndef TRIAL_STACK
#define TRIAL_STACK

//class implementing three stacks with a single array
//assumptions: the stack contains integers and the size
//of the array is given by the user
class TrialStack {

  int* arr;
  int size, tos1, tos2, tos3;
  int left_bound, right_bound;

 public:
  TrialStack (int n);
  ~TrialStack ();
  void push1 (int x);
  void push2 (int x);
  void push3 (int x);
  int pop1 (void);
  int pop2 (void);
  int pop3 (void);
  //we can still add emp
}

#endif
