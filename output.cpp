#include <bits/stdc++.h> //Can we use this??
#include "utils.h"
#include <math.h>
#include <random>

#define pb push_back
#define mp make_pair
#define ll long long int


using namespace std;

int main(int argc, char* argv[]){

  string file = argv[1];
  // cout << "File: " << file << endl;
  int n,m,k;
  string graph = file + ".graph";
  ifstream readg(graph);
  readg >> n >> m >> k;

  string satoutput = file + ".satoutput";
  ifstream read(satoutput);
  string str;
  getline(read,str);
  // cout << str << endl;
  ofstream write;
  string output = file + ".subgraphs";
  write.open(output);
  int r;
  if(str=="SAT"){
    for(int t=1; t<=k; t++){
      vector<int> v;
      for(int i=0; i<n; i++){
        read>>r;
        if(r>0){
          if(r%n==0)
            v.pb(n);
          else
            v.pb(r%n);
        }
      }
      write<<"#"<<t<<" "<<v.size()<<endl;
      for(int y=0; y<v.size(); y++){
        write<<v[y]<<" ";
      }
      write<<endl;
    }
  }else{
    write<<0;
  }

  write.close();
}
