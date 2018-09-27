#include <bits/stdc++.h> //Can we use this??
#include "utils.h"
#include<math.h>
#include <random>

#define pb push_back
#define mp make_pair
#define ll long long int


using namespace std;

int main(){
  // cout << "Is it working" << endl;

  int n,m,k; //n->vertices, m->edges, k->number of subgraphs required
  vector<pair<int,int> > edgesIn;
  int tempA, tempB;
  /*Reading the input Data*/
  ifstream read("dataIn.txt");
  read >> n >> m >> k;
  for(int i=0; i<m; i++){
    read >> tempA >> tempB;
    edgesIn.pb(mp(tempA,tempB));
  }

  /*Calculations*/
  /*Edges*/
  bool edges[n+1][n+1] = { false };
  for(int i=0; i<n+1; i++){
    for(int j=0; j<n+1; j++){
      edges[i][j] = false;
    }
    edges[i][i] = true;
  }
  for(int i=0; i<edgesIn.size(); i++){
    int a = edgesIn[i].first;
    int b = edgesIn[i].second;
    edges[a][b] = edges[b][a] = true;
  }
  cout << "Edges[0][1] " << edges[0][1] << endl;
  /*Vertices*/
  bool vertices[n+1][k+1] = { false }; //index,subgraphs

  /*Writing the data Finally in the input file to SAT solver*/
  ofstream write;

  write.open ("inputTemp.cnf");
  write << "p cnf " << (n*k) << " " << n << endl; //Number of variables, Number of clauses
  /*Each vertex is present in atleast one subgraph*/
  for(int i=1; i<=n; i++){
    for(int j=0; j<k; j++){
      write << i+n*j << " ";
    }
    write << 0 << endl;
  }

  /*Subgraph checking*/
  for(int i=1; i<=k; i++){
    for(int j=1; j<=k; j++){
      //Checking if i is subgraph of j
      if(i!=j){

      }
    }
  }



  write.close();
  cout << "Writing done!" << endl;
}
