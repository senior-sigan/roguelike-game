/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#ifndef ROGUELIKE_LOGGING_H
#define ROGUELIKE_LOGGING_H

#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/exception.h"

#define LOG_INIT(LOGGER_NAME) log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger(LOGGER_NAME))

#define LOG_CONFIGURE() log4cxx::BasicConfigurator::configure()
#define LOG_PROP_CONFIGURE(PATH) log4cxx::PropertyConfigurator::configure(PATH)

// Note that TRACE level is compiled out in release (non-debug) mode.

#define LOG_TRACE(x) LOG4CXX_TRACE(logger, x)
#define LOG_DEBUG(x) LOG4CXX_DEBUG(logger, x)
#define LOG_INFO(x) LOG4CXX_INFO(logger, x)
#define LOG_WARN(x) LOG4CXX_WARN(logger, x)
#define LOG_ERROR(x) LOG4CXX_ERROR(logger, x)
#define LOG_FATAL(x) LOG4CXX_FATAL(logger, x)

#endif //ROGUELIKE_LOGGING_H
