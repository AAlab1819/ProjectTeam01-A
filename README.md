# ProjectTeam01-A
A comparison of implementation of making change using Dynamic Programming and Greedy

Team Member <br>
Izzy Engelbert S. <br>
Kevin Jonathan <br>
Marselus Vinsens <br>
Yoel Adriel C. <br>

Language <br>
C++ 14 <br>

# Main Problem

In this case we are given a set of coins whose amount can be vary. The set of coins is 5c, 10c, 20c, 50c, $1, and $2.
The problem is we need to find the minimum number of coins that change hands. If we need to pay 55c, and we do not hold
a 50c coin, we could pay this as 2 × 20c + 10c + 5c to make a total of 4 coins. If we tender $1 we will
receive 45c in change which also involves 4 coins, but if we tender $1.05 ($1 + 5c), we get 50c change
and the total number of coins that changes hands is only 3 so the minimum number of coins that change hands was 3.

Sample Input 

2 4 2 2 1 0  &nbsp;&nbsp; &nbsp;&nbsp; 0.95 <br>
2 4 2 0 1 0  &nbsp;&nbsp; &nbsp;&nbsp; 0.55 <br>
0 0 0 0 0 0 <br>

Sample Output <br>
2 <br>
3 <br>



# GREEDY SOLUTION EXPLANATION

First we need to make a index for all the coins. Then after indexing is done we will need to sort the inputted coins. Sorting is done by Quick Sort technique. The sorting will be done in the loop (while value is > 0 or value is < 0).
```c++
while(value > 0 || value < 0) 
```
After sorting is done, we will reduce value with the coin that has the smallest difference with the value.
```c++
quickSort(diffs, diffsIndex, 0, coinSize-1);
for(int i=0; i<coinSize; ++i){<br>
    if(coins[diffsIndex[i]]>0){<br>
      value -= allCoins[diffsIndex[i]];<br>
      --coins[diffsIndex[i]];<br>
      ++ans;<br>
      cout<<"remove coin: "<<allCoins[diffsIndex[i]]<<endl;<br>
      break;<br>
      }
}
```
After done reducing the value, we will check the availability of the coins, if the previous value is not changed then the coin is empty. Then proceeded to creating an array consisting of difference of value and coins fraction, after that we will sort it again.
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
Then do reducing reduce value with the coin that has the smallest difference with the value, but this will return changes, so we want the value not to exceed zero when added by the coin fraction
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
The output of greedy only looking for the most optimal in that time so the output won't be maximal.<br><br>



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

return 0;
```
```c++
for(int i = coinCents; i<maxValue; i++){ 
    answer = min(answer, ways[i] + minimumChange(i - coinCents, coinsCents)); 
}
cout<<answer<<endl;
```
# COMPARISON 
 <br>
 <br>
 
# ANALYSIS
 <br>
 <br>
