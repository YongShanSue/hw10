
//////HW10.cpp		 
//////Author:	YUNG-SHAN SU 
//////Date: 5/7


///////////////////////Tutorial
//////If you want to use this code, you should change two parts:	
//////		Change the variable "size"  in line 24
//////		Change the data name  in line 35

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"MAT.h"
#include<math.h>
#include<sys/time.h>
void order_w_initial(VEC & order1, VEC &order2, VEC &order3, VEC &order4, VEC &order5, VEC &order6);
void generateY(double origin,double end, int N, VEC & y);
double NewtonCotes(VEC& y, VEC& order_w, int order, int regionN, double h);
void printOutput( int regionN, double range_origin,double range_end,double realdata);

VEC order_one_w(2);	VEC order_two_w(3);	VEC order_three_w(4);
VEC order_four_w(5);	VEC order_five_w(6);	VEC order_six_w(7);

int main(int argc,char **argv){
	int order = 1;
	int regionN = 12;
	double range_origin=0;
	double range_end=2;
	//double h=(range_end-range_origin)/regionN;
	double realdata=exp(2)-exp(0);
	double integral;
	order_w_initial(order_one_w, order_two_w, order_three_w, order_four_w,order_five_w, order_six_w);
	printOutput( 12, range_origin, range_end,realdata);

	printOutput( 24, range_origin, range_end,realdata);
	
	printOutput( 48, range_origin, range_end,realdata);
	printOutput( 96, range_origin, range_end,realdata);
	printOutput( 192, range_origin, range_end,realdata);
	printOutput( 384, range_origin, range_end,realdata);
	printOutput( 768, range_origin, range_end,realdata);
	printOutput( 1536, range_origin, range_end,realdata);
	
	return 0;
}	



void generateY(double origin,double end, int N, VEC & y){
	double interval = (end-origin) / N ;
	for(int i=0; i< N+1 ;i++)
		y[i]=exp(origin + interval*i);
	return;
}
void order_w_initial(VEC & order1, VEC &order2, VEC &order3, VEC &order4, VEC &order5, VEC &order6){
	/////////order 1 Initial//////
	order1[0]=1.0/2;	
	order1[1]=1.0/2;
	/////////order 2 Initial//////
	order2[0]=1.0/3;	
	order2[1]=4.0/3;
	order2[2]=1.0/3;	
	/////////order 3 Initial//////
	order3[0]=3.0/8;	
	order3[1]=9.0/8;
	order3[2]=9.0/8;
	order3[3]=3.0/8;	
	/////////order 4 Initial//////
	order4[0]=14.0/45;	
	order4[1]=64.0/45;
	order4[2]=24.0/45;
	order4[3]=64.0/45;
	order4[4]=14.0/45;
	
	/////////order 5 Initial//////
	order5[0]=95.0/288;	
	order5[1]=375.0/288;
	order5[2]=250.0/288;
	order5[3]=250.0/288;
	order5[4]=375.0/288;
	order5[5]=95.0/288;
	/////////order 6 Initial//////
	order6[0]=41.0/140;	
	order6[1]=216.0/140;
	order6[2]=27.0/140;
	order6[3]=272.0/140;
	order6[4]=27.0/140;
	order6[5]=216.0/140;
	order6[6]=41.0/140;
	return ;
}
double NewtonCotes(VEC &y, VEC &order_w, int order, int regionN, double h){
	long double integral=0;
	for(int i=0 ; i < regionN/order; i++){
		for(int k=0;k<order+1;k++){
			//printf("%lf\n",integral);
			integral += h * order_w[k] * y[i*(order)+k];
		}
	}
	return integral;
}
void printOutput( int regionN, double range_origin,double range_end,double realdata){
	double h=(range_end-range_origin)/regionN;
	long double integral;
	VEC y(regionN+1);
	generateY(range_origin,range_end,regionN,y);
	printf("IntervalNumber\t%d\n",regionN);
	integral = NewtonCotes(y, order_one_w, 1, regionN, h);
	printf("Order\t%d\tError\t%g\n",1,fabs(integral-realdata));
	integral = NewtonCotes(y, order_two_w, 2, regionN, h);
	printf("Order\t%d\tError\t%g\n",2,fabs(integral-realdata));
	integral = NewtonCotes(y, order_three_w, 3, regionN, h);
	printf("Order\t%d\tError\t%g\n",3,fabs(integral-realdata));
	integral = NewtonCotes(y, order_four_w, 4, regionN, h);
	printf("Order\t%d\tError\t%g\n",4,fabs(integral-realdata));
	integral = NewtonCotes(y, order_six_w, 6, regionN, h);
	printf("Order\t%d\tError\t%g\n",6,fabs(integral-realdata));
	printf("\n");
}