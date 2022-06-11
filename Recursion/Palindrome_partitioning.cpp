#include <bits/stdc++.h>

using namespace std;

bool ispalindrome(string str){
    int start = 0;
    int end = str.length()-1;

    while(start<end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
    
}

void palpar(int ind, string s,vector<string> res, vector<vector<string>> &ans){
    if(ind  == s.length()){
        ans.push_back(res);
        return;
    }
    for(int i = ind; i< s.length();i++){
        if(ispalindrome(s.substr(0,ind))){
            res.push_back(s.substr(0,ind)) ;
            palpar(i+1,s,res,ans);
            res.pop_back();   
        }
    }
}


vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> res;
    palpar(0,s,res,ans);
    return ans;
}

int main()
{
    string s;
    getline(cin,s);

    // vector<vector<string>> result = partition(s);

    // for (auto x : result)
    // {
    //     for(auto y : x){
    //         cout<<y<<"  ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<s.substr(1,2);
    

return 0;
}