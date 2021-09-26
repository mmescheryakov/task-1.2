#include <iostream>
#include <cmath>
using namespace std;

void init_zero(int** m, int N) {
	for (size_t i = 0; i != N; i++) 
		for (size_t j = 0; j != N; j++)
			m[i][j] = 0;	
}

void print_matrix(int**& m, int N) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++)
			cout << m[i][j] << ' ';
		cout << endl;
	}					
}

void spiral_matrix(int**& m, int N) {
	m = new int*[N];

	/*m[0] = new int[N * N];

	for (size_t i = 1; i != N; i++)
		m[i] = m[i - 1] + N;*/

	for (size_t i = 0; i < N; i++)
		m[i] = new int[N];
	

	int i,  j;
	i = j = 0;
	int count = 1;

	for (int p = 0; p < ceil((double)N / 2); p++) {
		for (i = p, j = p; j < N - p; ++j)
			m[i][j] = count++;
		for (i = p + 1, j--; i < N - p; i++)
			m[i][j] = count++;
		for (j = N - p - 2, i--; j >= p; j--)
			m[i][j] = count++;
		for (i = N - p - 2, j++; i >= p + 1; i--)
			m[i][j] = count++;
	}
}

int main() {
	int** m = nullptr, 
		  N;
	cin >> N;
	spiral_matrix(m, N);
	print_matrix(m, N);
	return 0;
}