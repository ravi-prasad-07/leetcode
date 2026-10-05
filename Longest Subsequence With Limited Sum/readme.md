# LeetCode - Answer Queries With Sum of Prefix

## Problem

Given an integer array `nums` and an array of `queries`, for each query find the maximum size of a subsequence of `nums` such that the sum of its elements is less than or equal to the query.

### Example

```text
Input:
nums = [4,5,2,1]
queries = [3,10,21]

Output:
[2,3,4]
```

## Approach

The main idea is to use **Sorting + Prefix Sum + Binary Search**.

### 1. Sort the Array

First, sort `nums` in ascending order.

```text
[4,5,2,1] → [1,2,4,5]
```

Taking the smallest elements gives us the maximum possible number of elements for a given sum.

### 2. Create Prefix Sum

Convert the sorted array into a prefix sum array.

```text
[1,2,4,5]
```

becomes:

```text
[1,3,7,12]
```

Here:

- `1` = sum of first 1 element
- `3` = sum of first 2 elements
- `7` = sum of first 3 elements
- `12` = sum of first 4 elements

### 3. Binary Search

For every query, perform binary search on the prefix sum array.

We need to find the largest prefix sum that is:

```text
<= query
```

If the valid prefix ends at index `mid`, then the number of elements is:

```text
mid + 1
```

## Code

```cpp
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
        }

        for(int i=0; i<queries.size(); i++){
            int l=0,r=nums.size()-1;
            int cnt=0;

            while(l<=r){
                int mid=l+(r-l)/2;

                if(nums[mid]<=queries[i]){
                    cnt=mid+1;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
```

## Dry Run

### Input

```text
nums = [4,5,2,1]
queries = [3,10,7]
```

### After Sorting

```text
[1,2,4,5]
```

### Prefix Sum

```text
[1,3,7,12]
```

### Query = 3

Largest prefix sum `<= 3` is `3`.

```text
[1,3]
```

Number of elements:

```text
2
```

### Query = 10

Largest prefix sum `<= 10` is `7`.

```text
[1,2,4]
```

Number of elements:

```text
3
```

### Query = 7

Largest prefix sum `<= 7` is `7`.

```text
[1,2,4]
```

Number of elements:

```text
3
```

### Final Output

```text
[2,3,3]
```

## Complexity Analysis

Let:

- `n` = number of elements in `nums`
- `m` = number of queries

### Time Complexity

```text
O(n log n + m log n)
```

- Sorting: `O(n log n)`
- Prefix Sum: `O(n)`
- Binary Search for each query: `O(log n)`

### Space Complexity

```text
O(m)
```

The answer vector requires `O(m)` space. The prefix sum is created directly inside `nums`, so no extra array is used.

## Concepts Used

- Sorting
- Prefix Sum
- Binary Search
- Greedy Observation

## LeetCode

**Problem:** Answer Queries With Sum of Prefix

**Difficulty:** Easy

**Language:** C++
