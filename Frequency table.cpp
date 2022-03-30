#include <bits/stdc++.h>

using namespace std;

vector <float> tab;

void calcula(float Xmin, float Xmax, int n){ 
   float i,Li,c,Fi,Fac,Fr,h;
   int k,j=0;
   
   k=round(sqrt(n));
   c=(Xmax-Xmin)/(k-1);
   Li=Xmin-(c/2);

    printf("                  Fi    Fr  Fac\n");

    Fac=Fr=0;

   for(i=Li;i<Xmax;i+=c){ 
       Fi=0;
       while((tab[j]<(i+c-0.001)) && (j<tab.size())){
           Fi++;
           j++;
       }
       Fr=((Fi*100/n)/100);
       Fac+=Fr;
       //cout<<i<<"|-> "<<i+c<<" "<<Fi<<" "<<((Fi*100)/n)/100<<"  "<<endl;
      printf("%7.2f |-> %5.2f   %.f  %.2f %.2f\n",i,i+c,Fi,Fr,Fac);
   }


}


int main(){ 
   float numero,n,total,totalQ,var;
   float Xmax,Xmin;
   
   cin>>n;

   total=totalQ=0;

  for(int i=0;i<n;i++){
      cin>>numero;
      tab.push_back(numero);
      total+=numero;
      totalQ+=pow(numero,2);
  }

  sort(tab.begin(),tab.end());

  Xmin=tab[0];
  Xmax=tab[n-1];

  calcula(Xmin,Xmax,n);

  var=(1/(n-1))*(totalQ-(pow(total,2)/n));

  
  cout<<endl<<"Media : "<<total/n<<endl;
  cout<<"Variance : "<<var<<endl;
  cout<<"Standard deviation : "<<sqrt(var)<<endl;
  cout<<"Coefficient of variation : "<<(sqrt(var)/(total/n))*100<<" %"<<endl;
  cout<<"First number of the set : "<<tab[0]<<endl<<"Last number of the set : "<<tab[n-1]<<endl<<"AT : "<<tab[n-1]-tab[0]<<endl;
}