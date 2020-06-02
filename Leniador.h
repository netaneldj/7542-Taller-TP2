#ifndef LENIADOR_H_
#define LENIADOR_H_

#include "Recolector.h"
#include <string>

class Leniador: public Recolector {
public:
	Leniador(ColaBloqueante &fuente, Inventario &inventario);
	~Leniador();
	virtual void cerrarInventarioRecurso() override;
	virtual std::string trabajador() override;
};

#endif /* LENIADOR_H_ */
