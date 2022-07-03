#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        stack<char> a;
        bool insm=false;
        bool ok = true;

        //if(s.empty())
            //cout << "SM\n";

        for(auto c : s)
        {
            if(!ok)
                break;

            if(c == '<' || c == '[' || c =='(' || c == '{')
                a.push(c);
            else if(c == 's')
                insm = true;
            else if(c == 'm')
            {
                if(insm)
                {
                    a.push('s');
                    insm = false;
                }
                else
                ok = false;
            }
            else
            {
                if(a.empty())
                {
                    ok = false;
                    break;
                }

                switch (c)
                {
                case '>':
                if(a.top() == '<')
                    a.pop();
                else if(a.top() == 's')
                {
                    while(a.top() == 's')
                    {
                        a.pop();
                        if(a.empty())
                            ok = false;
                    }
                    if(a.top() == '<')
                        a.pop();
                    else
                        ok = false;
                }
                else
                    ok = false;
                    break;
                case ')':
                if(a.top() == '(')
                    a.pop();
                else if(a.top() == 's')
                {
                    while(a.top() == 's')
                    {
                        a.pop();
                        if(a.empty())
                            ok = false;
                    }
                    if(a.top() == '(')
                        a.pop();
                    else
                        ok = false;
                }
                else
                    ok = false;
                    break;
                case ']':
                if(a.top() == '[')
                    a.pop();
                else if(a.top() == 's')
                {
                    while(a.top() == 's')
                    {
                        a.pop();
                        if(a.empty())
                            ok = false;
                    }
                    if(a.top() == '[')
                        a.pop();
                    else
                        ok = false;
                }
                else
                    ok = false;
                    break;
                case '}':
                if(a.top() == '{')
                    a.pop();
                else if(a.top() == 's')
                {
                    while(a.top() == 's')
                    {
                        a.pop();
                        if(a.empty())
                            ok = false;
                    }
                    if(a.top() == '{')
                        a.pop();
                    else
                        ok = false;
                }
                else
                    ok = false;
                    break;
                }
            }

        }

        if(!a.empty())
        {
            if(a.top()!='s')
                ok = false;
            else
            {
                while(a.top()=='s')
                {
                    a.pop();
                    if(a.empty())
                        break;
                }

                if(!a.empty())
                    ok = false;
            }
        }

        if(ok)
            cout << "SM\n";
        else
            cout << "MS\n";

        while(!a.empty())
            a.pop();
    }
}