class SpecialStack {
public:
    stack<int> st;
    stack<int> stMax;

    SpecialStack() {}

    void push(int x) {
        st.push(x);

        if(stMax.empty())
            stMax.push(x);
        else
            stMax.push(max(x, stMax.top()));
    }

    void pop() {
        if(st.empty()) return;

        st.pop();
        stMax.pop();
    }

    int peek() {
        return st.empty() ? -1 : st.top();
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMax() {
        return st.empty() ? -1 : stMax.top();
    }
};
