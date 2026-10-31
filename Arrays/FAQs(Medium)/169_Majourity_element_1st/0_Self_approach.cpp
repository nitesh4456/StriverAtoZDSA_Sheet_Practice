class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        // (key ) (count)

        for(auto ele : nums){
            if(m.find(ele) != m.end()){
                //key exist;
                m[ele]++;//increment the count of number
                continue;
            }
            else{
                //key does not exist;
                m[ele] = 1; //add count of number
            }
        }

        for( auto mObject : m){
            if(mObject.second > nums.size()/2 ) return mObject.first;
            //  count of number > n/2                        number
        }
        return -pow(10,4)-1;

        //time complexity --- o(2n) -- o(n) 
        //space complexity --- o(2n) -- o(n)
    }
};