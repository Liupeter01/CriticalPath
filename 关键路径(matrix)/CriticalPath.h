#pragma once
#include"MGraph.h"

void InitCriticalPathArray(MGraph G, unsigned int** Ve, unsigned int** Vl);	//初始化关键路径算法
void DestroyCriticalPathArray(unsigned int* Ve, unsigned int* Vl);		  //销毁关键路径数组
void CriticalPath(MGraph G);			//关键路径算法