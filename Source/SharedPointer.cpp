#include "iostream"
#include "vector"
#include "memory"

using namespace std;

// 객체 클래스
class Object {
public:
	int id;		// 객체의 고유 번호
	Object(int id) : id(id) { }		// //생성자 함수, 초기화 리스트
};

// 포인터 클래스
class Pointer {
public:
	shared_ptr<Object> ptr;
	int id;

	Pointer(int id) : id(id), ptr(nullptr) {}

	//객체를 가리키게 하는 함수
	void PointToObject(shared_ptr<Object> obj)
	{
		ptr = obj;
	}
};

// 객체와 포인터를 관리하는 클래스
class Main {
private:
	vector<shared_ptr<Object>> objects;
	vector<Pointer> pointers;

public:
	Main(int N, int M)
	{
		//객체와 포인터 생성
		for (int i = 1; i <= N; i++)
		{
			objects.push_back(make_shared<Object>(i));		// make_shared<Object>(i) : Object 타입 객체를 동적 메모리에 할당, 객체 가리키는 포인터 반환
		}
		for (int i = 1; i <= M; i++)
		{
			pointers.emplace_back(i);		// 벡터 끝에 새로운 요소를 in-place로 생성(외부에서 만들어서 붙여넣지 않고, 전달된 인자로 벡터 메모리 내에서 직접 구성)
		}
	}

	//포인터가 객체를 가리키게 설정
	void AssignPointerToObject(int pointerId, int objectId)
	{
		if (pointerId > 0 && pointerId <= pointers.size() && objectId > 0 && objectId <= objects.size())
		{
			pointers[pointerId - 1].PointToObject(objects[objectId - 1]);
		}
	}

	//포인터와 객체 상태 출력
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
	Main app(5, 3);		// 5개 객체, 3개 포인터 생성
	app.AssignPointerToObject(1, 1);
	app.AssignPointerToObject(2, 3);
	app.printStatus();		// 포인터 상태 출력

	return 0;
}