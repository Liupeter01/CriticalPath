#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"CriticalPath.h"                      //�ؼ�·��

typedef struct Pair
{
          VertexType v1;
          VertexType v2;
          int distance;
}Pair;

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEFGHK" };
          CreateBatchVertex(&Graph, arr, NORMALGRAPH);      //�����б��������

          Pair pair[] =
          {
                    {'A','B',6},{'A','C',4},{'A','D',5},{'B','E',1},
                    {'C','E',1},{'D','F',2},{'E','G',9},{'E','H',7},
                    {'F','H',4},{'G','K',2},{'H','K',4},
          };

          for (int i = 0; i < sizeof(pair)/sizeof(Pair); ++i)
          {
                    InsertDirectEdgeValue(&Graph, pair[i].v1, pair[i].v2, pair[i].distance);
          }

          DisplayGraph(Graph);          //ͼ�����

          CriticalPath(Graph);

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}