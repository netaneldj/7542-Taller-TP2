#ifndef AGRICULTOR_H_
#define AGRICULTOR_H_

#include "Recolector.h"
#include <string>


class Agricultor: public Recolector {
public:
	Agricultor(ColaBloqueante &fuente, Inventario &inventario);
	~Agricultor();
	virtual void cerrarInventarioRecurso() override;
	virtual std::string trabajador() override;
};

#endif /* AGRICULTOR_H_ */
