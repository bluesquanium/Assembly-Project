#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
//City's coordinates
typedef struct {
	int x;
	int y;
} City;


//Calculate the distance between two cities.
float CalDistance(City city1, City city2);

int main(void) {
	City cities[8] = { { -1,-1 },{ 0,0 },{ 2,6 },{ 8,4 },{ 7,2 },{ 1,6 },{ 4,9 },{ 3,2 } }; //cities[i] is 'i'th city.
	int i, j, k, l, m, n;
	int result_path[8] = { 0, };
	float temp, min = 1.7e+307;
	float temptemp;
	
	float distances[8][8]; // Calculate distance between cities and save.
	for (i = 1; i <= 7; i++)
		for (j = 1; j <= 7; j++)
			distances[i][j] = CalDistance(cities[i], cities[j]);

	//Core Algorithm
	min = 1.7e+307;
	result_path[0] = result_path[7] = 1; //It means tour starts from city1 and finish to city1.
	
	for (i = 2; i <= 7; i++) {
		for (j = 2; j <= 7; j++) {
			if (j == i )
				continue;
			temptemp = distances[1][i] + distances[i][j] + distances[j][1];
			if ( temptemp > min )
				continue;
			for (k = 2; k <= 7; k++) {
				if (k == i || k == j )
					continue;
				temptemp = distances[1][i] + distances[i][j] + distances[j][k] + distances[k][1];
				if ( temptemp > min )
					continue;
				for (l = 2; l <= 7; l++) {
					if (l == i || l == j || l == k )
						continue;
					temptemp = distances[1][i] + distances[i][j] + distances[j][k] + distances[k][l]
							+ distances[l][1];
					if ( temptemp > min )
						continue;
					for (m = 2; m <= 7; m++) {
						if (m == i || m == j || m == k || m == l )
							continue;
						temptemp = distances[1][i] + distances[i][j] + distances[j][k] + distances[k][l]
								+ distances[l][m] + distances[m][1];
						if ( temptemp > min )
							continue;
						for (n = 2; n <= 7; n++) {
							if (n == i || n == j || n == k || n == l || n == m)
								continue;
							temp = distances[1][i] + distances[i][j] + distances[j][k] + distances[k][l]
								+ distances[l][m] + distances[m][n] + distances[n][1];
							if (min> temp) {
								min = temp;
								result_path[1] = i;
								result_path[2] = j;
								result_path[3] = k;
								result_path[4] = l;
								result_path[5] = m;
								result_path[6] = n;
							}
						}
					}
				}
			}
		}
	}
	//print results.
	printf("Path : ");
	for (i = 0; i<8; i++)
		printf("%d ", result_path[i]);
	putchar('\n');
	printf("Distance : %f\n", min);

	return 0;
}


float CalDistance(City city1, City city2) {
	float dx = city1.x - city2.x;
	float dy = city1.y - city2.y;
	return sqrt(dx*dx + dy * dy);
}
