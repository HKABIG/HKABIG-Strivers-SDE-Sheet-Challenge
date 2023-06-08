import java.io.*;
import java.util.* ;

public class Solution {
    public static int lengthOfLongestConsecutiveSequence(int[] nums, int n) {
        // Brute Force O(NLog(N))+O(N)
        // Arrays.sort(arr);
        // int prev = arr[0];
        // int mx = 1;
        // int c = 1;
        // for(int i=1;i<n;i++){
        //     if(arr[i]==prev+1){
        //         c++;
        //     }
        //     else if(arr[i]!=prev){// Checking for the duplicate elements
        //         c = 1;
        //     }
        //     prev = arr[i];
        //     mx = Math.max(mx,c);
        // }
        // return mx;

        // Optimal Approach O(N)
        Set < Integer > hashSet = new HashSet < Integer > ();
        for (int num: nums) {
            hashSet.add(num);
        }

        int longestStreak = 0;

        for (int num: nums) {
            if (!hashSet.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (hashSet.contains(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}