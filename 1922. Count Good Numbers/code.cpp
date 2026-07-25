/*## Intuition

A good number is formed such that:

* Digits at **even indices (0-based)** can only be one of `{0, 2, 4, 6, 8}` → **5 choices**.
* Digits at **odd indices** can only be one of `{2, 3, 5, 7}` → **4 choices**.

So,

* Number of even positions = `(n + 1) / 2`
* Number of odd positions = `n / 2`

Hence, the total number of good numbers is:

[
5^{\text{even positions}} \times 4^{\text{odd positions}}
]

Since `n` can be as large as `10^15`, computing powers normally is impossible. We use **Binary Exponentiation (Fast Power)** to calculate powers in **O(log n)** time under modulo `1e9 + 7`.

---

## Approach

1. Count the number of even and odd indexed positions.
2. Compute:

   * `5^evenPositions % MOD`
   * `4^oddPositions % MOD`
     using binary exponentiation.
3. Multiply both results under modulo.
4. Return the final answer.

---

## Time Complexity

* Binary exponentiation for `5^(even)` → **O(log n)**
* Binary exponentiation for `4^(odd)` → **O(log n)**

**Overall:** **O(log n)**

---

## Space Complexity

* Recursive binary exponentiation uses recursion depth **O(log n)**.

**Overall:** **O(log n)**

> **Note:** An iterative binary exponentiation would reduce the space complexity to **O(1)**.

---

## Code

```cpp*/
class Solution {
public:
    const long long mod = 1e9 + 7;

    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        long long res = (half * half) % mod;

        if (exp % 2)
            res = (base * res) % mod;

        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans = (power(5, even) * power(4, odd)) % mod;

        return (int)ans;
    }
};
/*```

---

## Dry Run

### Example: `n = 4`

Positions:

* Index `0` (even) → 5 choices
* Index `1` (odd) → 4 choices
* Index `2` (even) → 5 choices
* Index `3` (odd) → 4 choices

So,

* Even positions = `(4 + 1) / 2 = 2`
* Odd positions = `4 / 2 = 2`

Compute:

* `5² = 25`
* `4² = 16`

Answer:

```
25 × 16 = 400
400 % (1e9 + 7) = 400
```

**Output:** `400`

---

### Example: `n = 1`

* Even positions = 1
* Odd positions = 0

```
5¹ × 4⁰
= 5 × 1
= 5
```

**Output:** `5`
*/
