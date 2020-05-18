#ifndef RECURSO_H_
#define RECURSO_H_

#include <string>

class Recurso {
public:
	Recurso();
	virtual ~Recurso();
	void identificador(char id);
	char identificador();
	char id;
};

#endif /* RECURSO_H_ */
