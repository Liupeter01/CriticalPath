#pragma once
#include"MGraph.h"

void InitCriticalPathArray(MGraph G, unsigned int** Ve, unsigned int** Vl);	//��ʼ���ؼ�·���㷨
void DestroyCriticalPathArray(unsigned int* Ve, unsigned int* Vl);		  //���ٹؼ�·������
void CriticalPath(MGraph G);			//�ؼ�·���㷨