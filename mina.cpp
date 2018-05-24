#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair <int, int> pii;

const int MAXN = 110, INF = 0x3f3f3f3f;
int n, m[MAXN][MAXN], dist[MAXN][MAXN];
int dir[5] = {0, 1, 0, -1, 0};

void Dijkstra(void){
	dist[0][0] = 0;
	priority_queue < pair<int, pii> > fila;
	fila.push({-dist[0][0], {0, 0}});

	while(!fila.empty()){
		pii atual = fila.top().second;
    fila.pop();

		for(int k = 0; k < 4; k++){
			pii c = {atual.x + dir[k], atual.y + dir[k+1]};

			if (c.x < 0 || c.x >= n || c.y < 0 || c.y >= n)
				continue;

			if (dist[c.x][c.y] > dist[atual.x][atual.y] + m[c.x][c.y])
      {
				dist[c.x][c.y] = dist[atual.x][atual.y] + m[c.x][c.y];
				fila.push({-dist[c.x][c.y], c});
			}	
		}
	}
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &m[i][j]);

	memset(dist, INF, sizeof dist);
	Dijkstra();

	printf("%d\n", dist[n-1][n-1]);
}