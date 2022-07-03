#include<iostream>
#include<list>
#include<queue>
#include<set>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    //set<int> group[m];
    queue<int> rep[m];
    list<int> line;
    int people[100005];
    bool leave[100005];

    for(int i=0; i<100005; i++)
        people[i] = -1;

    for(int i=0; i<m; i++)
    {
        int p,id;
        cin >> p;
        for(int j=0; j<p; j++)
        {
            cin >> id;
            people[id] = i;
            //group[i].insert(id);
        }
    }

    while(n--)
    {
        string o;
        int id;
        cin >> o;

        if( o == "ENQUEUE")
        {
            cin >> id;
            int gr = people[id];
            //cout << gr;
            if(gr == -1)
            {
                //exit(1);
                line.push_back(id);
            }
            else
            {
                if(!rep[gr].empty())
                {
                    rep[gr].push(id);
                }
                else
                {
                    rep[gr].push(id);
                    line.push_back(-gr);
                }
            }
        }
        else if(o == "DEQUEUE")
        {
            if(line.empty())
            {
                //exit(1);
                cout << "The queue is empty\n";
                continue;
            }
            int cur = line.front();
            //cout <<cur;
            if(cur<=0)
            {
            cout << rep[-cur].front() << endl;
            rep[-cur].pop();

            if(rep[-cur].empty())
                line.pop_front();
            }
            else
            {
                cout << cur << endl;
                line.pop_front();
            }
        }
        else
        {
            cin >> id;
            leave[id] = true;
        }
    }
}