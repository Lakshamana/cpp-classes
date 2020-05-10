#include <iostream>

using namespace std;

typedef struct t_course {
  string name;
} Course;

typedef struct t_student {
  string name;
  Course course;
} Student;

int main(int argc, char *argv[]) {
  Student s = {"John Doe", {"Computer Science"}};
  Student* ps = &s;
  cout << "Student name: " << ps->name << endl;
  cout << "Course name: " << ps->course.name << endl;
  return 0;
}
