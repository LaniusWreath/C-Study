#include "iostream"
#include "vector"
#include "memory"

using namespace std;

// ��ü Ŭ����
class Object {
public:
	int id;		// ��ü�� ���� ��ȣ
	Object(int id) : id(id) { }		// //������ �Լ�, �ʱ�ȭ ����Ʈ
};

// ������ Ŭ����
class Pointer {
public:
	shared_ptr<Object> ptr;
	int id;

	Pointer(int id) : id(id), ptr(nullptr) {}

	//��ü�� ����Ű�� �ϴ� �Լ�
	void PointToObject(shared_ptr<Object> obj)
	{
		ptr = obj;
	}
};

// ��ü�� �����͸� �����ϴ� Ŭ����
class Main {
private:
	vector<shared_ptr<Object>> objects;
	vector<Pointer> pointers;

public:
	Main(int N, int M)
	{
		//��ü�� ������ ����
		for (int i = 1; i <= N; i++)
		{
			objects.push_back(make_shared<Object>(i));		// make_shared<Object>(i) : Object Ÿ�� ��ü�� ���� �޸𸮿� �Ҵ�, ��ü ����Ű�� ������ ��ȯ
		}
		for (int i = 1; i <= M; i++)
		{
			pointers.emplace_back(i);		// ���� ���� ���ο� ��Ҹ� in-place�� ����(�ܺο��� ���� �ٿ����� �ʰ�, ���޵� ���ڷ� ���� �޸� ������ ���� ����)
		}
	}

	//�����Ͱ� ��ü�� ����Ű�� ����
	void AssignPointerToObject(int pointerId, int objectId)
	{
		if (pointerId > 0 && pointerId <= pointers.size() && objectId > 0 && objectId <= objects.size())
		{
			pointers[pointerId - 1].PointToObject(objects[objectId - 1]);
		}
	}

	//�����Ϳ� ��ü ���� ���
	void printStatus()
	{
		for (auto& pointer : pointers)
		{
			if (pointer.ptr)
			{
				cout << "Pointer " << pointer.id << "points to Object " << pointer.ptr->id << endl;
			}
			else
			{
				cout << "Pointer " << pointer.id << "points to no Object " << endl;
			}
		}
	}
};

int main()
{
	Main app(5, 3);		// 5�� ��ü, 3�� ������ ����
	app.AssignPointerToObject(1, 1);
	app.AssignPointerToObject(2, 3);
	app.printStatus();		// ������ ���� ���

	return 0;
}