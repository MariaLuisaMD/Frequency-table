#include <bits/stdc++.h>

using namespace std;

vector <float> tab;
float h;

void calcula(float Xmin, float Xmax, int n){ 
   float i,Li,c,Fi,Fac,Fr;
   int k,j=0;
   
   k=round(sqrt(n));
   c=(Xmax-Xmin)/(k-1);
   Li=Xmin-(c/2);


    cout<<setw(22)<<"Fi"<<setw(5)<<"Fr"<<setw(5)<<"Fac"<<endl;

    Fac=Fr=0;

   for(i=Li;i<Xmax;i+=c){ 
       Fi=0;
       while((tab[j]<(i+c-0.001)) && (j<tab.size())){
           Fi++;
           j++;
       }
       Fr=((Fi*100/n)/100);
       Fac+=Fr;
      
      printf("%7.2f |-> %5.2f   %.f  %.2f %.2f\n",i,i+c,Fi,Fr,Fac);
   }

   if(n%2==1){
       h=tab[((n)/2)];
   }
   else{
       h=(tab[(n/2)-1]+tab[((n+2)/2)-1])/2;
   }
}


int main(){ 
   float numero,n,total,totalQ,var;
   float Xmax,Xmin;
   cout<<"Enter the amount of data"<<endl;
   cin>>n;

   total=totalQ=0;
  cout<<"Enter the data: "<<endl;
   
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
  cout<<"First number of the set : "<<tab[0]<<endl<<"Last number of the set : "<<tab[n-1]<<endl<<"AT : "<<tab[n-1]-tab[0]<<endl<<"Median: "<<h<<endl;
}
