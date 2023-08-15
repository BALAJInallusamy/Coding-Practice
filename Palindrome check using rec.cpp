#include <bits/stdc++.h>
using namespace std;
bool palindrome_rec(string s,int n,int i){
	if(n==1) return true;
	if(i==n/2) return true;
	if(s[i]!=s[n-i-1]) return false;
	
	return	palindrome_rec(s,n,i+1);
	
}
int main(){
	string input;
	cin>>input;
	int n=input.size();
	if(palindrome_rec(input,n,0)) cout<<input<<" is a Palindrome";
	else cout<<input<<" is NOT a Palindrome";
	return 0;
}