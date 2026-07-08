/*Nobita’s Roller Coaster Ride
Difficulty: MEDIUM | Max Score: 50
Nobita and Doraemon are at a futuristic amusement park where they find a crazy roller coaster! The ride starts going up, reaches a thrilling peak, and then rushes down.

Nobita is curious to find the highest point of the ride, and Doraemon challenges him to do it as quickly as possible (in O(log n) time complexity)!



Can you help Nobita find the peak of the roller coaster before it’s too late?



Input Format:

The first line contains an integer n, the number of points recorded during the ride.
The second line contains an array arr of length n, where each element represents the height of the roller coaster at different points.


Output Format:

Print a single integer — the index where the roller coaster reaches its highest point.


Constraints:

3 ≤ n ≤ 105
0 ≤ arr[i] ≤ 106
The given array is guaranteed to have a single peak.




Example 1:

Input:
3 
0 1 0 
Output:
1 
Explanation:
The roller coaster goes up from 0 to 1, then comes down to 0.
The highest point is at index 1, with a height of 1.


Example 2:

Input:
4 
0 2 1 0 
Output:
1 
Explanation:
The ride ascends to height 2 at index 1, then descends.
The peak is at index 1 with value 2.


Example 3:

Input:
4 
0 5 10 2 
Output:
2
Explanation:
The ride climbs to height 10 at index 2 and then goes down.
The highest point is index 2, where the height is 10.*/