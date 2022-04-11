// C++ code to implement above approach
#include <bits/stdc++.h>
using namespace std;

// Stack to store intermediate strings
stack<string> ans;
string res = "";

// Recusrsive function to decode
// the encoded string
void decode(string s, int i)
{
	if (i == s.length()) {
		res = ans.top();
		return;
	}
	
	// If the string character is '['
	if (s[i] == '[');
	
	// If the string character is ']'
	else if (s[i] == ']') {
		string temp = ans.top();
		ans.pop();
		int x = stoi(ans.top());
		ans.pop();
		for (string j = temp; x > 1; x--)
			temp = temp + j;
		string temp1
			= ans.empty() == false ?
			ans.top() : "";
		
		if (!temp1.empty() &&
			!(temp1[0] - '0' < 10)) {
			ans.pop();
			temp1 = temp1 + temp;
			ans.push(temp1);
		}
		else {
			ans.push(temp);
		}
	}

	// If string character is a digit
	else if (s[i] - '0' < 10) {	
		string temp =
			ans.empty() == false ?
			ans.top() : "";
	
		if (!temp.empty() &&
			temp[0] - '0' < 10
			&& s[i - 1] - '0' < 10) {
			ans.pop();
			temp = temp + s[i];
			ans.push(temp);
		}   
		else {
			temp = s[i];
			ans.push(temp);
		}	
	}
	
	// If the string character is alphabet
	else if (s[i] - 'a' < 26) {	
		string temp =
			ans.empty() == false ?
			ans.top() : "";
	
		if (!temp.empty() &&
			temp[0] - 'a' >= 0
			&& temp[0] - 'a' < 26) {
			ans.pop();
			temp = temp + s[i];
			ans.push(temp);
		}
		else {
			temp = s[i];
			ans.push(temp);
		}
	}
	
	// Recursive call for next index
	decode(s, i + 1);
}

// Function to call the recursive function
string decodeString(string s)
{
	decode(s, 0);
	return res;
}

// Driver code
int main()
{
	string str = "100[a]";
	cout << decodeString(str) << endl;
	return 0;
}
