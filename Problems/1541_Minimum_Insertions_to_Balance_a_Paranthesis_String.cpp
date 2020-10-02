// Count will keep track of all '(' ans is the insertions required.
// we iterate the string and count the '('
// If the char is ')'we decrement count by 1 and check if the next char is ')' too
// If it is true then the count-1 was proper as condition for one of the '(' is satisfied.
// If it is not ')' we have to add ')' we have already decremented count so increment ans by 1 as we need to add one ')'
// This is same if the char was last char as we increment ans and decrement count.
// After this check if the count is below zero. If yes then we need to add '(' for the two '))' so againg ans++ and count++. Although here count++ will give count = 0.
// Note the i++ inside the else that means we have skipped the next char as it was ')'. So the next i++ will make the correct position.
// Now when the iteration is complete we already have the ans. But we also need to check the count.
// Count means we have some '(' left at the end for each '(' we need two ')' so count*2;
// The final result is ans + count*2;
class Solution {
public:
    int minInsertions(string s) {
        int count = 0,ans = 0,i=0,n = s.length();
        while(i<n){
            if(s[i] == '(') count++;
            else{
                count--;
                if(i == n-1 || s[i+1] != ')')ans++;
                else i++;
            }
            i++;
            if(count<0){
                ans++;
                count++;
            }
        }
        return ans + (count * 2);
    }
};
