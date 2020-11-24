#include"CriticalPath.h"

void InitCriticalPathArray(MGraph G, int** Ve, int** Vl)	//��ʼ���ؼ�·���㷨
{
		  *Ve = (int*)malloc(sizeof(int) * G.vexnum);
		  *Vl = (int*)malloc(sizeof(int) * G.vexnum);
		  assert(*Ve != NULL || *Vl != NULL);
		  memset(*Ve, 0, sizeof(int) * G.vexnum);
		  memset(*Vl, 0, sizeof(int) * G.vexnum);
}

void DestroyCriticalPathArray(int* Ve, int* Vl)		  //���ٹؼ�·������
{
		  free(Ve);
		  free(Vl);
}

void CriticalPath(MGraph G)			//�ؼ�·���㷨
{
		  int* Ve = NULL;				//Ve�����緢��ʱ��Ve (k)
		  int* Vl = NULL;				//Vl����ٷ���ʱ��Vl (k)
		  InitCriticalPathArray(G, &Ve, &Vl);		  //��ʼ��

		  //���Ve���飺���緢��ʱ��
		  for (int i = 0; i < G.vexnum; ++i)				//������"dijstra�����·��"
		  {
					for (int pos = FindFirstNeighbor(G, G.Vex[i]); pos != -1; pos = FindNextNeighbor(G, G.Vex[i], G.Vex[pos]))
					{
							  if (Ve[i] + G.Edge[i][pos] > Ve[pos])
							  {
										Ve[pos] = Ve[i] + G.Edge[i][pos];
							  }
					}
		  }

		  //���Vl���飺��ٷ���ʱ��
		  Vl[G.vexnum - 1] = Ve[G.vexnum - 1];		  //Ve���緢��ʱ����Vl������ʱ����ͬ
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

		  //���ؼ�·�������e��l�Ĳ��ȷ���ؼ�·��
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					for (int pos = FindFirstNeighbor(G, G.Vex[i]); pos != -1; pos = FindNextNeighbor(G, G.Vex[i], G.Vex[pos]))
					{
							  int E = Ve[i];	  //��ȡ��e���ai�����緢��ʱ��e(i)
							  int L = Vl[pos] - G.Edge[i][pos];	 //��ȡ��l���ai����ٷ���ʱ��e(i)
							  if (E == L)		  //�ai�Ĳ���ùؼ�·��
							  {
										printf("<%c,%c>�ǹؼ�·��\n", G.Vex[i], G.Vex[pos]);
							  }
					}
		  }
		  DestroyCriticalPathArray(Ve, Vl);				  //����
}