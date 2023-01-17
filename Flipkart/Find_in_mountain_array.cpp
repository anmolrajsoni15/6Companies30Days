#include<bits/stdc++.h>
using namespace std;


class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
    int binarySearch(int target, MountainArray &arr, int l, int r, bool isSorted = true){
        while(l<=r){
            int m = (l+r)/2;
            auto val = arr.get(m);
            if(val == target)   return m;
            if(target > val == isSorted)
                l = m+1;
            else    r = m-1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &arr) {
        auto pk = 0, bs = arr.length()-1;
        while(pk < bs){
            int m = (pk+bs)/2;
            if(arr.get(m) > arr.get(m+1))
                bs = m;
            else pk = m+1;
        }

        auto ans = binarySearch(target, arr, 0, pk);
        
        if(ans == -1)
            ans = binarySearch(target, arr, pk+1, arr.length()-1, false);

        return ans;
    }
};