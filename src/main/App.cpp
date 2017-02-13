#ifdef N1AMR_MULTIPLE_FILES
#include "App.h"
#endif //N1AMR_MULTIPLE_FILES

BigInt random(const BigInt &from, const BigInt &to) {
  BigInt ans = from +
               (to - from) * BigInt((long long) rand())
               / BigInt((long long) 1 << 31);
  assert(from <= ans && ans < to);
  return ans;
}

bool millerRabinTest(const BigInt &n) {
  assert(n > BigInt(2));

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

  for (int j = 0; j < k; j++) {
    if (last_pow == n_1)
      return INCLUSIVE;
    last_pow = (last_pow * last_pow) % n;
  }

  return COMPOSITE;
}

bool isPrime(const BigInt &n) {
  BigInt n_abs = BigInt::absolute(n);
  if (n_abs < BigInt(2))
    return false;
  if (n_abs == BigInt(2))
    return true;

  for (int i = 0; i < MAX_MILLER_RABIN_TRIALS_COUNT; i++)
    if (millerRabinTest(n_abs) == COMPOSITE)
      return false;
  return true;
}

BigInt inverse(const BigInt &a, const BigInt &mod) {
  BigInt ans;

  BigInt right_old = mod;
  BigInt right = a;
  BigInt left_old = BigInt::ZERO;
  BigInt left = BigInt::ONE;
  BigInt tmp, Q;
  while (1) {
    if (right.isZero()) {
      ans = BigInt::ZERO;  // no inverse
      break;
    } else if (right == BigInt::ONE) {
      ans = left > 0 ? left : mod + left;
      break;
    }

    Q = right_old / right;

    tmp = left_old - Q * left;
    left_old = left;
    left = tmp;

    tmp = right_old - Q * right;
    right_old = right;
    right = tmp;
  }
  assert(BigInt::mod(ans * a, mod) == BigInt::ONE || ans == BigInt::ZERO);
  return ans;
}

map<char, BigInt> cache;
map<char, bool> boolCache;

string eval(string line) {
  transform(line.begin(), line.end(), line.begin(), ::tolower);
  if (line.length() > 2 && line[1] == '=') {
    readNumber(line[0], line.substr(2));
  } else if (line == "printphi") {
    return get('h').toDecimalString();

  } else if (line.substr(0, 5) == "print") {
    return get(line[5]).toDecimalString();

  } else if (line == "ispprime" || line == "isqprime") {
    return isXPrime(line[2]);

  } else if (line.substr(0, 14) == "encryptpublic=") {
    BigInt message(line.substr(14));
    return message.pow(get('e'), get('n')).toDecimalString();

  } else if (line.substr(0, 15) == "encryptprivate=") {
    BigInt message(line.substr(15));
    return message.pow(get('d'), get('n')).toDecimalString();

  } else if (line == "quit") {
    return "exit";
  }
  return "ignore";
}

void readNumber(char name, string val) {
  cache[name] = BigInt(val);
  cache.erase('n');
  cache.erase('h');
  cache.erase('d');
  boolCache.erase(name);
}

BigInt &get(char name) {
  assert(string("pqnhed").find(name) != string::npos);
  if (string("pqnhed").find(name) != string::npos) {
    if (name == 'n')
      refreshN();
    else if (name == 'h')
      refreshPhi();
    else if (name == 'd')
      refreshD();

    assert(cache.count(name));
    return cache[name];
  }
  throw "Error: Key not found!";
}

void refreshN() {
  assert(cache.count('p') && cache.count('q'));
  if (cache.count('n') == 0)
    cache['n'] = get('p') * get('q');
}

void refreshPhi() {
  assert(cache.count('p') && cache.count('q'));
  if (cache.count('h') == 0)
    cache['h'] = (get('p') - 1) * (get('q') - 1);
}

void refreshD() {
  if (cache.count('d') == 0) {
    if (cache.count('h') == 0)
      refreshPhi();

    assert(cache.count('e') && cache.count('h'));
    cache['d'] = inverse(get('e'), get('h'));
  }
}

string isXPrime(char name) {
  if (boolCache.count(name) == 0)
    boolCache[name] = isPrime(get(name));
  return (boolCache[name] ? "Yes" : "No");
}

void appLoop() {
#ifdef N1AMR_FILE_INPUT
  FILE *file = freopen("input", "r", stdin);
  if (file == NULL)
    exit(1);
#endif //N1AMR_FILE_INPUT

#ifndef N1AMR_LOCAL_PC
  srand(time(NULL));
#endif //N1AMR_LOCAL_PC

  string line;
  while (getline(cin, line)) {
    string ans = eval(line);
    if (ans != "ignore") {
      if (ans == "exit")
        return;
      else
        cout << ans << endl;
    }
  }
}
