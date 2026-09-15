# Diameter of Binary Tree

## 🧩 Problem

Given the root of a binary tree, return the **length of the diameter of the tree**.

The **diameter** of a binary tree is the length of the longest path between any two nodes. The path may or may not pass through the root.

> The length of a path is measured by the **number of edges** between the nodes.

---

## 💡 Intuition

For every node, the longest path passing through that node is:

```text
height(left subtree) + height(right subtree)
```

So, while calculating the height of each node, we can also calculate the diameter passing through that node.

The recursive function:

* Returns the **height** of the current subtree.
* Updates the global `ans` with the maximum diameter found so far.

For every node:

```cpp
diameter = leftHeight + rightHeight
```

and its height is:

```cpp
height = 1 + max(leftHeight, rightHeight)
```

This allows us to calculate both height and diameter in a **single traversal**.

---

## 🚀 Approach

1. If the current node is `nullptr`, return `0`.
2. Recursively find the height of the left subtree.
3. Recursively find the height of the right subtree.
4. Calculate the diameter passing through the current node:

   ```cpp
   left + right
   ```
5. Update the global maximum:

   ```cpp
   ans = max(ans, left + right);
   ```
6. Return the height of the current subtree:

   ```cpp
   1 + max(left, right)
   ```

---

## 💻 C++ Solution

```cpp
class Solution {
public:

    int ans = 0;

    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        // Diameter passing through current node
        ans = max(ans, left + right);

        // Height of current subtree
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;

        solve(root);

        return ans;
    }
};
```

---

## 🧪 Dry Run

Consider the following tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

### Node 4

```text
left = 0
right = 0

diameter = 0 + 0 = 0
height = 1
```

### Node 5

```text
left = 0
right = 0

diameter = 0
height = 1
```

### Node 2

```text
left = 1
right = 1

diameter = 1 + 1 = 2
height = 1 + max(1, 1) = 2
```

So far:

```text
ans = 2
```

### Node 3

```text
left = 0
right = 0

diameter = 0
height = 1
```

### Node 1

```text
left = 2
right = 1

diameter = 2 + 1 = 3
height = 1 + max(2, 1) = 3
```

Therefore:

```text
ans = 3
```

The longest path is:

```text
4 → 2 → 1 → 3
```

which contains **3 edges**.

---

## ⏱️ Complexity Analysis

### Time Complexity

```text
O(N)
```

Each node is visited exactly once.

### Space Complexity

```text
O(H)
```

where `H` is the height of the binary tree because of the recursive call stack.

* Balanced tree: `O(log N)`
* Skewed tree: `O(N)`

---

## ✅ Key Takeaway

The important idea is to calculate the **height and diameter simultaneously**.

```text
Height   = 1 + max(left, right)
Diameter = left + right
```

This avoids repeatedly calculating subtree heights and gives an optimal **O(N)** solution.
