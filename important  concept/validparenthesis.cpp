
class Solution {
    public:
        bool checkValidString(string s) {
            int mincount=0;
            int maxcount=0;
            int n= s.length();
    
            for(int i=0;i<n;i++){
                if(s[i]=='('){
                    mincount++;
                    maxcount++;
                }
                else if(s[i]==')'){
                    mincount=max(0,mincount-1);
                    maxcount--;
                }
                else {
                    mincount=max(0,mincount-1);
                    maxcount++;
                }
                if(maxcount<0)return false;
    
            }
            if(mincount!=0)return false;
            else return true;
        }
    };
    //we can use min and max to check the range if the overall parenthesus sum is null 
    