#include<bits/stdc++.h>
using namespace std;

string pattern,text;
vector <vector<int>> transitions;
vector<char> symbol = {'a','b'};
bool isSuffix(string pk, string pq)
{
    int k= pk.size();
    int q= pq.size();
    string temp= pq.substr(q-k);
    
    if(k> q) return false;
    if(temp == pk){
        return true;
    }
    return false;
}

void FAM()
{
    int n= text.size();
    int q=0, s=0;
    int count = 0;
    int m= pattern.length();
    for(int i=1; i<=n; i++)
    {
        q= transitions[q][text[i]-'a'];
        if(q==m)
        {
            s= i-m;
            cout << "pattern occurs with shift " << s << endl;
            count ++;
        }
    }
    cout << count << endl;
}

void ctf()
{
    int m= pattern.size();
    transitions.resize(m+1, vector<int>(symbol.size()));
    int k;
    for(int q=0; q<=m; q++)
    {
        for(auto i: symbol)
        {
            k= 1+ min(m, q+1);
            while(true)
            {
                k--;
                string pk= pattern.substr(0, k);
                string pq= pattern.substr(0,q);
                pq.push_back(i);
                if(isSuffix(pk, pq)) break;
            }
            transitions[q][i-'a']= k;
        }
    }
}

int main(){
    freopen("pattern.txt","r",stdin);
    cin >> pattern >> text;
    ctf();

    for(auto i: transitions)
    {
        for(auto k: i)
        {
            cout << k << " ";
        }
        cout << endl;
    }
    
    FAM();
}