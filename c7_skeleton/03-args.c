#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// definice argumentu programu
const char *usage = "syntax: [-x|-y] [-n COUNT] -s STR\n"
"-x and -y are optional and mutually exclusive\n"
"-s STR - mandatory, STR is a string\n"
"-n COUNT - optional, COUNT is non-negative integer (default: 10)\n";

/**
 * Slozeny datovy typ, ktery obsahuje nastavenou konfiguraci programu.
*/
struct config_t {
   
};

/**
 * Funkce zpracuje argumenty prikazoveho radku, vysledek v promenne config.
*/
void parseArgs(int argc, char* argv[], struct config_t* config)
{

}


int main(int argc, char* argv[])
{


    return 0;
}