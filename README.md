# ProjectTeam01-A
A comparison of implementation of making change using Dynamic Programming and Greedy

Team Member
Izzy Engelbert S.
Kevin Jonathan
Marcelus Vinsens
Yoel Adriel C.

Language
C++ 14

Main Problem
In this case we are given a set of coins whose amount can be vary. The set of coins is 5c, 10c, 20c, 50c, $1, and $2.
The problem is we need to find the minimum number of coins that change hands. If we need to pay 55c, and we do not hold
a 50c coin, we could pay this as 2 × 20c + 10c + 5c to make a total of 4 coins. If we tender $1 we will
receive 45c in change which also involves 4 coins, but if we tender $1.05 ($1 + 5c), we get 50c change
and the total number of coins that changes hands is only 3 so the minimum number of coins that change hands was 3.

Sample Input 

2 4 2 2 1 0  &nbsp;&nbsp;0.95 <br>
2 4 2 0 1 0  &nbsp;&nbsp;0.55 <br>



