#include <bits/stdc++.h>
using namespace std;

int minimumChange(int v, int values[])
{
    for(int i = 5; i>=0; i--)
    {
        if(values[i]<=v)
        {
            return 1 + minimumChange(v - values[i], values);
        }
    }
    return 0;
}

int main()
{
    //coins index in the array
	int num = 6;
	int coins[num] = {5,10,20,50,100,200};
	int coinsCents[num];
	for (int i=0; i<num; i++)
	{
		coinsCents[i] = coins[i]/5;
	}

	int maxValue = 200;

    double coin;
    int answer;
    long long limit = 1000000000;

	//represents the number of ways to reprecent the coins in cents
	int ways[maxValue+1];
	time_t start_time;
    time_t end_time;
	//looping with error handling
	while(cin>>coins[0]>>coins[1]>>coins[2]>>coins[3]>>coins[4]>>coins[5]>>coin)
    {
        time(&start_time);
		if(coins[0]+coins[1]+coins[2]+coins[3]+coins[4]+coins[5] == 0) break;

        //to define the zero Cents
        ways[0]=0;
        answer = limit;

        //to set the value with inside the array to be compared
        for(int i=1; i<maxValue; i++) ways[i] = limit;

        for(int i=0; i<num; i++)
        {
            while(coins[i])
            {
                for(int j = maxValue - coinsCents[i] - 1; j>=0; j--)
                {
                    //to compare and overwrite the value with the possible cents
                    if(ways[j] < limit)
                    {
                        ways[j + coinsCents[i]] = min(ways[j]+1, ways[j+coinsCents[i]]);
                    }
                }
                coins[i]--;
            }
        }

        int coinCents = (int)(coin * 100 / 5 + 0.1);

        //to compare the coins given and output the answer
        for(int i = coinCents; i<maxValue; i++)
        {

            answer = min(answer, ways[i] + minimumChange(i - coinCents, coinsCents));
        }
        cout<<answer<<endl;
        time(&end_time);
        double elapsed_time = end_time - start_time;
        //cout<<"Elapsed Time: "<<elapsed_time<<endl;
    }
	return 0;
}
