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
                if(nums.size()<2) return nums;
                vector<int>ans;//max size will go upto 2;
                //candidate 1                   candidate2
                int value1=nums[0],count1=0, value2=nums[1],count2=0;
                for(int i=2; i<nums.size();i++){
                    if(value1==nums[i]){
                        count1++;
                        continue;
                    }
                    else if(value2==nums[i]){
                        count2++;
                        continue;
                    }
                    else if(value1!=nums[i] && value2!=nums[i] && count1>0 && count2>0){
                        count1--;
                        count2--;
                        continue;
                    }
                    else if(value1!=nums[i] && value2!=nums[i] && count1==0 && count2>0){
                        value1=nums[i];
                        count1++;
                        continue;
                    }
                    else if(value1!=nums[i] && value2!=nums[i] && count1>0 && count2==0){
                        value2=nums[i];
                        count2++;
                        continue;
                    }
                    else{
                        cout<<"eroor in approach";
                        return ans;
                    }
                }
                //
                if(count1>0 && count2>0){
                    ans.push_back(value1);
                    ans.push_back(value2);
                    sort(ans.begin(),ans.end());//constant as ans.size()<=2
                    return ans;
                }
                else if(count1>0 && count2==0){
                    ans.push_back(value1);
                    return ans;
                }
                else if(count1==0 && count2>0){
                    ans.push_back(value2);
                    return ans;
                }
                else{
                    return ans;
                }
            }
        //time complexity
            //iteration-- O(N)
        //space complexity
            // O(1)
        //better -- self 
};
int main(){
    vector<int> nums ={1, 2, 1, 1, 3, 2, 2};
    Solution s;
    for(int ele: s.majorityElementTwo(nums)){
        cout<<ele<<", ";
    }
    cout<<endl;

}