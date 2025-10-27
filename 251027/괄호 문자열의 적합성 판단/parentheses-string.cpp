#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

int main() {
    cin >> str;

    // Please write your code here.

    stack<char> st;
    for (char c : str)
    {
        if (c == ')')
        {
            if (st.empty() || st.top() == ')')
            {
                cout << "No\n";
                return 0;
            }
            else
            {
                st.pop();
            }
        }
        else
        {
            st.push(c);
        }
    }
    if (st.empty())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
