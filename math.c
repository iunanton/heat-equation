#include <stdio.h>
#include <math.h>

const
	unsigned int N = 36;
	double K = 2.04e2, C = 2.51e6, CFM = 2.49e2, S = 1e-5, L = 5e-3, H = L/N, D = 0.2*H*H*C/K, T0 = 300, T1 = 600, T2 = 348;

typedef
	double array[N];

void print(array A, double t)
{
	printf("t= %3.0f|", t);
	for(int i = 0; i < N; i++){
		printf("%3.0f ", A[i]-273);
	}
	printf("\n");
}

int main()
{
//Mathematical modeling of heating of the gold wire soldered to the aluminum terminal of the microchip
	printf("안녕하세요!=)\n");
	array Ma, Mb;
	int k = 0;
	Mb[0] = T1;
	for(int i = 1; i < N; i++)
		Mb[i] = T0;
	do{
		print(Mb, k*D);
		for(int j = 0; j < 50000; j++){
			Ma[0] = T1;
			for(int i = 1; i < N-1; i++)
				Ma[i] = K*D*(Mb[i-1]-2*Mb[i]+Mb[i+1])/(H*H*C)+Mb[i];
			Ma[N-1] = -S*K*D*(Mb[N-1]-Mb[N-2])/(H*CFM)+Mb[N-1];
			for(int i = 0; i < N; i++)
				Mb[i] = Ma[i];
			k++;
		}
	}while (Mb[N-1] < T2);
	return 0;
}
