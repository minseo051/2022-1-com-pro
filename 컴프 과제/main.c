/* [���׸� 1] : ���� ����
* 
* ��ǻ�����α׷��� �򰡰��� (���� 25��)
* �а�: ��ǻ�Ͱ��к�
* �й�: 202102978
* �̸�: ���μ�
* 
* ���� ����: �ڷγ��� �ɸ����� ���� ������� ���� �ڷγ��� �ɸ� ����� ��������� �Ⱓ, �׷� ���� ���� ���� ���� �Է��Ͽ� �����ִ� ���α׷�

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "struct.h"

double average(int, int);

int main() {
	
	struct info s[100];						//[�� �׸� 3] �迭, [�� �׸� 5] ����ü ���
	int i = 0;
	char righ;
	int ma = 1;
	double (*cal)(int, int);				//[�� �׸� 4] ������ ���

	cal = average;							//[�� �׸� 6] ������ Ȱ��
	
	while (ma == 1) {

		int order = 0;
		int f = 1;

		printf("1.���� �Է�\n");
		printf("2.���� ����\n");
		printf("3.��� �ִ� ���� ��ġ\n");
		printf("4.���Ϸ� ���\n");
		printf("�����Ϸ��� Q�� �Է��Ͻÿ�\n");

		order = getchar();

		if (order == '1') {						//����, ���� �� ��, �ִ� ���� ��ġ �Է�
			int a = 1;
			while (f == 1) {
				printf("�̸�: ");
				scanf("%s", &s[i].name);

				printf("����: ");
				scanf("%d", &s[i].age);

				while (1) {
					printf("����(m/w): ");
					scanf("%s", &s[i].gender);

					if (s[i].gender == 'w' || s[i].gender == 'm')
						break;
					else
						printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.");

				}
				printf("�ڷγ��� ���� �Ⱓ(��): ");
				scanf("%d", &s[i].leng);
				loop:
					printf("������ ��ġ�� ǥ���ϸ� �󸶳� �����̳���?\n");
					printf("(0:�� ����, 1:�ణ�� ������, 2~3:������ �ణ ������, 4~5:������ �ϻ� ������ ������ �ߵ� �� ����, 6~7: �ߵ�� ����, 8:�ϻ��Ȱ �Ұ���): ");
					scanf("%d", &s[i].hurt);
				if (s[i].hurt > 8 || s[i].hurt < 0) {
					printf("�߸��� ���Դϴ�. �ٽ� �Է��� �ּ���.\n");
					goto loop;	
				}

				printf("�̸�: %s, ����; %d, ����: %c, ���� �Ⱓ: %d, ���� ��ġ: %d\n", s[i].name, s[i].age, s[i].gender, s[i].leng, s[i].hurt);
			
				printf("���Ͻô� �Է°��� �����ø� y, �ƴϸ� n�� �Է��ϼ���: ");
				
				scanf("%c", &righ);
				//char righ1 = (char)righ;
				while (a == 1) {
					if (righ == 'y') {
						
						i++;
					}

					else if (righ == 'n') {
						printf("ó������ �ٽ� �Է��ϼ���.\n");
					}
					else {
						printf("�߸��� ���Դϴ�. �ٽ� �Է��ϼ���.\n");
					}
					f = 0;
					a = 0;

					
					
				}
			}
		}

		else if (order == '2') {				//��� ����
			for (int p = 0; p < i; p++) {
				printf("�̸�: %s, ����; %d, ����: %c, ���� �Ⱓ: %d, ���� ��ġ: %d\n", s[p].name, s[p].age, s[p].gender, s[p].leng, s[p].hurt);

			}
			getchar();
		}

		else if (order == '3') {				//��� ���� ��ġ - �Լ� ������
			int sum = 0;

			for (int b = 0; b < i; b++) {
				sum += s[b].hurt;
			}
			printf("%lf", cal(sum, i));

			getchar();
		}

		else if (order == '4') {				//��� - ���� �����
			
			char fnam[100];

			printf("����� ������ �̸��� �����ÿ�.: ");
			scanf("%s", fnam);
			for (int z = 0; z < i; z++) {

				printtxt(fnam, s[z]);

			}

			getchar();

		}
		else if (order == 'Q') {
			ma = 0;							//Q �Է½� ����
		}

		else {
			printf("�߸��� ���Դϴ�.\n");				//���� �� �Է½� ����
			getchar();
		}
		
	}
	return 0;
}

double average(int sum, int num) {				//[���׸� 2] �Լ� ���

	double avg;
	avg = (double)sum / (double)num;

		return avg;
}