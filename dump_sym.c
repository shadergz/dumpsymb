#include <assert.h>
#include <stdio.h>

#include <xtext/ext_bin.h>

static bool symbols_func (xtext_ctx_t *ctx, const object_symb_t *func_object,
                          object_symb_t *user_object);

int
main (int argc, char *argv[])
{
  if (argc < 2)
    {
      return argc;
    }

  xtext_ctx_t ctx;
  xtext_error_e err;

  bin_load_file (argv[1], &ctx);

  err = xtext_error_get_last (&ctx);

  if (err != XTEXT_E_OK)
    {
      return fprintf (stderr, "Something wrong has happen: %s\n",
                      xtext_error_to_str (err));
    }

  /* Assert test */
  assert (err == xtext_error_get_last (&ctx));

  xtext_parser (&ctx);

  err = xtext_error_get_last (&ctx);

  if (err != XTEXT_E_OK)
    {
      return fprintf (stderr, "Something wrong has happen: %s\n",
                      xtext_error_to_str (err));
    }
  printf ("%s was been opened for parser\n", xtext_obj_get_filename (&ctx));
  printf ("Binary size: %ld\n", xtext_obj_get_size (&ctx));

  printf ("Binary type is: %s\n",
          xtext_obj_type_to_str (xtext_obj_get_type (&ctx)));

  printf ("Binary endianness: %s\n",
          xtext_cpu_endian_to_str (xtext_obj_get_endian (&ctx)));
  printf ("Binary arch: %s\n",
          xtext_class_to_str (xtext_obj_get_class (&ctx)));

  /* Getting symbols */
  xtext_obj_symbols_foreach (&ctx, symbols_func, NULL);

  /* bin_unload call isn't required */
  bin_finish (&ctx);
  return err;
}

static bool
symbols_func (xtext_ctx_t *ctx, const object_symb_t *func_object,
              object_symb_t *user_object)
{
  (void)ctx;
  (void)func_object;
  (void)user_object;
}
