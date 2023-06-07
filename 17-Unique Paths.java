import java.util.* ;
import java.io.*; 
public class Solution {
	public static int uniquePaths(int m, int n) {
		int dx[] = new int[]{-1,1,0};
		int dy[] = new int[]{0,0,-1};
		int [][] vis = new int [m][n];
		for(int i=0;i<m;i++){
			Arrays.fill(vis[i],0);
		}
		vis[0][0] = 1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(vis[i][j]==0){
					for(int k=0;k<3;k++){
						int nx = dx[k] + i;
						int ny = dy[k] + j;
						if(nx>=0 && nx<m && ny>=0 && ny<n){
							vis[i][j] += vis[nx][ny];
						}
					}
				}
			}
		}
		return vis[m-1][n-1];
	}
}