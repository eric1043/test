#include<iostream>
#include<map>
using namespace std;

int main()
{
    int m,w,e;
    cin >> m >> w >> e;

    map<int,int> men;
    map<int,int> women;
    int tmp;
    for(int i=0; i<m; i++)
    {
        cin >> tmp;
        men[tmp]++;
    }
    for(int i=0; i<w; i++)
    {
        cin >> tmp;
        women[tmp]++;
    }

    int count=0;

    if(men.size()<women.size())
    {
        for(int i=0; i<e; i++)
        {
            //set<set<int>::iterator> form;
            //set<int> tmps = women;
            int event;
            cin >> event;
            bool found = false;

            for(auto j : men)
            {
                auto it = women.find(event-j.first);
                if(it!=women.cend())
                {
                    found = true;
                    count += max(j.second,it->second);
                }
            }
            cout << count << endl;
            count=0;
        }
    }
    else
    {
        for(int i=0; i<e; i++)
        {
            //set<set<int>::iterator> form;
            //set<int> tmps = women;
            int event;
            cin >> event;
            bool found = false;

            for(auto j : women)
            {
                auto it = men.find(event-j.first);
                if(it!=men.cend())
                {
                    found = true;
                    count += max(j.second,it->second);
                }
            }
            cout << count << endl;
            count=0;
        }
    }
}