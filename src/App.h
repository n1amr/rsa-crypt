#ifndef RSA_APP_H
#define RSA_APP_H

#include "bigint/BigInt.h"
#include "bits/stdc++.h"
using namespace std;

#define COMPOSITE 0
#define INCLUSIVE 1

class App {
private:
  bool MRTEST(BigInt n) {
    if (!n.isOdd())
      return COMPOSITE;

    int k = 0;
    BigInt q = n - 1;
    while (!q.isOdd()) {
      k++;
      q >>= 1;
    }

    BigInt a = random(2, n);

    if(a.pow(q, n) == BigInt::ONE)
      return INCLUSIVE;

    BigInt n_1 = n - 1;
    for (int j = 0; j < k; ++j) {
      if(a.pow(q, n) == n_1)
        return INCLUSIVE;
      q <<= 1;
    }

    return COMPOSITE;
  }

  BigInt random(BigInt from, BigInt to) {
    // TODO
    return (from + to) / 2;
  }

  bool isPrime(BigInt n) {
    bool ans = 0;
    const int TRIALS = 5;
    for (int i = 0; i < TRIALS; ++i)
      if (MRTEST(n) == COMPOSITE)
        return false;
    return true;
  }

  BigInt encrypt(BigInt message, BigInt e_or_d, BigInt N) {
    // TODO
    return BigInt::ZERO;
  }

  BigInt generate(BigInt P, BigInt Q, BigInt E) {
    // TODO
    return BigInt::ZERO;
  }

public:
  void appLoop() {
#ifdef N1AMR_f220929df
    freopen("input", "r", stdin);
#endif
    BigInt P, Q, N, Phi, E, D;
    bool generated = false;

    string line;
    while (getline(cin, line)) {
      if (line.length() > 2 && line.substr(0, 2) == "P=")
        P = BigInt(line.substr(2));
      else if (line.length() > 2 && line.substr(0, 2) == "Q=")
        Q = BigInt(line.substr(2));
      else if (line.length() > 2 && line.substr(0, 2) == "E=")
        E = BigInt(line.substr(2));
      else if (line == "PrintP")
        cout << P << endl;
      else if (line == "PrintQ")
        cout << Q << endl;
      else if (line == "PrintE")
        cout << E << endl;
      else if (line == "PrintD")
        cout << D << endl;
      else if (line == "PrintN")
        cout << (N = P * Q) << endl;
      else if (line == "PrintPhi")
        cout << (Phi = (P - 1) * (Q - 1)) << endl;
      else if (line == "IsPPrime") {
        cout << (isPrime(P) ? "Yes" : "No") << endl;
      } else if (line == "IsQPrime") {
        cout << (isPrime(Q) ? "Yes" : "No") << endl;
      } else if (line.substr(0, 14) == "EncryptPublic=") {
        BigInt message(line.substr(14));
        BigInt cipher = encrypt(message, E, N);
        cout << cipher << endl;
      } else if (line.substr(0, 15) == "EncryptPrivate=") {
        if (!generated) {
          D = generate(P, Q, E);
          generated = true;
        }
        BigInt message(line.substr(15));
        BigInt cipher = encrypt(message, D, N);
        cout << cipher << endl;
      } else if (line == "Quit")
        return;
    }
  }
};

#endif //RSA_APP_H
