#ifndef RECOLECTOR_H_
#define RECOLECTOR_H_

#include "ColaBloqueante.h"
#include "Inventario.h"
#include "Thread.h"
#include <string>

class Recolector : public Thread {
public:
	Recolector(ColaBloqueante &fuente, Inventario &inventario);
	virtual ~Recolector();
	char recibirRecurso();
	bool depositarRecurso(char recurso);
	virtual void cerrarInventarioRecurso();
	virtual std::string trabajador();
	void trabajar();
	virtual void run() override;
	ColaBloqueante &fuente;
	Inventario &stock;
};

#endif /* RECOLECTOR_H_ */
