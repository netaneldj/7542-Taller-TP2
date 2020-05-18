#ifndef TABLERO_H_
#define TABLERO_H_

#include <condition_variable>
#include <mutex>

class Tablero {
public:
	Tablero(std::mutex &m);
	~Tablero();
	void sumar(int puntos);
	int consultar();
	void imprimir();

private:
	int puntaje;
	std::mutex &m;
	std::condition_variable cv;
};

#endif /* TABLERO_H_ */
