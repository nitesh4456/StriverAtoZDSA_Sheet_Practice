class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        map<int,int> m;
        // number count
        // (key ) (count)
        int threshold = floor(nums.size()/2);

        for(auto ele : nums){
            if(m.find(ele) != m.end()){//key exist
                m[ele]++;//increment the count of number
                //check if current ele is the required answer
                if(m[ele]>threshold){
                    return ele;
                }
                continue;
            }
            m[ele] = 1; //introduce new key for new ele with 1 count
        }
        return -pow(10,4)-1;

    }
};

/*## Time Complexity: O(n log n)

Your code has O(n log n) time complexity in the worst case, not O(n).

### Why?

- `for (auto ele : nums)` iterates through the array, so it runs at most $n$ times.
- `m.find(ele)` takes O(log k) time because `map` in C++ is typically implemented as a balanced binary search tree.
- `m[ele]++` and `m[ele] = 1` take O(log k) time when accessing or inserting keys, where $k$ is the number of distinct elements.

Therefore, each iteration takes $O(\log k)$, and there are at most $n$ iterations.

$$
T(n)=O(n\log k)
$$

Since $k \le n$, the worst-case time complexity is:

$$
\boxed{O(n\log n)}
$$

## Space Complexity: O(n)

In the worst case, all elements are distinct, so the map stores $n$ keys.

$$
\boxed{S(n)=O(n)}
$$

## Final complexity

| Complexity | Your code |
| --- | --- |
| Best case | $O(1)$ for a single-element array |
| Worst-case time | $O(n\log n)$ |
| Auxiliary space | $O(n)$ |

Note: If you replace `map<int,int>` with `unordered_map<int,int>`, the average time complexity becomes $O(n)$, although its worst-case time complexity can be $O(n^2)$.*/