#ifndef HERRAMIENTAS_LOCK_H_
#define HERRAMIENTAS_LOCK_H_

#include <mutex>

class Lock {
public:
  Lock(std::mutex &m);

  ~Lock();

private:
    Lock(const Lock&) = delete;
    Lock& operator=(const Lock&) = delete;
    Lock(Lock&&) = delete;
    Lock& operator=(Lock&&) = delete;
    std::mutex &m;
};

#endif /* HERRAMIENTAS_LOCK_H_ */
