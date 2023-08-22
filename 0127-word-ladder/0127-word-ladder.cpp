class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // following set will be used to search words of wordList in O(1) time
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // given conditions
        if(st.find(endWord) == st.end()){
            return 0;
        }
        // will use queqe to store word and transformation distance
        queue<pair<string, int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            string word=it.first;
            int dist = it.second;
            
            // if transformed word is equal to targetWord then returning the distance of transformation
            if(word == endWord) return dist;
            
            // I will be changing every char of word from a to z and check if it is in the given list
            // that means It can be one of the transformed word and saving dist for it
            for(int i=0; i<word.length(); i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i]=ch;
                    if(st.find(word) != st.end()){
                        q.push({word, dist+1});
                        st.erase(word);// it is like I have visited this word so i will not come back toSame
                    }
                }
                word=it.first;// restoring word
            }
        }
        return 0;// no such sequence exists
    }
};