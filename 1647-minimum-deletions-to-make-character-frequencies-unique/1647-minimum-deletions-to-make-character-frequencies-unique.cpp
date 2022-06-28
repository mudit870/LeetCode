class Solution {
public:
    int minDeletions(string s) {        // "aaabbbcc"   understand with this testcase
        vector<int> freq(26, 0);
        for(char c: s) freq[c-'a']++;       // save freq    3 3 2
        int count = 0;
        sort(begin(freq), end(freq), greater<int>());       // 3 3 2 (sort in decreasing order)
        for(int i=1; i<26; i++){
      // 3 equal 3 so delete 1 now its 2 move to next here 2 equal 2 so delete 1 now all unique
            while(freq[i] != 0 and freq[i-1] <= freq[i]) {  // jab tak equal h delete ++
                freq[i]--, ++count;
            }
        }
        return count;
    }
};

//  <= to handle "abcabc" case whwre all freq are equal a -> 2 so  b decreases to 1 then b -> 1 so 
//    decrease c to 0 here 2 deletion(means delete less equal to make unique)