#include <iostream>
#include <cstdlib>


//Test 3. Initialize algorithm
void Initialize(int **A, int N){

		int value = 1, i = 0;


		while(value <= N*N){
		for(int j = i; j < N - i; j++)
			A[i][j] = value++;
		
		for(int j = i + 1; j < N - i; j++)
			A[j][N - i - 1] = value++;
		

		for(int j = N - i - 2; j >= i; j--)
			A[N - i - 1][j] = value++;
		

		for(int j = N - i - 2; j > i; j--)
			A[j][i] = value++;
	
		++i;	
	}

}

//Prints array 
void Print(int **A, int N){

	for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
			 	printf("%2d ", A[i][j]); 
			}
				std::cout << std::endl;
		}
}

int main(){



	int N = 2;
	int **A = (int **) malloc(sizeof(N * sizeof(int *)));
	for(int i = 0; i < N; i++){
		A[i] = (int *) malloc(N * sizeof(int *));
	}

	std::cout << "2-nd case, N = 2" << std::endl;
	Initialize(A, N);
	Print(A, N);

	for(int i = 0; i < N; i++){
		free(A[i]);
	}
	free(A);	

	N = 4; 
     A = (int **) malloc(sizeof(N * sizeof(int *)));
	for(int i = 0; i < N; i++){
		A[i] = (int *) malloc(N * sizeof(int *));
	}

	std::cout << "1-st case, N = 4" << std::endl;
	Initialize(A, N);
	Print(A, N);

	return 0;
}