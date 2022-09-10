// author: Vinicius Mari Marrafon
// signature: ViMM
// date: 11/01/2021

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int tour[8][8] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 }
};

bool Knight[64][64]; 	 // grafo
bool vis[64];		 // vis

void print_house( int vertex )
{
	char col = vertex % 8 + 'a';
	int line = (vertex/ 8) + 1;

	printf("vertex[%02d] = %c%d\n", vertex, col, line);
}

void print_board( int l, int c )
{
	system("cls"); // system("clear") - se vc usar linux ou o Power Shell

	for( register int i = 0; i < 8; i++ )
	{
		for( register int j = 0; j < 8; j++ )
		{
			if( i == l && j == c )
				printf("\033[1;94mN\033[0m ");
			else if( tour[i][j] != 0 )
				printf("\033[1;92m#\033[0m ");
			else
				printf("\033[1;90m#\033[0m ");
		}
		printf("\n");
	}

	sleep(1);
}

int check_options( int vertex )
{
	int s_adj = 8;		// Adjacencia maxima = 8
	int s_vertex = vertex;  // Ninguem mais do que o vertice atual

	// adj de vertex
	for( int i = 0; i < 64; i++ )
	{
		if( vis[i] || !Knight[vertex][i] ) continue;

		int count_adj = 0;

		// adj de i
		for( int j = 0; j < 64; j++ )
		{
			if( vis[j] || !Knight[i][j] ) continue;
			count_adj++;
		}

		if( count_adj < s_adj )
		{
			s_adj = count_adj;
			s_vertex = i;
		}
	}

	return s_vertex;
}


void solve_knight_tour( int x0 )
{
	static int move = 1;
	// move to the vertex with least adjacences members
	vis[x0] = true;

	int col = ( x0 % 8 + 'a' )% 'a';
	int lin = 8 - (( x0/ 8 ) + 1);

	tour[lin][col] = move++;

	print_board( lin, col );

	int next = check_options( x0 );

	if( next == x0 ) return;

	solve_knight_tour( next );
}

void create_knight_graph( void )
{
	for( int i = 0; i < 64; i++ )
		for( int j = 0; j < 64; j++ )
		{
			Knight[i][j] = false;

			if( j == i + 06 && i % 8 > 1 ) Knight[i][j] = true;
			if( j == i + 15 && i % 8 > 0 ) Knight[i][j] = true;
			if( j == i + 17 && i % 8 < 7 ) Knight[i][j] = true;
			if( j == i + 10 && i % 8 < 6 ) Knight[i][j] = true;

			if( j == i - 06 && i % 8 < 6 ) Knight[i][j] = true;
			if( j == i - 15 && i % 8 < 7 ) Knight[i][j] = true;
			if( j == i - 17 && i % 8 > 0 ) Knight[i][j] = true;
			if( j == i - 10 && i % 8 > 1 ) Knight[i][j] = true;
		}
}

int main( void )
{
	create_knight_graph();

	for( register int i = 0; i < 64; i++ )
	{
		//printf("Vertex[%d]:: ", i );
		for( register int j = 0; j < 64; j++ )
			//if( Knight[i][j] )
			printf("%d ", Knight[i][j]);
				//printf("%d --> ", j );
		printf("\\\n");
	}

	solve_knight_tour( 8 );
	print_board(-1,-1);

	printf("\n");
	for( int i = 0; i < 8; i++ )
	{
		for( int j = 0; j < 8; j++ )
			printf("%02d ", tour[i][j]);
		printf("\n");
	}

	for( int i = 0; i < 64; i++ )
		printf("%d ", vis[i] );
	puts("");

	return 0;
}





