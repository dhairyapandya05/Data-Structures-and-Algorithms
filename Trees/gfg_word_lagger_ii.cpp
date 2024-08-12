class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(),wordList.end());
        set<string> usedstringinalevel;
        queue<vector<string>> q;
        usedstringinalevel.insert(beginWord);
        q.push({beginWord});
        int level = 0;
        while(!q.empty()){
            vector<string> temp=q.front();
            q.pop();
            if(temp.size()>level){
                level++;
                // in this case we will have to delete the string used from the set
                for(auto& it:usedstringinalevel){
                    st.erase(it);
                }
                usedstringinalevel.clear();
            }
            string word=temp.back();
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(temp);
                }
                else{
                    if(ans[0].size()==temp.size()){
                        ans.push_back(temp);
                    }
                }
            }
            for(int i=0;i<word.length();i++){
                char originalch=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    auto it=st.find(word);
                    if(it!=st.end()){
                        temp.push_back(*it);
                        q.push(temp);
                        usedstringinalevel.insert(*it);
                        temp.pop_back();
                    }
                }
                word[i]=originalch;
            }
            
        }
        return ans;
    }
};