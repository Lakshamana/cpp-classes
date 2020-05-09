#include <iostream>
#include <vector>

using namespace std;

class Point {
  public:
    int x, y;

    Point(int x, int y) {
      this->x = x;
      this->y = y;
    }
};

int main(int argc, char *argv[]) {
  vector<Point*> v;
  Point* p1 = new Point(1, 2);
  Point* p2 = new Point(3, 4);

  v.push_back(p1);
  v.push_back(p2);

  // The easy way
  // for (Point* p : v) {
  //   printf("(%i, %i)\n", p->x, p->y);
  // }

  // Masochistic way
  vector<Point*>::iterator it;
  for(it = v.begin(); it < v.end(); it++) {
    // In that case it will be of type (Pointer**),
    // which means you should always derreference it
    printf("(%i, %i)\n", (*it)->x, (*it)->y);
  }

  cout << "\nWe can also have a object vector:" << endl;
  vector<Point> v2;
  for (int i = 0; i < 5; i++) {
    v2.push_back(Point(i, i + 1));
  }

  for (Point& p : v2) {
    printf("(%i, %i)\n", p.x, p.y);
  }
  return 0;
}
