import java.util.ArrayList;
public class Solution {
    static boolean searchMatrix(ArrayList<ArrayList<Integer>> mat, int target) {
        int n = mat.size();
        int m = mat.get(0).size();
        int lo = 0;
        int hi = (n*m) - 1;
        while(lo<=hi){
            int mid = (lo + (hi-lo)/2);
            if(mat.get(mid/m).get(mid%m)==target) return true;
            else if(mat.get(mid/m).get(mid%m)<target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return false;
    }
}
