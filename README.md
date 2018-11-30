# ProjectTeam01-A
A comparison of implementation of making change using Dynamic Programming and Greedy

Team Member <br>
Izzy Engelbert S. <br>
Kevin Jonathan <br>
Marselus Vinsens <br>
Yoel Adriel C. <br>

Language <br>
C++ 14 <br>

Main Problem <br>

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



GREEDY SOLUTION EXPLANATION <br>

First we need to make a index for all the coins. Then after indexing is done we will need to sort the inputted coins. Sorting is done by Quick Sort technique. The sorting will be done in the loop (while value is > 0 or value is < 0), after sorting is done, we will reduce value with the coin that has the smallest difference with the value. After done reducing the value we will check the availability of the coins, if the previous value is not changed then the coin is empty. Then proceeded to creating an array consisting of difference of value and coins fraction, after that we will sort it again. Then do reducing reduce value with the coin that has the smallest difference with the value, but this will return changes, so we want the value not to exceed zero when added by the coin fraction

The output of greedy only looking for the most optimal in that time so the output won't be maximal.<br><br>



DYNAMIC PROGRAMMING SOLUTION EXPLANATION <br>

For Dynamic programing after input first we are going  to set the value with inside the array to be compared <br>
for(int i=1; i<maxValue; i++) ways[i] = limit; <br>
after that we are going to loop and compare all the value in the array and overwrite the value with the possible cents<br>
<br>   if(ways[j] < limit) <br>
{ ways[j + coinsCents[i]] = min(ways[j]+1, ways[j+coinsCents[i]]);} <br>
 
 after overwrite it with possible coins than we are going to compare the coins given and output the answer. <br> <br>
 to find the minimum change we are using  <br> <br>
 
    for(int i = 5; i>=0; i--)
    { if(values[i]<=v)
        { return 1 + minimumChange(v - values[i], values);}
    }
    return 0;
 
 for(int i = coinCents; i<maxValue; i++) <br><br>
 { answer = min(answer, ways[i] + minimumChange(i - coinCents, coinsCents)); } <br> cout<<answer<<endl; <br>
 
 COMPARISON 
 <br>
 <br>
 
 ANALYSIS
 <br>
 <br>
