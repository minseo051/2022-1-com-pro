/* [평가항목 1] : 과제 설명
* 
* 컴퓨터프로그래밍 평가과제 (배점 25점)
* 학과: 컴퓨터공학부
* 학번: 202102978
* 이름: 전민서
* 
* 과제 주제: 코로나에 걸린적이 없는 사람들을 위해 코로나에 걸린 사람의 낫기까지의 기간, 그로 인한 고통 등의 경험 입력하여 보여주는 프로그램

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "struct.h"

double average(int, int);

int main() {
	
	struct info s[100];						//[평가 항목 3] 배열, [평가 항목 5] 구조체 사용
	int i = 0;
	char righ;
	int ma = 1;
	double (*cal)(int, int);				//[평가 항목 4] 포인터 사용

	cal = average;							//[평가 항목 6] 포인터 활용
	
	while (ma == 1) {

		int order = 0;
		int f = 1;

		printf("1.정보 입력\n");
		printf("2.정보 보기\n");
		printf("3.평균 최대 고통 수치\n");
		printf("4.파일로 출력\n");
		printf("종료하려면 Q를 입력하시오\n");

		order = getchar();

		if (order == '1') {						//정보, 아픈 일 수, 최대 고통 수치 입력
			int a = 1;
			while (f == 1) {
				printf("이름: ");
				scanf("%s", &s[i].name);

				printf("나이: ");
				scanf("%d", &s[i].age);

				while (1) {
					printf("성별(m/w): ");
					scanf("%s", &s[i].gender);

					if (s[i].gender == 'w' || s[i].gender == 'm')
						break;
					else
						printf("잘못된 입력입니다. 다시 입력해 주세요.");

				}
				printf("코로나를 앓은 기간(일): ");
				scanf("%d", &s[i].leng);
				loop:
					printf("아픔을 수치로 표현하면 얼마나 아프셨나요?\n");
					printf("(0:안 아픔, 1:약간의 불편함, 2~3:통증이 약간 느껴짐, 4~5:통증이 일상에 지장을 주지만 견딜 수 있음, 6~7: 견디기 힘듦, 8:일상생활 불가능): ");
					scanf("%d", &s[i].hurt);
				if (s[i].hurt > 8 || s[i].hurt < 0) {
					printf("잘못된 값입니다. 다시 입력해 주세요.\n");
					goto loop;	
				}

				printf("이름: %s, 나이; %d, 성별: %c, 앓은 기간: %d, 아픔 수치: %d\n", s[i].name, s[i].age, s[i].gender, s[i].leng, s[i].hurt);
			
				printf("원하시는 입력값이 맞으시면 y, 아니면 n을 입력하세요: ");
				
				scanf("%c", &righ);
				//char righ1 = (char)righ;
				while (a == 1) {
					if (righ == 'y') {
						
						i++;
					}

					else if (righ == 'n') {
						printf("처음부터 다시 입력하세요.\n");
					}
					else {
						printf("잘못된 값입니다. 다시 입력하세요.\n");
					}
					f = 0;
					a = 0;

					
					
				}
			}
		}

		else if (order == '2') {				//기록 보기
			for (int p = 0; p < i; p++) {
				printf("이름: %s, 나이; %d, 성별: %c, 앓은 기간: %d, 아픔 수치: %d\n", s[p].name, s[p].age, s[p].gender, s[p].leng, s[p].hurt);

			}
			getchar();
		}

		else if (order == '3') {				//평균 고통 수치 - 함수 포인터
			int sum = 0;

			for (int b = 0; b < i; b++) {
				sum += s[b].hurt;
			}
			printf("%lf", cal(sum, i));

			getchar();
		}

		else if (order == '4') {				//출력 - 파일 입출력
			
			char fnam[100];

			printf("출력할 파일의 이름을 적으시오.: ");
			scanf("%s", fnam);
			for (int z = 0; z < i; z++) {

				printtxt(fnam, s[z]);

			}

			getchar();

		}
		else if (order == 'Q') {
			ma = 0;							//Q 입력시 종료
		}

		else {
			printf("잘못된 값입니다.\n");				//외의 값 입력시 오류
			getchar();
		}
		
	}
	return 0;
}

double average(int sum, int num) {				//[평가항목 2] 함수 사용

	double avg;
	avg = (double)sum / (double)num;

		return avg;
}