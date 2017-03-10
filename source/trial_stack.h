#ifndef TRIAL_STACK
#define TRIAL_STACK

//class implementing three stacks with a single array
//assumptions: the stack contains integers and the size
//of the array is given by the user
class TrialStack {
  static const int n_stacks = 3;
  int* arr;
  int size;
  int tos[n_stacks];
  int left_bound, right_bound; //left and right bounds for stack3
  bool move_right; //true if tos3 move to the right wrt size/2

  void insert (int stack, int x);
  int  remove(int stack);
  void checkPush (int stack);
  void checkPop(int stack);

 public:
  TrialStack (int n);
  ~TrialStack ();
  void push (int stack, int x);
  int pop(int stack);
  //we can still add emp
};

void testTrialStack (int n);

#endif
