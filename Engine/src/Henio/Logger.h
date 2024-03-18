#pragma once

#include "Core.h"

#include <iostream>
#include <cstdio>
#include <ostream>

#define LOG_ERROR(...) \
std::printf("[Error] [%s] ", __FUNCTION__); \
Henio::Logger::Log(Henio::LogVerbosity::Error, __VA_ARGS__);

#define LOG_WARNING(...) \
std::printf("[Warning] [%s] ", __FUNCTION__); \
Henio::Logger::Log(Henio::LogVerbosity::Warning, args ... );

#define LOG_MESSAGE(...) \
std::printf("[Message] [%s] ", __FUNCTION__); \
Henio::Logger::Log(Henio::LogVerbosity::Message, __VA_ARGS__);

namespace Henio
{
    enum HENIO_API LogVerbosity
    {
        Error = 1,
        Warning = 2,
        Message = 3,
    };

    class HENIO_API Logger
    {
    public:
        /* log if input log level is equal or smaller to log level set */
        template <typename... Args>
        static void Log(unsigned int inLogLevel, Args ... args)
        {
            if (logToFile)
            {
                static bool bInitialized = false;
                if (!bInitialized)
                {
                    std::ofstream clearFile("log/log.txt");
                    bInitialized = true;
                }
            }

            if (inLogLevel <= logLevel) 
            {
                char buffer[100];
                sprintf_s(buffer, args ...);
                std::cout << buffer << std::endl;
               
                if (logToFile)
                {
                    std::ofstream ofile("log/log.txt", std::ios::app);
                    ofile << buffer << '\n';
                    ofile.close();
                }
            }
        }
    
        static void SetLogLevel(unsigned int inLogLevel)
        {
            logLevel = inLogLevel;
        }
    
        static unsigned int logLevel;
        static unsigned int logError;
        static unsigned int logWarning;
        static unsigned int logMessage;
        static bool logToFile;
    };
}