#ifndef RSA_APP_H
#define RSA_APP_H

#include <iostream>
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

    if (a.pow(q, n) == BigInt::ONE)
      return INCLUSIVE;

    BigInt n_1 = n - 1;
    for (int j = 0; j < k; ++j) {
      if (a.pow(q, n) == n_1)
        return INCLUSIVE;
      q <<= 1;
    }

    return COMPOSITE;
  }

  BigInt random(BigInt from, BigInt to) {
    return from +
           (to - from) * BigInt((long long) rand())
           / BigInt((long long) 1 << 31);
  }

  bool isPrime(BigInt n) {
    bool ans = 0;
    const int TRIALS = 5;
    for (int i = 0; i < TRIALS; ++i)
      if (MRTEST(n) == COMPOSITE)
        return false;
    return true;
  }

  BigInt encrypt(BigInt message, BigInt e_or_d, BigInt n) {
    // TODO
    return BigInt::ZERO;
  }

  BigInt generate(BigInt p, BigInt q, BigInt e) {
    BigInt n = p * q;
    BigInt phi = (p - 1) * (q - 1);
    BigInt d = inverse(e, phi);
    if (d.isZero())
      throw "Cannot find inverse (gcd != 1)";

    return d;
  }

  BigInt inverse(BigInt a, BigInt mod) {
    BigInt right_old = mod;
    BigInt right = a;
    BigInt left_old = BigInt::ZERO;
    BigInt left = BigInt::ONE;
    BigInt tmp, Q;
    while (1) {
      if (right.isZero())
        return BigInt::ZERO;// no inverse
      else if (right == BigInt::ONE)
        return left > 0 ? left : mod + left;

      Q = right_old / right;

      tmp = left_old - Q * left;
      left_old = left;
      left = tmp;

      tmp = right_old - Q * right;
      right_old = right;
      right = tmp;
    }
  }

public:
  void appLoop() {
#ifdef N1AMR_f220929df
    freopen("input", "r", stdin);
#endif
    BigInt p, q, n, phi, e, d;
    bool generated = false;

    string line;
    while (getline(cin, line)) {
      if (line.length() > 2 && line.substr(0, 2) == "P=") {
        p = BigInt(line.substr(2));
        generated = false;
      } else if (line.length() > 2 && line.substr(0, 2) == "Q=") {
        q = BigInt(line.substr(2));
        generated = false;
      } else if (line.length() > 2 && line.substr(0, 2) == "E=") {
        e = BigInt(line.substr(2));
        generated = false;
      } else if (line == "PrintP") {
        cout << p << endl;
      } else if (line == "PrintQ") {
        cout << q << endl;
      } else if (line == "PrintE") {
        cout << e << endl;
      } else if (line == "PrintD") {
        if (!generated) {
          d = generate(p, q, e);
          generated = true;
        }
        cout << d << endl;
      } else if (line == "PrintN") {
        cout << (n = p * q) << endl;
      } else if (line == "PrintPhi") {
        cout << (phi = (p - 1) * (q - 1)) << endl;
      } else if (line == "IsPPrime") {
        cout << (isPrime(p) ? "Yes" : "No") << endl;
      } else if (line == "IsQPrime") {
        cout << (isPrime(q) ? "Yes" : "No") << endl;
      } else if (line.substr(0, 14) == "EncryptPublic=") {
        BigInt message(line.substr(14));
        BigInt cipher = encrypt(message, e, n);
        cout << cipher << endl;
      } else if (line.substr(0, 15) == "EncryptPrivate=") {
        if (!generated) {
          d = generate(p, q, e);
          generated = true;
        }
        BigInt message(line.substr(15));
        BigInt cipher = encrypt(message, d, n);
        cout << cipher << endl;
      } else if (line == "Quit")
        return;
    }
  }
};

#endif //RSA_APP_H
