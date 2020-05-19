#ifndef AGRICULTOR_H_
#define AGRICULTOR_H_

#include "Recolector.h"
#include "Trigo.h"


class Agricultor: public Recolector {
public:
	Agricultor(ColaBloqueante* fuente, Inventario* inventario);
	~Agricultor();
	virtual void cerrarInventario() override;
	virtual std::string trabajador() override;
};

#endif /* AGRICULTOR_H_ */
