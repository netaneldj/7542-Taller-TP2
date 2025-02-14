#include <iostream>
#include <fstream>
#include <string.h>

#include "Poblado.h"
#include "Inventario.h"
#include "Tablero.h"

#define ARGS_TRABAJADORES 1
#define ARGS_MAPA 2

#define SUCCESS 0
#define ERROR 1

int main(int argc, char** argv) {
	if (argc < 3 or argc > 3) {
        printf("Uso: ./tp <trabajadores> <mapa>\n");
        return ERROR;
    }

	Poblado p;
	try {
		p.ingresarTrabajadores(argv[ARGS_TRABAJADORES]);
		p.iniciarTrabajadores();
		p.ingresarRecursos(argv[ARGS_MAPA]);
		p.detenerTrabajadores();
		p.imprimir();
	    return 0;
	} catch (...) {
		return 1;
	}
}




