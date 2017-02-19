#ifdef N1AMR_MULTIPLE_FILES
#include "REPL.h"
#include "RSA.h"
#endif //N1AMR_MULTIPLE_FILES

map<char, BigInt> cache;
map<char, bool> boolCache;

string eval(string line) {
  transform(line.begin(), line.end(), line.begin(), ::tolower);
  if (line.length() > 2 && line[1] == '=') {
    readNumber(line[0], line.substr(2));
  } else if (line == "printphi") {
    return get('h').toDecimalString();

  } else if (line.length() == 6 && line.substr(0, 5) == "print") {
    return get(line[5]).toDecimalString();

  } else if (line == "ispprime" || line == "isqprime") {
    return isXPrime(line[2]);

  } else if (line.length() > 14 && line.substr(0, 14) == "encryptpublic=") {
    BigInt message(line.substr(14));
    return message.pow(get('e'), get('n')).toDecimalString();

  } else if (line.length() > 15 && line.substr(0, 15) == "encryptprivate=") {
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

void startREPL() {
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
