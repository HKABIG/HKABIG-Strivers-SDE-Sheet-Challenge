import java.io.*;
import java.util.* ;

public class Solution{
    public static List<int[]> pairSum(int[] arr, int s) {
        int n = arr.length;
        Arrays.sort(arr);
        List<int[]> ans = new ArrayList<>();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((arr[i]+arr[j])==s){
                    ans.add(new int[]{arr[i],arr[j]});
                }
            }
        }
        //Collection.sort(ans);
        return ans;
    }
}
