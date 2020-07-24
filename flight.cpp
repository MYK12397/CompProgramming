#include<iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  int ***E = new int**[t];
  int *sizes = new int[t];
  for(int tc=0;tc<t;tc++)
  {

    int n;
    cin>>n;
    char *incomming = new char[n];
    char *outgoing  = new char[n];
    for(int i=0;i<n;i++)
     cin>>incomming[i];
    for(int i=0;i<n;i++)
     cin>>outgoing[i];
    int **edges = new int*[n];
    for(int i=0;i<n;i++) {
      edges[i] = new int[n];
      for(int j=0;j<n;j++)
      edges[i][j]=0;
    }
    for(int i=0;i<n;i++) {
       int j=i+1;
        while( j<n && incomming[j]=='Y' && outgoing[j-1]=='Y'){
          edges[i][j]=1;
          j++;
        }
       j=i-1;
       while(j>=0 && incomming[j]=='Y' && outgoing[j+1]=='Y'){
         edges[i][j]=1;
         j--;
       }
       edges[i][i]=1;
      }

      E[tc] = edges;
      sizes[tc] = n;
    }
  for(int i=0;i<t;i++){
    cout<<"Case #"<<t+1<<":"<<endl;
    for(int j=0;j<sizes[i];j++)
     {
       for(int k=0;k<sizes[i];k++) {
        if(E[i][j][k])
        cout<<"Y";
        else
        cout<<"N";
      }
       cout<<endl;
     }
   }
}
/*
8
2
YY
YY
2
NY
YY
2
NN
YY
5
YNNYY
YYYNY
10
NYYYNNYYYY
YYNYYNYYNY
20
YYNYNYNYNNYYYYYYNYNY
NYYYNYNYYNNYNYYNNYYY
50
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
50
YNYYYYNYNYYYNYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYNYNYYYY
YYYYYYYYYYYYYYNYYYYYYYNYYYYYNYYYYNYYNYYYYNNYYYYYYY
*/
