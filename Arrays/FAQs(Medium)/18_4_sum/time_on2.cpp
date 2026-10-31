#include<vector>
#include<iostream>
#include<utility>
#include<cmath>
#include<map>
#include<unordered_set>
#include<algorithm>
#include<set>
using namespace std;

class Solution{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target){
            set<vector<int>> ans_set;
            vector<pair<int,int>>single_need;
            single_need.reserve(nums.size());
            for(int i=0 ; i<nums.size();i++){
                pair<int,int> temp(i,nums[i]);
                // temp.first = i;
                // temp.second =nums[i]);
                single_need.push_back(temp);
            }
            //display
            for(auto ele: single_need){
                cout<<"[";
                cout<<ele.first<<", "<<ele.second;
                cout<<"]"<<endl;
            }
            //
            map<int,vector<pair<int,int>>> double_need;
            // need , vector<pairs(2)>
            for(int i=0 ; i<single_need.size();i++){
                for(int j=i+1 ; j<single_need.size();j++){
                    pair<int,int> temp2(single_need[i].first,single_need[j].first);//indexes
                    double_need[single_need[i].second+single_need[j].second].push_back(temp2);//sum of nums[i],nums[j]; OR sum of nums[k] , nums[l]
                }
            }
            for (const auto& [key, vec] : double_need) {
                cout << key << " -> ";
                for (const auto& [a, b] : vec) {
                    cout << "(" << a << ", " << b << ") ";
                }
                cout << "\n";
            }
            //

            ///answer forming
            for(auto [key,vec1]:double_need){
                // b = target - a 
                // a = nums[i] + nums[j]
                // b = nums[k] + nums[l]
                if(double_need.find(target-key)==double_need.end()) continue;
                vector<pair<int,int>> vec2 = double_need[target-key];

                for(auto ele: vec1){
                    for(auto element: vec2){
                        //make sure that i!=j!=k!=l;
                        vector<int> vec_indexes={ele.first,ele.second,element.first,element.second};
                        unordered_set<int> set_indexes(vec_indexes.begin(),vec_indexes.end());
                        if(set_indexes.size()!=4) continue;
                        vector<int> temp3(4,0);
                        for(int i=0 ; i<vec_indexes.size();i++){
                            temp3[i]=nums[vec_indexes[i]];
                        }
                        sort(temp3.begin(),temp3.end());
                        ans_set.insert(temp3);
                    }
                }
            }
            vector<vector<int>> ans(ans_set.begin(),ans_set.end());
            //display
            cout<<"\n";
            for(auto ele : ans){
                cout<<"[";
                for(auto element: ele){
                    cout<<element<<", ";
                }
                cout<<"]"<<endl;
            }
            return ans;
        }
};

int main(){
    vector<int>nums={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90};
    int target = 200;
    Solution s;
    s.fourSum(nums,target);
}