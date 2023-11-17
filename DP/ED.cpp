#include<bits/stdc++.h>
using namespace std;
#define UP 1
#define SIDE 2
#define DIAG 3
#define NO_EDIT 4
int arrow[100][100];
void printED(char first[],char second[],int i,int j){
    // cout << first[i] << " " << second[j] << endl;
    if(arrow[i][j]==NO_EDIT){
        printED(first,second,i-1,j-1);
    }
    else if(arrow[i][j]==DIAG){
        printED(first,second,i-1,j-1);
        cout << "Replace " << first[i] << " with " << second[j] << endl;
    }
    else if(arrow[i][j]==UP){
        printED(first,second,i-1,j);
        cout << "Delete " << first[i] << " from first string." << endl;
    }
    else if(arrow[i][j]==SIDE){
        printED(first,second,i,j-1);
        cout << "Insert " << second[j] << " at positon " << (i+1) << endl;
    }
    return;
}
int main(){
    string one,two;
    cout << "Enter first string: ";
    cin >> one;
    cout << "Eneter second string: ";
    cin >> two;
    int m = one.size(),n = two.size();
    char first[m+1],second[n+1];
    int c[m+1][n+1];
    for(int i=0; i<m; i++)first[i+1] = one[i];
    for(int i=0; i<n; i++)second[i+1] = two[i];
    for(int i=0; i<=m; i++)c[i][0] = i;
    for(int i=0; i<=n; i++)c[0][i] = i;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(first[i]==second[j]){
                c[i][j] = c[i-1][j-1];
                arrow[i][j] = NO_EDIT;
            }
            else{
                c[i][j] = min(c[i-1][j-1],min(c[i-1][j],c[i][j-1])) + 1;
                if(c[i][j]-1==c[i-1][j-1]){
                    arrow[i][j] = DIAG;
                }
                else if(c[i][j]-1==c[i-1][j]){
                    arrow[i][j] = UP;
                }
                else{
                    arrow[i][j] = SIDE;
                }
            }
        }
    }
    cout << "Edit Distance between " << one << " & " << two << " is: " << c[m][n] << endl;
    cout << endl;
    for(int i=1; i<=m; i++)arrow[i][0] = UP; 
    for(int i=1; i<=n; i++)arrow[0][i] = SIDE; 
    printED(first,second,m,n);
    return 0;
}