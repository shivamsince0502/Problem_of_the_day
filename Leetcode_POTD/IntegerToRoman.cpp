class Solution {
public:
    string intToRoman(int num) {
        
        int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string ans="";
        
        for(int i=0;num;i++) // loop till num exists
        {
            while(num>= val[i])
            {
                ans+=roman[i]; // adding required roman numeral code for digit
                
                num-=val[i]; // subtracting CONCATENATED roman numeral code value from original num 
            }
        }
        
    return ans;
    }
};
