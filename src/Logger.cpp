#include <iostream>
#include "Logger.h"

std::shared_ptr<spdlog::logger> Logger::logger;

void Logger::init()
{
    try
    {
        logger = spdlog::basic_logger_mt("basic_logger", "logs/logfile.log");
        spdlog::set_level(spdlog::level::debug); // Set global log level to debug
        spdlog::flush_on(spdlog::level::debug);
        logger->info("Logger initialized");
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    }
}

std::shared_ptr<spdlog::logger> &Logger::getLogger()
{
    return logger;
}
