class CombinationIterator {
public:
    string s;
    int l;
    queue<string> q;
    void subs(string s, int l, queue<string>& q, string st, int i) {

        if (st.size() == l) {
            q.push(st);
            return;
        }
        if (i >= s.size())
            return;
        st.push_back(s[i]);
        subs(s, l, q, st, i + 1);

        st.pop_back();
        subs(s, l, q, st, i + 1);
    }
    CombinationIterator(string characters, int combinationLength) {
        this->s = characters;
        this->l = combinationLength;

        string st;
        subs(s, l, q, st, 0);
    }

    string next() {
        string res = q.front();
        q.pop();
        return res;
    }

    bool hasNext() { return !q.empty(); }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */