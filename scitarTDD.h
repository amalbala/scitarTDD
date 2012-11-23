
#ifndef SCITARTDD_H
#define SCITARTDD_H

#include <stdexcept>

class ScitarTDD{
private:


	int numberOfFaces;

public:
	ScitarTDD(int facesnumber);
	void ValidateNumFaces(int facesnumber);
	void ValidatePhrase(char* phrase);

	void setNumberOfFaces(int facesnumber);
	int getNumberOfFaces();
	char* codify(char* phrase);
	char* decodify(char* phrase);
};

#endif