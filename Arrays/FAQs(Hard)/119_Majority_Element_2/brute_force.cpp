#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution{
    public:
            vector<int> majorityElementTwo(vector<int>& nums) {
                map<int,int> mp;
                for(int i=0 ; i<nums.size();i++){
                    if(mp.find(nums[i])!=mp.end()){
                        mp[nums[i]]++;
                        continue;
                    }
                    mp[nums[i]]=1;
                }
                int n=nums.size()/3;
                vector<int>ans;
                ans.reserve((n/3)-1);
                    // N/3 -1
                for(auto [key,count]:mp){
                    cout<<key<<": "<<count<<endl;
                    if(count>n) ans.push_back(key);
                }
                return ans;
                //time complexity
                    // map formation for N elements -- O(N*logN) -- each insertio takes O(LogN)
                    //  mp.find -- O(N*logN) -- O(LogN) for lookup in map
                    // find ans from map --- O(no. of unique elements in the nums); -- O(N)
                    // O(NlogN)
                //space complexity 
                    // map -- O(N);
                    //ans -- O(N);
                    //O(N)

            // note:- find better approach 
            //observation :- no. of total ans for any nums of size n is going to be 0 or 1 or 2 only.
            }

};
int main(){
    vector<int> nums ={1, 2, 1, 1, 3, 2, 2};
    Solution s;
    for(int ele: s.majorityElementTwo(nums)){
        cout<<ele<<", ";
    }

}