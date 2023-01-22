/* INCOMPLETE TYPE (FORWARD) DECLERATION:
 
 - Derleyici bir türün varlığından haberdar fakat o türün tanımıyla(örneğin yapının elemanlarıyla ) karşılaşmamışsa bu tür incomplete type'dır.
 - Incomplete türünden nesne yaratılamaz çünkü derleyicinin nesne yaratabilmesi için boyutunu bilmesi gerekmektedir.
 
*/


// Include
#include <iostream>


// Yapılar
struct NECO;    // incomplete type, tamamlanmamis tur



// Func

struct NECO foo(struct NECO *);   // GECERLI
typedef struct NEOCO  necati;     // GECERLI


//
int main()
{
    struct NECO *p;   // GECERLI
    
    struct NECO x;    // HATALI, Derleyicinin nesne olusturabilmesi icin yer ayırması lazım. Bu yüzden de NECO'nun boyutunu bilmesi gerekir

    int x = sizeof(struct NECO);   // HATALI, Incomplite type kullanilamaz
}
