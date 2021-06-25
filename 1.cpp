// 1. Design 3 classes called A,B,C then implement read() and get() functions as non- member functions and scan and print the data for three class with the help of friend functions.
#include<iostream>
#include<string>

class A {
  private:
    std::string data;
  public:
    friend std::string print(A &a);
    friend void scan(A &a);
};

std::string get(class A &a) { // Non-member function
  return print(a);
}
std::string print(A &d) { // Friend Function
  return d.data;
}

void scan(A &a) { // Friend Function
  std::cout << "string to store in class a: " ;
  std::cin >> a.data ;
}
void read(class A &a) { // Non-member function
  scan(a) ;
}

class B {
  private:
    std::string data;
  public:
    friend std::string print(B &a);
    friend void scan(B &a);
};

std::string get(class B &a) { // Non-member function
  return print(a);
}
std::string print(B &d) { // Friend Function
  return d.data;
}

void scan(B &a) { // Friend Function
  std::cout << "string to store in class a: " ;
  std::cin >> a.data ;
}
void read(class B &a) { // Non-member function
  scan(a) ;
}

class C {
  private:
    std::string data;
  public:
    friend std::string print(C &a);
    friend void scan(C &a);
};

std::string get(class C &a) { // Non-member function
  return print(a);
}
std::string print(C &d) { // Friend Function
  return d.data;
}

void scan(C &a) { // Friend Function
  std::cout << "string to store in class a: " ;
  std::cin >> a.data ;
}
void read(class C &a) { // Non-member function
  scan(a) ;
}


int main() {
  A a;
  read(a);
  std::cout << "string in a: " << get(a) << std::endl;
  B b;
  read(b);
  std::cout << "string in b: " << get(b) << std::endl;
  C c;
  read(c);
  std::cout << "string in c: " << get(c) << std::endl;
}
