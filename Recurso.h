#ifndef RECURSO_H_
#define RECURSO_H_

#include <string>

class Recurso {
public:
	Recurso();
	virtual ~Recurso();
	void identificador(char id);
	std::string identificador();
	std::string id;
};

#endif /* RECURSO_H_ */
