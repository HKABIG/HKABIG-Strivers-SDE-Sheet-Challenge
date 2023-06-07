import java.io.*;
import java.util.* ;

public class Solution {
  public static String fourSum(int[] arr, int target, int n) {
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          for(int k=j+1;k<n;k++){
            for(int l=k+1;l<n;l++){
              if(arr[i]+arr[j]+arr[k]+arr[l]==target){
                return "Yes";
              }
            }
          }
        }
      }
      return "No";
  }
}

// HashSet<Integer> set = new HashSet<>();
//       for(int i=3;i<n;i++){
//         set.add(arr[i]);
//       }
//       for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//           for(int k=j+1;k<n;k++){
//             int sum = arr[i]+arr[j]+arr[k];
//             int fourth = target-sum;
//             if(set.contains(fourth)){
//               return "Yes";
//             }
//           }
//         }
//       }
//       return "No";

// for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//           HashSet<Integer> set = new HashSet<>();
//           for(int k=j+1;k<n;k++){
//             int sum = arr[i]+arr[j]+arr[k];
//             int fourth = target-sum;
//             if(set.contains(fourth)){
//               return "Yes";
//             }
//             set.add(arr[k]);
//           }
//         }
//       }
//       return "No";
