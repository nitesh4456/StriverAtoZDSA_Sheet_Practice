#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution{
    public:
        //brute force 
        // O(N2)
        //better -- using hasing;
            vector<int> majorityElementTwo(vector<int>& nums) {
                map<int,int> mp;
                for(int i=0 ; i<nums.size();i++){
                    if(mp.find(nums[i])!=mp.end()){
                        mp[nums[i]]++;
                        continue;
                    }
                    mp[nums[i]]=1;
                }

                int n=nums.size();
                vector<int>ans;//atmost length will be 2; 
                for(auto [key,count]:mp){
                    if(count>(int)(n/3)) ans.push_back(key);
                }
                return ans;
                //time complexity
                    // iteration -- O(N)+O(N) ==> O(N);
                    //map formation -- O(NLogN)
                    //O(NLogN)
                    // (note:-  unordered_map gives O(1); ut in worst case O(N));
                //space comlexity 
                    //map formation --O(N);
            // note:- find better approach 
            //observation :- no. of total ans for any nums of size n is going to be 0 or 1 or 2 only.
            }
        //better -- self 
        vector<int> majorityElementTwo_usingSort(vector<int>&nums){
            vector<int> ans;
            if(nums.size()==0) return ans;
            sort(nums.begin(),nums.end());
            int count =1, temp = nums[0];
            for(int i=1; i<nums.size();i++){
                if(temp==nums[i]) {
                    count++;
                    continue;
                }
                //check
                if(count>(int)(nums.size()/3)) ans.push_back(temp);
                //
                count =1;
                temp=nums[i];
            }
            return ans;
            //time complexity 
                //sort -- O(NlogN)
                //iteration -- O(N)
                //O(NlogN)
            //space complexity
                //sort -- O(LogN)
            
        }

};
int main(){
    vector<int> nums ={1, 2, 1, 1, 3, 2, 2};
    Solution s;
    for(int ele: s.majorityElementTwo(nums)){
        cout<<ele<<", ";
    }
    cout<<endl;
    for(int ele: s.majorityElementTwo_usingSort(nums)){
        cout<<ele<<", ";
    }

}