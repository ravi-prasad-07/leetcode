/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i]!=nullptr){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode dummy(-1);
        ListNode* res=&dummy;

        while(!pq.empty()){
            int num=pq.top().first;
            ListNode* temp=pq.top().second;
            pq.pop();

            res->next=new ListNode(num);
            res=res->next;

            if(temp->next!=nullptr){
                pq.push({temp->next->val, temp->next});
            }
        }

        return dummy.next;

    }
};

/*## Intuition

Each of the `k` linked lists is already sorted. At any point, the smallest element among all lists must be one of the current head nodes of those lists.

A **min-heap (priority queue)** is ideal for efficiently retrieving the smallest node. Initially, we insert the head of every non-empty list into the heap. Then, we repeatedly:

1. Extract the smallest node.
2. Add its value to the result list.
3. Insert the next node from the same linked list into the heap (if it exists).

This process continues until the heap becomes empty, ensuring the merged list remains sorted.

---

## Approach

1. Create a **min-heap** that stores `{node value, node pointer}`.
2. Insert the head node of every non-empty linked list into the heap.
3. Create a dummy node to simplify building the merged list.
4. While the heap is not empty:

   * Remove the smallest node from the heap.
   * Create a new node with that value and attach it to the result list.
   * If the extracted node has a next node, push it into the heap.
5. Return `dummy.next` as the head of the merged sorted list.

---

## Dry Run

### Input

```text
lists = [[1,4,5], [1,3,4], [2,6]]
```

### Initial Heap

```text
(1,List1), (1,List2), (2,List3)
```

### Step 1

Pop:

```text
1 (List1)
```

Result:

```text
1
```

Push next node from List1:

```text
4
```

Heap:

```text
1, 2, 4
```

---

### Step 2

Pop:

```text
1 (List2)
```

Result:

```text
1 -> 1
```

Push:

```text
3
```

Heap:

```text
2, 3, 4
```

---

### Step 3

Pop:

```text
2 (List3)
```

Result:

```text
1 -> 1 -> 2
```

Push:

```text
6
```

Heap:

```text
3, 4, 6
```

---

### Step 4

Pop:

```text
3
```

Result:

```text
1 -> 1 -> 2 -> 3
```

Push:

```text
4
```

Heap:

```text
4, 4, 6
```

---

### Step 5

Pop:

```text
4 (List1)
```

Result:

```text
1 -> 1 -> 2 -> 3 -> 4
```

Push:

```text
5
```

Heap:

```text
4, 5, 6
```

---

### Step 6

Pop:

```text
4 (List2)
```

Result:

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4
```

List2 ends.

Heap:

```text
5, 6
```

---

### Step 7

Pop:

```text
5
```

Result:

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5
```

List1 ends.

Heap:

```text
6
```

---

### Step 8

Pop:

```text
6
```

Result:

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
```

Heap becomes empty.

**Final Answer**

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
```

---

## Complexity

**Time Complexity:** `O(N log k)`

* `N` = Total number of nodes across all linked lists.
* `k` = Number of linked lists.

Each node is inserted into and removed from the priority queue exactly once, and each heap operation takes `O(log k)` time.

**Space Complexity:** `O(k)`*/

* The priority queue stores at most one node from each linked list at any time, so it contains at most `k` elements.
* (Your implementation also allocates `N` new nodes for the output list. This is part of the output itself and is typically not counted as auxiliary space.)

---
