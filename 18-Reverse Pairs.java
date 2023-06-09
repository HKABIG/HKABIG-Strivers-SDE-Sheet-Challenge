import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution 
{
    static int Merge(ArrayList<Integer> arr,int low,int mid,int high){
        int total = 0;
        int j = mid + 1;
        for(int i=low;i<=mid;i++){
            while(j<=high && arr.get(i)>2*arr.get(j)){
                j++;
            }
            total += (j-(mid+1));
        }
        ArrayList<Integer> t = new ArrayList<>();
        int left = low;int right = mid + 1;
        while(left<=mid && right<=high){
            if(arr.get(left)<=arr.get(right)){
                t.add(arr.get(left));
                left++;
            }
            else{
                t.add(arr.get(right));
                right++;
            }
        }
        while(left<=mid){
            t.add(arr.get(left));
            left++;
        }
        while(right<=high){
            t.add(arr.get(right));
            right++;
        }
        for(int i=low;i<=high;i++){
            arr.set(i, t.get(i - low));
        }
        return total;
    }
    static int MergeSort(ArrayList<Integer> arr,int low,int high){
        if(low>=high) return 0;
        int mid = (low + (high-low)/2);
        int inv = MergeSort(arr, low, mid);
        inv += MergeSort(arr, mid+1, high);
        inv += Merge(arr,low,mid,high);
        return inv;
    }
    public static int reversePairs(ArrayList<Integer> arr) 
    {
        // Brute Force TC:O(N^2) SC:O(1)
        // int n = arr.size();
        // int count = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr.get(i)>2*arr.get(j)){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // Optimal Approach Using Count Inversions TC:(ON(LOG(N))) SC:O(N)
        return MergeSort(arr,0,arr.size()-1);
    }
}