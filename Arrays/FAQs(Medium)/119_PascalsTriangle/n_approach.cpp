#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int  get_pascals_value(int rowIndex, int columnIndex){
        if(columnIndex == 0){
            return 1;
        }else if(rowIndex == columnIndex){
            return 1;
        }
        else{
            Solution s;
            return s.get_pascals_value(rowIndex-1,columnIndex -1) + s.get_pascals_value(rowIndex-1,columnIndex);
        }
    }
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1,1);
        Solution s;
        for(int columnIndex =1; columnIndex<rowIndex; columnIndex++){
            row[columnIndex] = s.get_pascals_value(rowIndex,columnIndex);
        }
        return row;
    }

    //time complexity -- O(2^rowIndex)
};

int main(){
    int rowIndex;
    cout<<"Enter rowIndex : ";
    cin >>rowIndex;
    cout<<endl;
    Solution s;
    vector<int> ans=s.getRow(rowIndex);
    for(auto ele: ans){
        cout<<ele<<", ";
    }
    cout<<endl;
}
