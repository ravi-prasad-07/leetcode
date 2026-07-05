# 36. Valid Sudoku

## Intuition

To determine whether a Sudoku board is valid, we need to ensure that:

1. Each **row** contains unique digits (`1-9`).
2. Each **column** contains unique digits.
3. Each **3×3 sub-box** contains unique digits.

Since we only need to validate the current board (not solve it), we can keep track of the digits we've already seen using hash sets.

---

## Approach

* Create three arrays of hash sets:

  * `rows[9]` → stores digits seen in each row.
  * `cols[9]` → stores digits seen in each column.
  * `sqr[9]` → stores digits seen in each 3×3 box.
* Traverse every cell in the board.
* If the current cell contains `'.'`, skip it.
* Compute the corresponding 3×3 box index using:

```cpp
box = (i / 3) * 3 + (j / 3);
```

* Before inserting the digit:

  * Check if it already exists in the current row, column, or box.
  * If yes, the board is invalid, so return `false`.
* Otherwise, insert the digit into all three sets.
* If the traversal completes without finding duplicates, return `true`.

---

## Time Complexity

* We visit each cell exactly once.

**Time Complexity:** **O(81) = O(1)**

(Sudoku board size is fixed at 9×9.)

---

## Space Complexity

We use:

* 9 row sets
* 9 column sets
* 9 box sets

Each set can contain at most 9 digits.

**Space Complexity:** **O(81) = O(1)**

---

## Code

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> sqr(9);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {
                    continue;
                }

                int box = (i / 3) * 3 + (j / 3);

                if(rows[i].count(board[i][j]) ||
                   cols[j].count(board[i][j]) ||
                   sqr[box].count(board[i][j])) {
                    return false;
                }

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                sqr[box].insert(board[i][j]);
            }
        }

        return true;
    }
};
```

---

# Dry Run

### Input

```text
5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .
----------------------
8 . . | . 6 . | . . 3
4 . . | 8 . 3 | . . 1
7 . . | . 2 . | . . 6
----------------------
. 6 . | . . . | 2 8 .
. . . | 4 1 9 | . . 5
. . . | . 8 . | . 7 9
```

### Traversal

* Cell `(0,0)` → `'5'`

  * Row 0: not present
  * Column 0: not present
  * Box 0: not present
  * Insert `'5'`.

* Cell `(0,1)` → `'3'`

  * Not found in row, column, or box.
  * Insert `'3'`.

* Cell `(0,2)` → `'.'`

  * Skip.

* Cell `(1,0)` → `'6'`

  * Not found in Row 1, Column 0, or Box 0.
  * Insert `'6'`.

* Continue similarly for every filled cell.

If at any point a digit is already present in:

* the same row,
* the same column, or
* the same 3×3 box,

the function immediately returns **`false`**.

Since no duplicates are found in this example, the traversal completes successfully and returns:

```text
true
```

This validates that the Sudoku board satisfies all row, column, and 3×3 sub-box constraints.
