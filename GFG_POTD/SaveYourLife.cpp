class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here   
          unordered_map<char, int> map;
          
          for(int i = 0;i < n; i++){
              map[x[i]] = b[i];
          }
          int sum = 0, ans = INT_MIN, prevSum = 0;
          string ansStr = "", currStr = "", prevStr = "";
         
          for(int i = 0; i < w.length(); i++) {
              char it = w[i];
              if(map.find(it) != map.end()) {
                  sum += map[it];
                //   cout<<it<<" : "<<map[it]<<endl;
              }else {
                  sum += int(it);
                //   cout<<it<<" : "<<int(it)<<endl;
              }
              
              currStr += it; 
              
              if(sum > ans) {
                      ans = sum;
                      ansStr = currStr;
                  }
                 if(sum <= 0) {
                  sum = 0;
                  currStr = "";
              }
            //   cout<<ans<<" "<<ansStr<<endl;
          }
          return ansStr;
      }
};
