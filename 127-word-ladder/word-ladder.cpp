class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            string word=temp.first;
            int step=temp.second;
            if(word==endWord) return step;
            for(int i=0;i<word.size();i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=og;
            }
        }
        return 0;
    }
};