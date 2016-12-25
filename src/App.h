#ifndef RSA_APP_H
#define RSA_APP_H

#include "bigint/BigInt.h"
#include "bits/stdc++.h"
using namespace std;

class App {
private:
  bool isPrime(BigInt n) {
    // TODO
    return 0;
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
