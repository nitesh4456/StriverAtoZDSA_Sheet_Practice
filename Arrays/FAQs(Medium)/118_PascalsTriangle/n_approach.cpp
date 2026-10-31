#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    void display_pascals_tiangle(const vector<vector<int>>& pascalsTriangle){
        cout<<"[";
        for(vector<int> ele : pascalsTriangle){
            cout<<" [";
            for (int element: ele){
                cout<<element<<", ";
            }
            cout<<"], ";
        }
        cout<<"] ";
    } 

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalsTriangle;
        pascalsTriangle.reserve(numRows);
        for(int i=0 ; i<numRows; i++){
            vector<int> row(i+1,1); //initialize the array with 1;
            for(int j =1;j<i;j++){
                row[j] = pascalsTriangle[i-1][j-1]+pascalsTriangle[i-1][j];
            }
            pascalsTriangle.push_back(row);
        }
        return pascalsTriangle;
    }


};

int main(){
    Solution s;
    int numRows =6;
    vector<vector<int>> pascalsTriangle = s.generate(numRows);
    s.display_pascals_tiangle(pascalsTriangle);
}