#include <iostream> //cout 
#include <string> //string 
#include <cctype> //isalpha(), tolower(), toupper()

/* Objective: Provide a modified copy of a 
 * string that contains only letters with 
 * casing citeria
 * Input: A string
 * Constraint: The orignal string must only
 * contain letters and spaces
 * Algorithm:
 * 1. While traversing the string parameter, do
 * 	1. If the current character is not a 
 * 	space or letter, then 
 * 		1. return an empty string
 * 	2. If the current character is a letter, then
 *		1. If the previous character is a space, then
 *			1. Append the uppercase of the current 
 *			character to the copy
 *		2. Else,
 *			1. Append the lowercase of the current 
 *			character to the copy
 *2. Return the copy
 */  

std::string Format(const std::string str)
{
	std::string result;
	char prev = '\0';

	for(const char i : str)
	{
		if(!isalpha(i) && i != ' ')
		{
			return std::string();
		}
		else if(isalpha(i))
		{
			result += (prev == ' ')?(toupper(i)):(tolower(i));
		}
		prev = i;
	}
	return result;
}

int main()
{
	std::cout << "Format(\"The new eNtraNce\") = " << Format("The new eNtraNce") << "\n";
	std::cout << "Format(\"All for 1and2\") = " << Format("All for 1and2") << "\n";
	return 0;
}
