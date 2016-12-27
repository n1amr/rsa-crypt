#ifdef N1AMR_MULTIPLE_FILES

#include "App.h"
#endif

BigInt random(BigInt from, BigInt to) {
  return from +
         (to - from) * BigInt((long long) rand())
         / BigInt((long long) 1 << 31);
}

bool millerRabinTest(BigInt n) {
  if (!n.isOdd())
    return COMPOSITE;

  int k = 0;
  BigInt n_1 = n - 1;
  BigInt q = n_1;
  while (!q.isOdd()) {
    k++;
    q >>= 1;
  }

  BigInt a = random(2, n);
  BigInt last_pow = a.pow(q, n);
  if (last_pow == BigInt::ONE)
    return INCLUSIVE;

  for (int j = 0; j < k; ++j) {
    if (last_pow == n_1)
      return INCLUSIVE;
    last_pow = (last_pow * last_pow) % n;
  }

  return COMPOSITE;
}

bool isPrime(BigInt n) {
  for (int i = 0; i < MAX_MILLER_RABIN_TRIALS_COUNT; ++i)
    if (millerRabinTest(n) == COMPOSITE)
      return false;
  return true;
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

void appLoop() {
#ifdef N1AMR_FILE_INPUT
  FILE *file = freopen("input", "r", stdin);
  if (file == NULL)
    exit(1);
#endif
  map<char, BigInt> cache;
  map<char, bool> boolCache;

  string line;
  while (getline(cin, line)) {
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    if (line.length() > 2 && line.substr(0, 2) == "p=") {
      cache['p'] = BigInt(line.substr(2));
      cache.erase('n');
      cache.erase('h');
      cache.erase('d');
      boolCache.erase('p');
    } else if (line.length() > 2 && line.substr(0, 2) == "q=") {
      cache['q'] = BigInt(line.substr(2));
      cache.erase('n');
      cache.erase('h');
      cache.erase('d');
      boolCache.erase('q');
    } else if (line.length() > 2 && line.substr(0, 2) == "e=") {
      cache['e'] = BigInt(line.substr(2));
      cache.erase('n');
      cache.erase('h');
      cache.erase('d');
    } else if (line == "printp") {
      cout << cache['p'] << endl;
    } else if (line == "printq") {
      cout << cache['q'] << endl;
    } else if (line == "printe") {
      cout << cache['e'] << endl;
    } else if (line == "printd") {
      if (cache.count('d') == 0) {
        if (cache.count('h') == 0)
          cache['h'] = (cache['p'] - 1) * (cache['q'] - 1);
        cache['d'] = inverse(cache['e'], cache['h']);
      }
      cout << cache['d'] << endl;
    } else if (line == "printn") {
      if (cache.count('n') == 0)
        cache['n'] = cache['p'] * cache['q'];
      cout << cache['n'] << endl;
    } else if (line == "printphi") {
      if (cache.count('h') == 0)
        cache['h'] = (cache['p'] - 1) * (cache['q'] - 1);
      cout << cache['h'] << endl;
    } else if (line == "ispprime") {
      if (boolCache.count('p') == 0)
        boolCache['p'] = isPrime(cache['p']);
      cout << (boolCache['p'] ? "Yes" : "No") << endl;
    } else if (line == "isqprime") {
      if (boolCache.count('q') == 0)
        boolCache['q'] = isPrime(cache['q']);
      cout << (boolCache['q'] ? "Yes" : "No") << endl;
    } else if (line.substr(0, 14) == "encryptpublic=") {
      if (cache.count('n') == 0)
        cache['n'] = cache['p'] * cache['q'];
      BigInt message(line.substr(14));
      cout << message.pow(cache['e'], cache['n']) << endl;
    } else if (line.substr(0, 15) == "encryptprivate=") {
      if (cache.count('d') == 0) {
        if (cache.count('h') == 0)
          cache['h'] = (cache['p'] - 1) * (cache['q'] - 1);
        cache['d'] = inverse(cache['e'], cache['h']);
      }
      if (cache.count('n') == 0)
        cache['n'] = cache['p'] * cache['q'];
      BigInt message(line.substr(15));
      cout << message.pow(cache['d'], cache['n']) << endl;
    } else if (line == "quit")
      return;
  }
}
