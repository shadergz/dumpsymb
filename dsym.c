#include <stdio.h>
#include <assert.h>

#include <bin/binary.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
		return argc;

	BinCtx_t ctx;
	BinError_t err;

	BinLoadFile(argv[1], &ctx);

	err = BinGetLastError(&ctx);

	if (err != BIN_E_OK)
	{
		return fprintf(stderr, "Something wrong has happen: %s\n", BinErrorToStr(err));
	}

	assert(err == BinGetLastError(&ctx));

	BinParser(&ctx);

	err = BinGetLastError(&ctx);
	
	if (err != BIN_E_OK)
	{
		return fprintf(stderr, "Something wrong has happen: %s\n", BinErrorToStr(err));
	}

	printf("%s was been opened for parser\n", BinGetFilename(&ctx));

	printf("Binary size: %ld\n", BinGetObjectSize(&ctx));

	printf("Binary type is: %s\n", 
		BinObjectTypeToStr(BinObjectGetType(&ctx))
	);

	BinFinish(&ctx);

	return err;
}

