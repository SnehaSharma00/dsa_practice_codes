/*KALI YUGA: The End
Difficulty: HARD | Max Score: 75
It's the end of the KALI YUGA and destruction is at it's peak everywhere. 

The world is fully diminished but you are carrying the hope for all.



The world has fallen into ruin, and the wasteland is highly irradiated. You are an elite courier carrying a vital cure, and you must travel from your home at Settlement 1 to a distant medical outpost at Settlement N.

The settlements are located along a single highway. Each settlement i has two distinct attributes:

Radiation Level (Ri): The ambient background radiation present at the settlement.
Scavenger Toll (Ci): The amount of supplies you must hand over to the local warlord to safely rest inside their walls.


You have a backpack carrying a maximum of F units of supplies (food, water, stamina). Traveling between settlements is exhausting. If you travel from Settlement i directly to Settlement j (i < j), the supply cost is based on the distance traveled (which grows quadratically due to the harsh terrain) plus the toll of the destination settlement.

The formula for the supply cost is: 

 (j - i)2 + Cj



Your goal is to choose a sequence of settlements to rest at such that you minimize the maximum Radiation Level you are exposed to on your journey, without running out of your total supplies F.

You begin at Settlement 1 and must end exactly at Settlement N.





Input Format:

An integer N (number of settlements) and an integer F (total supplies).

An array R of size N, where R[i] is the radiation level at the i-th settlement.

An array C of size N, where C[i] is the toll at the i-th settlement (Note: C[0] is 0 since you start there safely).



Output Format:

An integer representing the minimum possible "maximum radiation level" you must endure to reach Settlement N. If it is impossible to reach Settlement N without starving/running out of supplies, return -1.

 



Example 1:

Input: 5 15
10 50 20 40 30
0 2 1 3 2
Output: 30
Explanation: You have to visit settlements 1,3,5 having radiation levels 10,20,30. So the maximum radiation level here is 30. And the total supplies used in between this journey is 11(11<=15). This is the minimum answer that you can find out without exhausting the total supply. Any other route will give more answer.
 

Constraints:

2 <= N <=1000
1 <= F <= 1012
0 <= Ri <= 109
0 <= Ci <= 106 (C0 is guaranteed to be 0)*/