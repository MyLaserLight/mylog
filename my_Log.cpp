 ///
 /// @file    Mylog.cc
 /// @author  MyLaserLight(MyLaserLight@163.com)
 /// @date    2018-06-11 21:15:27
 ///

#include "pch.h"
#include "my_Log.h"

#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/RollingFileAppender.hh"
#include "log4cpp/Priority.hh"
#include "log4cpp/PatternLayout.hh"

#include <iostream>
using std::cout;
using namespace YBTC;
using namespace log4cpp;

//Mylog * Mylog::_pInstance = NULL;

Mylog * Mylog::getInstance()
{  // 单例模式 静态局部对象
	static Mylog Instance;
	return &Instance;
}

#if 0
void Mylog::destroy()
{
	if (_pInstance)
	{
		delete _pInstance;
	}
}

template <class... T>
void Mylog::warn(const char *msg, T... args)
{
	_root.warn(msg, args...);
}

template <class... T>
void Mylog::info(const char *msg, T... args)
{
	_root.info(msg, args...); }

template <class... T>
void Mylog::error(const char *msg, T... args)
{
	_root.error(msg, args...);
}

template <class... T>
void Mylog::debug(const char *msg, T... args)
{
	_root.debug(msg, args...);
}
#endif 
Mylog::Mylog()
: _root(Category::getRoot().getInstance("root"))
{
	PatternLayout *ptnLyout1 = new PatternLayout();
	ptnLyout1->setConversionPattern("%d [%p] %x %m%n");
	PatternLayout *ptnLyout2 = new PatternLayout();
	ptnLyout2->setConversionPattern("%d [%p] %x %m%n");
	
	OstreamAppender *ostreamappender = 
		new OstreamAppender("ostreamappender", &cout);
	ostreamappender->setLayout(ptnLyout1);

	RollingFileAppender *rollingfileAppender = 
		new RollingFileAppender("rollingfileAppender", "run.log", 5*1024*1024);
	rollingfileAppender->setLayout(ptnLyout2);

	_root.addAppender(ostreamappender);
	_root.addAppender(rollingfileAppender);
	_root.setPriority(Priority::DEBUG);
}

Mylog::~Mylog()
{
	Category::shutdown();
}
