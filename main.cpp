#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define CELL_T unsigned char
#define CELL_TYPE_LENGTH (sizeof(CELL_T) * 8)
//#define CELL_T bitset<8>
//#define CELL_TYPE_LENGTH (sizeof(CELL_T))

typedef long long int LL;

class BigInt {
//  private:

  public:
  vector<CELL_T> data;

  BigInt() {
    // TODO
    cout << CELL_TYPE_LENGTH << endl;
  }

  string toCellsString() const {
    stringstream ss;
    ss << "BigInt({";
    for (CELL_T cell : data)
      ss << ((LL) cell) << ", ";
    ss << "})";
    return ss.str();
  }

  string toBinaryString() const {
    stringstream nss;
    vector<CELL_T> tmp = data;
    reverse(tmp.begin(), tmp.end());

    while (!tmp.empty()) {
      CELL_T cell = tmp.back();
      tmp.pop_back();
      for (int i = 0; i < CELL_TYPE_LENGTH; ++i) {
        nss << cell % 2;
        cell /= 2;
      }
    }
    string bitString = nss.str();
    reverse(bitString.begin(), bitString.end());
    return bitString;
  }

  friend ostream &operator<<(ostream &os, const BigInt &x) {
    return os << x.toCellsString();
  }
};

int main() {
  cout << "Hello, World!" << endl;
  BigInt x;
  x.data.push_back(7 + 128);
  x.data.push_back(3 + 128);
//  x.data.push_back(120);
//  x.data.push_back(121);
//  x.data.push_back(122);
  cout << x << endl;
  cout << x.toCellsString() << endl;
  cout << x.toBinaryString() << endl;

  return 0;
}