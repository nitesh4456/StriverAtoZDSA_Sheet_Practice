#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            //fix i
            //dont chosse same element at i
            while(i>0 && i<nums.size() && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            //2 pointer approach
            int j= i+1, k = nums.size()-1;
            while(j<k){
                //select all the possible combinations
                int sum=nums[i]+nums[j]+nums[k];
                if(sum < 0){
                    //increase;
                    j++;
                    continue;
                }else if(sum>0){
                    //decrease;
                    k--;
                    continue;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    //since sorted ans then it will be duplicate prevented already
                    j++;
                    k--;
                    //change j and k element wise
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                        continue;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                        continue;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={-2,0,-2,-1,2,-1,0,-2,0,2,-1,2,2};
    vector<vector<int>>ans= s.threeSum(nums);
    for(auto ele: ans){
        cout<<"[";
        for(auto element: ele){
            cout<<element<<", ";
        }
        cout<<"]\n";
    }

}