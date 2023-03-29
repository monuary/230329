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

typedef struct Data	//구조체 이름
{
	int data;
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);
}Data;	//타 함수에서 구조체를 부를 때의 별칭. 없으면 원래 이름을 불러야 한다.

void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }	//함수 포인터를 정의할 때는 포인터를 붙이지 않는다.
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

//클래스는 이런 구조체의 형태를 취한다. 클래스 내의 멤버함수는 같은 부류의 클래스끼리 공유한다.