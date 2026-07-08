/*Minions and Bananas
Difficulty: MEDIUM | Max Score: 50
Gru has N minions standing in a line, each with a loyalty rating represented as an integer. Since they work so hard, Gru wants to reward them with bananas. However, he must follow these rules:

Every minion must get at least one banana.
Minions with a higher loyalty rating than their immediate neighbors must get more bananas than them.


Gru wants to minimize the total number of bananas he distributes while keeping all minions happy.

Can you help Gru distribute the bananas efficiently?



Input Format:

The first line contains an integer N — the number of minions.
The next line contains N space-separated integers — representing each minion’s loyalty rating.


Output Format:

Print a single integer — the minimum number of bananas Gru needs to distribute.


Constraints:

1 ≤ N ≤ 2*105
0 ≤ rating ≤ 2*105


Example 1:

Input:
6  
5 3 1 2 4 6  

Output:
15  

Explanation:
Possible banana distribution:

[3, 2, 1, 2, 3, 4]

The values first decrease, then increase, so bananas are distributed accordingly.
Total = 15 bananas.




Example 2:

Input:
4  
1 3 2 2 

Output:
5  

Explanation:
Possible banana distribution:
[1, 2, 1, 1]

The second minion (higher rating) gets 2 bananas.
The others get 1 because they don’t need more.
Total = 5 bananas.*/