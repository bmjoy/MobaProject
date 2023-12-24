#ifndef UCSINGLETON_H
#define UCSINGLETON_H
/**
* @file sdsingleton.h
* @brief ������������ϵ��
*
**/
#include "uctype.h"

namespace   UCODE
{
    /**
    * @defgroup groupsingleton �������װ
    * @ingroup  UCODE
    * @{
    */

    /**
    ���ʹ��
    1. ��������ʹ�õ���������Ӧ���������캯������������Ϊ˽��
    2. ��������ʹ�õ���������Ӧ�������������캯����operator �� Ϊ˽��
    3. ���DECLARE_SINGLETON(cls)��������������, clsΪ���������
    4. ���IMPLEMENT_SINGLETON(cls)�������Ķ��崦

    for example:
    //Sample.h
    class CSample
    {
    CSample();
    ~CSample();
    DECLARE_SINGLETON(CSample)
    }

    //Sample.cpp
    IMPLEMENT_SINGLETON(CSample)
    */
#define SIMPLE_DECLARE_SINGLETON(cls)\
public:\
    static cls* CreateInstance()\
    {\
        static cls oCls;\
        return &oCls;\
    }

#define DECLARE_SINGLETON(cls)\
private:\
	 static cls* m_poInstance;\
public:\
	static BOOL CreateInstance()\
	{\
	if(NULL == m_poInstance)\
	m_poInstance = new cls;\
	return m_poInstance != NULL;\
}\
	static cls* Instance(){ return m_poInstance; }\
	static VOID DestroyInstance()\
	{\
	if(m_poInstance != NULL)\
	{\
	delete m_poInstance;\
	m_poInstance = NULL;\
}\
}

#define IMPLEMENT_SINGLETON(cls) \
	cls* cls::m_poInstance = NULL;


//The second way to declare a singleton class
#define  SINGLETON_FRIEND_CLASS_REGISTER(T)  friend  class  CSingleton<T>

    /**
    @brief ����ģ����
    *
    *@remarks
    *1.��ĵ�����Ӧ����publicly�ķ�ʽ�̳��Դ��ಢ�ҹ��캯������������Ӧ������Ϊ˽�еġ�
    *2.��������ʹ�õ���������Ӧ�������������캯����operator �� Ϊ˽��
    *3.��Ӻ� SINGLETON_FRIEND_CLASS_REGISTER(T) �������������ע�᱾��Ϊһ��friend��
    */
    template<class  T>
    class   CSingleton
    {
    public:

        /**
        * @brief
        * ��ʼ������������
        * @return false means failed
        */
        static BOOL CreateInstance()
        {
            if(NULL == m_poInstance)
            {
                m_poInstance = new T;
            }
            return m_poInstance != NULL;
        }

        /**
        * @brief
        * ��ȡ������ָ��
        * @return ������ָ�룬���������ʵ����ʼ��ʧ�ܣ�����NULL
        */
        static T* Instance(VOID)
        {
            return m_poInstance;
        }

        /**
        * @brief
        * ���ٵ�����ʵ��
        * @return VOID
        */
        static VOID DestroyInstance(VOID)
        {
            SDDelete  m_poInstance;
            m_poInstance = NULL;
        }

    protected:
        CSingleton(VOID) {}
        virtual ~CSingleton(VOID) {}

    private:
        static T*   m_poInstance;
    };

    template<class T>
    T* CSingleton<T>::m_poInstance = NULL;



// ����ģʽ����һ��ʵ��,�û�ֻ�趨�� typedef CSDSingleton<Type> TypeSingleton;

    template <class T>
    class CSDSingleton : private T
    {
    private:
        CSDSingleton();
        ~CSDSingleton();

    public:
        static T& Instance();
    };


    template <class T>
    inline CSDSingleton<T>::CSDSingleton()
    {
    }

    template <class T>
    inline CSDSingleton<T>::~CSDSingleton()
    {
    }

    template <class T>
    /*static*/ T &CSDSingleton<T>::Instance()
    {
        // function-local static to force this to work correctly at static
        // initialization time.
        static CSDSingleton<T> s_instance;
        return(s_instance);
    }


}

/** @} */

#endif

