class TRN
{
public:
    TRN *children[10];
    bool isEnd;

    TRN()
    {
        for (int i = 0; i < 10; ++i)
        {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class TR
{
public:
    TRN *root;

    TR()
    {
        root = new TRN();
    }

    void insert(int node)
    {
        TRN *nd = root;
        string str1 = to_string(node);

        for (char ch : str1)
        {
            int in = ch - '0';
            if (!nd->children[in])
            {
                nd->children[in] = new TRN();
            }
            nd = nd->children[in];
        }
        nd->isEnd = true;
    }

    int longestCommonPrefixLength(int node)
    {
        TRN *nd = root;
        string str1 = to_string(node);
        int ct = 0;

        for (char ch : str1)
        {
            int in = ch - '0';
            if (!nd->children[in])
            {
                return ct;
            }
            nd = nd->children[in];
            ++ct;
        }

        return ct;
    }
};

class Solution
{
public:
    int longestCommonPrefix(vector<int> &vec1, vector<int> &vec2)
    {
        TR trie;
        int ln = 0;

        for (int node : vec1)
        {
            trie.insert(node);
        }

        for (int node : vec2)
        {
            int okk=trie.longestCommonPrefixLength(node);
            ln = max(ln, okk);
        }

        return ln;
    }
};