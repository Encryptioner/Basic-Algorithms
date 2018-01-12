#include<bits/stdc++.h>//ok but don't give minimum nodes completely
using namespace std;
typedef pair<int,int>pi;

int main()
{
    vector<pi>edge;
    vector<int>select;
    int i,n,u,v,n1,a,b;

    cin>>n;
    n1=n;
    bool active[n];
    bool c=0;
    for(i=0;i<n;i++)
    {
        cin>>u>>v;
        edge.push_back( pi(u,v) );
    }
    printf("\n\n");

    while(c==0)
    {
        c=1;
    for(i=0;i<n;i++)
    {
        u=edge[i].first;
        v=edge[i].second;
        if(active[u]==0 && active[v]==0)
        {
            if(active[u]==0)
            {
                select.push_back(u);
            }
            if(active[v]==0)
            {
                select.push_back(v);
            }
            active[u]=1;
            active[v]=1;
            c=0;
            //cout<<u<<" "<<v<<endl;
        }
    }
    }
    cout<<"\nNode no to cover all vertex:\n\n";
    for(i=0;i<select.size();i++)
    {
        cout<<select[i]<<endl;
    }
    printf("\n\n");
    return 0;
}

// erasing from list
/*#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  return 0;
}
/*#include<iostream>
#include <list>
#include <string>

using namespace std;

typedef std::list< std::pair<int,int> > myType;


int main()
{

list<pair<int,int>> some_rules;

int i,n,u,v,n1;

    cin>>n;
    n1=n;

    for(i=0;i<n;i++)
    {
        cin>>u>>v;
        some_rules.push_back( make_pair(u,v) );
    }


myType::iterator iter = some_rules.begin();

for(;iter != some_rules.end();iter++)
{
    u = (*iter).first;
    v = (*iter).second;
    cout<<u<<" "<<v<<endl;
}
}

/*#include<bits/stdc++.h>
using namespace std;


typedef pair<int,int>pi;
vector<pi>edge;

int main()
{
    int i,n,u,v,n1;

    cin>>n;
    n1=n;

    for(i=0;i<n;i++)
    {
        cin>>u>>v;
        edge.push_back(pi(u,v));
    }
    while(n1!=0)
    {

    }
    return 0;
}
*/
