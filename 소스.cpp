#include<iostream>
using namespace std;

/*
class Data
{
	int data;
public:
	Data(int num):data(num){}
	void ShowData() { cout << "Data: " << data << endl; }
	void Add(int num) { data += num; }
};

int main()
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
	return 0;
}
*/

typedef struct Data	//����ü �̸�
{
	int data;
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);
}Data;	//Ÿ �Լ����� ����ü�� �θ� ���� ��Ī. ������ ���� �̸��� �ҷ��� �Ѵ�.

void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }	//�Լ� �����͸� ������ ���� �����͸� ������ �ʴ´�.
void Add(Data* THIS, int num) { THIS->data += num; }

int main()
{
	Data obj1 = { 15,ShowData,Add };
	Data obj2 = { 7,ShowData,Add };
	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
}

//Ŭ������ �̷� ����ü�� ���¸� ���Ѵ�. Ŭ���� ���� ����Լ��� ���� �η��� Ŭ�������� �����Ѵ�.