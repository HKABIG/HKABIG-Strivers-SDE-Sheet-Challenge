
string help(string s,int st,int en){
    int n = s.length();
    while(st>=0 && en<n){
        if(s[st]==s[en]){
            st--;
            en++;
        }
        else break;
    }
    return s.substr(st+1,en-st-1);
}

string longestPalinSubstring(string str){
    int n = str.length();
    string ans = "";
    int maxLen = 0;
    for(int i=0;i<n;i++){
        string curr = help(str,i,i);// Odd Length
        if(maxLen<curr.length()){
            maxLen = curr.length();
            ans = curr;
        }
        curr = help(str,i,i+1);
        if(maxLen<curr.length()){
            maxLen = curr.length();
            ans = curr;
        }
    }
    return ans;
}