class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode(): isWord(false) {
        for (auto &a : child) a = nullptr;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n=word.size();
        if(n==0)
            return;
        TrieNode* cur=root;
        for(int i=0;i<n;i++)
        {
            char c=word[i];
            if(cur->child[c-'a']==NULL)
            {
                TrieNode* tmp=new TrieNode();
                cur->child[c-'a']=tmp;
            }
            cur=cur->child[c-'a'];
        }
        cur->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n=word.size();
        if(n==0)
            return false;
        TrieNode* cur=root;
        for(int i=0;i<n;i++)
        {
            char c=word[i];
            if(cur->child[c-'a']==NULL)
            {
                return false;
            }
            cur=cur->child[c-'a'];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n=prefix.size();
        if(n==0)
            return false;
        TrieNode* cur=root;
        for(int i=0;i<n;i++)
        {
            char c=prefix[i];
            if(cur->child[c-'a']==NULL)
            {
                return false;
            }
            cur=cur->child[c-'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
