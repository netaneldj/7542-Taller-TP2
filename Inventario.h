#ifndef INVENTARIO_H_
#define INVENTARIO_H_

#include <condition_variable>
#include <string>
#include <mutex>
#include <map>

#include "Recurso.h"

class Inventario {
public:
	explicit Inventario(std::mutex &m);
	~Inventario();
	bool cerrado(Recurso item);
	int cantidad(Recurso item);
	bool hay(Recurso item, int cantidad);
	bool agregar(Recurso item);
	bool quitar(Recurso item);
	void cerrar(Recurso item);
	void imprimir();
	void incorporarTrabajador(std::string trabajador);
	void suspenderTrabajador(std::string trabajador);
	int cantidadTrabajador(std::string trabajador);
private:
	std::mutex &m;
	std::map<char, int> inventario;
	std::map<char, bool> estaCerrado;
	std::map<std::string, int> trabajadores;
    std::condition_variable cv;
};

#endif /* INVENTARIO_H_ */
