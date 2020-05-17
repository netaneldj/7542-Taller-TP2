#ifndef TABLERO_H_
#define TABLERO_H_

#include <condition_variable>
#include <mutex>

class Tablero {
public:
	Tablero();
	~Tablero();
	bool sumar(int puntos);
	int consultar();
	void imprimir();

private:
	std::mutex m;
	int puntaje;
	std::condition_variable cv;
};

#endif /* TABLERO_H_ */
