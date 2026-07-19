## LeetCode 155. Min Stack

### Intuition

The main challenge is to support `getMin()` in **O(1)** time without using an extra stack.

Instead of storing every minimum separately, we encode values whenever a new minimum is pushed.

* If the new value is **greater than or equal to the current minimum**, store it normally.
* If the new value is **smaller than the current minimum**, store an **encoded value**:

[
\text{encoded} = 2 \times val - mn
]

Then update `mn = val`.

The encoded value is always **less than the new minimum**, allowing us to recognize later that it represents a previous minimum.

---

### Approach

#### Push

* If the stack is empty:

  * Push the value.
  * Set `mn = value`.
* If `value >= mn`:

  * Push normally.
* Otherwise:

  * Push `2 * value - mn`.
  * Update `mn = value`.

---

#### Pop

* Pop the top element.
* If the popped value is **less than the current minimum**, it is an encoded value.
* Recover the previous minimum using:

[
\text{previousMin} = 2 \times mn - encoded
]

---

#### Top

* If the top value is **greater than or equal to `mn`**, it is a normal value.
* Otherwise, the top is an encoded value, so the actual top element is the current minimum.

---

#### getMin

Simply return `mn`.

---

### Why Encoding Works

Suppose

* Previous minimum = `oldMin`
* New minimum = `newMin`

Stored value:

[
encoded = 2 \times newMin - oldMin
]

Since `newMin < oldMin`,

[
encoded < newMin
]

Thus, every encoded value is always smaller than the current minimum, making it easy to detect.

When popping:

[
oldMin = 2 \times newMin - encoded
]

which restores the previous minimum.

---

### Time Complexity

* **push()** → **O(1)**
* **pop()** → **O(1)**
* **top()** → **O(1)**
* **getMin()** → **O(1)**

---

### Space Complexity

* **O(n)** (single stack)
* No extra stack is required.

---

### Code

```cpp
class MinStack {
public:
    stack<long long> st;
    long long mn;

    MinStack() {
        mn = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mn = val;
        }
        else if (val >= mn) {
            st.push(val);
        }
        else {
            st.push(2LL * val - mn);
            mn = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mn) {
            mn = 2LL * mn - x;
        }

        if (st.empty()) {
            mn = LLONG_MAX;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();

        if (x >= mn)
            return (int)x;
        else
            return (int)mn;
    }

    int getMin() {
        return (int)mn;
    }
};
```

---

## Dry Run

### Operations

```
push(5)
push(3)
push(7)
push(2)
pop()
top()
getMin()
```

| Operation | Stack (stored values) | mn | Explanation                                 |
| --------- | --------------------- | -- | ------------------------------------------- |
| push(5)   | [5]                   | 5  | First element                               |
| push(3)   | [5, 1]                | 3  | Store `2×3−5 = 1` (encoded)                 |
| push(7)   | [5, 1, 7]             | 3  | Normal push                                 |
| push(2)   | [5, 1, 7, 1]          | 2  | Store `2×2−3 = 1` (encoded)                 |
| pop()     | [5, 1, 7]             | 3  | Encoded popped → previous min = `2×2−1 = 3` |
| top()     | [5, 1, 7]             | 3  | Top is `7`                                  |
| getMin()  | [5, 1, 7]             | 3  | Minimum is `3`                              |

### Final Output

```
top()    = 7
getMin() = 3
```

This solution achieves **O(1)** time for all operations while using only **one stack** through the encoding technique.
