# Project Team 01-A

A comparison of implementation of making change using Dynamic Programming and Greedy

#### Team Member:
- Izzy Engelbert S.
- Kevin Jonathan
- Marselus Vinsens
- Yoel Adriel C.

#### Programming Language:
- C++ 14

# Main Problem

In this case we are given a set of coins whose amount can be vary. The set of coins is 5c, 10c, 20c, 50c, $1, and $2.
The problem is we need to find the minimum number of coins that change hands. If we need to pay 55c, and we do not hold
a 50c coin, we could pay this as 2 × 20c + 10c + 5c to make a total of 4 coins. If we tender $1 we will
receive 45c in change which also involves 4 coins, but if we tender $1.05 ($1 + 5c), we get 50c change
and the total number of coins that changes hands is only 3 so the minimum number of coins that change hands was 3.

Sample Input :
```
2 4 2 2 1 0 0.95
2 4 2 0 1 0 0.55
0 0 0 0 0 0
```
Sample Output:
```
2 
3
```


# GREEDY SOLUTION EXPLANATION

First we index all the coins and map it to the coin value difference with the required value.
Then after indexing is done we will need to sort the inputted coins from the smallest the difference. 
We custom the Quick Sort function to also swap the index array. 
The sorting is done in each loop.
The loop will continue as long as more current required value is not zero.
```c++
while(value > 0 || value < 0) 
```

After sorting is done, we will reduce value with the coin that has the smallest difference with the value.
```c++
quickSort(diffs, diffsIndex, 0, coinSize-1);
for(int i=0; i<coinSize; ++i){
    if(coins[diffsIndex[i]]>0){
          value -= allCoins[diffsIndex[i]];
          --coins[diffsIndex[i]];
          ++ans;
          cout<<"remove coin: "<<allCoins[diffsIndex[i]]<<endl;
          break;
      }
}
```
After done reducing the value, we will check the availability of the coins, if the previous value is not changed then the coin is empty.
Then, the transaction loop will stop and request new input.
```c++
bool empty = false;
if(prevValue == 0){
    prevValue = value;
}else if(prevValue == value){
    empty = true;
}else{
    prevValue = value;
}
if(empty){
    cout<<"coin not enough"<<endl;
    value = 0;
}
```
Then reduce value with the coin that has the smallest difference with the value, but this will return changes. 
So we want the value not to exceed zero when added by the coin fraction
```c++
int inValue = value*-1;
for(int i=0; i<coinSize; ++i){
    if(inValue - allCoins[diffsIndex[i]] >= 0){
        value += allCoins[diffsIndex[i]];
        ++ans;
        cout<<"return coin: "<<allCoins[diffsIndex[i]]<<endl;
        break;
    }
}
```
The output of greedy only get the most optimal value at the time so the output in this case won't be the global maximum.


# DYNAMIC PROGRAMMING SOLUTION EXPLANATION

For Dynamic programing after input first we are going  to set the value with inside the array to be compared <br>
```c++
for(int i=1; i<maxValue; i++) ways[i] = limit;
```
after that we are going to loop and compare all the value in the array and overwrite the value with the possible cents

```c++
if(ways[j] < limit){
    ways[j + coinsCents[i]] = min(ways[j]+1, ways[j+coinsCents[i]]);
}
```
After overwriting it with possible coins than we are going to compare the coins given and output the answer.
To find the minimum change we are using:
```c++
for(int i = 5; i>=0; i--){
    if(values[i]<=v){
        return 1 + minimumChange(v - values[i], values);
    }
}
```
```c++
for(int i = coinCents; i<maxValue; i++){ 
    answer = min(answer, ways[i] + minimumChange(i - coinCents, coinsCents)); 
}
cout<<answer<<endl;
```
# COMPARISON 

##### Greedy Algorithm result:
![greedy](https://github.com/AAlab1819/ProjectTeam01-A/blob/master/GreedyCapt.PNG)
##### Dynamic Programming result:
![dp](https://github.com/AAlab1819/ProjectTeam01-A/blob/master/dp.JPG)
 
As we can see, we get different result from the example. There is difference between this two method output. Its because greedy only looking for most optimal value at the time. The run time of this two code was also different. For DP its take about 2.04s and greedy take 1.5s. So DP 0.5s longer than greedy. But in memory greedy was bigger than DP. Greedy take around 2872 and DP 2764.
<br>
Time complexity for greedy was Ω(n log(n)) and <br>
Time complexity for dynamic programming was O(n) <br>

So the conclution is using dynamic programming is better than greedy because it gave us the optiomal output. But DP took more time to run. 



 

