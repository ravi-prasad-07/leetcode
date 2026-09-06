## LeetCode 319 — Bulb Switcher

### Intuition

Initially, all bulbs are **OFF**.

For bulb `i`, its state is toggled every time we visit a round number that **divides `i`**.

For example, bulb `12` is toggled in rounds:

```text
1, 2, 3, 4, 6, 12
```

So it is toggled **6 times** → even → remains OFF.

The important observation is:

> Normally, divisors come in pairs.

For `12`:

```text
(1,12), (2,6), (3,4)
```

So it has an even number of divisors.

But for a **perfect square**, one divisor is paired with itself.

For example, `9`:

```text
(1,9), (3,3)
```

So `9` has an **odd number of divisors**.

Therefore, a bulb remains ON **only when its number is a perfect square**.

So the answer is simply:

```text
Number of perfect squares ≤ n
= floor(sqrt(n))
```

---

### Approach

We don't need to simulate all the rounds.

Just calculate:

```cpp
sqrt(n)
```

For example:

```text
n = 10

Perfect squares ≤ 10:
1, 4, 9

Answer = 3
```

Since `sqrt(10)` is approximately `3.16`, converting it to `int` gives:

```text
3
```

---

### Code

```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
```

### Time Complexity

```text
O(1)
```

### Space Complexity

```text
O(1)
```

---

### Dry Run

Suppose:

```text
n = 5
```

Bulbs:

```text
1  2  3  4  5
```

Only bulbs `1` and `4` remain ON because both are perfect squares.

```text
1 = 1²
4 = 2²
```

Therefore:

```text
answer = 2
```

Our code:

```cpp
sqrt(5) = 2.23
```

Integer conversion:

```text
2
```

So the answer is **2**.

### ⭐ Key Point

**A bulb is ON at the end if and only if its number is a perfect square.**

Hence:

```cpp
answer = floor(sqrt(n));
```
