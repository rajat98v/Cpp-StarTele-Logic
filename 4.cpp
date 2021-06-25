//4. WAP to find implement shallow and deep copies.

#include <iostream>

using namespace std;

class ShallowCopy { // No need for deep copy
  public:
    int fruitno;
    ShallowCopy(int a) {
      fruitno = a;
    }
};
class DeepCopy {
  public:
    int fruitno;
    int *rottenno;
    DeepCopy(int a, int *n) {
      fruitno = a;
      rottenno = n;
    }
    DeepCopy(DeepCopy &d) {
      fruitno = d.fruitno;
      rottenno = new int;
      *rottenno = *(d.rottenno);
    }
};

int main() {
  ShallowCopy a(10);
  ShallowCopy b = a;

  int rot = 3;
  DeepCopy c(10, &rot);
  /* DeepCopy d(20, &rot); */
  /* d = c; */
  DeepCopy d = c;
  cout << "before update: *c.rotten: " << *c.rottenno << " *d.rotten: " << *d.rottenno << endl;
  *c.rottenno = 4;
  cout << "after update: *c.rotten: " << *c.rottenno << " *d.rotten: " << *d.rottenno << endl;

  return 0;
}
