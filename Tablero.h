#ifndef TABLERO_H_
#define TABLERO_H_

#include <condition_variable>
#include <mutex>

class Tablero {
public:
	Tablero();
	~Tablero();
	void sumar(int puntos);
	int consultar();
	void imprimir();

private:
	int puntaje;
	std::mutex m;
};

#endif /* TABLERO_H_ */
