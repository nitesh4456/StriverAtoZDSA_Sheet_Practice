#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    
    vector<int> getRow(int rowIndex) {//update the same vector to many times;
        vector<int> row(rowIndex+1,0);
        row[0]=1;
        for(int i=0 ;i<=rowIndex; i++){
            int temp1 = row[0];
            for(int curr=1; curr<=i; curr++){
                int temp2 = row[curr];
                row[curr]=temp1+temp2;
                temp1=temp2;
            }
        }
    }
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
