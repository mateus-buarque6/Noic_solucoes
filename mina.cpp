/* 
   Mateus Gonçalves - 05/18
   Mina - OBI 2015 F2P2
   Complexidade : O(N lg N)
*/

#include <bits/stdc++.h>

using namespace std;

// por comodidade
#define x first
#define y second
typedef pair <int, int> pii;

// defino as constantes e as variáveis que vou usar
const int MAXN = 110, INF = 0x3f3f3f3f;
int n, m[MAXN][MAXN], dist[MAXN][MAXN];
int dir[5] = {0, 1, 0, -1, 0};

void Dijkstra(void){
	dist[0][0] = 0; // a distância da fonte para ela mesma é 0
	priority_queue < pair<int, pii> > fila; // declaro a heap
	fila.push({-dist[0][0], {0, 0}}); // coloco a fonte na heap

	while(!fila.empty()){ // enquanto houverem elementos na fila de prioridade
		pii atual = fila.top().second; // pego o elemento do topo (mínimo)
   		fila.pop(); // retiro o mesmo

		for(int k = 0; k < 4; k++){ // analiso todos os vértices adjacentes à ele
			pii c = {atual.x + dir[k], atual.y + dir[k+1]}; // defino as coordenadas do vértice da vez
			
			// se o da vez estiver fora dos limites da matriz, pulo para o próximo
			if (c.x < 0 || c.x >= n || c.y < 0 || c.y >= n)
				continue; 
			
			// Se posso melhorar a distância do vértice da vez, faço isso e o coloco na fila
			if (dist[c.x][c.y] > dist[atual.x][atual.y] + m[c.x][c.y])
      			{
				dist[c.x][c.y] = dist[atual.x][atual.y] + m[c.x][c.y];
				fila.push({-dist[c.x][c.y], c});
			}	
		}
	}
}

int main(){
	scanf("%d", &n); // Leio o tamanho da entrada

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &m[i][j]); // Leio a matriz

	memset(dist, INF, sizeof dist); // "seto" todas as distâncias como infinito por padrão
	Dijkstra(); // Executo o algoritmo de Dijkstra

	printf("%d\n", dist[n-1][n-1]); // Printo o resultado
}
