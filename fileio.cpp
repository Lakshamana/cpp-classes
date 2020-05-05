#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> readlines(ifstream& in) {
  vector<string> lines;
  while(in.good()) {
    string buf;
    getline(in, buf);
    lines.push_back(buf);
  }
  return lines;
}

int main(int argc, char *argv[]) {
  ifstream in("./test-file.txt");
  string text;

  // Read by char
  while(in.good()) {
    text += in.get();
  }

  cout << "Reading char-by-char: " << text << endl;

  // Reset offset to byte 0
  in.clear();
  in.seekg(0);

  // Read by lines
  vector<string> lines = readlines(in);
  cout << "\nReading line-by-line:" << endl;
  // vector<string>::iterator i;
  // for (i = lines.begin(); i < lines.end(); i++) {
  //   cout << *i << endl;
  // }

  // less verbose form
  int i = 0;
  for(string& line : lines) {
    cout << line << " " << i++ << endl;
  }

  ofstream out("./out.txt");
  out << "Learning C++" << endl << "end" << endl;
  return 0;
}
