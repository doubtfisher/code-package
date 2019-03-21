
//对象池一般不支持拷贝构造，拷贝构造一份对象，相当于又有一个指针指向了这个内存池，如果两个对象都去申请的话，拿到的是同一块内存，是会出现问题的


//#pragma once
//#include <iostream>
//
//template<class T,size_t N_OBJ=20>
//class ObjectPool
//{
//public:
//	ObjectPool() = default;//default是告诉编译器，不使用自己写的构造，而让编译器生成一个默认的构造函数
//	ObjectPool(const ObjectPool<T>&) = delete;//拷贝构造声明为删除函数
//	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;//operator=声明为删除函数
//
//	template <class INIT_T>
//	T* New(const INIT_T& x = INIT_T())
//	{
//		T* obj = nullptr;
//		if (_freelist != nullptr)//如果自由链表不为空，就直接去自由链表拿内存
//		{
//			void* next = *((void**)_freelist);//void**j解引用之后，是一个void*
//			obj = (T*)_freelist;
//			_freelist = next;
//		}
//		else//如果自由链表为空，就去找内存(对象)池要内存
//		{
//			if (_start == _finish)//如果内存(对象)池没有内存，就去找malloc申请
//			{
//				_start = (char*)malloc(sizeof(T)*N_OBJ); 
//				//if (_start == nullptr)//如果申请失败，会抛异常
//				//{
//				//	throw bad_alloc()；
//				//}
//				_finish = _start + sizeof(T)*N_OBJ;
//			}
//			else//如果有内存的话，直接把对象池的_start给obj
//			{
//				obj =(T*) _start;
//				_start += sizeof(T);
//			}		
//		}
//		new(obj)T(x);//new的定位表达式，用于初始化已开辟好的空间
//		return obj;
//	}
//    void Delete(T* ptr)//把内存还回来
//	{
//		ptr->~T();
//		*(void**)ptr = _freelist;
//		_freelist = ptr;
//	}
//
//private:
//	char* _start=nullptr;//这儿给char* 是因为+1时，加的是一个字节
//	char* _finish = nullptr;
//	void* _freelist = nullptr;
//
//};
//void test()
//{
//	ObjectPool<std::string> pool;
//	std::string* p1 = pool.New("11111");
//	std::string* p2 = pool.New("22222");
//	pool.Delete(p1);
//	pool.Delete(p2);
//
//	std::string* p3 = pool.New("33333");
//	std::string* p4 = pool.New("44444");
//	//std::string* p5 = pool.New("55555");
//	/*pool.Delete(p3);
//	pool.Delete(p4);
//	*/
//}

#pragma once
//注意：模板不支持分离编译
template<class T, size_t N_Obj = 20>
class ObjectPool
{
public:
	ObjectPool() = default;//编译器自己生成一个构造函数
	//防拷贝
	ObjectPool(const ObjectPool<T>&) = delete;//拷贝构造
	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;//operator赋值

	template<class INIT_T>//类模板的模板成员函数
	T* New(const INIT_T& x = INIT_T())//在new的时候就初始化
	{
		T* obj = nullptr;
		if (_freelist != nullptr)//不为空则有内存可以直接用
		{
			//内存块的头四个字节存下一块的地址
			void* next = *((void**)_freelist);//类型决定看多少所以强转为(int*)
			obj = (T*)_freelist;
			_freelist = next;
		}
		else//没有内存，需要向对象池申请
		{
			if (_start == _finish)//对象池没有内存，向系统申请
			{
				_start = (char*)malloc(sizeof(T)*N_Obj);
				_finish = _start + sizeof(T)*N_Obj;
			}
			//内存池有内存,直接切着用
			obj = (T*)_start;
			_start += sizeof(T);
		}
		new(obj)T(x);//new的定位表达式，对已有空间进行初始化
		return obj;
	}
	void Delete(T* ptr)
	{
		*(void**)ptr = _freelist;
		_freelist = ptr;
	}

private:
	char* _start = nullptr;//对象池一开始什么也没有，给定缺省值自动初始化
	char* _finish = nullptr;//char*类型＋1正好加一个字节

	void* _freelist = nullptr;
};

void TestObjectPool()
{
	ObjectPool<std::string> pool;
	std::string* p1 = pool.New("111");
	std::string* p2 = pool.New("222");
	cout << p1 << endl;
	cout << p2 << endl;
	pool.Delete(p1);
	pool.Delete(p2);

	std::string* p3 = pool.New("333");
	std::string* p4 = pool.New("444");
	std::string* p5 = pool.New("555");
	cout << p3 << endl;
	cout << p4 << endl;
	cout << p5 << endl;
}



