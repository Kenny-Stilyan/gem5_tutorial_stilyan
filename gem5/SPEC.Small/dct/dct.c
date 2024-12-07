
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
                  
#define N 8
                        
int I[N][N],O[N][N] ;
float temp[N][N] ;
float temp1 ;
                                                   
float C[N][N] = {
	{ 0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.490393 },
	{ 0.490393, 0.415735, 0.277785, 0.097545, -0.097545, -0.277785, -0.415735, 0.461940 },
	{ 0.461940, 0.191342, -0.191342, -0.461940, -0.461940, -0.191342, 0.191342, 0.415735 },
	{ 0.415735, -0.097545, -0.490393, -0.277785, 0.277785, 0.490393, 0.097545, 0.353553 },
	{ 0.353553, -0.353553, -0.353553, 0.353553, 0.353553, -0.353553, -0.353553, 0.277785 },
	{ 0.277785, -0.490393, 0.097545, 0.415735, -0.415735, -0.097545, 0.490393, 0.191342 },
	{ 0.191342, -0.461940, 0.461940, -0.191342, -0.191342, 0.461940, -0.461940, 0.097545 },
	{ 0.097545, -0.277785, 0.415735, -0.490393, 0.490393, -0.415735, 0.277785, 0.000000 }
};

float Ct[N][N] = {
	{ 0.353553, 0.490393, 0.461940, 0.415735, 0.353553, 0.277785, 0.191342, 0.353553 },
	{ 0.353553, 0.415735, 0.191342, -0.097545, -0.353553, -0.490393, -0.461940, 0.353553 },
	{ 0.353553, 0.277785, -0.191342, -0.490393, -0.353553, 0.097545, 0.461940, 0.353553 },
	{ 0.353553, 0.097545, -0.461940, -0.277785, 0.353553, 0.415735, -0.191342, 0.353553 },
	{ 0.353553, -0.097545, -0.461940, 0.277785, 0.353553, -0.415735, -0.191342, 0.353553 },
	{ 0.353553, -0.277785, -0.191342, 0.490393, -0.353553, -0.097545, 0.461940, 0.353553 },
	{ 0.353553, -0.415735, 0.191342, 0.097545, -0.353553, 0.490393, -0.461940, 0.353553 },
	{ 0.353553, -0.490393, 0.461940, -0.415735, 0.353554, -0.277785, 0.191342, 0.000000 }
};

void DCT( int input[N][N], int output[ N ][ N ])
{
	       
	  int i, j,k;                                                                                              
	 /*  MatrixMultiply( temp, input, Ct ); */
	     for ( i = 0 ; i < N ; i++ ) {
	             for ( j = 0 ; j < N ; j++ ) {
	                 temp[ i ][ j ] = 0.0;
		             for ( k = 0 ; k < N ; k++ )
		                      temp[ i ][ j ] += ( (int) input[ i ][ k ] - 128 ) * Ct[ k ][ j ];
		             }
	         }
		                                                                                                         
     /*  MatrixMultiply( output, C, temp ); */
        for ( i = 0 ; i < N ; i++ ) {
	         for ( j = 0 ; j < N ; j++ ) {
	             temp1 = 0.0;
                     for ( k = 0 ; k < N ; k++ )
		                temp1 += C[ i ][ k ] * temp[ k ][ j ];
  		     output[ i ][ j ] = (int) temp1 ;
		     }
		}
}
		                                   
int main(){
	
	DCT(I,O);
	return 0;

}
