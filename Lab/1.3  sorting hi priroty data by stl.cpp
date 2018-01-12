#include<bits/stdc++.h>//ok
using namespace std;

struct data
{
    int r;
    double w;
    data(int roll,double priority){r=roll;w=priority;}
    bool operator > ( const data&p ) const {
        if(w!=p.w){
        return w < p.w;}
        else if(r<p.r){return w < p.w;}
    }
};


int main()
{
    int r,i;
    double p;
    priority_queue <data,vector<data>, greater<data> > q;

    while(cin>>r && cin>>p && r!=0 && p!=0)
    {
        q.push(data(r,p));
    }
    printf("\n\nSorted data : \n\n\n");
    i=0;
    //cout<<654646<<endl;
    while(!q.empty())
    {
        data top = q.top();
        r = top.r;
        p = top.w;
        q.pop();
        cout<<++i<<"\t"<<r<<"\t"<<p<<endl<<endl;//priority result, if equal then in order to roll increasing
        if(i>120)
        {
            break;
        }
    }
    cin>>i;
    return 0;
}
/*
1 3.94
2 3.01

6 2.90
7 3.8
8 3.54
9 3.13
10 3.32
11 2.91
12 3.10
14 2.83
15 3.06

17 3.10
18 3.20
20 3.20
22 3.18
24 3.35

26 2.90
27 3.00

29 2.78
30 3.69

32 3.73
33 3.33
34 3.30
35 3.07
36 3.12
37 3.28
38 3.27
39 3.11
40 2.85
41 2.78

43 3.17

46 2.89
47 3.30

50 3.21
51 3.45
52 3.31
53 3.46
54 3.37


60 3.76
61 3.88
62 3.26
63 3.17
64 3.30
65 3.27
66 3.40
68 3.08
69 3.58


72 3.58
73 3.63
74 2.89
76 3.02
77 2.80
78 3.42
79 3.40
80 2.76
81 3.23
83 3.41
84 3.34
85 3.15
86 3.66
87 3.45


90 3.57

92 3.48
93 3.30
94 3.68

96 3.71
97 3.1

99 3.26
100 2.97

102 3.38
103 3.06
104 3.42
105 2.99
106 3.10
108 3.22
109 3.69

111 2.64
113 3.09

115 2.89

118 3.80
0 0.0

*/
