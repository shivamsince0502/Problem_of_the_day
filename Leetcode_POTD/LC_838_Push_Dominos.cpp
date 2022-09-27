class Solution {
public:
    vector<pair<char, int>>left, right;
    int n;
    void getLeft(string ch) {
        for(int i = n-1; i >= 0; i--) {
            if(ch[i] == '.') {
                left[i] = make_pair('.', 0);
            }else if(ch[i] == 'L') {
                int j = 1; 
                left[i] = make_pair('L', j);
                while(i-1 >= 0 && ch[i-1] == '.') {
                    j++; i--;
                    left[i] = make_pair('L', j);
                }
            }else if(ch[i] == 'R') {
                left[i] = make_pair('R', 1);
            }       
        }
    }
    void getRight(string ch){
        for(int i = 0; i < n; i++) {
            if(ch[i] == '.') {
                right[i] = make_pair('.', 0);
            }else if(ch[i] == 'R') {
                int j = 1; 
                right[i] = make_pair('R', j);
                while(i+1 < n && ch[i+1] == '.') {
                    j++; i++;
                    right[i] = make_pair('R', j);
                }
            }else if(ch[i] == 'L') {
                right[i] = make_pair('L', 1);
            }       
        }
    }
    string pushDominoes(string ch) {
        n = ch.size();
        pair<char, int>p = make_pair('.', 0);
        left.resize(n, p);
        right.resize(n, p);
        getLeft(ch);
        getRight(ch);
        for(int i = 0; i  < n; i++) {    
            if(left[i].first == right[i].first){
                ch[i] = left[i].first;
            }else {
                if(right[i].first == '.') ch[i] = left[i].first;
                else if(left[i].first == '.') ch[i] = right[i].first;
                else {
                    if(left[i].second == right[i].second) ch[i] = '.';
                    else {
                        if(left[i].second > right[i].second) 
                            ch[i] = right[i].first;
                        
                        else ch[i] = left[i].first;
                    }
                }
            }
        }
        return ch;
    }
};
