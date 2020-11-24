#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图
#include"CriticalPath.h"                      //关键路径

typedef struct Pair
{
          VertexType v1;
          VertexType v2;
          int distance;
}Pair;

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEFGHK" };
          CreateBatchVertex(&Graph, arr, NORMALGRAPH);      //顶点列表批量添加

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

          DisplayGraph(Graph);          //图的输出

          CriticalPath(Graph);

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}