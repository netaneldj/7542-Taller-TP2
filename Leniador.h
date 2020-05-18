#ifndef LENIADOR_H_
#define LENIADOR_H_

#include "Recolector.h"
#include "Madera.h"

class Leniador: public Recolector {
public:
	Leniador(ColaBloqueante* fuente, Inventario* inventario);
	~Leniador();
	virtual void cerrarInventario() override;
};

#endif /* LENIADOR_H_ */
