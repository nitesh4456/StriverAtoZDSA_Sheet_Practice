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
        //optimal using voting of 2 candiadates;
            vector<int> majorityElementTwo(vector<int>& nums) {
                if(nums.size()<2) return nums;
                vector<int>ans;
                if(nums.size()==2 && nums[0]==nums[1]){
                    ans.push_back(nums[0]);
                    return ans;
                }
                //candidate 1                   candidate2
                int value1=INT_MIN, count1=0,           value2=INT_MIN, count2=0; 

                for(auto ele : nums){
                    if(count1>0 && count2>0){
                        if(ele==value1){
                            count1++;
                            continue;
                        }
                        else if(ele==value2){
                            count2++;
                            continue;
                        }
                        else{
                            count1--;
                            count2--;
                            //check
                            if(count1==0) value1=INT_MIN;
                            if(count2==0) value2=INT_MIN;
                            //
                            continue;
                        }
                    }
                    else if(count1==0 && count2==0){
                        value1=ele;
                        count1++;
                        continue;
                    }
                    else if(count1>0 && count2==0){
                        if(ele==value1){
                            count1++;
                            continue;
                        }else{
                            value2=ele;
                            count2++;
                            continue;
                        }
                    }
                    else if(count1==0 && count2>0){
                        if(ele==value2){
                            count2++;
                            continue;
                        }else{
                            value1=ele;
                            count1++;
                            continue;
                        }
                    }else{
                        cout<<"wrong path of iteratin taken approach";
                        return ans;
                    }
                }

                //verification
                count1=0,count2=0;
                for(auto ele: nums){
                    if(ele == value1 &&ele != value2){
                        count1++;
                        continue;
                    }else if(ele == value2 && ele!=value1){
                        count2++;
                        continue;
                    }else{
                        continue;
                    }
                }
                //
                if(count1>(int)(nums.size()/3)) ans.push_back(value1);
                if(count2>(int)(nums.size()/3)) ans.push_back(value2);
                //
                return ans;
            }
        //time complexity
            //iteration-- O(N) +(ON)
            //O(N)
        //space complexity
            // O(1)
        //better -- self 
};
int main(){
    // vector<int> nums ={4,1,2,3,4,4,3,2,1,4};
    vector<int> nums ={1,2};
    Solution s;
    for(int ele: s.majorityElementTwo(nums)){
        cout<<ele<<", ";
    }
    cout<<endl;

}