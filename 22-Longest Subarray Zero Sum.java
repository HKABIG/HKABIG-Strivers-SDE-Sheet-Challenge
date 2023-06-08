import java.io.*;
import java.util.* ;

import java.util.ArrayList;

public class Solution {

	public static int LongestSubsetWithZeroSum(ArrayList<Integer> arr) {
		// Brute Force
		// int n = arr.size();
		// int mx = 0;
		// for(int i=0;i<n;i++){
		// 	int curSum = 0;
		// 	for(int j=i;j<n;j++){
		// 		curSum += arr.get(j);
		// 		if(curSum==0){
		// 			mx = Math.max(mx,j-i+1);
		// 		}
		// 	}
		// }
		// return mx;

		// Optimal Approach
        HashMap<Integer,Integer> map = new HashMap<Integer, Integer>();
        int maxLen = 0;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr.get(i);
            if(sum==0) maxLen = i + 1;
            if(map.containsKey(sum)) maxLen = Math.max(maxLen,i-map.get(sum));
            else map.put(sum, i);
        }
        return maxLen;
	}
}
