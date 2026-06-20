// Last updated: 6/20/2026, 5:07:16 PM
class Solution {
public:

    struct Node {
        int child[26];
        int idx;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;

    void update(int node, int index, vector<string>& wordsContainer) {

        if(trie[node].idx == -1) {
            trie[node].idx = index;
            return;
        }

        int old = trie[node].idx;

        if(wordsContainer[index].size() < wordsContainer[old].size())
            trie[node].idx = index;
        else if(wordsContainer[index].size() == wordsContainer[old].size()
                && index < old)
            trie[node].idx = index;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(Node()); // root

        // Build Trie
        for(int i=0;i<wordsContainer.size();i++) {

            string s = wordsContainer[i];
            int curr = 0;

            update(curr, i, wordsContainer);

            for(int j=s.size()-1;j>=0;j--) {

                int id = s[j]-'a';

                if(trie[curr].child[id] == -1) {
                    trie[curr].child[id] = trie.size();
                    trie.push_back(Node());
                }

                curr = trie[curr].child[id];

                update(curr, i, wordsContainer);
            }
        }

        vector<int> ans;

        // Queries
        for(string &q : wordsQuery) {

            int curr = 0;

            for(int j=q.size()-1;j>=0;j--) {

                int id = q[j]-'a';

                if(trie[curr].child[id] == -1)
                    break;

                curr = trie[curr].child[id];
            }

            ans.push_back(trie[curr].idx);
        }

        return ans;
    }
};