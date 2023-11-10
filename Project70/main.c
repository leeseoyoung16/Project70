#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 500
#define INF 1000L

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];

}GraphType;

int selected[MAX_VERTICES]; //선택된 정점의 정보(선택 유무)
int distance[MAX_VERTICES]; //최소 거리 정보 배열

int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++) {
		if (!selected[i]) { //선택되지 않은 정점의 번호를 v에 저장
			v = i;
			break;

		}
	}
	for (i = 0; i < n; i++) { //선택된 정점이 최소거리인지 확인
		if (!selected[i] && (distance[i] < distance[v])) //선택되지 않고, 거리가 짧으면
			v = i;
	}
	return (v);
}

void prim(GraphType* g, int s) {
	int i, u, v;

	for (u = 0; u < g->n; u++) //초기화
		distance[u] = INF;
	distance[s] = 0; //자기자신 순회x
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return; //경로가 없다면 함수 종료
		printf("정점 %d 추가\n", u + 1);
		for (v = 0; v < g->n; v++) {
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
		}
	}
}


int main(void) {
	printf("Prim MST Algorithm\n");

	GraphType g = {10,	 //그래프 생성
	{{0 ,3 ,INF,INF,INF,11 ,12 ,INF,INF,INF},
	{3 ,0 ,5 ,4 ,1 ,7 ,8 ,INF,INF,INF},
	{INF,5 ,0 ,2 ,INF,INF,6 ,5 ,INF,INF},
	{INF,4 ,2 ,0 ,13 ,INF,INF,14 ,INF,16 },
	{INF,1 ,INF,13 ,0 ,9 ,INF,INF,18 ,10 },
	{11 ,7 ,INF,INF,9 ,0 ,INF,INF,INF,INF},
	{11 ,8 ,6 ,INF,INF,INF,0 ,13 ,INF,INF},
	{INF,INF,5 ,14 ,INF,INF,13 ,0 ,INF,15 },
	{INF,INF,INF,INF,18 ,INF,INF,INF,0 ,10},
	{INF,INF,INF,16 ,INF,INF,INF,15 ,10 ,0 } }
	};

	prim(&g, 0);
	return 0;
}