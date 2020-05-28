#ifndef INVENTARIO_H_
#define INVENTARIO_H_

#include <condition_variable>
#include <string>
#include <mutex>
#include <map>

class Inventario {
public:
	Inventario();
	~Inventario();
	bool cerrado(char recurso);
	int cantidad(char recurso);
	bool hay(char recurso, int cantidad);
	bool agregar(char recurso);
	bool quitar(char recurso);
	void cerrar(char recurso);
	void imprimir();
	void incorporarTrabajador(std::string trabajador);
	void suspenderTrabajador(std::string trabajador);
	int cantidadTrabajador(std::string trabajador);
private:
	std::mutex m;
	std::map<char, int> inventario;
	std::map<char, bool> estaCerrado;
	std::map<std::string, int> trabajadores;
};

#endif /* INVENTARIO_H_ */
