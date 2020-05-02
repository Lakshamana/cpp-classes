#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  string s = "Lakshamana";
  cout << "String: " << s << endl;
  cout << "Length: " << s.length() << endl;
  cout << "Char at index 3: " << s.at(3) << endl;
  cout << "First char: " << s.front() << endl;
  cout << "Last char: " << s.back() << endl;
  cout << "Fisrt 3 chars: " << s.substr(0, 3) << endl;
  cout << "Last 3 chars: " << s.substr(s.length() - 3, 3) << endl;
  cout << "Is empty? " << s.empty() << endl;
  cout << "Replace Lak for lak: " << s.replace(0, 3, "lak") << endl;
  cout << "Does \"lakshamana\" includes \"ama\"? " << (s.find("ama") != string::npos) << endl;

  cout << endl;
  string s1 = "Hello ", s2 = "world";
  string cat = s1.append(s2);
  cout << "Concat: " << cat << endl;
  cat.insert(0, "$");
  cout << "Add char \"$\" before: " << cat << endl;
  cat.push_back('!');
  cout << "Add char \"!\" after: " << cat << endl;
  cout << "Erase chars: " << cat.erase(6, cat.size()) << endl;
  cout << "std::string -> C const char *: " << cat.c_str() << endl;
  const char *str = "Hello! const char * here!";
  cout << "C const char * -> std::string: " << string(str) << endl;
  cat.clear();
  cout << "Cleared string!" << endl;
  return 0;
}
