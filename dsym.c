#include <stdio.h>
#include <assert.h>

#include <bin/bin.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
        return argc;

    BinCtx_t ctx;
    BinError_t err = BinLoadFile(argv[1], &ctx);

    if (err != BIN_E_OK)
        return fprintf(stderr, "something wrong has happen: %s\n", BinErrorToStr(err));
    
    assert(err == BinGetLastError(&ctx));

    BinParser(&ctx);

    err = BinGetLastError(&ctx);
    
    if (err != BIN_E_OK)
        return fprintf(stderr, "something wrong has happen: %s\n", BinErrorToStr(err));
    
    printf("%s has been opened for parser\n", BinGetFilename(&ctx));

    printf("binary size: %ld\n", BinGetBinarySize(&ctx));

    printf("binary type is: %s\n", 
        BinBinaryTypeToStr(BinGetType(&ctx))
    );

    BinFinish(&ctx);
    

    return err;
}

