class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> match = {
            {')','('},
            {']','['},
            {'}','{'},
        };

        for(char c : s){
            if(match.count(c)){
                if(!stack.empty() && stack.top() == match[c]){
                    stack.pop();
                } else{
                     return false;
                     }
                } 
                else{
                    stack.push(c);
                }
            
        }
        return stack.empty();
        
    }
};