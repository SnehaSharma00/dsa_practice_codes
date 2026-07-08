/*Stringify
Difficulty: HARD | Max Score: 75
Two strings X and Y are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}. Notice that "tars" and "arts" are in the same group even though they are not similar. Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.



You will be given N strings where every string in strs is an anagram of every other string in strs.

You have to find out that how many groups are there?

Note: Anagram of a string is formed by jumbling the characters of it.



Input Format:

The first line contains a single integer N - representing the number of strings that you will be given
Next N lines will contain strings (one in each line)


Output Format:

Print a single integer representing the number of groups formed


 

Example:

Input: 4
tars
rats
arts
star
Output: 2
Explanation: 2 groups are - {star} , {tars, rats, arts}
 

Constraints:

1 <= N <= 200
1 <= length of a single string <= 100
string contains only lowercase english letters
All the strings are of same length and anagrams of each other*/

