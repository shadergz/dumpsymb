#include <stdio.h>
#include <assert.h>

#include <bin/bin.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
        return argc;

    bin_ctx_t ctx;
    bin_err_e err = bin_load_file(argv[1], &ctx);

    if (err != BIN_E_OK)
        return fprintf(stderr, "something wrong has heppen: %s\n", bin_error_to_str(err));
    
    assert(err == bin_get_binary_size(&ctx));

    bin_parser(&ctx);

    err = bin_get_last_error(&ctx);
    
    if (err != BIN_E_OK)
        return fprintf(stderr, "something wrong has heppen: %s\n", bin_error_to_str(err));
    
    printf("%s has been opened for parser\n", bin_get_filename(&ctx));

    printf("binary size: %ld\n", bin_get_binary_size(&ctx));

    printf("binary type is: %s\n", 
        bin_binary_type_to_str(bin_get_binary_type(&ctx))
    );

    bin_finish(&ctx);
    

    return err;
}

