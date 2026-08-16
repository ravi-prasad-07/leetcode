### Intuition

For every drone:

1. Calculate Manhattan distance from the drone to the target:
   [
   |x_1-x_2| + |y_1-y_2|
   ]
2. The drone is eligible only if:

   ```cpp
   distance <= drones[i][2]
   ```
3. Among all eligible drones, keep the one with the minimum distance.
4. If no drone can reach the target, return `-1`.

### One small improvement

You don't need both:

```cpp
mn = min(mn, cal);
```

because you've already checked:

```cpp
mn > cal
```

So simply:

```cpp
mn = cal;
```

Also, initialize `ans = -1` to make it safer.

### Clean LeetCode Solution

```cpp
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mn = INT_MAX;
        int ans = -1;

        for (int i = 0; i < drones.size(); i++) {
            int dist = abs(drones[i][0] - target[0]) +
                       abs(drones[i][1] - target[1]);

            // Drone can reach the target
            if (dist <= drones[i][2] && dist < mn) {
                mn = dist;
                ans = i;
            }
        }

        return ans;
    }
};
```

### Time Complexity

There are `n` drones and we check each exactly once.

**Time:** `O(n)`

### Space Complexity

We only use a few variables.

**Space:** `O(1)`

### Dry Run

Suppose:

```text
drones = [[1,2,3], [5,5,2], [3,3,5]]
target = [3,2]
```

| Drone     | Distance | Range | Can reach? | Best    |
| --------- | -------: | ----: | ---------- | ------- |
| `[1,2,3]` |      `2` |   `3` | Yes        | Drone 0 |
| `[5,5,2]` |      `5` |   `2` | No         | Drone 0 |
| `[3,3,5]` |      `1` |   `5` | Yes        | Drone 2 |

So:

```text
answer = 2
```

**Note:** If two drones have the same minimum distance, your code keeps the **first** one because of `dist < mn`.
