
//�����һ�㲻֧�ֿ������죬��������һ�ݶ����൱������һ��ָ��ָ��������ڴ�أ������������ȥ����Ļ����õ�����ͬһ���ڴ棬�ǻ���������


//#pragma once
//#include <iostream>
//
//template<class T,size_t N_OBJ=20>
//class ObjectPool
//{
//public:
//	ObjectPool() = default;//default�Ǹ��߱���������ʹ���Լ�д�Ĺ��죬���ñ���������һ��Ĭ�ϵĹ��캯��
//	ObjectPool(const ObjectPool<T>&) = delete;//������������Ϊɾ������
//	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;//operator=����Ϊɾ������
//
//	template <class INIT_T>
//	T* New(const INIT_T& x = INIT_T())
//	{
//		T* obj = nullptr;
//		if (_freelist != nullptr)//�����������Ϊ�գ���ֱ��ȥ�����������ڴ�
//		{
//			void* next = *((void**)_freelist);//void**j������֮����һ��void*
//			obj = (T*)_freelist;
//			_freelist = next;
//		}
//		else//�����������Ϊ�գ���ȥ���ڴ�(����)��Ҫ�ڴ�
//		{
//			if (_start == _finish)//����ڴ�(����)��û���ڴ棬��ȥ��malloc����
//			{
//				_start = (char*)malloc(sizeof(T)*N_OBJ); 
//				//if (_start == nullptr)//�������ʧ�ܣ������쳣
//				//{
//				//	throw bad_alloc()��
//				//}
//				_finish = _start + sizeof(T)*N_OBJ;
//			}
//			else//������ڴ�Ļ���ֱ�ӰѶ���ص�_start��obj
//			{
//				obj =(T*) _start;
//				_start += sizeof(T);
//			}		
//		}
//		new(obj)T(x);//new�Ķ�λ���ʽ�����ڳ�ʼ���ѿ��ٺõĿռ�
//		return obj;
//	}
//    void Delete(T* ptr)//���ڴ滹����
//	{
//		ptr->~T();
//		*(void**)ptr = _freelist;
//		_freelist = ptr;
//	}
//
//private:
//	char* _start=nullptr;//�����char* ����Ϊ+1ʱ���ӵ���һ���ֽ�
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
//ע�⣺ģ�岻֧�ַ������
template<class T, size_t N_Obj = 20>
class ObjectPool
{
public:
	ObjectPool() = default;//�������Լ�����һ�����캯��
	//������
	ObjectPool(const ObjectPool<T>&) = delete;//��������
	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;//operator��ֵ

	template<class INIT_T>//��ģ���ģ���Ա����
	T* New(const INIT_T& x = INIT_T())//��new��ʱ��ͳ�ʼ��
	{
		T* obj = nullptr;
		if (_freelist != nullptr)//��Ϊ�������ڴ����ֱ����
		{
			//�ڴ���ͷ�ĸ��ֽڴ���һ��ĵ�ַ
			void* next = *((void**)_freelist);//���;�������������ǿתΪ(int*)
			obj = (T*)_freelist;
			_freelist = next;
		}
		else//û���ڴ棬��Ҫ����������
		{
			if (_start == _finish)//�����û���ڴ棬��ϵͳ����
			{
				_start = (char*)malloc(sizeof(T)*N_Obj);
				_finish = _start + sizeof(T)*N_Obj;
			}
			//�ڴ�����ڴ�,ֱ��������
			obj = (T*)_start;
			_start += sizeof(T);
		}
		new(obj)T(x);//new�Ķ�λ���ʽ�������пռ���г�ʼ��
		return obj;
	}
	void Delete(T* ptr)
	{
		*(void**)ptr = _freelist;
		_freelist = ptr;
	}

private:
	char* _start = nullptr;//�����һ��ʼʲôҲû�У�����ȱʡֵ�Զ���ʼ��
	char* _finish = nullptr;//char*���ͣ�1���ü�һ���ֽ�

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



