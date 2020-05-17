#ifndef INVENTARIO_H_
#define INVENTARIO_H_

#include <condition_variable>
#include <string>
#include <mutex>
#include <map>

#include "Recurso.h"

class Inventario {
public:
	Inventario(std::mutex &m);
	~Inventario();
	bool encuentra(Recurso item);
	bool cerrado(Recurso item);
	int cantidad(Recurso item);
	bool hay(Recurso item, int cantidad);
	bool agregar(Recurso item);
	bool quitar(Recurso item);
	void cerrar(Recurso item);
	void imprimir();
private:
	std::mutex &m;
	std::map<std::string, int> inventario;
	std::map<std::string, bool> estaCerrado;
    std::condition_variable cv;
};

#endif /* INVENTARIO_H_ */
