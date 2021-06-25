//5. WAP to design swap_function() with function overloading

#include<iostream>
using namespace std;

void swap(int &a,int &b) {
  int temp;
  temp=a;
  a=b;
  b=temp;
}

void swap(float &a, float &b) {
  float temp;
  temp=a;
  a=b;
  b=temp;
}

void swap(char &a, char &b) {
  char temp;
  temp=a;
  a=b;
  b=temp;
}

int main() {
  int int_a,int_b;

  cout << "Enter Two Integer: ";
  cin >> int_a >> int_b;

  swap(int_a,int_b);

  float float_x,float_y;

  cout << "Enter Two Floating Point: ";
  cin >> float_x >> float_y;

  swap(float_x, float_y);

  char char_x,char_y;
  cout<<"Enter Two Character: ";
  cin >> char_x >> char_y ;

  swap(char_x, char_y);

  cout<<"\nAfter swapping Integers: " << int_a << " " << int_b << endl;

  cout << "After Swapping Floating Points: " << float_x << " " << float_y << endl;

  cout << "After Swapping Characters: " << char_x << " " << char_y << endl;

  return 0;
}
