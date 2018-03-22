//		LeetCode Problem 3 :
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include "../HeaderFiles/LongestSubstring.hpp"

int LongestSubstring::lengthOfLongestSubstring(string s) {
	map<char, int> maptable;
	int maxlength = 0, position = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (((maptable[s[i]] != 0) || (s[i] == s[0])) && (i != 0))
			position = max(position, maptable[s[i]] + 1);
		maxlength = max(maxlength, i - position + 1);
		maptable[s[i]] = i;
	}
	return maxlength;
}

void LongestSubstring::Main() {
	// Setting test Case :
	string testA = "abcabcbb";
	string testB = "bbbbbb";
	string testC = "pwwkew";
	string testD = "aab";
	string testE = "dvdf";
	string testF = "au";
	string testG = "abba";
	string testH = "uqinntq";
	string testI = "vbxpvwkkteaiob";

	std::cout << lengthOfLongestSubstring(testA) << std::endl;
	std::cout << lengthOfLongestSubstring(testB) << std::endl;
	std::cout << lengthOfLongestSubstring(testC) << std::endl;
	std::cout << lengthOfLongestSubstring(testD) << std::endl;
	std::cout << lengthOfLongestSubstring(testE) << std::endl;
	std::cout << lengthOfLongestSubstring(testF) << std::endl;
	std::cout << lengthOfLongestSubstring(testG) << std::endl;
	std::cout << lengthOfLongestSubstring(testH) << std::endl;
	std::cout << lengthOfLongestSubstring(testI) << std::endl;
}