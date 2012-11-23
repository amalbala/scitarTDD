
#include <limits.h>
#include <stdlib.h>
#include <stdexcept>

#include "scitarTDD.h"
#include "gtest/gtest.h"

namespace{

	class ScitarTests : public ::testing::Test{
	protected:
		ScitarTDD *scitar;

		ScitarTests()
    	{
        	// You can do set-up work for each test here.
    	}

		virtual void SetUp()
    	{

        	scitar = new ScitarTDD(10);

    	}
	};


	TEST_F(ScitarTests, NegativeNumberofFaces){
		try{
			scitar->setNumberOfFaces(-1);
			FAIL() << "Exception is not being throw on negative number of faces";
		}catch(std::range_error &err){}
	}
/*
	TEST_F(ScitarTests,ReadStringwithBlankSpaces){
		try{

			scitar->setPhraseToProcess("En un lugar de la Mancha, de cuyo nombre no quiero acordarme");

		}catch(char){
			FAIL()<< "No exception must be throwed on normal strings";
		}
	}
*/
	TEST_F(ScitarTests,CodifyPhraseSmallerThanFaces){
		try{
				scitar->codify("hola");
				FAIL() << "Exception is not being throw on phase smaller than scitar";
		}catch(std::range_error &err){}
	}

	TEST_F(ScitarTests,TheProcessIsCodify){
		char *outputString = scitar->codify("En un lugar de la Mancha, de cuyo nombre no quiero acordarme");
		ASSERT_TRUE(strcmp("Ernu  n cyna dhoocuea  on ,nqr l oudladmiau ebergM rrmaaceoe",
			outputString) == 0);
	}

	TEST_F(ScitarTests,TheProcessIsDecodify){
		char *outputString = scitar->decodify("Ernu  n cyna dhoocuea  on ,nqr l oudladmiau ebergM rrmaaceoe");
		ASSERT_TRUE(strcmp("En un lugar de la Mancha, de cuyo nombre no quiero acordarme",
			outputString) == 0);
	}
}
