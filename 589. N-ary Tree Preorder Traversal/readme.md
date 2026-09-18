# N-ary Tree Postorder Traversal

## 📝 Problem

Given the root of an **N-ary tree**, return the **postorder traversal** of its nodes' values.

In **postorder traversal**, we visit:

```text
Children → Root
```

Each node in an N-ary tree can have zero or more children.

---

## 💡 Intuition

For every node:

1. Visit all of its children recursively.
2. After visiting all children, add the current node's value to the result.

The key idea is that the root node is added **after** all of its children.

For example:

```text
        1
      / | \
     3  2  4
    / \
   5   6
```

Postorder traversal:

```text
5 → 6 → 3 → 2 → 4 → 1
```

---

## 🔨 Approach

We use a recursive helper function `solve()`.

### Steps

1. If the current node is `nullptr`, return.
2. Traverse every child of the current node.
3. After all children have been processed, add the current node's value to `ans`.
4. Return the final `ans` vector.

---

## 💻 C++ Solution

```cpp
/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     vector<Node*> children;

     Node() {}

     Node(int _val) {
         val = _val;
     }

     Node(int _val, vector<Node*> _children) {
         val = _val;
         children = _children;
     }
 };
*/

class Solution {
public:

    void solve(vector<int>& ans, Node* root) {
        if(root == nullptr) {
            return;
        }

        int n = root->children.size();

        // Visit all children first
        for(int i = 0; i < n; i++) {
            solve(ans, root->children[i]);
        }

        // Visit root after all children
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;

        solve(ans, root);

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

Let `N` be the total number of nodes and `H` be the height of the tree.

### Time Complexity

```text
O(N)
```

Every node is visited exactly once.

### Space Complexity

The recursive call stack can contain at most `H` nodes.

```text
Auxiliary Space: O(H)
```

The result vector requires:

```text
Output Space: O(N)
```

Therefore:

```text
Total Space: O(N + H)
```

---

## 🔍 Dry Run

Consider the following tree:

```text
        1
      / | \
     3  2  4
    / \
   5   6
```

### Step 1

Start at node `1`.

Its children are:

```text
3, 2, 4
```

### Step 2

Visit node `3`.

Its children are:

```text
5, 6
```

Visit `5`:

```text
ans = [5]
```

Visit `6`:

```text
ans = [5, 6]
```

All children of `3` are processed, so add `3`:

```text
ans = [5, 6, 3]
```

### Step 3

Return to node `1` and visit `2`:

```text
ans = [5, 6, 3, 2]
```

### Step 4

Visit `4`:

```text
ans = [5, 6, 3, 2, 4]
```

### Step 5

All children of `1` are processed, so add `1`:

```text
ans = [5, 6, 3, 2, 4, 1]
```

### Final Answer

```text
[5, 6, 3, 2, 4, 1]
```

---

## ⭐ Key Takeaway

The defining rule of **postorder traversal** is:

```text
Process all children
        ↓
Process the root
```

In code, this is achieved by placing:

```cpp
ans.push_back(root->val);
```

**after** the loop that recursively processes all children.
