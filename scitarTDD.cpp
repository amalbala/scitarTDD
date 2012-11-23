

#include "scitarTDD.h"
#include <string.h>

void ScitarTDD::ValidateNumFaces(int facesnumber){
	if(facesnumber<1){
		throw(std::range_error("Number of faces is below 1"));
	}
}

void ScitarTDD::ValidatePhrase(char *phrase){
	if(strlen(phrase)<= getNumberOfFaces()){
		throw(std::range_error("Lenght of phrase smaller than number of faces"));
	}
}

ScitarTDD::ScitarTDD(int facesnumber){
	ValidateNumFaces(facesnumber);
	this->numberOfFaces = facesnumber;
}

void ScitarTDD::setNumberOfFaces(int facesnumber){
	ValidateNumFaces(facesnumber);
	this->numberOfFaces = facesnumber;
}

int ScitarTDD::getNumberOfFaces(){
	return numberOfFaces;
}

char* ScitarTDD::codify(char* phrase){
	ValidatePhrase(phrase);
	int phraselenght = strlen(phrase);

	char* codedPhrase = (char*)malloc(sizeof(char) * phraselenght);

	int positiononOutputPhrase = 0;
	for(int j=0; j<(getNumberOfFaces()); j++){
		for(int i=j; i<phraselenght; i+=(getNumberOfFaces())){
			codedPhrase[positiononOutputPhrase] = phrase[i];
			positiononOutputPhrase++;
		}
	}
	codedPhrase[positiononOutputPhrase]='\0';
	return codedPhrase;
}

char* ScitarTDD::decodify(char* phrase){

	int string_lenght =  strlen(phrase);
	int originalNumFaces = getNumberOfFaces();
	int newStepForDecoding = string_lenght / this->numberOfFaces;
	setNumberOfFaces(newStepForDecoding);
	char* decodePhrase =  codify(phrase);
	setNumberOfFaces(originalNumFaces);
	return decodePhrase;

}