#include <stdio.h>
#include <assert.h>

#include <bin/binary.h>

static bool SymbolsFunc(BinCtx_t *ctx, const ObjectSymbol_t *funcObject, ObjectSymbol_t *userObject);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return argc;
    }

    BinCtx_t ctx;
    BinError_e err;

    bin_load_file(argv[1], &ctx);

    err = bin_error_get_last(&ctx);

    if (err != BIN_E_OK) {
        return fprintf(stderr, "Something wrong has happen: %s\n", bin_error_to_str(err));
    }

    /* Assert test */
    assert(err == bin_error_get_last(&ctx));

    bin_parser(&ctx);

    err = bin_error_get_last(&ctx);
    
    if (err != BIN_E_OK) {
        return fprintf(stderr, "Something wrong has happen: %s\n", bin_error_to_str(err));
    }
    printf("%s was been opened for parser\n", bin_obj_get_filename(&ctx));
    printf("Binary size: %ld\n", bin_obj_get_size(&ctx));

    printf("Binary type is: %s\n", 
        bin_obj_type_to_str(bin_obj_get_type(&ctx))
    );

    printf("Binary endianness: %s\n", bin_cpu_endian_to_str(bin_obj_get_endian(&ctx)));
    printf("Binary arch: %s\n", bin_class_to_str(bin_obj_get_class(&ctx)));

    /* Getting symbols */
    bin_obj_symbols_foreach(&ctx, SymbolsFunc, NULL);

    /* bin_unload call isn't required */
    bin_finish(&ctx);
    return err;
}

static bool SymbolsFunc(BinCtx_t *ctx, const ObjectSymbol_t *funcObject, ObjectSymbol_t *userObject)
{
    (void)ctx;
    (void)funcObject;
    (void)userObject;
}


