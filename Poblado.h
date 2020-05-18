#ifndef POBLADO_H_
#define POBLADO_H_

#include "ColaBloqueante.h"
#include "Inventario.h"
#include "Tablero.h"
#include "Thread.h"
#include "Armero.h"
#include "Carpintero.h"
#include "Cocinero.h"
#include "Agricultor.h"
#include "Leniador.h"
#include "Minero.h"
#include <string>
#include <list>
#include <mutex>

class Poblado {
public:
	Poblado(std::mutex &m);
	~Poblado();
	void ingresarRecursos(std::string ruta);
	void ingresarTrabajadores(std::string ruta);
	void crearTrabajadores(std::string tipo, int cantidad);
	void iniciarTrabajadores();
	void detenerTrabajadores();
	void imprimir();

private:
	ColaBloqueante colaAgricultor;
	ColaBloqueante colaLeniador;
	ColaBloqueante colaMinero;
	Tablero puntos;
	Inventario stock;
	std::mutex &m;
	std::vector<Thread*> trabajadores;
	void split(std::string& str, std::vector<std::string>& tupla, char delim);
};

#endif /* POBLADO_H_ */
