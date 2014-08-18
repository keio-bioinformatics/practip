/*
  File autogenerated by gengetopt version 2.22.6
  generated with the following command:
  gengetopt -u

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "PRactIP: Protein-RNA intACTion using Integer Programming.";

const char *gengetopt_args_info_usage = "Usage: practip [OPTIONS] labeled-data [unlabeled-data]";

const char *gengetopt_args_info_versiontext = "";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help                    Print help and exit",
  "  -V, --version                 Print version and exit",
  "  -c, --cross-validation=INT    Perform the n-fold cross validation\n                                  (default=`0')",
  "  -e, --eta=FLOAT               Initial step width for the subgradient\n                                  optimization  (default=`0.5')",
  "  -w, --pos-w=FLOAT             The weight for positive interactions\n                                  (default=`4')",
  "      --neg-w=FLOAT             The weight for negative interactions\n                                  (default=`1')",
  "  -D, --discriminative=FLOAT    The weight for the regularization term of the\n                                  discriminative model  (default=`1.0')",
  "  -G, --generative=FLOAT        The weight for the regularization term of the\n                                  generative models  (default=`1.0')",
  "  -d, --d-max=INT               The maximim number of iterations of the\n                                  supervised learning  (default=`500')",
  "  -g, --g-max=INT               The maximum number of iterations of the\n                                  semi-supervised learning  (default=`500')",
  "      --aa-int-max=INT          The maximum number of interations of each amino\n                                  acid  (default=`3')",
  "      --rna-int-max=INT         The maximum number of interations of each\n                                  nucleotide  (default=`4')",
  "      --exceeding-penalty=FLOAT The penalty for exceeding the limit of the\n                                  number of interactions for each residue/base\n                                  (default=`0.5')",
    0
};

typedef enum {ARG_NO
  , ARG_INT
  , ARG_FLOAT
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->cross_validation_given = 0 ;
  args_info->eta_given = 0 ;
  args_info->pos_w_given = 0 ;
  args_info->neg_w_given = 0 ;
  args_info->discriminative_given = 0 ;
  args_info->generative_given = 0 ;
  args_info->d_max_given = 0 ;
  args_info->g_max_given = 0 ;
  args_info->aa_int_max_given = 0 ;
  args_info->rna_int_max_given = 0 ;
  args_info->exceeding_penalty_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->cross_validation_arg = 0;
  args_info->cross_validation_orig = NULL;
  args_info->eta_arg = 0.5;
  args_info->eta_orig = NULL;
  args_info->pos_w_arg = 4;
  args_info->pos_w_orig = NULL;
  args_info->neg_w_arg = 1;
  args_info->neg_w_orig = NULL;
  args_info->discriminative_arg = 1.0;
  args_info->discriminative_orig = NULL;
  args_info->generative_arg = 1.0;
  args_info->generative_orig = NULL;
  args_info->d_max_arg = 500;
  args_info->d_max_orig = NULL;
  args_info->g_max_arg = 500;
  args_info->g_max_orig = NULL;
  args_info->aa_int_max_arg = 3;
  args_info->aa_int_max_orig = NULL;
  args_info->rna_int_max_arg = 4;
  args_info->rna_int_max_orig = NULL;
  args_info->exceeding_penalty_arg = 0.5;
  args_info->exceeding_penalty_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->cross_validation_help = gengetopt_args_info_help[2] ;
  args_info->eta_help = gengetopt_args_info_help[3] ;
  args_info->pos_w_help = gengetopt_args_info_help[4] ;
  args_info->neg_w_help = gengetopt_args_info_help[5] ;
  args_info->discriminative_help = gengetopt_args_info_help[6] ;
  args_info->generative_help = gengetopt_args_info_help[7] ;
  args_info->d_max_help = gengetopt_args_info_help[8] ;
  args_info->g_max_help = gengetopt_args_info_help[9] ;
  args_info->aa_int_max_help = gengetopt_args_info_help[10] ;
  args_info->rna_int_max_help = gengetopt_args_info_help[11] ;
  args_info->exceeding_penalty_help = gengetopt_args_info_help[12] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);

  if (strlen(gengetopt_args_info_versiontext) > 0)
    printf("\n%s\n", gengetopt_args_info_versiontext);
}

static void print_help_common(void) {
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  if (strlen(gengetopt_args_info_usage) > 0)
    printf("\n%s\n", gengetopt_args_info_usage);

  printf("\n");

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n\n", gengetopt_args_info_description);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);

  args_info->inputs = 0;
  args_info->inputs_num = 0;
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  unsigned int i;
  free_string_field (&(args_info->cross_validation_orig));
  free_string_field (&(args_info->eta_orig));
  free_string_field (&(args_info->pos_w_orig));
  free_string_field (&(args_info->neg_w_orig));
  free_string_field (&(args_info->discriminative_orig));
  free_string_field (&(args_info->generative_orig));
  free_string_field (&(args_info->d_max_orig));
  free_string_field (&(args_info->g_max_orig));
  free_string_field (&(args_info->aa_int_max_orig));
  free_string_field (&(args_info->rna_int_max_orig));
  free_string_field (&(args_info->exceeding_penalty_orig));
  
  
  for (i = 0; i < args_info->inputs_num; ++i)
    free (args_info->inputs [i]);

  if (args_info->inputs_num)
    free (args_info->inputs);

  clear_given (args_info);
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  FIX_UNUSED (values);
  if (arg) {
    fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->cross_validation_given)
    write_into_file(outfile, "cross-validation", args_info->cross_validation_orig, 0);
  if (args_info->eta_given)
    write_into_file(outfile, "eta", args_info->eta_orig, 0);
  if (args_info->pos_w_given)
    write_into_file(outfile, "pos-w", args_info->pos_w_orig, 0);
  if (args_info->neg_w_given)
    write_into_file(outfile, "neg-w", args_info->neg_w_orig, 0);
  if (args_info->discriminative_given)
    write_into_file(outfile, "discriminative", args_info->discriminative_orig, 0);
  if (args_info->generative_given)
    write_into_file(outfile, "generative", args_info->generative_orig, 0);
  if (args_info->d_max_given)
    write_into_file(outfile, "d-max", args_info->d_max_orig, 0);
  if (args_info->g_max_given)
    write_into_file(outfile, "g-max", args_info->g_max_orig, 0);
  if (args_info->aa_int_max_given)
    write_into_file(outfile, "aa-int-max", args_info->aa_int_max_orig, 0);
  if (args_info->rna_int_max_given)
    write_into_file(outfile, "rna-int-max", args_info->rna_int_max_orig, 0);
  if (args_info->exceeding_penalty_given)
    write_into_file(outfile, "exceeding-penalty", args_info->exceeding_penalty_orig, 0);
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char **argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char **argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  FIX_UNUSED (args_info);
  FIX_UNUSED (prog_name);
  return EXIT_SUCCESS;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  FIX_UNUSED (default_value);
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_INT:
    if (val) *((int *)field) = strtol (val, &stop_char, 0);
    break;
  case ARG_FLOAT:
    if (val) *((float *)field) = (float)strtod (val, &stop_char);
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_INT:
  case ARG_FLOAT:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
cmdline_parser_internal (
  int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "cross-validation",	1, NULL, 'c' },
        { "eta",	1, NULL, 'e' },
        { "pos-w",	1, NULL, 'w' },
        { "neg-w",	1, NULL, 0 },
        { "discriminative",	1, NULL, 'D' },
        { "generative",	1, NULL, 'G' },
        { "d-max",	1, NULL, 'd' },
        { "g-max",	1, NULL, 'g' },
        { "aa-int-max",	1, NULL, 0 },
        { "rna-int-max",	1, NULL, 0 },
        { "exceeding-penalty",	1, NULL, 0 },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "hVc:e:w:D:G:d:g:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'c':	/* Perform the n-fold cross validation.  */
        
        
          if (update_arg( (void *)&(args_info->cross_validation_arg), 
               &(args_info->cross_validation_orig), &(args_info->cross_validation_given),
              &(local_args_info.cross_validation_given), optarg, 0, "0", ARG_INT,
              check_ambiguity, override, 0, 0,
              "cross-validation", 'c',
              additional_error))
            goto failure;
        
          break;
        case 'e':	/* Initial step width for the subgradient optimization.  */
        
        
          if (update_arg( (void *)&(args_info->eta_arg), 
               &(args_info->eta_orig), &(args_info->eta_given),
              &(local_args_info.eta_given), optarg, 0, "0.5", ARG_FLOAT,
              check_ambiguity, override, 0, 0,
              "eta", 'e',
              additional_error))
            goto failure;
        
          break;
        case 'w':	/* The weight for positive interactions.  */
        
        
          if (update_arg( (void *)&(args_info->pos_w_arg), 
               &(args_info->pos_w_orig), &(args_info->pos_w_given),
              &(local_args_info.pos_w_given), optarg, 0, "4", ARG_FLOAT,
              check_ambiguity, override, 0, 0,
              "pos-w", 'w',
              additional_error))
            goto failure;
        
          break;
        case 'D':	/* The weight for the regularization term of the discriminative model.  */
        
        
          if (update_arg( (void *)&(args_info->discriminative_arg), 
               &(args_info->discriminative_orig), &(args_info->discriminative_given),
              &(local_args_info.discriminative_given), optarg, 0, "1.0", ARG_FLOAT,
              check_ambiguity, override, 0, 0,
              "discriminative", 'D',
              additional_error))
            goto failure;
        
          break;
        case 'G':	/* The weight for the regularization term of the generative models.  */
        
        
          if (update_arg( (void *)&(args_info->generative_arg), 
               &(args_info->generative_orig), &(args_info->generative_given),
              &(local_args_info.generative_given), optarg, 0, "1.0", ARG_FLOAT,
              check_ambiguity, override, 0, 0,
              "generative", 'G',
              additional_error))
            goto failure;
        
          break;
        case 'd':	/* The maximim number of iterations of the supervised learning.  */
        
        
          if (update_arg( (void *)&(args_info->d_max_arg), 
               &(args_info->d_max_orig), &(args_info->d_max_given),
              &(local_args_info.d_max_given), optarg, 0, "500", ARG_INT,
              check_ambiguity, override, 0, 0,
              "d-max", 'd',
              additional_error))
            goto failure;
        
          break;
        case 'g':	/* The maximum number of iterations of the semi-supervised learning.  */
        
        
          if (update_arg( (void *)&(args_info->g_max_arg), 
               &(args_info->g_max_orig), &(args_info->g_max_given),
              &(local_args_info.g_max_given), optarg, 0, "500", ARG_INT,
              check_ambiguity, override, 0, 0,
              "g-max", 'g',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          /* The weight for negative interactions.  */
          if (strcmp (long_options[option_index].name, "neg-w") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->neg_w_arg), 
                 &(args_info->neg_w_orig), &(args_info->neg_w_given),
                &(local_args_info.neg_w_given), optarg, 0, "1", ARG_FLOAT,
                check_ambiguity, override, 0, 0,
                "neg-w", '-',
                additional_error))
              goto failure;
          
          }
          /* The maximum number of interations of each amino acid.  */
          else if (strcmp (long_options[option_index].name, "aa-int-max") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->aa_int_max_arg), 
                 &(args_info->aa_int_max_orig), &(args_info->aa_int_max_given),
                &(local_args_info.aa_int_max_given), optarg, 0, "3", ARG_INT,
                check_ambiguity, override, 0, 0,
                "aa-int-max", '-',
                additional_error))
              goto failure;
          
          }
          /* The maximum number of interations of each nucleotide.  */
          else if (strcmp (long_options[option_index].name, "rna-int-max") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->rna_int_max_arg), 
                 &(args_info->rna_int_max_orig), &(args_info->rna_int_max_given),
                &(local_args_info.rna_int_max_given), optarg, 0, "4", ARG_INT,
                check_ambiguity, override, 0, 0,
                "rna-int-max", '-',
                additional_error))
              goto failure;
          
          }
          /* The penalty for exceeding the limit of the number of interactions for each residue/base.  */
          else if (strcmp (long_options[option_index].name, "exceeding-penalty") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->exceeding_penalty_arg), 
                 &(args_info->exceeding_penalty_orig), &(args_info->exceeding_penalty_given),
                &(local_args_info.exceeding_penalty_given), optarg, 0, "0.5", ARG_FLOAT,
                check_ambiguity, override, 0, 0,
                "exceeding-penalty", '-',
                additional_error))
              goto failure;
          
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */




  cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  if (optind < argc)
    {
      int i = 0 ;
      int found_prog_name = 0;
      /* whether program name, i.e., argv[0], is in the remaining args
         (this may happen with some implementations of getopt,
          but surely not with the one included by gengetopt) */

      i = optind;
      while (i < argc)
        if (argv[i++] == argv[0]) {
          found_prog_name = 1;
          break;
        }
      i = 0;

      args_info->inputs_num = argc - optind - found_prog_name;
      args_info->inputs =
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        if (argv[optind++] != argv[0])
          args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind-1]) ;
    }

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
