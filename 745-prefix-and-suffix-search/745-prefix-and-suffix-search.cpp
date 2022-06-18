struct Node{
    Node* link[26];
    vector<int> idx;
};
class WordFilter {
private:
    Node* root;
    unordered_map<string,int> mp;
    vector<string> words;
    
    void insert_in_trie(string &str,Node* root){
        for(auto &it : str){
            if(!root->link[it - 'a']){
                root->link[it - 'a'] = new Node();
            }
            root = root->link[it - 'a'];
            root->idx.push_back(mp[str]);
        }
    }
public:
    WordFilter(vector<string>& words) {
        this->words = words;
        root = new Node();
        for(int i=0;i<words.size();i++){
            mp[words[i]] = i; // storing last index of string
        }
        unordered_set<string> st;
        for(auto &it : words){
            if(st.count(it)) continue;
            st.insert(it); // inserting in set so we don't waste time by inserting duplicate string
            insert_in_trie(it,root);
        }
    }
    
    int f(string prefix, string suffix) {
        Node* curr = root;
        for(auto &it : prefix){
            if(!curr->link[it - 'a']) return -1; // if prefix is not present, there is no point of suffix
            curr = curr->link[it - 'a'];
        }
        int ans = -1;
        auto &vec = curr->idx; // taking vector where our suffix might be present
        for(auto &it : vec){
            int len = words[it].size();
            if(words[it].substr(len - suffix.size()) == suffix) ans = it;
        }
        return ans;
    }
};
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */