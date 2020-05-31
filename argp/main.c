#include <stdlib.h>
#include <argp.h>
#include <limits.h>
#include <stdbool.h>

const char *argp_program_version = "1.0.0";

static char doc[] = "Change number";
static char args_doc[] = "number";
static struct argp_option options[] = {
  {"verbose", 'v', 0, 0, "Produce verbose output" },
  {"input", 'i', "type", 0, "Input number type"},
  {"output", 'o', "type", 0, "Output number type"},
  { 0 }
};

typedef enum {
	    BIN = 2,
	    OCT = 8,
	    DEC = 10,
	    HEX = 16
} ntype;

struct arguments
{
  char *args[1];
  int verbose;
  ntype itype;
  ntype otype;
};

static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;
  switch (key) {
  case 'v':
    arguments->verbose = 1;
    break;
  case 'i':
    {
      ntype type;
      switch (arg[0]) {
      case 'b':
	type = BIN;
	break;
      case 'o':
	type = OCT;
	break;
      case 'd':
	type = DEC;
	break;
      case 'h':
	type = HEX;
	break;
      default:
	type = DEC;
      }
      arguments->itype = type;
      break;
    }
  case 'o':
    {
      ntype type;
      switch (arg[0]) {
      case 'b':
	type = BIN;
	break;
      case 'o':
	type = OCT;
	break;
      case 'd':
	type = DEC;
	break;
      case 'h':
	type = HEX;
	break;
      default:
	type = DEC;
      }
      arguments->otype = type;
      break;
    }
  case ARGP_KEY_ARG:
    if (state->arg_num >= 1)
      argp_usage (state);
    arguments->args[state->arg_num] = arg;
    break;
  case ARGP_KEY_END:
    if (state->arg_num < 1)
      argp_usage (state);
    break;
  default:
    return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

static ntype getType(char* numstr) {
  if (numstr[0] == '0') {
    switch (numstr[1]) {
    case 'b':
      return BIN;
    case 'o':
      return OCT;
    case 'x':
      return HEX;
    default:
      break;
    }
  }
  return DEC;
}

static unsigned long long convert(char* str, int base) {
  char* end;
  unsigned long long number = strtoull(str, &end, base);
  return number;
}

static void print_bin(unsigned long long num) {
  unsigned long long mask = (unsigned long long)1 << (sizeof(num) * CHAR_BIT - 1);
  bool flag = false;
  do {
    bool bit = (mask & num) > 0;
    if (flag) {
      putchar(bit ? '1' : '0');
    } else {
      if (bit) {
	putchar('1');
	flag = true;
      }
    }
  } while (mask >>= 1);
  printf("\n");
}

int main (int argc, char **argv) {
  struct arguments arguments;

  argp_parse(&argp, argc, argv, 0, 0, &arguments);

  if (arguments.verbose) {
    printf("numstr: %s\n"
	   "input type: %d\n"
	   "output type: %d\n"
	   "verbose: %s\n",
	   arguments.args[0],
	   arguments.itype,
	   arguments.otype,
	   arguments.verbose ? "yes" : "no");
  }

  char* numstr = arguments.args[0];
  ntype type = getType(numstr);

  if (arguments.verbose) {
    printf("auto detected type: %d\n", type);
  }

  unsigned long long number;
  if (type == DEC) {
    number = convert(numstr, arguments.itype);
  } else {
    if (arguments.itype != 0 && type != arguments.itype) {
      printf("error: mismatch type\n");
      return 1;
    }      
    numstr += 2;
    number = convert(numstr, type);
  }

  char *format;
  switch (arguments.otype) {
  case BIN:
    print_bin(number);
    return 0;
  case OCT:
    format = "%llo\n";
    break;
  case DEC:
    format = "%lld\n";
    break;
  case HEX:
    format = "%llx\n";
    break;
  default:
    format = "%lld\n";
    break;
  }
  printf(format, number);
  return 0;
}
