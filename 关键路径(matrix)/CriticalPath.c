#include"CriticalPath.h"

void InitCriticalPathArray(MGraph G, int** Ve, int** Vl)	//初始化关键路径算法
{
		  *Ve = (int*)malloc(sizeof(int) * G.vexnum);
		  *Vl = (int*)malloc(sizeof(int) * G.vexnum);
		  assert(*Ve != NULL || *Vl != NULL);
		  memset(*Ve, 0, sizeof(int) * G.vexnum);
		  memset(*Vl, 0, sizeof(int) * G.vexnum);
}

void DestroyCriticalPathArray(int* Ve, int* Vl)		  //销毁关键路径数组
{
		  free(Ve);
		  free(Vl);
}

void CriticalPath(MGraph G)			//关键路径算法
{
		  int* Ve = NULL;				//Ve：最早发生时间Ve (k)
		  int* Vl = NULL;				//Vl：最迟发生时间Vl (k)
		  InitCriticalPathArray(G, &Ve, &Vl);		  //初始化

		  //求解Ve数组：最早发生时间
		  for (int i = 0; i < G.vexnum; ++i)				//类似于"dijstra查找最长路径"
		  {
					for (int pos = FindFirstNeighbor(G, G.Vex[i]); pos != -1; pos = FindNextNeighbor(G, G.Vex[i], G.Vex[pos]))
					{
							  if (Ve[i] + G.Edge[i][pos] > Ve[pos])
							  {
										Ve[pos] = Ve[i] + G.Edge[i][pos];
							  }
					}
		  }

		  //求解Vl数组：最迟发生时间
		  Vl[G.vexnum - 1] = Ve[G.vexnum - 1];		  //Ve最早发生时间与Vl最晚发生时间相同
		  for (int i = G.vexnum - 2; i > 0; --i)
		  {
					for (int pos = FindFirstNeighbor(G, G.Vex[i]); pos != -1; pos = FindNextNeighbor(G, G.Vex[i], G.Vex[pos]))
					{
							  if (Vl[pos] - G.Edge[i][pos]  >Vl[i])
							  {
										Vl[i] = Vl[pos] - G.Edge[i][pos];
							  }
					}
		  }

		  //求解关键路径，求解e和l的差额确定关键路径
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					for (int pos = FindFirstNeighbor(G, G.Vex[i]); pos != -1; pos = FindNextNeighbor(G, G.Vex[i], G.Vex[pos]))
					{
							  int E = Ve[i];	  //获取数e，活动ai的最早发生时间e(i)
							  int L = Vl[pos] - G.Edge[i][pos];	 //获取数l，活动ai的最迟发生时间e(i)
							  if (E == L)		  //活动ai的差额，求得关键路径
							  {
										printf("<%c,%c>是关键路径\n", G.Vex[i], G.Vex[pos]);
							  }
					}
		  }
		  DestroyCriticalPathArray(Ve, Vl);				  //销毁
}