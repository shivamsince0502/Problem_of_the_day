class Solution {
public:
    int minChar(string str){
        //Write your code here
        int n = str.length();
        int i = 0, j = n-1, cnt = 0, it = n-1;
        while(i < j) {
            if(str[i] == str[j]){
                i++;
                j--;
            }else {
                cnt++;
                j = --it;
                i = 0;
            }
        }
        return cnt;
    }
};
