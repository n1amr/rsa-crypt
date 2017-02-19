#ifdef N1AMR_MULTIPLE_FILES
#include "RSA.h"
#endif //N1AMR_MULTIPLE_FILES

BigInt random(const BigInt &from, const BigInt &to) {
  assert(from < to);
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
  assert(mod != BigInt::ZERO);
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
