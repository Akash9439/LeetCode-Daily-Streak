/*Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> m;
        int i=0;
        int j,count=0;
        for(auto x:s)
        {
            m[x].push_back(i++);
        }
        
        for(i=0;i<words.size();i++)
        {
            string curr=words[i];
            int latest=-1;
            for(j=0;j<curr.size();j++)
            {
                auto it=upper_bound(m[curr[j]].begin(),m[curr[j]].end(),latest);
                if(it==m[curr[j]].end())
                {
                    break;
                }
                latest=*it;
                if(j==curr.size()-1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
