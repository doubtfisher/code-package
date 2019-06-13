#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
using namespace std;

//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout <<"delete: "<< _ptr << endl;
//		delete[] _ptr;
//	}
//private:
//	T* _ptr;
//};

//void test1()
//{	
//	int* p1 = new int;
//	SmartPtr<int> sp1(p1);
//
//	vector<int> v;
//	v.at(0) = 10;
//
//	//delete p1;	
//}

//void test()
//{
//	int n;
//	cin >> n;
//	int* p1 = new int;
//	int* p2 = new int[n];//���n�ܴ�ʱ�����ڴ治��ʱ�������ڴ�ʧ�ܣ��ͻ����쳣���������Ǵ�ʱp1��û���ͷ�
//
//	delete p1;
//	delete[] p2;
//}

////������
//template<class T>//֮����Ҫʹ��ģ�壬����ΪҪ�������Դ��������ָ������������ܻ����������͵���Դ
//class SmartLock
//{
//public:
//	SmartLock(T& lock)
//		:_lock(lock)
//	{
//		_lock.lock();
//	}
//
//
//	~SmartLock()
//	{
//		cout << "unlock: " << &_lock << endl;
//		_lock.unlock();
//	}
//private:
//	T& _lock;
//};
//
//std::mutex mtx;
//
//void Add(size_t n, int* value)
//{
//	std::unique_lock<std::mutex> lock(mtx);//ֻ������1��
//	for (size_t i = 0; i < n; i++)
//	{
//		//SmartLock<std::mutex> smtlock(mtx);//���Ĵ�Ҫ��n����
//		(*value)++;
//	}
//}
////����������һ���߳���������ڶ����߳���������ֵ�һ���̼߳����ˣ��ڶ����߳̾ͻᱣ����������Ϣ�����г�ȥ������������ߵȴ�״̬��ֱ����һ���߳̽����ˣ�ȥ������
////�������������г�ȥ���᲻��������ȥ����̵߳�״̬���������߳���û�н����������ˣ��Ϳ��Է����ˣ�û���������л������ģ�����������߳��������ת����cpuռ���ţ���������Ļ��������߳�ִ�в��ˡ�
////���߳̾������Ǻ�����ʱ��Ҳ�����������Ⱥ�Сʱ���ʺ�����������
//int main()
//{
//	int x = 0;
//	std::thread t1(Add, 100, &x);
//	std::thread t2(Add, 100, &x);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	//std::mutex mtx;
//	//SmartLock<std::mutex> smtlock(mtx);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//test();
//	/*try{
//		test1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}*/
//
//	std::mutex mtx;
//	/*mtx.lock();
//	mtx.unlock();*/
//	SmartLock<std::mutex> smtlock(mtx);
//
//	system("pause");
//	return 0;
//}

//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr=nullptr)
//		:_ptr(ptr)
//	{}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;	
//	}
//private:
//	T* _ptr;
//};

//struct A
//{
//	int a;
//	int b;
//};

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


////c++98 auto_ptr
////1.����Ȩת��  �Ǵ���ȱ�ݵ�������ƣ���˾�Ͻ�ʹ����
//namespace yan
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr)
//			:_ptr(ptr)
//		{}
//		
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		//ap1(ap2) ap2��������ap1����ʱ��ap2�ÿգ����Ұѹ���Ȩ����ap1
//		auto_ptr(auto_ptr<T>& ap)//��������   ����Ȩת��
//			:_ptr(ap._ptr)
//		{
//			ap._ptr = nullptr;
//		}
//
//		auto_ptr<T>& operator=(auto_ptr<T>& ap)//��ֵ
//		{
//			if (this != &ap)//����Ƿ����Լ����Լ���ֵ
//			{
//				//�ͷŵ�ǰ�����е���Դ
//				if (_ptr)
//					delete _ptr;
//
//				//ת��ap�е���Դ����ǰ������
//				_ptr = ap._ptr;
//				ap._ptr = nullptr;
//			}
//			return *this;
//		}
//
//		~auto_ptr()
//		{
//			
//			if (_ptr)
//			{
//				cout << "delete: " << _ptr << endl;
//				delete _ptr;
//			}
//				
//		}
//	private:
//		T* _ptr;
//	};
//}

//void auto_ptr_test()
//{
//	yan::auto_ptr<int> ap1(new int);
//	yan::auto_ptr<int> ap2(ap1);//��ap1���������ap2�󣬰�ap1�ÿ�
//}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

//C++11 unique_ptr 
// 1.�򵥴ֱ�����������Ч�ʸߣ������ܲ�ȫ����֧�ֿ�������͸�ֵ��ֻҪ��ʹ�ÿ�������͸�ֵ�ĳ����£���˾����ʹ������
//namespace yan
//{
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr)
//			:_ptr(ptr)
//		{}
//		
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		unique_ptr(const unique_ptr<T>& ap) = delete;//������
//		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;//����ֵ
//			
//		~unique_ptr()
//		{	
//			if (_ptr)
//			{
//				cout << "delete: " << _ptr << endl;
//				delete _ptr;
//			}		
//		}
//	private:
//		T* _ptr;
//	};
//}

//void unique_ptr_test()
//{
//	yan::unique_ptr<int> ap1(new int);
//	//yan::unique_ptr<int> ap2(ap1);//���ܽ��п���
//}

//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

//C++11 shared_ptr  ����ȫ��֧�ֿ�����ʹ�����ü�����ȱ�㣺��Ƹ��ӣ���ѭ���������⡣
namespace yan
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))//�����ü�����Ϊ1
			, _pmtx(new std::mutex)
		{}

		void AddRef()//���ü���++������
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Release()//�ͷ�
		{
			bool flag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)//��֤�ͷ����̰߳�ȫ��
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				delete _pcount;
				flag = true;
			}
			_pmtx->unlock();

			if (flag)
				delete _pmtx;

			//����������ָ���п��ܻᱻ�ͷ�2�Σ���Ϊ���ǽ���֮�󣬲��ж�pcount���ͷŵ�
			/*_pmtx->lock();
			--(*pcount);
			_pmtx->unlock();
			if (--(*_pcount) == 0)
			{
				delete _ptr;
				delete _pcount;
				delete _pmtx;
			}*/

		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		//��������-->++���ü�������
		shared_ptr(const shared_ptr<T>& sp)//��������
			:_ptr(sp._ptr)
			,_pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			//++(*_pcount);
			AddRef();
		}

		//sp1=sp3
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)//��ֵ
		{
			
			//if (this != &sp)//��������ǿ����Ż�
			//���������ptr�����ͬ�Ͳ���ȥ�ˣ�����--��++���������ù�
			//Ҫ����ͬ�Ķ���ptr��ͬ�Ͳ�������
			//Ҫ�ǲ�ͬ�Ķ�������ָ��ͬһ��ռ䣬ptr��ͬҲ��������
			if (_ptr!=sp._ptr)//�Ż���� ��ֹ�Լ����Լ���ֵ
			{
				//�ж�Ҫ��ֵ��������ü����ǲ���1
				//������ü�����1������Ҫ�ͷ����ռ䣬Ȼ���ø�ָ��ָ���µĿռ�
				//if (--(*_pcount) == 0)//��Ϊԭ���Ŀռ�����ж������ָ����,���ԭ���ռ�ֻ��һ������ָ��������ֱ���ͷţ�����--pcount
				//{
				//	delete _ptr;
				//	delete _pcount;
				//}
				Release();//�ͷŵ���sp1

				//����ָ��ָ��ͬһ��ռ䣬��++���ü���
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				//(*_pcount)++;
				AddRef();//���ӵ���sp3�����ü���
			}
			return *this;
		}

		int use_count()
		{
			return *_pcount;
		}

		~shared_ptr()
		{
			//if (--(*_pcount) == 0) //���ü���--Ϊ0����ʱ�����ͷ�
			//{
			//	cout << "delete: " << _ptr << endl;
			//	delete _ptr;//�ͷ�ָ��
			//	delete _pcount;//�ͷ����ü���
			//}
			Release();
		}
	private:
		T* _ptr;
		int* _pcount;
		std::mutex* _pmtx;
	};
}

void shared_ptr_test()
{
	yan::shared_ptr<int> sp1(new int);
	yan::shared_ptr<int> sp2(sp1);

	//sp1 = sp2;
	yan::shared_ptr<int> sp3(new int);
	sp1 = sp3;
}

std::mutex mtx;
void test_multi_thread_copy(yan::shared_ptr<int>& sp,size_t n)//������ָ�뿽��n��
{
	for (size_t i = 0; i < n; i++)
	{
		//��һ�����̰߳�ȫ��
		yan::shared_ptr<int> copy(sp);

		
		//�����̰߳�ȫ��
		{
			std::unique_lock<std::mutex> lock(mtx);
			++(*copy);
		}
	     //....
	}
}


void test_shared_ptr_safe()
{
	yan::shared_ptr<int> sp(new int);

	std::thread t1(test_multi_thread_copy, sp, 1000);
	std::thread t2(test_multi_thread_copy, sp, 1000);

	t1.join();
	t2.join();
	cout << sp.use_count() << endl;
	cout << *sp << endl;
}


struct ListNode
{
	/*std::shared_ptr<ListNode> _next;
	std::shared_ptr<ListNode>  _prev;*/

	std::weak_ptr<ListNode> _next;
	std::weak_ptr<ListNode>  _prev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

void test_shared_ptr_cycleRef()
{
	std::shared_ptr<ListNode> cur(new ListNode);
	std::shared_ptr<ListNode> next(new ListNode);

	cur->_next = next;
	next->_prev = cur;

	cout << cur.use_count() << endl;
	cout << next.use_count() << endl;
}



template<class T>
struct DeleteArray
{
	void operator()(T* ptr)//�º���
	{
		delete[] ptr;
	}
};

struct B
{
	~B()
	{
		cout << "~B()" << endl;
	}
};

//����ɾ����������ɾ���ķ�ʽ��һ��Ĭ����delete��
void test_shared_ptr_deletor()
{
	DeleteArray<B> del;
	std::shared_ptr<B> sp(new B[10],del);
}

int main()
{
	//auto_ptr_test();
	//unique_ptr_test();
	//shared_ptr_test();
	//test_shared_ptr_safe();
	//test_shared_ptr_cycleRef();
	test_shared_ptr_deletor();
	system("pause");
	return 0;




//int main()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(sp1);//����ָ�벻����������Ϊ����ָ���ǰ���������Դ�ģ������ܷ��������Դ�������Դ�������Լ��ģ����Բ��ܽ��п�������
//	
//	
//	system("pause");
//	return 0;
}

//int main()
//{
//	int* p1 = new int;
//	SmartPtr<int> sp1(new int);//����ָ��
//	*p1 = 10;
//	*sp1 = 20;//����ָ��֧�ֽ�����
//	cout << *sp1 << endl;
//
//	SmartPtr<A> sp2(new A);
//	(*sp2).a= 10;
//	sp2->b = 20;
//	cout << sp2->b << endl;
//	system("pause");
//	return 0;
//}