#include<bits/stdc++.h>
using namespace std;

int n,W;
vector<int> weight,value;
vector<vector<int>> price;

void read_input();
void knapsack();
void print_knapsack();

int main(){
    read_input();
    knapsack();
    cout<<"Maximum profit: "<<price[n][W]<<endl;
    print_knapsack();
    return 0;
}

void read_input(){
    freopen("knapsack.txt","r",stdin);
    cin>>W>>n;
    int x;
    weight.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>x;
        weight.push_back(x);
    }
    value.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>x;
        value.push_back(x);
    }
    price.resize(n+1,vector<int>(W+1));
}

void knapsack(){
    int i,j;
    for(i=0;i<=n;i++){
        price[i][0]=0;
    }
    for(i=0;i<=W;i++){
        price[0][i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=W;j++){
            if(weight[i]>j){
                price[i][j]=price[i-1][j];
            }
            else{
                price[i][j]=max(value[i]+price[i-1][j-weight[i]],price[i-1][j]);
            }
        }
    }
}

void print_knapsack(){
    int i,j=W;
    stack<int> items;
    for(i=n;i>0;i--){
        if(price[i][j]!=price[i-1][j]){
            items.push(i);
            j-=weight[i];
        }
    }
    cout<<"Items taken: ";
    while(!items.empty()){
        cout<<items.top()<<" ";
        items.pop();
    }
    cout<<endl;
}