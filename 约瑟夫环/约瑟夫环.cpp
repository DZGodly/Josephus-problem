#include<iostream>
using namespace std;

typedef struct CircleList {
	CircleList* node;
	int num;
	int secret;
} *ListNode;

ListNode SetCircle(int n) {						//用户输入人数n，该函数将这n个人生成单向循环列表
	ListNode p = new CircleList;
	int i = 1;
	p->num = i;									//创建第一个节点
	cin >> p->secret;
	ListNode first = p;
	p->node = new CircleList;
	p = p->node;

	for (i = 2; i < n; i++) {					//创建中间部分节点
		p->num = i;
		cin >> p->secret;
		p->node = new CircleList;
		p = p->node;
	}

	p->node = new CircleList;					//创建最后一个节点并将最后一个节点与第一个节点连接
	p->num = i;
	cin >> p->secret;
	p->node = first;
	cout << "循环链表已生成" << endl;
	return first;
}

void JosephCircle(int m, ListNode p) {			//解决约瑟夫问题
	ListNode pre = NULL;
	int i = 1;
	while (p) {

		for (; i < m - 1; i++) {				//报数直到第m-2
			cout << "here is " << i << endl;
			p = p->node;
		}

		pre = p;								//保存报第m-1号的数据并报第m-1号
		cout << "here is " << i << endl;
		p = p->node;
		m = p->secret;

		cout << "here is " << ++i << endl;		//报第m号
		cout <<"my password is "<<m<< endl;		//报第m号的人需要报出自己的密码
		i = 1;									//重置循环
		pre->node = p->node;					//从该行开始，删除p指向的节点并将剩下的人重新连接成环
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
