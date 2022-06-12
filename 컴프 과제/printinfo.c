#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void printtxt(char x[], struct info s) {					//[평가항목 7] 파일 입출력
	FILE* fp = NULL;
	if ((fp = fopen(x, "wt")) == NULL) {					//w 형식으로 미리 열어봄으로써 같은 내용의 파일 존재시 삭제
		fprintf(stderr, "파일 %s를 열 수 없습니다.\n", x);	
		exit(1);
	}
	fclose(fp);


	if ((fp = fopen(x, "at")) == NULL) {		
		fprintf(stderr, "파일 %s를 열 수 없습니다.\n", x);	
		exit(1);
	}

	fprintf(fp, "이름: %s, 나이; %d, 성별: %c, 앓은 기간: %d, 아픔 수치: %d\n", s.name, s.age, s.gender, s.leng, s.hurt);
	printf("\n");
	fclose(fp);
}
	
	