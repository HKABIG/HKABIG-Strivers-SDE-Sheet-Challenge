import java.io.*;
import java.util.* ;

import java.util.ArrayList;

public class Solution {
	public static int subarraysXor(ArrayList<Integer> arr, int x) {

		// Brute Force O(N^2)
		// int n = arr.size();
		// int count = 0;
		// for(int i=0;i<n;i++){
		// 	int xorSum = 0;
		// 	for(int j=i;j<n;j++){
		// 		xorSum = xorSum^arr.get(j);
		// 		if(xorSum==x){
		// 			count++;
		// 		}
		// 	}
		// }
		// return count;

		// Optimal Approach O(N) SC: O(N)
		HashMap<Integer,Integer> map = new HashMap<>();
		int n = arr.size();
		int xor = 0;
		int count = 0;
		map.put(0,1);
		for(int i=0;i<n;i++){
			xor ^= arr.get(i);
			int k = xor^x;
			if(map.containsKey(k)) count+= map.get(k);
			map.put(xor,map.getOrDefault(xor, 0)+1);
		}
		return count;
	}
}