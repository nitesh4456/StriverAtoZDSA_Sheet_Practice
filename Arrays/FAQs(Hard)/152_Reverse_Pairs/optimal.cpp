#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int count=0;//global
    void countReversePairs(vector<int>&nums,int left, int mid, int right){
        //left part // left sorted array /// [left,mid]
        //right part // right sorted array /// [mid+1,right]
        int leftIndex=left, rightIndex=mid+1;
        while(leftIndex<=mid){
            count+=rightIndex-(mid+1);
            while(rightIndex<=right){
                if(nums[leftIndex]>2*nums[rightIndex]){
                    count++;
                    rightIndex++;
                    continue;
                }
                break;
            }
            leftIndex++;
        }
        return;
    }
        //sort left part
        //sort right part
        //return after merge
    void merge(vector<int>&nums,int left,int  mid, int right){
        //left part == left,mid
        //right part == mid+1, right
        vector<int>leftPart, rightPart;
        for(int i=left; i<=mid;i++){
            leftPart.push_back(nums[i]);
        }
        for(int i=mid+1; i<=right;i++){
            rightPart.push_back(nums[i]);
        }
        int leftIndex=0,rightIndex=0,writeIndex=left;
        //sorted merge
        while(leftPart.begin()+leftIndex<leftPart.end() && rightPart.begin()+ rightIndex <rightPart.end()){
            if(leftPart[leftIndex]<=rightPart[rightIndex]) {
                nums[writeIndex]=leftPart[leftIndex];
                leftIndex++;
                writeIndex++;
                continue;
            }else{
                nums[writeIndex]=rightPart[rightIndex];
                rightIndex++;
                writeIndex++;
            }
        }
        while(leftPart.begin()+leftIndex<leftPart.end()){
            nums[writeIndex]=leftPart[leftIndex];
            leftIndex++;
            writeIndex++;
        }
        while(rightPart.begin()+rightIndex<rightPart.end()){
            nums[writeIndex]=rightPart[rightIndex];
            rightIndex++;
            writeIndex++;
        }
        //
        return ;
    }
    void mergersort(vector<int>&nums,int left,int right){
        if(left>=right) return; //if len ==1;
        int mid = left + (right-left)/2;
        mergersort(nums,left,mid);
        mergersort(nums,mid+1,right);
        //
        // count no. of reverse_pairs as currently we have range of i from left to mid, range j from mid+1 to right;
        //we also have two sorted array to compare
        countReversePairs(nums,left,mid,right);
        //
        merge(nums,left,mid,right);
        return;
    }
    
    int reversePairs(vector<int>& nums) {
        Solution s;
        s.mergersort(nums,0,nums.size()-1);
        return s.count;
    }
};

int main(){
    vector<int> nums={6, 4, 1, 2, 7};
    Solution s;
    cout<<s.reversePairs(nums);
    return 0;
}

