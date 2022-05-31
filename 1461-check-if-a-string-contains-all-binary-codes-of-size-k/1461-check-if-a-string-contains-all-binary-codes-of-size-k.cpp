// Rolling Hash Approach : (Optimized)
// So, we are calculating all the distinct substrings of length k for all which we actually don't need to do. We can just find the hash for the first substring of length k and then use the rolling hash technique.

// What is rolling hash approach actually ->
// The approach is very simple we will just keep on removing the last character of previous substring and keep adding the next character from s and calculate the hash from this only instead of recalculating the whole hash.

class Solution {
public:
    bool hasAllCodes(string s, int k) {
	// (allOnes = ~0 = -1) in general
   int n = s.size(), size = 1 << k, count = 0, hash = 0, allOnes = ~size; 
	bool set[size]; memset(set, false, sizeof(set));
	for(int i = 0; i < n; i++){                    	    
		// below line combines all above-metioned steps for rolling hash calculation
		hash = ((hash << 1) & allOnes) | (s[i] - '0');            
		if(i >= k - 1 && !set[hash])   // first k - 1 iteration are to calculate hash of first substring of length k
			set[hash] = true, count++;
	}
	return count == size;
    }
};
    