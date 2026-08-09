/*
### Intuition

To get the minimum possible total:

* Sort `prices` in **descending order**.
* Sort `discounts` in **descending order**.
* Apply the **largest discount to the most expensive item**.
* Apply the next largest discount to the next most expensive item, and so on.

This pairing is optimal because a larger discount gives a larger absolute saving when applied to a more expensive item.

For an item with price `p` and discount `d%`:

[
\text{final price} = p \times \frac{100-d}{100}
]

### Approach

1. Sort both arrays in descending order.
2. Pair the first `min(prices.size(), discounts.size())` elements.
3. If there are more prices than discounts, add the remaining prices without any discount.
4. If there are more discounts than prices, the extra discounts are simply unused.

### Complexity

Let:

* `P = prices.size()`
* `D = discounts.size()`

Sorting dominates:

* **Time:** `O(P log P + D log D)`
* **Space:** `O(log P + log D)` auxiliary space for sorting (depending on the sorting implementation).

### Clean LeetCode-style solution

## Intuition

To minimize the total price, we should give the **largest discount to the most expensive item**.

For example:

* Price = `100`, Discount = `50%` → Saving = `50`
* Price = `50`, Discount = `50%` → Saving = `25`

So applying the same discount to the more expensive item gives a greater saving.

Therefore, we sort both `prices` and `discounts` in descending order and pair them from left to right.

---

## Approach

1. Sort `prices` in descending order.
2. Sort `discounts` in descending order.
3. For every pair:

   * Calculate the discounted price.
   * Add it to `ans`.
4. If there are more prices than discounts, those remaining prices receive no discount.
5. Return the total.

### Formula

For price `p` and discount `d`:

```text
discounted price = p × (100 - d) / 100
```

---

## Code

```cpp*/
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        double ans = 0.0;

        int n = min(prices.size(), discounts.size());

        for (int i = 0; i < n; i++) {
            ans += (prices[i] * (100.0 - discounts[i])) / 100.0;
        }

        // Remaining prices get no discount
        for (int i = n; i < prices.size(); i++) {
            ans += prices[i];
        }

        return ans;
    }
};/*
```

---

## Time Complexity

Let `P = prices.size()` and `D = discounts.size()`.

```text
Sorting prices    → O(P log P)
Sorting discounts → O(D log D)
Pairing           → O(min(P, D))
```

Therefore:

**Time:** `O(P log P + D log D)`

**Space:** `O(log P + log D)` auxiliary space due to sorting.

---

## Dry Run

Suppose:

```text
prices    = [100, 50, 20]
discounts = [20, 50]
```

### Step 1: Sort

```text
prices    = [100, 50, 20]
discounts = [50, 20]
```

### Step 2: Apply discounts

First item:

```text
100 with 50% discount
= 100 × (100 - 50) / 100
= 50
```

Second item:

```text
50 with 20% discount
= 50 × (100 - 20) / 100
= 40
```

Third item has no discount:

```text
20
```

Therefore:

```text
Total = 50 + 40 + 20
      = 110
```

So the minimum price is:

```text
110
```
*/
