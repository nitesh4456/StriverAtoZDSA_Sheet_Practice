class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        unordered_map<int,int> m;
        // number count
        // (key ) (count)
        int threshold = nums.size()/2;

        for(auto ele : nums){
            m[ele]++;//increment the count of number (store 0 and increment to 1 when key does not exist)
            //check if current ele is the required answer
            if(m[ele]>threshold){
                return ele;
            }
        }
        return -pow(10,4)-1;

    }
};

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        unordered_map<int,int> m;
        // number count
        // (key ) (count)
        int threshold = nums.size()/2;

        for(auto ele : nums){
            m[ele]++;//increment the count of number (store 0 and increment to 1 when key does not exist)
            //check if current ele is the required answer
            if(m[ele]>threshold){
                return ele;
            }
        }
        return -pow(10,4)-1;

    }
};

/*## Time Complexity

Average case: $O(n)$

- The loop iterates through the array at most $n$ times.
- `m.find(ele)` takes $O(1)$ average time with `unordered_map`.
- `m[ele]++` and `m[ele] = 1` take $O(1)$ average time.
- The loop may return early if the majority element is found.

Therefore,

$$
\boxed{T(n)=O(n)\text{ average case}}
$$

Worst case: $O(n^2)$, due to potential hash collisions in `unordered_map`.

## Space Complexity

In the worst case, the map stores up to $n$ distinct elements.

$$
\boxed{S(n)=O(n)}
$$

## Final answer

| Complexity | Result |
| --- | --- |
| Average-case time | $O(n)$ |
| Worst-case time | $O(n^2)$ |
| Auxiliary space | $O(n)$ |

Small improvement: You can simplify your loop by incrementing the frequency directly:

cpp
```
for (int ele : nums) {
    m[ele]++;
    if (m[ele] > threshold) {
        return ele;
    }
}
```

This works because `m[ele]` automatically initializes a new key to `0` before incrementing it. The complexity remains the same.*/