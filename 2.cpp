// 2. Design a class called student with roll no,name and marks as data members,set_data(),get_data() as member functions to read and print student details.Implement sort_data() as member function to sort data in ascending order according to user option(roll no,name,marks).
#include<cstdlib>
#include<stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
  private:
    int rollno;
    string name;
    int marks;
    string printRandomString() {
      char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
			    'h', 'i', 'j', 'k', 'l', 'm', 'n',
			    'o', 'p', 'q', 'r', 's', 't', 'u',
			    'v', 'w', 'x', 'y', 'z' };
 
      string res = "";
      for (int i = 0; i < rand()%10; i++) {
	  res = res + alphabet[rand() % 26];
      }
     
      return res;
    }


  public:
    void random_student_data() {
      rollno = (rand() % (30 + 1));
      marks = (rand() % (100 + 1));
      name = printRandomString();
      get_data();
    }
    void set_data() {
      cout << "Enter Following detail" << endl;
      cout << "Roll No of Student: "; cin >> rollno;
      cout << "Name of Student: "; cin >> name;
      cout << "Marks of Student: "; cin >> marks;
      cout << endl;
    }

    void get_data() {
      cout << "Details" << endl;
      cout << "Roll No: " << rollno << endl;
      cout << "Name: " << name << endl;
      cout << "Marks: " << marks << endl << endl;
    }
    bool roll_no_is_greater(Student &s) { return rollno > s.rollno; }

    bool greater_than_acc_dictionary(Student &s) { // check if name is greater than according to dictionary

      int mini = min(s.name.length(), name.length());
      for (int i = 0; i < mini; ++i) {
	if (name[i] > s.name[i]) {
	  return true;
	} else if (name[i] < s.name[i]) {
	  return false;
	}
      }

      if (name.length() > s.name.length()) {
	return true;
      } else {
	return false;
      }
    }
    bool marksisgreater(Student &s) { return marks > s.marks; }
};

class StudentList {
  public:
    vector<Student> list;
    void rand_data() {
      int n;
      cout << "how many random student to generate: ";
      cin >> n;
      for(int i = 0 ; i < n; ++i) {
	Student a;
	a.random_student_data();
	a.get_data();
	list.push_back(a);
      }
    }
    void sort_data() {
      int choice;
      cout << "To sort data Type your Choice:\n1. RollNo\n2. Name\n3. "
	"Marks\nYour Choices is: ";
      cin >> choice;
      if ( list.size() > 5000 ) {
	cout << "number greater than 5000 takes few moments. Hold on ..." << endl;
      }
      cout << endl;

      switch (choice) {
	case 1:
	  sort_roll();
	  break;
	case 2:
	  sort_name();
	  break;
	case 3:
	  sort_marks();
	  break;
	default:
	  cout << "Input a Valid Choice(1,2,3)" << endl;
      }
      for (int i = 0; i < list.size(); ++i) {
	list[i].get_data();
      }
    }

    void sort_roll() {
      int i, j;
      for (i = 0; i < list.size() - 1; i++){
	// Last i elements are already in place
	for (j = 0; j < list.size() - 1; j++){
	  if (list[j].roll_no_is_greater(list[j + 1])){
	    swap(&list[j], &list[j + 1]);
	  }
	}
      }
    }
    void sort_name() {
      int i, j;
      for (i = 0; i < list.size() - 1; i++){
	// Last i elements are already in place
	for (j = 0; j < list.size() - 1; j++){
	  if (list[j].greater_than_acc_dictionary(list[j + 1])){
	    swap(&list[j], &list[j + 1]);
	  }
	}
      }
    }
    void sort_marks() {
      int i, j;
      for (i = 0; i < list.size() - 1; i++){
	// Last i elements are already in place
	for (j = 0; j < list.size() - 1; j++){
	  if (list[j].marksisgreater(list[j + 1])){
	    swap(&list[j], &list[j + 1]);
	  }
	}
      }
    }

    void swap(Student *xp, Student *yp) {
      Student temp = *xp;
      *xp = *yp;
      *yp = temp;
    }
};




int main() {
  Student a;
  a.set_data();
  a.get_data();

  StudentList list;
  list.rand_data();
  list.sort_data();

  return 0;
}
