//dijkstra

/*Hinderland
Difficulty: MEDIUM | Max Score: 50
You are currently exploring the magical world of Hinderland with Shinchan. The world consists of N cities connected by M bidirectional roads, where each road requires a certain amount of fuel to cross.

Shinchan's home base is located at a specific pivot city, X. He wants to visit every single city in Hinderland, but because he gets homesick, his travel plan is very strict:

Every year, he selects one unvisited city as his destination.
He travels from city X to that destination using the most fuel-efficient route possible. (He is free to pass through any other cities along the way).
In the exact same year, he returns from the destination straight back to city X using the most fuel-efficient route.
He repeats this process until every city has been visited exactly once as a destination.
Your task is to calculate the minimum total fuel cost required for Shinchan to successfully visit every other city and return home each time. If a city is completely unreachable from city X, Shinchan will skip it (assume a cost of 0 for unreachable cities).





Input Format:

The first line contains three integers: N (number of cities), M (number of roads), and X (the starting pivot city).
The next M lines each contain three integers U, V, and W, representing a bidirectional road between city U and city V that costs W fuel to traverse.
Output Format:

Print a single integer representing the total minimum fuel cost for all the round trips.




 

Example:

Input: 4 4 1
1 2 4
1 3 1
3 2 2
2 4 5

Output: 24

Explanation: Shinchan starts at city 1.
Trip to city 2: The shortest path is 1 -> 3 -> 2 (cost = 3). Round trip = 6.
Trip to city 3: The shortest path is 1 -> 3 (cost = 1). Round trip = 2.
Trip to city 4: The shortest path is 1 -> 3 -> 2 -> 4 (cost = 8). Round trip = 16. Total Fuel Cost = 6 + 2 + 16 = 24.
 

Constraints:

1 <= N <= 105
1 <= M <= 2*105
1 <= X <= N
1 <= W <= 109*/