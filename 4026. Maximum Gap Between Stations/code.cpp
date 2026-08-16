## Intuition

We need to find the **maximum gap between two consecutive characters of `skill` inside `station`**.

For every character `skill[i]` and `skill[i+1]`, we want:

* the **earliest possible position** of `skill[i]`
* the **latest possible position** of `skill[i+1]`

Then the maximum gap is:

`latest position of skill[i+1] - earliest position of skill[i]`

Your approach does exactly this using two passes:

1. **Left to right** → store earliest positions in `left`.
2. **Right to left** → store latest positions in `right`.
3. Compare corresponding positions for every adjacent pair.

---

## Approach

### 1. Find earliest positions

```cpp
for(int i=0; i<skill.length(); i++){
    for(int j=prev+1; j<station.size(); j++){
        if(skill[i]==station[j]){
            left.push_back(j);
            prev=j;
            break;
        }
    }
}
```

For example:

```text
skill   = "abc"
station = "axbyc"
```

The earliest positions are:

```text
a -> 0
b -> 2
c -> 4

left = [0, 2, 4]
```

### 2. Find latest positions

We scan `station` from right to left.

For the same example:

```text
c -> 4
b -> 2
a -> 0

right = [4, 2, 0]
```

Because `right` is stored in reverse order, the position corresponding to `skill[i+1]` is:

```cpp
right[skill.length() - 2 - i]
```

### 3. Calculate maximum gap

For each adjacent pair:

```cpp
ans = max(ans, right[skill.length()-2-i] - left[i]);
```

For:

```text
skill = "abc"
station = "axbyc"
```

we get:

```text
a -> b : 2 - 0 = 2
b -> c : 4 - 2 = 2

answer = 2
```

---

## Important Issue in Your Code

Your code assumes that `skill` is always a subsequence of `station`.

If that is guaranteed by the problem constraints, your solution is fine.

However, if it is **not guaranteed**, this can cause an out-of-bounds access:

```cpp
right[skill.length()-2-i]
```

because `left` or `right` might contain fewer elements than `skill`.

---

## Cleaner Version of Your Solution

We can make your code easier to read by using `n` and `m`:

```cpp
class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        
        if(n <= 1) return 0;

        vector<int> left, right;

        // Earliest positions
        int prev = -1;

        for(int i = 0; i < n; i++) {
            for(int j = prev + 1; j < station.size(); j++) {
                if(skill[i] == station[j]) {
                    left.push_back(j);
                    prev = j;
                    break;
                }
            }
        }

        // Latest positions
        prev = station.size();

        for(int i = n - 1; i >= 0; i--) {
            for(int j = prev - 1; j >= 0; j--) {
                if(skill[i] == station[j]) {
                    right.push_back(j);
                    prev = j;
                    break;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, right[n - 2 - i] - left[i]);
        }

        return ans;
    }
};
```

## Complexity

Let:

* `n = skill.length()`
* `m = station.length()`

In the worst case, the nested loops can scan a large portion of `station` for each character.

**Time:** `O(n × m)`

**Space:** `O(n)`

---

## Dry Run

```text
skill   = "abc"
station = "axbyc"
```

### Left-to-right

```text
skill[0] = 'a' → position 0
skill[1] = 'b' → position 2
skill[2] = 'c' → position 4

left = [0, 2, 4]
```

### Right-to-left

```text
skill[2] = 'c' → position 4
skill[1] = 'b' → position 2
skill[0] = 'a' → position 0

right = [4, 2, 0]
```

### Calculate

For `a → b`:

```text
right[1] - left[0]
= 2 - 0
= 2
```

For `b → c`:

```text
right[0] - left[1]
= 4 - 2
= 2
```

Therefore:

```text
Maximum Gap = 2
```

**Key idea:** earliest occurrence of the left character + latest occurrence of the next character gives the largest possible gap.
