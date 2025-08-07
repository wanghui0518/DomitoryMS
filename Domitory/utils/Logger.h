#ifndef _LOGGER_H_
#define _LOGGER_H_


// C++ Header File(s)
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifdef WIN32
// Win Socket Header File(s)
#include <Windows.h>
#include <process.h>
#else
// POSIX Socket Header File(s)
#include <errno.h>
#include <pthread.h>
#endif


namespace CPlusPlusLogging
{

   #define LOG_ERROR(x)    Logger::getInstance()->error(x)
   #define LOG_ALARM(x)	   Logger::getInstance()->alarm(x)
   #define LOG_ALWAYS(x)	Logger::getInstance()->always(x)
   #define LOG_INFO(x)     Logger::getInstance()->info(x)
   #define LOG_BUFFER(x)   Logger::getInstance()->buffer(x)
   #define LOG_TRACE(x)    Logger::getInstance()->trace(x)
   #define LOG_DEBUG(x)    Logger::getInstance()->debug(x)

   typedef enum LOG_LEVEL
   {
      DISABLE_LOG       = 1,
      LOG_LEVEL_INFO	   = 2,
      LOG_LEVEL_BUFFER	= 3,
      LOG_LEVEL_TRACE   = 4,
      LOG_LEVEL_DEBUG   = 5,
      ENABLE_LOG        = 6,
   }LogLevel;

   typedef enum LOG_TYPE
   {
      NO_LOG            = 1,
      CONSOLE           = 2,
      FILE_LOG          = 3,
   }LogType;


   class Logger
   {
      public:
         static Logger* getInstance() throw ();


      private:
         static Logger*          m_Instance;
         std::ofstream           m_File;

#ifdef	WIN32
         CRITICAL_SECTION        m_Mutex;
#else
         pthread_mutexattr_t     m_Attr; 
         pthread_mutex_t         m_Mutex;
#endif

         LogLevel                m_LogLevel;
         LogType                 m_LogType;
   };

}


#endif // End of _LOGGER_H_



