
#include <stdio.h>
#include <stdlib.h>
#include "scitarTDD.h"

int main(int argc, char const *argv[])
{
	ScitarTDD *scitar;
	scitar = new ScitarTDD(10);
	char *outputString;
	outputString = scitar->codify("En un lugar de la Mancha, de cuyo nombre no quiero acordarme");
	printf("%s\n",outputString);

	return 0;
}