#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target){
            vector<vector<int>>ans;
            //nums[i],nums[j],nums[l],nums[r];
            sort(nums.begin(),nums.end());//introsort O(NlogN)
            for(int i=0 ; i<nums.size();i++){
                if(i>0 && nums[i]==nums[i-1]) continue;
                //fix i
                for(int j=i+1; j<nums.size();j++){
                    if(j>i+1 && nums[j]==nums[j-1])continue;
                    //fix j
                    unordered_set<int> seen_values;
                    int k = j+1;
                    for( int k= j+1; k<nums.size();k++){
                        if(k>j+1 && nums[k]==nums[k-1])continue;
                        int fourthvalue = (long)(target) - ((long)(nums[i])+(long)(nums[j])+(long)(nums[k]));
                        if(seen_values.find(fourthvalue)!=seen_values.end()){
                            //means already seen fourthvalue
                            vector<int> temp ={nums[i],nums[j],nums[k],fourthvalue}; //is a vlaid quadruplets
                            ans.push_back(temp);
                        }
                        seen_values.insert(nums[k]);
                    }
                }
            }
            return ans;
        }
};

int main(){
    vector<int>nums={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
    int target = 200;
    Solution s;
    vector<vector<int>> ans = s.fourSum(nums,target);
    for(auto ele : ans){
        cout<<"[";
        for ( auto element: ele){
            cout<<element<<", ";
        }
        cout<<"]"<<endl;
    }
}