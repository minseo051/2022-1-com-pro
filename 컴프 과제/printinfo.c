#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void printtxt(char x[], struct info s) {					//[���׸� 7] ���� �����
	FILE* fp = NULL;
	if ((fp = fopen(x, "wt")) == NULL) {					//w �������� �̸� ������ν� ���� ������ ���� ����� ����
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", x);	
		exit(1);
	}
	fclose(fp);


	if ((fp = fopen(x, "at")) == NULL) {		
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", x);	
		exit(1);
	}

	fprintf(fp, "�̸�: %s, ����; %d, ����: %c, ���� �Ⱓ: %d, ���� ��ġ: %d\n", s.name, s.age, s.gender, s.leng, s.hurt);
	printf("\n");
	fclose(fp);
}
	
	