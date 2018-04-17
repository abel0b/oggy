#ifndef OGGY_LOG_HPP
#define OGGY_LOG_HPP

#include <string>

namespace oggy {
  class Log {
  public:
    static void info(std::string& message);
    static void debug(std::string& message);
  };
}

#endif
