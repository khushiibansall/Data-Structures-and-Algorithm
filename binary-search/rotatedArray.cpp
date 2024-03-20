//Search In A Rotated Sorted Array in O(log n)
#include <bits/stdc++.h>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
        int lo = 0;
        int hi = A.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == key) return true;
            if(A[lo]==A[mid] && A[mid]==A[hi]){
                lo=lo+1;
                hi=hi-1;
                continue;
            }
           
            if (A[lo] <= A[mid]) {
                if (A[lo] <= key && key <= A[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (A[mid] <= key && key <= A[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    };
