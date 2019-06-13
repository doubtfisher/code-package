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
//	int* p2 = new int[n];//如果n很大时或者内存不足时，申请内存失败，就会抛异常结束，但是此时p1还没有释放
//
//	delete p1;
//	delete[] p2;
//}

////智能锁
//template<class T>//之所以要使用模板，是因为要管理的资源不仅仅是指针或者锁，可能还有其他类型的资源
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
//	std::unique_lock<std::mutex> lock(mtx);//只会消耗1次
//	for (size_t i = 0; i < n; i++)
//	{
//		//SmartLock<std::mutex> smtlock(mtx);//消耗大，要加n次锁
//		(*value)++;
//	}
//}
////互斥锁：第一个线程来，如果第二个线程来如果发现第一个线程加锁了，第二个线程就会保存上下文信息，并切出去，进入就绪休眠等待状态，直到另一个线程解锁了，去唤醒它
////自旋锁：不会切出去，会不断自旋，去检查线程的状态，，看该线程有没有解锁，解锁了，就可以访问了，没有上下文切换的消耗，自旋会带来线程在这儿空转，把cpu占用着，再有任务的话，其它线程执行不了。
////当线程竞争不是很厉害时，也就是锁的粒度很小时，适合用自旋锁。
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
////1.管理权转移  是带有缺陷的早期设计，公司严禁使用它
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
//		//ap1(ap2) ap2拷贝构造ap1，此时把ap2置空，并且把管理权交给ap1
//		auto_ptr(auto_ptr<T>& ap)//拷贝构造   管理权转移
//			:_ptr(ap._ptr)
//		{
//			ap._ptr = nullptr;
//		}
//
//		auto_ptr<T>& operator=(auto_ptr<T>& ap)//赋值
//		{
//			if (this != &ap)//检测是否是自己给自己赋值
//			{
//				//释放当前对象中的资源
//				if (_ptr)
//					delete _ptr;
//
//				//转移ap中的资源到当前对象中
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
//	yan::auto_ptr<int> ap2(ap1);//把ap1拷贝构造给ap2后，把ap1置空
//}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

//C++11 unique_ptr 
// 1.简单粗暴，防拷贝。效率高，但功能不全，不支持拷贝构造和赋值，只要不使用拷贝构造和赋值的场景下，公司鼓励使用它。
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
//		unique_ptr(const unique_ptr<T>& ap) = delete;//防拷贝
//		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;//防赋值
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
//	//yan::unique_ptr<int> ap2(ap1);//不能进行拷贝
//}

//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

//C++11 shared_ptr  功能全，支持拷贝，使用引用计数。缺点：设计复杂，有循环引用问题。
namespace yan
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))//把引用计数置为1
			, _pmtx(new std::mutex)
		{}

		void AddRef()//引用计数++，加锁
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Release()//释放
		{
			bool flag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)//保证释放是线程安全的
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				delete _pcount;
				flag = true;
			}
			_pmtx->unlock();

			if (flag)
				delete _pmtx;

			//错误，这三个指针有可能会被释放2次，因为它是解锁之后，才判断pcount并释放的
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

		//拷贝构造-->++引用计数即可
		shared_ptr(const shared_ptr<T>& sp)//拷贝构造
			:_ptr(sp._ptr)
			,_pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			//++(*_pcount);
			AddRef();
		}

		//sp1=sp3
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)//赋值
		{
			
			//if (this != &sp)//不算错，但是可以优化
			//两个对象的ptr如果相同就不进去了，否则--再++就是做无用功
			//要是相同的对象，ptr相同就不作操作
			//要是不同的对象，它们指向同一块空间，ptr相同也不作操作
			if (_ptr!=sp._ptr)//优化后的 防止自己给自己赋值
			{
				//判断要赋值对象的引用计数是不是1
				//如果引用计数是1，则需要释放这块空间，然后让该指针指向新的空间
				//if (--(*_pcount) == 0)//因为原来的空间可能有多个对象指向它,如果原来空间只有一个对象指向它，就直接释放，否则--pcount
				//{
				//	delete _ptr;
				//	delete _pcount;
				//}
				Release();//释放的是sp1

				//两个指针指向同一块空间，再++引用计数
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				//(*_pcount)++;
				AddRef();//增加的是sp3的引用计数
			}
			return *this;
		}

		int use_count()
		{
			return *_pcount;
		}

		~shared_ptr()
		{
			//if (--(*_pcount) == 0) //引用计数--为0，此时进行释放
			//{
			//	cout << "delete: " << _ptr << endl;
			//	delete _ptr;//释放指针
			//	delete _pcount;//释放引用计数
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
void test_multi_thread_copy(yan::shared_ptr<int>& sp,size_t n)//把智能指针拷贝n次
{
	for (size_t i = 0; i < n; i++)
	{
		//这一句是线程安全的
		yan::shared_ptr<int> copy(sp);

		
		//不是线程安全的
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
	void operator()(T* ptr)//仿函数
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

//定制删除器（定制删除的方式，一般默认是delete）
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
//	SmartPtr<int> sp2(sp1);//智能指针不能这样，因为智能指针是帮助管理资源的，并不能访问这份资源，这个资源并不是自己的，所以不能进行拷贝构造
//	
//	
//	system("pause");
//	return 0;
}

//int main()
//{
//	int* p1 = new int;
//	SmartPtr<int> sp1(new int);//智能指针
//	*p1 = 10;
//	*sp1 = 20;//智能指针支持解引用
//	cout << *sp1 << endl;
//
//	SmartPtr<A> sp2(new A);
//	(*sp2).a= 10;
//	sp2->b = 20;
//	cout << sp2->b << endl;
//	system("pause");
//	return 0;
//}