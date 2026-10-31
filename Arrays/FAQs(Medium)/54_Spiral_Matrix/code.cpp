#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()|| matrix[0].empty()){
            return ans;
        }

        int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        
        while(top<=bottom && left<=right){
        if(top<=bottom){
            // [top][left] --> [top][right]
            for(int i =left; i<=right; i++){
            ans.push_back(matrix[top][i]);
            }
            top++;
        }
        if(left<=right){
        //[top][right]  -->[bottom][right]
        for(int i=top; i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        }
        if(left<<right){
        //[bottom][right]  --> [botom][left]
        for(int i= right; i>=left; i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        if(top<=bottom){
        //[bottom][left] --> [top][left]
        for(int i=bottom; i>=top; i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution s;
    vector<int> ans = s.spiralOrder(matrix);
    for(auto ele: ans){
        cout<<ele<<", ";
    }
    cout<<endl;
}