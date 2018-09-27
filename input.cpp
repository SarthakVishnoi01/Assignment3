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
  ifstream read("test.graph");
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
  int realVariables = n*k + n*n; //
  int variables = realVariables+n*k*(k-1);
  int clauses = n + (3*n+1)*k*(k-1) + n*n + k*n*(n-1);
  int countZ=1;
  write << "p cnf " << variables << " " << clauses << endl; //Number of variables, Number of clauses

  /*Each vertex is present in atleast one subgraph*/
  for(int i=1; i<=n; i++){
    for(int j=0; j<k; j++){
      write << i+n*j << " ";
    }
    write << 0 << endl;
  }

  /*Subgraph checking*/
  for(int i=0; i<k; i++){
    for(int j=0; j<k; j++){
      //Checking if i is subgraph of j
      if(i!=j){
        int tempCountZ = countZ;
        for(int x=1; x<=n; x++){
          write << (realVariables+countZ) << " " << -1*(i*n+x) << " " << -1*(j*n+x) << " 0" << endl; //Z ki definition
          write << -1*(realVariables+countZ) << " " << (i*n+x) << " 0" << endl;
          write << -1*(realVariables+countZ) << " " << -1*(j*n+x) << " 0" << endl;
          countZ++;
        }
        for(int x=1; x<=n; x++){
          write << (realVariables+tempCountZ) << " ";
          tempCountZ++;
        }
        write << 0 << endl;
      }
    }
  }

  /*Adding Clauses for edges*/
  int edgesZero = n*k;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(edges[i][j]){
        write << (edgesZero+n*(i-1)+j) << " 0" << endl;
      }
      else{
        write << -1*(edgesZero+n*(i-1)+j) << " 0" << endl;
      }
    }
  }

  /*Adding Clauses for full connectivity*/
  for(int j=0; j<k; j++){
    for(int i=1; i<=n; i++){
      for(int l=i+1; l<=n; l++){
        write << -1*((n*j)+i) << " " << -1*((n*j)+l) << " " << (edgesZero+((i-1)*n)+l) << " 0" << endl;
      }
    }
    // write << 0 << endl;
  }

  write.close();
  cout << "Writing done!" << endl;
}
