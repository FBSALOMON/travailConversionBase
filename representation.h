#ifndef REPRESENTATION_H
#define REPRESENTATION_H

// *****************************************************************************
// Symboles possibles pour ecrire un nombre.
// On n'aura jamais une base plus grande que la longueur de cette chaine.
// *****************************************************************************
static const char SYMBOLES [] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx";
static const int BASE_MAX = 60;
static const int BASE_MIN = 2;

// *****************************************************************************
// typedef struct Representation
//
// Contient tous les attributs relatifs a la reprensentation d'un nombre dans
// une base quelconque.
//
// Attributs :
//     int* nombre :
//         Le tableau contenant les digits du nombre. La plus grande puissance
//         est la premiere.
//     int taille :
//         La taille du tableau contenant les digits du nombre
//     int base :
//         La base dans laquelle le nombre est ecrit.
//
// Exemple :
//    {{1, 1, 1, 0, 1, 1}, 6,  2} est une representation de 11 1011 en binaire.
//    {{3, 11}, 2, 16} est une representation de 3B en hexadecimal.
//    {{5, 9}, 2, 10} est une representation de 59 en decimal.
//    {{2, 18}, 2, 20} est une representation de 2J en vicesimal
//
// *****************************************************************************
typedef struct{
    int* nombre;
    int taille;
    int base;
} Representation;

// *****************************************************************************
// Representation constructeur(int taille, int base)
//
// Fabrique une representation de taille taille en base base et initialise son
// tableau nombre avec la taille taille.
//
// Postcondition :
//     nb->nombre doit etre libere avec un free
//
// INPUT :
//     int taille:
//         La taille du nombre a fabriquer
//     long base :
//         La base du nombre a fabriquer
//
// OUTPUT :
//     Representation nb avec
//         nb->base = base,
//         nb->taille = taille
//         nb->nombre = un tableau de longueur taille. Son contenu n'est pas
//             initialise. Il peut etre nul, il peut etre autre chose. Seule
//             sa taille est garantie.
//
// Exemples :
//     constructeur(2, 16) = {{0,0}, 2, 16}
//     constructeur(11, 2) = {{0,0,0,0,0,0,0,0,0,0,0}, 11, 2}
//     constructeur(3, 16) = {{0,0,0}, 3, 16}
//     constructeur(2,  8) = {{0,0}, 2, 8}
//
// *****************************************************************************
Representation constructeur(int taille, int base);

// *****************************************************************************
// Representation traduireEntree(char* chaine, int base)
//
// Prend une chaine de caracteres (chaine) qui represente un nombre dans la base
// base fabrique une represnetation nb. La fonction met les indices appropries
// dans nb.nombre. Si chaine comprend des symboles qui depassent la base base,
// un message d'erreur est affiche et le programme s'arrete. L'appeleur est
// responsable de liberer la memoire utilisee par nb.nombre.
//
// Cette fonction est utile si on veut lire un nombre dans une base autre que
// la base 10.
//
// INPUT :
//     char* chaine :
//         Une chaine de caractere contenant un nombre dans la base base.
//     int base : 
//         La base dans laquelle est ecrite chaine.
//
// OUTPUT :
//     Une reprensentation du nombre entre dans la meme base.
//
// Exemples :
//     traduireEntree("FF1", 16) = ({15, 15, 1}, 3, 16)
//     traduireEntree("10001", 2) = ({1, 0, 0, 0, 1}, 5, 2)
//     traduireEntree("9", 8) = ERREUR 9 n'est pas un symbole dans la base 8.
//
// *****************************************************************************
Representation traduireEntree(char* chaine, int base);

// *****************************************************************************
// Representation decimalABase(int baseCible, long valeurSource)
//
// Fabrique une representation pour un nombre de valeur valeurSource et en base
// baseCible. L'appeleur est responsable de liberer la memoire utilisee par
// nb->nombre. la variable valeurSource doit etre une valeur en decimal.
//
// Préconditions :
//     baseCible doit etre entre 2 et BASE_MAX
//
// Postcondition :
//     nb->nombre doit etre libere avec un free
//
// INPUT :
//     int baseCible :
//         La base cible
//     long valeurSource :
//         La valeur en decimal qu'on doit traduire dans la base cible
//
// OUTPUT :
//     Representation nb avec
//         nb->base = baseCible,
//         nb->taille = longueur du nombre et
//         nb->nombre = un tableau dans le tas contenant la representation en
//             base baseCible de valeurSource.
//
// Exemples :
//     decimalABase(16,   10) = {{10}, 1, 16}
//     decimalABase( 2, 1025) = {{1,0,0,0,0,0,0,0,0,0,1}, 11, 2}
//     decimalABase(16, 1025) = {{4,0,1}, 3, 16}
//     decimalABase(16,  255) = {{15,15}, 2, 16}
//     decimalABase( 8,   25) = {{3,1}, 2, 8}
//
// *****************************************************************************
Representation decimalABase(int base, long valeur);

// *****************************************************************************
// long baseADecimal(Representation* nb)
//
// Fabrique une representation pour un nombre de valeur valeurSource et en base
// baseCible.  la representation place son nombre dans le tas avec un
// malloc. L'appeleur est responsable de liberer la memoire utilisee. la
// variable valeurSource doit etre une valeur en decimal.
//
// Préconditions :
//     baseCible doit etre entre BASE_MIN et BASE_MAX
//
// Postconditions :
//     nb->nombre doit etre libere avec un free
//
// INPUT :
//     int baseCible :
//         La base cible
//     long valeurSource :
//         La valeur en decimal qu'on doit traduire dans la base cible
//
// OUTPUT :
//     Representation nb avec
//         nb->base = baseCible,
//         nb->taille = longueur du nombre et
//         nb->nombre = un tableau dans le tas contenant la representation en
//             base baseCible de valeurSource.
//
// Exemples :
//     baseADecimal({{10}, 1, 16}) = 16
//     baseADecimal({{1,0,0,0,0,0,0,0,0,0,1}, 11, 2}) = 1025
//     baseADecimal({{4,0,1}, 3, 16}) = 1025 
//     baseADecimal({{15,15}, 2, 16}) = 255
//     baseADecimal({{3,1}, 2, 8}) = 25
//
// *****************************************************************************
long baseADecimal(Representation* nb);

#endif
