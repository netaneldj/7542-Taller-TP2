#ifndef COLABLOQUEANTE_H_
#define COLABLOQUEANTE_H_

#include "ColaBloqueante.h"
#include <condition_variable>
#include <mutex>
#include <queue>

class ColaBloqueante {
public:
    ColaBloqueante();
    ~ColaBloqueante();
    void encolar(char recurso);
    char desencolar();
    bool cerrada();
    bool vacia();
    void cerrar();

private:
    bool estaCerrada;
    std::mutex m;
    std::queue<char> cola;
    std::condition_variable cv;
};

#endif /* COLABLOQUEANTE_H_ */
