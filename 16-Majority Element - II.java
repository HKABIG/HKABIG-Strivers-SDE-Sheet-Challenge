import java.io.*;
import java.util.* ;

import java.util.ArrayList;

public class Solution 
{
    public static ArrayList<Integer> majorityElementII(ArrayList<Integer> arr) 
    {
        int n = arr.size();
        int mf = n/3;
        ArrayList<Integer> ans = new ArrayList<>();
		HashMap<Integer,Integer> map = new HashMap<>();
		for(int i=0;i<n;i++){
			map.put(arr.get(i),map.getOrDefault(arr.get(i), 0)+1);
			if(map.get(arr.get(i))>mf){
                if(!ans.contains(arr.get(i))) ans.add(arr.get(i));
            }
		}
		return ans;
    }
}