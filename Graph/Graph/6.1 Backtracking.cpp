#include<bits/stdc++.h>
using namespace std;

char arr[]={'B','G','Y','R','!'};
vector<char>result;
vector<string>per;

int taken[20]={0};
void call()
{
	if(result.size()==4)
	{
		bool val=false;
		string  s;
		for(int i=0;i<4;i++)
        {
            if(result[i]=='!'){val=true;}
        }
        if(val){
		for(int i=0;i<4;i++)
		printf("%c",result[i]);
		//s+=(string)result[i];
		//s=(string)result[i];
		puts(" ");
        }
		per.push_back(s);
		return;
	}
	for(int i=0;i<5;i++)
	{
		if(taken[i]==0)
		{
			/*for(int j=0;j<result.size();j++)
            {
                cout<<result[j];
            }
            cout<<endl;*/
			taken[i]=1; result.push_back(arr[i]);
			call();
			//printf(" ");
			//cout<<i<<" ";
			taken[i]=0; result.pop_back();
		}
		//printf("\n");
	}
}
int main()
{
	call();
}
