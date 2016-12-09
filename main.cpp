#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define CONTAINER_T deque
#define CELL_T unsigned char
#define CELL_TYPE_LENGTH (sizeof(CELL_T) * 8)
//#define CELL_T bitset<8>
//#define CELL_TYPE_LENGTH (sizeof(CELL_T))

typedef long long int LL;

string shiftRightDecimal(string s) {
  string r = "";

  int remainder = 0;

  for (int i = (int) (s.length() - 1); i >= 0; --i) {
    int x = s[i] - '0';
    int y = 2 * x + remainder;
    r.push_back((char) ('0' + (y % 10)));
    remainder = y / 10;
  }
  if (remainder)
    r.push_back((char) ('0' + (remainder % 10)));
  reverse(r.begin(), r.end());
  return r;
}

string addToDecimalString(string s, char d) {
  string r = "";

  int remainder = d - '0';

  for (int i = (int) (s.length() - 1); i >= 0; --i) {
    int x = (s[i] - '0');
    int y = x + remainder;
    r.push_back((char) ('0' + (y % 10)));
    remainder = y / 10;
  }
  if (remainder)
    r.push_back((char) ('0' + (remainder % 10)));
  reverse(r.begin(), r.end());
  return r;
}

class BigInt {
//  private:

  public:
  CONTAINER_T<CELL_T> data;

  BigInt() {
    // TODO
  }

  BigInt(const CONTAINER_T<CELL_T> &init) {
    // TODO
    data = CONTAINER_T<CELL_T>(init);
  }

  string toCellsString() const {
    stringstream ss;
    ss << "BigInt({";
    for (CELL_T cell : data)
      ss << ((LL) cell) << ", ";
    ss << "})";
    return ss.str();
  }

  string toBitsString() const {
    stringstream nss;
    queue<CELL_T> tmp(data);
    tmp.push((CELL_T) 0);

    while (!tmp.empty()) {
      CELL_T cell = tmp.front();
      tmp.pop();
      for (int i = 0; i < CELL_TYPE_LENGTH; ++i) {
        nss << cell % 2;
        cell /= 2;
      }
    }
    string bitString = nss.str();
    reverse(bitString.begin(), bitString.end());
    unsigned long firstOneIndex = bitString.find('1');
    bitString = bitString.substr(min(firstOneIndex, bitString.length() - 1));
    return bitString;
  }

  string toDecimalString() const {
    stringstream nss;
    string bitString = toBitsString();
    string n = "0";
    while (!bitString.empty()) {
      n = shiftRightDecimal(n);
      n = addToDecimalString(n, bitString.back());
      bitString.pop_back();
    }
    nss << n;
    return nss.str();
  }

  friend ostream &operator<<(ostream &os, const BigInt &x) {
    return os << x.toBitsString();
  }
};

int main() {
  cout << "Hello, World!" << endl;

  BigInt x(CONTAINER_T<CELL_T>({1, 2}));
  cout << x << endl;
  cout << x.toDecimalString() << endl;
  return 0;
}