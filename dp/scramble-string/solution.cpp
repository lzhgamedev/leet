class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScrambleSub(s1, 0, s1.length(), s2, 0);
    }
    bool isScrambleSub(string& s1, int k1, int L1, string& s2, int k2) {
        if(!hasSameLetters(s1, k1, L1, s2, k2)) return false;
        if(L1 == 0 || L1 == 1)
            return true;
        
        for(int i = 1; i < L1; ++i) {
            if(isScrambleSub(s1, k1, i, s2, k2) && 
                isScrambleSub(s1, k1+i, L1-i, s2, k2+i) ||
                isScrambleSub(s1, k1, i, s2, k2+L1-i) &&
                isScrambleSub(s1, k1+i, L1-i, s2, k2)
            )
                return true;
        }
        return false;
    }
    
    bool hasSameLetters(string& s1, int k1, int L1, string& s2, int k2) {
        int count[256] = {0};
        for (int i = 0; i < L1; ++i) {
            count[s1[k1]]++;
            k1++;
        }
        for (int i = 0; i < L1; ++i) {
            count[s2[k2]]--;
            k2++;
        }
        for (int i = 0; i < 256; ++i)
            if (count[i] != 0) return false;
        return true;
    }
};