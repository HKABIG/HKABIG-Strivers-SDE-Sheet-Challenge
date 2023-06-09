import java.util.* ;
import java.io.*; 
public class Solution 
{
	public static int uniqueSubstrings(String input) 
    {
		// First Optimal TC:O(2*N) SC:O(N)
		// HashSet<Character> set = new HashSet<>();
		// int maxLen = 0;
		// int l = 0;
		// for(int r=0;r<input.length();r++){
		// 	if(set.contains(input.charAt(r))){
		// 		while(l<r && set.contains(input.charAt(r))){
		// 			set.remove(input.charAt(l));
		// 			l++;
		// 		}
		// 	}
		// 	set.add(input.charAt(r));
		// 	maxLen = Math.max(maxLen,r-l+1);
		// }
		// return maxLen;

		// Second Optimal TC:O(N) SC:O(N)
		int left = 0,right = 0;
		int n = input.length();
		int maxLen = 0;
		int [] map = new int[256];
		Arrays.fill(map,-1);
		while(right<n){
			if(map[input.charAt(right)]!=-1){
				left = Math.max(map[input.charAt(right)]+1,left);
			}
			map[input.charAt(right)] = right;

			maxLen = Math.max(maxLen,right-left+1);
			right++;
		}
		return maxLen;
	}
}
