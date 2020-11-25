#include"CriticalPath.h"

void InitCriticalPathArray(MGraph G, unsigned int** Ve, unsigned int** Vl)	//��ʼ���ؼ�·���㷨
{
		  *Ve = (unsigned int*)malloc(sizeof(int) * G.vexnum);
		  *Vl = (unsigned int*)malloc(sizeof(int) * G.vexnum);
		  assert(*Ve != NULL || *Vl != NULL);
		  memset(*Ve, 0, sizeof(unsigned int) * G.vexnum);
		  **Vl = 0;
		  memset(*Vl + 1, INFINITYSIZE, sizeof(unsigned int) * (G.vexnum - 1));		//��ʼ��Ӧ��Ϊ���ֵ
}

void DestroyCriticalPathArray(unsigned int* Ve, unsigned int* Vl)		  //���ٹؼ�·������
{
		  free(Ve);
		  free(Vl);
}

void CriticalPath(MGraph G)			//�ؼ�·���㷨
{
		  unsigned int* Ve = NULL;				//Ve�����緢��ʱ��Ve (k)
		  unsigned int* Vl = NULL;				//Vl����ٷ���ʱ��Vl (k)
		  InitCriticalPathArray(G, &Ve, &Vl);		  //��ʼ��

		  //���Ve���飺���緢��ʱ��
		  for (int i = 0; i < G.vexnum; ++i)				//������"dijstra�����·��"
		  {
					for (int pos = FindFirstNeighbor(G, G.Vex[i]); pos != -1; pos = FindNextNeighbor(G, G.Vex[i], G.Vex[pos]))
					{
							  if (Ve[i] + G.Edge[i][pos] > Ve[pos])				//�����
							  {
										Ve[pos] = Ve[i] + G.Edge[i][pos];
							  }
					}
		  }

		  printf("\n");
		  //���Vl���飺��ٷ���ʱ��
		  Vl[G.vexnum - 1] = Ve[G.vexnum - 1];		  //Ve���緢��ʱ����Vl������ʱ����ͬ
		  for (int i = G.vexnum - 2; i > 0; --i)
		  {
					for (int pos = FindFirstNeighbor(G, G.Vex[i]); pos != -1; pos = FindNextNeighbor(G, G.Vex[i], G.Vex[pos]))
					{
							  if (Vl[pos] - G.Edge[i][pos]  <Vl[i])				//����С
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