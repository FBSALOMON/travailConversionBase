#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "representation.h"

// *****************************************************************************
// void printNombre(Representation * nb)
//
// Imprime la representation de nb a l'output standard utilise les symboles
// dans SYMBOLES
//
// Préconditions :
//     nb->taille doit etre la taille de nb->nombre
//
// INPUT :
//     nb : Une reprensetation en base nb->base d'un nombre.
//
// Exemples :
//     printNombre({{15,15}, 2, 16}) imprime FF
//     printNombre({{3,1}, 2, 8}) imprime 31
//     printNombre({{10,9,6}, 3, 17}) imprime A96
//
// *****************************************************************************
void printNombre(Representation * nb)
{
    for (int i = 0 ; i < nb->taille; i++)
    {
	printf("%c", SYMBOLES[nb->nombre[i]]);
    }
    printf("\n");
}

// *****************************************************************************
// int main()
//
// Lit a l'input standard une base et un nombre dans cette base et affiche ce
// nombre dans toutes les bases. Si la base demandee est inferieure a 2 ou
// superieure a BASE_MAX, un message d'erreur est affiche et le programme s'arrete.
//
// Préconditions :
//     Le nombre entre ne doit pas depasser en valeur ce qui entre dans un long
//     sur un ordinateur de 64 bits, le plus grand nombre qui peut entrer dans
//     un long signé est 9223372036854775807 (en base 10)
//     111111111111111111111111111111111111111111111111111111111111111 (en base
//     2). De plus, le nombre entre doit etre plus grand ou egal a 1.
//
// *****************************************************************************
int main()
{
    int base = 10;
    char mot[256];
    printf("Quelle est la base?\n");
    scanf("%d", &base);

    
    while ((base <= BASE_MAX) && (base >= BASE_MIN))
    {
		printf("Entrez un nombre dans la base %d\n", base);
		scanf("%s", mot);
		
		Representation nb = traduireEntree(mot, base);
		long d = baseADecimal(&nb);
		free(nb.nombre);
		
		/*Representation n = decimalABase(2, d);
		printf ("     Ada (base 2) : ");
		printNombre(&n);
		free(n.nombre);

		n = decimalABase(8, d);
		printf ("  Donald (base 8) : ");
		printNombre(&n);
		free(n.nombre);
		
		n = decimalABase(10, d);
		printf ("   Vous (base 10) : ");
		printNombre(&n);
		free(n.nombre);
		
		n = decimalABase(60, d);
		printf ("Kidinnu (base 60) : ");
		printNombre(&n);
		free(n.nombre);
		
		printf("\nQuelle est la base?\n");
		scanf("%d", &base);*/
    }

    printf("Bye\n");
    return 0;
}
