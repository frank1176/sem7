#include "omp.h"
#include "stdio.h"


int main() {
	int x = 5;

	#pragma omp parallel
	{
		int x = 5;
		x = x + 1;
		int ID = omp_get_thread_num();
		printf("share: x is %d at process(%d)\n", x, ID);
		
	}
	printf("final:x is %d\n",x);
	return 0;
}

