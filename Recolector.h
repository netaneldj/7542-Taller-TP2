#ifndef RECOLECTOR_H_
#define RECOLECTOR_H_

#include "Recurso.h"
#include "ColaBloqueante.h"
#include "Inventario.h"
#include "Thread.h"

class Recolector : public Thread {
public:
	Recolector(ColaBloqueante* fuente, Inventario* inventario);
	virtual ~Recolector();
	Recurso recibirRecurso();
	bool depositarRecurso(Recurso item);
	virtual void cerrarInventario();
	void trabajar();
	virtual void run() override;
	ColaBloqueante* fuente;
	Inventario* stock;
};

#endif /* RECOLECTOR_H_ */
