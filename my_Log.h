 ///
 /// @file    Mylog.h
 /// @author  MyLaserLight(MyLaserLight@163.com)
 /// @date    2018-06-11 20:59:20
 ///

#ifndef __YBTC_MYLOG_H__
#define __YBTC_MYLOG_H__

#include <log4cpp/Category.hh>


//Singleton
//1. 构造函数私有，析构函数私有
//2. 静态函数getInstance()
//3. 静态私有成员  类名 * _pInstance;
namespace YBTC
{

class Mylog
{
public:
	static Mylog *getInstance();
	static void destroy(); 

	template <class... T>
	void warn(const char *msg, T... args)
	{
		_root.warn(msg, args...);
	}
	template <class... T>
	void info(const char *msg, T... args)
	{
		_root.info(msg, args...);
	}
	template <class... T>
	void error(const char *msg, T... args)
	{
		_root.error(msg, args...);
	}
	template <class... T>
	void debug(const char *msg, T... args)
	{
		_root.debug(msg, args...);
	}

private:
	Mylog();
	~Mylog();
private:
	log4cpp::Category &_root;
};

}//end of namespace wd

#define prefix(msg) std::string("[").append(__FILE__)\
		.append(":").append(__FUNCTION__)\
		.append(":").append(std::to_string(__LINE__))\
		.append("]: ").append(msg).c_str()

#define LogWarn(msg, ...) YBTC::Mylog::getInstance()->warn(prefix(msg), __VA_ARGS__)
#define LogInfo(msg, ...) YBTC::Mylog::getInstance()->info(prefix(msg), __VA_ARGS__)
#define LogError(msg, ...) YBTC::Mylog::getInstance()->error(prefix(msg), __VA_ARGS__)
#define LogDebug(msg, ...) YBTC::Mylog::getInstance()->debug(prefix(msg), __VA_ARGS__)

#endif
