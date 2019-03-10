//1.设计一个类，要求只能在堆上创建对象
//
//思路：构造函数私有化；拷贝构造只声明，不定义，声明为私有；使用公有成员函数获取堆上的对象


//#include <iostream>
//using namespace std;
//
//class HeapOnly
//{
//public:
//	static HeapOnly* GetHeapObj()//使用公有成员函数调私有的构造函数
//	{
//		return new HeapOnly;
//	}
//	HeapOnly(const HeapOnly& obj) = delete;//②把拷贝构造函数设置为删除函数(c++11)
//private:
//	HeapOnly()//构造函数设为私有的
//	{}
//
//	//c++98：①拷贝构造只声明不实现，声明为私有(有一个缺陷，就是友元可以突破)
//	HeapOnly(const HeapOnly& obj);
//	//或者
//	HeapOnly(const HeapOnly& obj)=delete;//c++11,声明为公有也可以
//};
//
//int main()
//{
//	HeapOnly* pobj=HeapOnly::GetHeapObj();
//	system("pause");
//	//HeapOnly*  copy(*pobj);//创建的对象在栈上
//	return 0;
//}



//2.设计一个类，要求只能在栈上创建对象
//
//思路:构造函数私有化，然后使用公有成员函数获取匿名对象
//class StackOnly
//{
//public:
//	static StackOnly GetStackObj()
//	{
//		return StackOnly();//创建一个匿名对象返回
//	}
//
//private:
//	StackOnly()//构造函数私有化
//	{}
//};
//int main()
//{
//	StackOnly stObj = StackOnly::GetStackObj();
//	system("pause");
//	return 0;
//}
//
////或者也有一种bug的方法：只能在栈上创建对象，即不能在堆上创建，因此只要将new的功能屏蔽掉即可，即屏蔽掉operator new和定位new表达式.
////注意：屏蔽了operator new，实际也将定位new给屏蔽掉了。
//class StackOnly
//{
//public:
//	StackOnly()
//	{}
//private:
//	//因为new的底层调的是operator new，所以可以把operator new声明为私有的，如果一旦想要在堆上创建对象，就会出错
//	void* operator new(size_t size);
//	void operator delete(void* p);
//	//或(c++11)
//	void* operator new(size_t size) = delete;//把删除函数设置为公有的也可以
//	void operator delete(void* p) = delete;
//};
//int main()
//{
//	StackOnly stObj;
//}
//需要注意的是：这种方式禁不掉在全局范围中创建对象，也就意味着，只能阻止在堆上创建对象



//3.单例模式中的饿汉模式
//#include <iostream>
//using namespace std;
//
//class ConfigSingleton
//{
//public:
//	static ConfigSingleton& GetInstance()//2.提供公有的获取实例的成员函数
//	{
//		return _sinst;
//	}
//	void Print()
//	{
//		cout << _ip << " " << _port<< endl;
//	}
//private:
//	ConfigSingleton(const char* ip, int port)//1.构造函数私有化
//		:_ip(ip)
//		, _port(port)
//	{
//	 //初始化
//	}
//	//配置信息
//	const char* _ip;
//	int _port;
//
//	//防拷贝
//	ConfigSingleton(const ConfigSingleton&)=delete;//4.拷贝构造函数私有化，防止再拷贝一份对象出来
//	ConfigSingleton& operator=(const ConfigSingleton&) = delete;
//
//	static ConfigSingleton _sinst;//3.创建一个静态对象
//};
// ConfigSingleton ConfigSingleton::_sinst("127.0.01", 80);
//
//int main()
//{
//	ConfigSingleton::GetInstance().Print();
//
//	system("pause");
//	return 0;
//}
//饿汉模式：一上来就创建对象
//缺点：
//①如果配置信息太多，服务器启动起来很慢(因为这个对象是静态的，在进入main函数之前就要初始化，如果配置信息太多，服务器起来就会特别慢)
//②启动顺序不确定(如果一个项目里面有多个单例类，如果各个单例类之间有依赖关系的话，谁先初始化，谁后初始化并没有保证，所以导致启动书顺序不确定)
//优点：简单
//#include <iostream>
//
//using namespace std;
//
//class ConfigSingleton
//{
//public:
//	static ConfigSingleton& GetInstance()
//	{
//		return _sinst;
//	}
//	void Print()
//	{
//		cout << _ip << endl;
//		cout << _port << endl;
//	}
//private:
//	ConfigSingleton(const char* ip, int port)//1.构造函数私有化
//		:_ip(ip)
//		, _port(port)
//	{
//	}
//
//	//防拷贝
//	ConfigSingleton(const ConfigSingleton&) = delete;
//	ConfigSingleton& operator=(const ConfigSingleton&) = delete;
//
//
//	const char* _ip;
//	int _port;
//	static ConfigSingleton _sinst;//2.创建一个静态的对象
//};
//ConfigSingleton ConfigSingleton::_sinst("127.0.0.1", 80);
//
//int main()
//{
//	ConfigSingleton::GetInstance().Print();
//	//ConfigSingleton copy(ConfigSingleton::GetInstance());
//	system("pause");
//	return 0;
//}




//懒汉模式(到了万不得已才创建对象)
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class ConfigSingleton
{
public:
   static ConfigSingleton* GetInstance()
	{
	   //double check
	   if (_psinst == nullptr)//当第一次创建好对象后，过会儿，又有别的线程来的时候，别的线程直接进不去，也就接触不到锁，就不用加锁解锁，节省了时间，提高了效率
	   {
		   _mutex.lock();
		   if (_psinst == nullptr)//为了保证只创建一个对象,保护线程安全
		   {
			   _psinst = new ConfigSingleton;
		   }
		   _mutex.unlock();
	   }
	   
	   return _psinst;
	}

   class GC//释放_psinst
   {
   public:
	   ~GC()
	   {
		   delete _psinst;
	   }
   };

   void Print()
   {
	   cout << _ip << endl;
	   cout << _port << endl;
   }

   ~ConfigSingleton()
   {
	   cout << "~ConfigSingleton()" << endl;
   }
private:
	ConfigSingleton(const char* ip = "127.0.0.1", int port = 80)//构造函数私有化
		:_ip(ip)
		, _port(port)
	{
		cout << "ConfigSingleton()" << endl;
	}


	//防拷贝
	ConfigSingleton(const ConfigSingleton&)=delete;
	ConfigSingleton& operator=(const ConfigSingleton&)=delete;

   const char* _ip;
   int _port;
   static ConfigSingleton* _psinst;
   static mutex  _mutex;

   static GC _gc;//定义一个静态的_gc,程序结束时，系统会自动调用它的析构函数从而释放单例对象
};

 ConfigSingleton* ConfigSingleton::_psinst = nullptr;
 mutex  ConfigSingleton::_mutex;

 ConfigSingleton::GC ConfigSingleton::_gc;

void fun(int n)
 {
	 cout << "fun:GetInstance()" << endl;
 }

int main()
{

	thread t1(fun, 10);
	thread t2(fun, 10);
	t1.join();
	t2.join();
	ConfigSingleton::GetInstance()->Print();
	system("pause");
	return 0;
}

