// 3. WAP to implement private constructor.

#include<iostream>

using namespace std;

class Rectangle {
  private:
    int length, breath;
    Rectangle(int len, int bre) { // Private Construct accessible to friend class Square
      length = len;
      breath = bre;
      cout << "Rectangle Created with Length: " << length << " Breath: " << breath << endl;
    }
  public:
    friend class Square;
};
class Square {
  public:
    Square(int s) {
      cout << "Square going to contruct from rectangle." << endl;
      Rectangle(s,s); 
    }
};

int main() {
  Square a(10);
  return 0;
}
