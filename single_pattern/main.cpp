//1.���һ���࣬Ҫ��ֻ���ڶ��ϴ�������
//
//˼·�����캯��˽�л�����������ֻ�����������壬����Ϊ˽�У�ʹ�ù��г�Ա������ȡ���ϵĶ���


//#include <iostream>
//using namespace std;
//
//class HeapOnly
//{
//public:
//	static HeapOnly* GetHeapObj()//ʹ�ù��г�Ա������˽�еĹ��캯��
//	{
//		return new HeapOnly;
//	}
//	HeapOnly(const HeapOnly& obj) = delete;//�ڰѿ������캯������Ϊɾ������(c++11)
//private:
//	HeapOnly()//���캯����Ϊ˽�е�
//	{}
//
//	//c++98���ٿ�������ֻ������ʵ�֣�����Ϊ˽��(��һ��ȱ�ݣ�������Ԫ����ͻ��)
//	HeapOnly(const HeapOnly& obj);
//	//����
//	HeapOnly(const HeapOnly& obj)=delete;//c++11,����Ϊ����Ҳ����
//};
//
//int main()
//{
//	HeapOnly* pobj=HeapOnly::GetHeapObj();
//	system("pause");
//	//HeapOnly*  copy(*pobj);//�����Ķ�����ջ��
//	return 0;
//}



//2.���һ���࣬Ҫ��ֻ����ջ�ϴ�������
//
//˼·:���캯��˽�л���Ȼ��ʹ�ù��г�Ա������ȡ��������
//class StackOnly
//{
//public:
//	static StackOnly GetStackObj()
//	{
//		return StackOnly();//����һ���������󷵻�
//	}
//
//private:
//	StackOnly()//���캯��˽�л�
//	{}
//};
//int main()
//{
//	StackOnly stObj = StackOnly::GetStackObj();
//	system("pause");
//	return 0;
//}
//
////����Ҳ��һ��bug�ķ�����ֻ����ջ�ϴ������󣬼������ڶ��ϴ��������ֻҪ��new�Ĺ������ε����ɣ������ε�operator new�Ͷ�λnew���ʽ.
////ע�⣺������operator new��ʵ��Ҳ����λnew�����ε��ˡ�
//class StackOnly
//{
//public:
//	StackOnly()
//	{}
//private:
//	//��Ϊnew�ĵײ������operator new�����Կ��԰�operator new����Ϊ˽�еģ����һ����Ҫ�ڶ��ϴ������󣬾ͻ����
//	void* operator new(size_t size);
//	void operator delete(void* p);
//	//��(c++11)
//	void* operator new(size_t size) = delete;//��ɾ����������Ϊ���е�Ҳ����
//	void operator delete(void* p) = delete;
//};
//int main()
//{
//	StackOnly stObj;
//}
//��Ҫע����ǣ����ַ�ʽ��������ȫ�ַ�Χ�д�������Ҳ����ζ�ţ�ֻ����ֹ�ڶ��ϴ�������



//3.����ģʽ�еĶ���ģʽ
//#include <iostream>
//using namespace std;
//
//class ConfigSingleton
//{
//public:
//	static ConfigSingleton& GetInstance()//2.�ṩ���еĻ�ȡʵ���ĳ�Ա����
//	{
//		return _sinst;
//	}
//	void Print()
//	{
//		cout << _ip << " " << _port<< endl;
//	}
//private:
//	ConfigSingleton(const char* ip, int port)//1.���캯��˽�л�
//		:_ip(ip)
//		, _port(port)
//	{
//	 //��ʼ��
//	}
//	//������Ϣ
//	const char* _ip;
//	int _port;
//
//	//������
//	ConfigSingleton(const ConfigSingleton&)=delete;//4.�������캯��˽�л�����ֹ�ٿ���һ�ݶ������
//	ConfigSingleton& operator=(const ConfigSingleton&) = delete;
//
//	static ConfigSingleton _sinst;//3.����һ����̬����
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
//����ģʽ��һ�����ʹ�������
//ȱ�㣺
//�����������Ϣ̫�࣬������������������(��Ϊ��������Ǿ�̬�ģ��ڽ���main����֮ǰ��Ҫ��ʼ�������������Ϣ̫�࣬�����������ͻ��ر���)
//������˳��ȷ��(���һ����Ŀ�����ж�������࣬�������������֮����������ϵ�Ļ���˭�ȳ�ʼ����˭���ʼ����û�б�֤�����Ե���������˳��ȷ��)
//�ŵ㣺��
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
//	ConfigSingleton(const char* ip, int port)//1.���캯��˽�л�
//		:_ip(ip)
//		, _port(port)
//	{
//	}
//
//	//������
//	ConfigSingleton(const ConfigSingleton&) = delete;
//	ConfigSingleton& operator=(const ConfigSingleton&) = delete;
//
//
//	const char* _ip;
//	int _port;
//	static ConfigSingleton _sinst;//2.����һ����̬�Ķ���
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




//����ģʽ(�����򲻵��ѲŴ�������)
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
	   if (_psinst == nullptr)//����һ�δ����ö���󣬹���������б���߳�����ʱ�򣬱���߳�ֱ�ӽ���ȥ��Ҳ�ͽӴ����������Ͳ��ü�����������ʡ��ʱ�䣬�����Ч��
	   {
		   _mutex.lock();
		   if (_psinst == nullptr)//Ϊ�˱�ֻ֤����һ������,�����̰߳�ȫ
		   {
			   _psinst = new ConfigSingleton;
		   }
		   _mutex.unlock();
	   }
	   
	   return _psinst;
	}

   class GC//�ͷ�_psinst
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
	ConfigSingleton(const char* ip = "127.0.0.1", int port = 80)//���캯��˽�л�
		:_ip(ip)
		, _port(port)
	{
		cout << "ConfigSingleton()" << endl;
	}


	//������
	ConfigSingleton(const ConfigSingleton&)=delete;
	ConfigSingleton& operator=(const ConfigSingleton&)=delete;

   const char* _ip;
   int _port;
   static ConfigSingleton* _psinst;
   static mutex  _mutex;

   static GC _gc;//����һ����̬��_gc,�������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
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

