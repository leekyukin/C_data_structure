#include<stdio.h>
#include<stdlib.h>

// ����Լ� (recursice function)
// ��> �Լ� ���ο��� ���� �Լ��� ȣ���ϴ� ����

void func(int n) {  
	if (n == 0) {  // ����Լ��� ����Ǿ��ϴ� ������ �ʿ��ϴ�.
	
		return;
	}
	printf("%d ", n);    //����Լ����� �� => ��� �ϱ��� ����
	func(n-1);            // ��ͱ��� (��) 

    printf("%d ", n);          // ����Լ����� �Ʒ�=>��Ͱ� Ǯ���鼭 ����Ǵ� ����

}

int main() {
	func(3);
}