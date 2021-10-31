#include <iostream>
#include <math.h>
#include"Vector3D.h"
#include <bits/stdc++.h>
#include <string>
using namespace std;

void print(const string& word){
	cout << word << endl;
}

int main(int argc, char* argv[]){
  double x,y,z,u,v,w,a;

  if(argc==4){
    x=atof(argv[1]);
    y=atof(argv[2]);
    z=atof(argv[3]);
  }
  else{
    print("Inserire le coordinate del primo vettore.");
    cin>>x;
    cin>>y;
    cin>>z;
  }
  
  print("Inserire le coordinate del secondo vettore.");
    cin>>u;
    cin>>v;
    cin>>w;

  print("Inserire la costante moltiplicativa.");
    cin>>a;
  cout<<endl;
  Vector3D v1(x,y,z);
  Vector3D v2(u,v,w);

  print("Dati di v1");
  cout<<v1<<endl;
  cout<<"r: "<<v1.r()<<endl;
  cout<<"theta (rad): "<<v1.theta()<<"\t"<<"theta (grad): "<<v1.theta()*180/M_PI<<endl;
  cout<<"phi (rad): "<<v1.phi()<<"\t"<<"phi (grad): "<<v1.phi()*180/M_PI<<endl;
  v1.printSph();
  cout<<endl;

  print("Dati di v2");
  cout<<v2<<endl;
  cout<<"r: "<<v2.r()<<endl;
  cout<<"theta (rad): "<<v2.theta()<<"\t"<<"theta (grad): "<<v2.theta()*180/M_PI<<endl;
  cout<<"phi (rad): "<<v2.phi()<<"\t"<<"phi (grad): "<<v2.phi()*180/M_PI<<endl;
  v2.printSph();
  cout<<endl;

  Vector3D v3=v1+v2;
  cout<<"v1+v2:\t"<<v3<<endl;

  Vector3D v4=v1-v2;
  cout<<"v1-v2:\t"<<v4<<endl;
  
  Vector3D v5=v1;
  cout<<"v5=v1:\t"<<v5<<endl;

  Vector3D v6=v1*a;
  cout<<"v1*"<<a<<":\t"<<v6<<endl;

  Vector3D v7=v1/a;
  cout<<"v1/"<<a<<":\t"<<v7<<endl;

  double sp=v1.ScalarProd(v2);
  cout<<"v1 scalar v2:\t"<<sp<<endl;

  Vector3D v8=v1.VectorProd(v2);
  cout<< "v1 vettor v2:\t"<<v8<<endl;

  double angle=v1.angle(v2);
  cout<<"angolo tra v1 e v2 (rad): "<<angle<<"\n"<<"angolo tra v1 e v2 (grad): "<<angle*180/M_PI<<endl;
  


  return 0;
}
