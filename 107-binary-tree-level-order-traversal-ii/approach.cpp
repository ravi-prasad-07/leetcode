/*## LeetCode — Binary Tree Level Order Traversal II

### Intuition

Normally, **Level Order Traversal** visits a binary tree from **top to bottom** using **BFS (Breadth-First Search)**.

Here, we need the levels in the **reverse order**, i.e. from **bottom to top**.

So the idea is simple:

1. Use a **queue** to perform normal BFS.
2. For every level:

   * Store the number of nodes currently in the queue.
   * Process exactly those nodes.
   * Store their values in a temporary vector.
   * Add their children to the queue for the next level.
3. Store every level in `ans`.
4. Finally, use `reverse()` to reverse the order of the levels.

For example:

```text
        3
       / \
      9   20
         /  \
        15   7
```

Normal BFS gives:

```text
[[3],
 [9,20],
 [15,7]]
```

After reversing:

```text
[[15,7],
 [9,20],
 [3]]
```

---

### Approach

We use a queue because BFS naturally processes the tree **level by level**.

```cpp
int n = q.size();
```

This is important because `n` tells us how many nodes belong to the **current level**.

Then we process exactly `n` nodes:

```cpp
for(int i = 0; i < n; i++)
```

For each node:

* Remove it from the queue.
* Add its value to the current level.
* Push its left and right children into the queue.

After processing the complete level, add it to `ans`.

At the end:

```cpp
reverse(ans.begin(), ans.end());
```

converts the top-to-bottom result into bottom-to-top order.

---

### Code

```cpp*/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        // If the tree is empty, return an empty answer.
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> ans;

        // Queue is used for BFS (level-order traversal).
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            // Number of nodes in the current level.
            int n = q.size();

            vector<int> temp;

            // Process all nodes of the current level.
            for(int i = 0; i < n; i++){

                TreeNode* help = q.front();
                q.pop();

                // Store current node's value.
                temp.push_back(help->val);

                // Add children for the next level.
                if(help->left){
                    q.push(help->left);
                }

                if(help->right){
                    q.push(help->right);
                }
            }

            // Store the current level.
            ans.push_back(temp);
        }

        // BFS generated levels from top to bottom,
        // so reverse them to get bottom-to-top order.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```
/*
### Complexity

Let **N** be the number of nodes in the tree.

* **Time Complexity:** `O(N)`

  * Every node is pushed into and removed from the queue once.
  * `reverse()` takes `O(number of levels)`, which is at most `O(N)`.

* **Space Complexity:** `O(N)`

  * The queue can contain up to `O(N)` nodes.
  * `ans` also stores all `N` node values.

---

## Dry Run

Consider:

```text
        3
       / \
      9   20
         /  \
        15   7
```

### Initial

```text
q = [3]
ans = []
```

### Level 1

`n = 1`

Process `3`:

```text
temp = [3]
q = [9, 20]
```

Add:

```text
ans = [[3]]
```

---

### Level 2

`n = 2`

Process `9`:

```text
temp = [9]
```

Process `20`:

```text
temp = [9, 20]
```

Children of `20` are added:

```text
q = [15, 7]
```

Now:

```text
ans = [[3], [9,20]]
```

---

### Level 3

`n = 2`

Process `15` and `7`:

```text
temp = [15, 7]
q = []
```

So:

```text
ans = [[3], [9,20], [15,7]]
```

---

### Reverse

```cpp
reverse(ans.begin(), ans.end());
```

Result:

```text
[[15,7],
 [9,20],
 [3]]
```*/
