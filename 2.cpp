#include<iostream>
#include<set>
using namespace std;

struct cmp
{
    bool operator() (const set<int>::iterator&a, const set<int>::iterator&b) const
    {
        return *a < *b;
    }
};

int main()
{
    int m,w,e;
    cin >> m >> w >> e;

    set<int> men;
    set<int> women;
    int tmp;
    for(int i=0; i<m; i++)
    {
        cin >> tmp;
        men.insert(tmp);
    }
    for(int i=0; i<w; i++)
    {
        cin >> tmp;
        women.insert(tmp);
    }

    int count=0;

    if(men.size()<women.size())
    {
        for(int i=0; i<e; i++)
        {
            set<set<int>::iterator,cmp> form;
            int event;
            cin >> event;
            bool found = false;

            for(auto j : men)
            {
                auto it = women.find(event-j);
                if(it!=women.cend())
                {
                    //auto it2 = form.find(it);
                    //if(it2!=form.cend())
                        //continue;
                    found = true;
                    count++;
                    form.insert(it);
                    women.erase(it);
                }
            }
            cout << count << endl;
            count=0;
            for(auto it : form)
                women.insert(*it);
            form.clear();
        }
    }
    else
    {
        for(int i=0; i<e; i++)
        {
            set<set<int>::iterator,cmp> form;
            int event;
            cin >> event;
            bool found = false;

            for(auto j : women)
            {
                auto it = men.find(event-j);
                if(it!=men.cend())
                {
                    //auto it2 = form.find(it);
                    //if(it2!=form.cend())
                        //continue;
                    found = true;
                    count++;
                    form.insert(it);
                    men.erase(it);
                }
            }
            cout << count << endl;
            count=0;
            for(auto it : form)
                men.insert(*it);
            form.clear();
        }
    }
}