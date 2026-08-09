/*# Weighted Sum of a Tree

## Intuition

The tree is given using a `parent` array.

For every node `i`:

```text
parent[i] = parent of node i
```

The root is node `0`.

The weight of a node depends on its depth:

{weight}[i] = {height} - {depth}[i] + 1

So we need two things:

1. Find the **depth of every node**.
2. Find the **maximum depth**, i.e. the height of the tree.

We can use **BFS (level-order traversal)** because BFS naturally visits a tree level by level.

---

## Approach

### 1. Build the tree

Convert the `parent` array into a children adjacency list.

For every node `i`:

```cpp
children[parent[i]].push_back(i);
```

For example:

```text
parent = [-1, 0, 0, 1, 1]
```

creates:

```text
        0
       / \
      1   2
     / \
    3   4
```

---

### 2. Find the depth of every node

Start BFS from the root:

```cpp
depth[0] = 1;
```

For every child:

```cpp
depth[child] = depth[node] + 1;
```

At the same time, keep track of the maximum depth:

```cpp
height = max(height, depth[child]);
```

---

### 3. Calculate the weighted sum

For every node:

nums[i]*(height-depth[i]+1)

Therefore:

```cpp
ans += 1LL * nums[i] * (height - depth[i] + 1);
```

`1LL` is important because the multiplication can exceed the range of `int`.

---

## Code

```cpp*/
class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        // Build children adjacency list
        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        // Find depth of every node using BFS
        vector<int> depth(n);

        queue<int> q;
        q.push(0);

        depth[0] = 1;
        int height = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : children[node]) {
                depth[child] = depth[node] + 1;
                height = max(height, depth[child]);

                q.push(child);
            }
        }

        // Calculate weighted sum
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (height - depth[i] + 1);
        }

        return ans;
    }
};/*
```

---

## Time Complexity

Building the tree takes:

O(n)

BFS visits every node exactly once:

O(n)

Final calculation also takes:

O(n)

Therefore:

**Time Complexity: `O(n)`**

### Space Complexity

The children adjacency list stores every edge:

O(n)

The `depth` array and queue also require:

O(n)

Therefore:

**Space Complexity: `O(n)`**

---

## Dry Run

Consider:

```text
parent = [-1, 0, 0, 1, 1]
nums   = [10, 20, 30, 40, 50]
```

Tree:

```text
        0
       / \
      1   2
     / \
    3   4
```

### BFS

Depths:

```text
node:    0   1   2   3   4
depth:   1   2   2   3   3
```

Maximum depth:

```text
height = 3
```

### Calculate weights

For node `0`:

```text
weight = 3 - 1 + 1 = 3
contribution = 10 × 3 = 30
```

Node `1`:

```text
weight = 3 - 2 + 1 = 2
contribution = 20 × 2 = 40
```

Node `2`:

```text
weight = 3 - 2 + 1 = 2
contribution = 30 × 2 = 60
```

Node `3`:

```text
weight = 3 - 3 + 1 = 1
contribution = 40 × 1 = 40
```

Node `4`:

```text
weight = 3 - 3 + 1 = 1
contribution = 50 × 1 = 50
```

Therefore:

```text
ans = 30 + 40 + 60 + 40 + 50
    = 220
```

### Final Answer

```text
220
```*/
