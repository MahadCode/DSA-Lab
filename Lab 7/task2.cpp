#include <iostream>
#include "s.cpp"
using namespace std;

bool evaluateBooleanExpression(string expression)
{
    Stack<char> st;
    int l = expression.length();

    for (int i = 0; i < l; i++)
    {
        char ch = expression[i];
        if (ch != ')')
        {
            st.push(ch);
        }
        else
        {
            bool notAns = true;
            bool andAns = true;
            bool orAns = false;

            while (st.top() != '(')
            {
                if (st.top() == 't')
                {
                    orAns = true;
                    notAns = false;
                }
                else if (st.top() == 'f')
                {
                    andAns = false;
                    notAns = true;
                }
                st.pop();
            }
            st.pop();

            bool currAns;
            if (st.top() == '&')
            {
                currAns = andAns;
            }
            else if (st.top() == '|')
            {
                currAns = orAns;
            }
            else
            {
                currAns = notAns;
            }

            st.pop();

            if (currAns)
            {
                st.push('t');
            }
            else
            {
                st.push('f');
            }
        }
    }

    if(st.top()=='t'){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string a = "|(f,&(t,!(f)))";

    if(evaluateBooleanExpression(a)){
        cout << "true";
    }
    else{
        cout << "false";
    }
}