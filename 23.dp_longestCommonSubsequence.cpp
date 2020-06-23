// Given two sequence X = <x1,x2,...,xm>, Y = <y1,y2,...,yn>
// find maximum LCS from X and Y
// appear in same order, but not necessarily consecutively

#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

char B[100][100];

void printLCS(char *X, int i, int j){
    if(i==0 || j==0){
        return;
    }
    if(B[i][j] == 'd' ){
        printLCS(X,i-1,j-1);
        cout<<X[i-1]<<" ";
    }
    else if(B[i][j] == 'u' ){
        printLCS(X,i-1,j);
    }
    else{
        printLCS(X,i,j-1);
    }
}

int lcs( char *X, char *Y, int m, int n ){

    int i, j;
    int C[m + 1][n + 1];

    for (i = 0; i <= m; i++){
        for (j = 0; j <= n; j++){
            if (i == 0 || j == 0){
               C[i][j] = 0;
               B[i][j]='o';
            }
            else if (X[i-1] == Y[j-1]){
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 'd'; // diagonal //match
            }
            else if(C[i - 1][j]>=C[i][j - 1]){
                    C[i][j] = C[i - 1][j];
                    B[i][j] = 'u'; // up //max
            }
            else{
                 C[i][j] = C[i][j - 1];
                 B[i][j] = '_';
            }
        }
    }
    //display tableC
    cout<<"tableC: \n";
    for(i=0;i<m+1;i++){
        for(j=0;j<n+1;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"tableB: \n";
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            cout<<B[i][j]<<" ";
        }
        cout<<"\n";
    }
    //print LCS
    cout<<"\n";
    printLCS(X,m,n);
    return C[m][n];
}

int max(int a, int b){ return (a > b)? a : b; }
int main(){

    char X[] = "ABCBDAB";
    char Y[] = "BDCABA"; //bcba

    //char X[] = "AGGTAB";
    //char Y[] = "GXTXAYB"; //gtab

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length: " << lcs( X, Y, m, n );

    return 0;
}
