# 872. Leaf-Similar Trees

## Problem

Given the roots of two binary trees `root1` and `root2`, return `true` if the leaf value sequence of both trees is the same.

A **leaf value sequence** is the sequence of values of all the leaf nodes read from left to right.

### Example

```text
Tree 1 leaves: 6 → 7 → 4 → 9 → 8
Tree 2 leaves: 6 → 7 → 4 → 9 → 8

Output: true
```

---

## Intuition

Two trees are **leaf-similar** if their leaf nodes, when read from left to right, have exactly the same values.

Instead of comparing the entire structure of the trees, we only need to compare their leaf sequences.

The idea is:

1. Traverse the first tree and store all leaf values in a vector.
2. Traverse the second tree and compare each leaf with the corresponding value in the vector.
3. If any value is different, return `false`.
4. Finally, make sure both trees have the same number of leaves.

---

## Approach

### Step 1: Store leaf values of `root1`

Use DFS traversal.

Whenever we find a node where:

```cpp
root->left == nullptr && root->right == nullptr
```

it is a leaf node, so we add its value to `ans`.

Since DFS visits the left subtree before the right subtree, the leaf values are stored from **left to right**.

### Step 2: Compare leaves of `root2`

Traverse `root2` using DFS.

For every leaf node:

* Check whether a corresponding value exists in `ans`.
* Compare the current leaf value with `ans[i]`.
* If they are different, return `false`.
* Otherwise, increment `i`.

### Step 3: Check for extra leaves

After traversing `root2`, check:

```cpp
i == ans.size()
```

This ensures that `root2` does not have fewer or extra leaf nodes.

---

## Code

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool leaf(TreeNode* root, vector<int>& ans, int& i) {
        if (root == nullptr) {
            return true;
        }

        // Current node is a leaf
        if (root->left == nullptr && root->right == nullptr) {

            // No corresponding leaf or values don't match
            if (i >= ans.size() || ans[i] != root->val) {
                return false;
            }

            i++;
            return true;
        }

        return leaf(root->left, ans, i) &&
               leaf(root->right, ans, i);
    }

    void solve(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        // Store leaf value
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->val);
        }

        solve(root->left, ans);
        solve(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;

        // Store leaf sequence of root1
        solve(root1, ans);

        int i = 0;

        // Compare leaf sequence of root2
        if (!leaf(root2, ans, i)) {
            return false;
        }

        // Make sure root2 has no extra leaves
        return i == ans.size();
    }
};
```

---

## Complexity Analysis

Let:

* `n` = number of nodes in `root1`
* `m` = number of nodes in `root2`
* `L` = number of leaf nodes in `root1`
* `h` = height of the tree

### Time Complexity

```text
O(n + m)
```

We traverse both trees once.

### Space Complexity

```text
O(L + h)
```

* `O(L)` for storing the leaf values of `root1`.
* `O(h)` for the recursion stack.

---

## Dry Run

Consider:

```text
root1 leaf sequence = [6, 7, 4, 9]
root2 leaf sequence = [6, 7, 4, 9]
```

Initially:

```text
ans = [6, 7, 4, 9]
i = 0
```

Now traverse `root2`:

| Leaf | Expected Value | Match | `i` |
| ---- | -------------- | ----- | --- |
| 6    | 6              | ✅     | 1   |
| 7    | 7              | ✅     | 2   |
| 4    | 4              | ✅     | 3   |
| 9    | 9              | ✅     | 4   |

At the end:

```cpp
i == ans.size()
4 == 4
```

Therefore:

```text
Output: true
```

---

## Key Takeaway

The key observation is that we don't need to compare the complete structure of the two binary trees.

We only need to compare their **leaf value sequences from left to right**.

DFS is useful here because it naturally visits the leaf nodes in the required order.

---

## LeetCode

[872. Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/)

**Difficulty:** Easy

**Topics:** Binary Tree, DFS, Recursion
