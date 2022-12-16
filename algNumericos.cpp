#include "algNumericos.h"
#include <cmath>

int Nfeliz(int x){
	
	int aux=0,num=0;
	
	do{
		
		num=0;
		while(x>0){
			
			aux=x%10;
			x=x/10;
			num+=pow(aux,2);
			
		}
		
		if(num<10)
			  return num;
		else
			x=num;
		
	}while(x!=1 or x!=89 or x!=4);
	
	return x;	
}
	
double Raiz(int n){
	double a=6;
		
	if(n==0)
		return 3;
	else if(n==1)
		return 3+(1/a);
	else{
		a=1/a;
		for(int i=1;i<n;i++){
			
			a=1/(6+a);
			
		}
		a+=3;
	}
	return a;
}
	
double RaizR(int n){
			
	if(n==0)
		return n;
	else if(n==1)
		return n/6.00;
	else
		return  1.00/(6.00+RaizR(n-1));
}

unsigned long long LaGranFuncion(int n,int k){
	unsigned long long d=0,r,s;
	
	for(int j=1;j<=n;j++){

		if(n%j==0){

			if(k==1)
				d+=j;
			else if(k==0)
				d++;
		else{
			s=j;
			for(int i=1;i<k;i++){
				r=j*s;
				s=r;
			}
			d+=r;

			}
		}
		}
	return d;
}
