#include "stdc++.h"
using namespace std;

int lcp(string a, string b){
	int ai = a.length();
	int ac = 0;
	int bc = 0;
	int maxLength = 0;
	while(ac < ai){
		if(a[ac] == b[bc]){
			maxLength += 1;
			ac += 1;
			bc += 1;
		}
		else 
			return maxLength;
	}
	return maxLength;	
}

int substringcount(string s){
	string sfxArr[s.length()];
	for(int i=0; i<s.length(); i++)
		sfxArr[i] = s.substr(i,s.npos);
	sort(sfxArr,sfxArr+s.length());
	/*for(int i=0; i<s.length(); i++)
		cout << sfxArr[i] << endl;*/
	int subtract = 0;
	for(int i=1; i<s.length(); i++)
		subtract += lcp(sfxArr[i-1],sfxArr[i]);
	return s.length()*(s.length()+1)/2-subtract+1;
}

int main(){
	int n;
	string s;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		cin >> s;
		cout << substringcount(s) << endl;
	}

	return 0;
}
