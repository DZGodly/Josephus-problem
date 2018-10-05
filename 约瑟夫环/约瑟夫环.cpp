#include<iostream>
using namespace std;

typedef struct CircleList {
	CircleList* node;
	int num;
	int secret;
} *ListNode;

ListNode SetCircle(int n) {						//�û���������n���ú�������n�������ɵ���ѭ���б�
	ListNode p = new CircleList;
	int i = 1;
	p->num = i;									//������һ���ڵ�
	cin >> p->secret;
	ListNode first = p;
	p->node = new CircleList;
	p = p->node;

	for (i = 2; i < n; i++) {					//�����м䲿�ֽڵ�
		p->num = i;
		cin >> p->secret;
		p->node = new CircleList;
		p = p->node;
	}

	p->node = new CircleList;					//�������һ���ڵ㲢�����һ���ڵ����һ���ڵ�����
	p->num = i;
	cin >> p->secret;
	p->node = first;
	cout << "ѭ������������" << endl;
	return first;
}

void JosephCircle(int m, ListNode p) {			//���Լɪ������
	ListNode pre = NULL;
	int i = 1;
	while (p) {

		for (; i < m - 1; i++) {				//����ֱ����m-2
			cout << "here is " << i << endl;
			p = p->node;
		}

		pre = p;								//���汨��m-1�ŵ����ݲ�����m-1��
		cout << "here is " << i << endl;
		p = p->node;
		m = p->secret;

		cout << "here is " << ++i << endl;		//����m��
		cout <<"my password is "<<m<< endl;		//����m�ŵ�����Ҫ�����Լ�������
		i = 1;									//����ѭ��
		pre->node = p->node;					//�Ӹ��п�ʼ��ɾ��pָ��Ľڵ㲢��ʣ�µ����������ӳɻ�
		p->node = NULL;
		ListNode l = p;
		p = pre->node;
		delete l;
	}
}

int main()
{
	int m, n;
	cin >>m>> n;
	ListNode h = SetCircle(n);
	if (n >= 1 && m > 0) {
		JosephCircle(m, h);
	}
	//system("pause");
	return 0;

}
