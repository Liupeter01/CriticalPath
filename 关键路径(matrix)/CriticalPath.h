#pragma once
#include"MGraph.h"

void InitCriticalPathArray(MGraph G,int** Ve, int** Vl);	//��ʼ���ؼ�·���㷨
void DestroyCriticalPathArray(int* Ve, int* Vl);		  //���ٹؼ�·������
void CriticalPath(MGraph G);			//�ؼ�·���㷨