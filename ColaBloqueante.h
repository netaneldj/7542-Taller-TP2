#ifndef COLABLOQUEANTE_H_
#define COLABLOQUEANTE_H_

#include <condition_variable>
#include <mutex>
#include <queue>

#include "Recurso.h"
#include "ColaBloqueante.h"

class ColaBloqueante {
public:
    ColaBloqueante();
    ~ColaBloqueante();
    void encolar(Recurso item);
    Recurso desencolar();
    bool cerrada();
    bool vacia();
    void cerrar();

private:
    bool estaCerrada;
    std::mutex m;
    std::queue<Recurso> cola;
    std::condition_variable cv;
};

#endif /* COLABLOQUEANTE_H_ */
