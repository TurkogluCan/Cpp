#include <iostream>


static int g = 10;
int &func()
{
    return g;
}

int main()
{
    func() = 45;

    std::cout << "g = " << g << "\n";
}

/* Bu ornekte "int &func()" fonksiyonu referans donusu olan bir fonksiyondur ve static int olan g'yi doner. Nesneyi referans olarak doner.
   C++'da;
   "Tur &func(...)" prototipindeki bir fonksiyona "func() = ..." seklinde yapilan cagri ifadesi "lvalue expression" sol deger 
   ifadesidir.
   "func() = ..."  gibi bir atama durumu da mumkundur. Burada func donusu g'nin referansidir ve g'nin referansina
   bir deger ataniyor diye dusunulmelidir.
   -> func() = 45;    veya    int &r = g;
                              r = 45;
   
   -> Tur &r = func();
*/

/*
    ---------------------------------------------------- R E F E R A N C E ----------------------------------------------------
    Referanslar C dilinde XXX * const ptr; ifadesine benzetilebilir. (XXX değişken tipidir, örn int)

    1* Referanslara ilk deger vermek mecburi.
    -> int ival = 10;
    -> int &r   = ival;                         // Lvalue expression
       int &r{ival};
       int &r(ival);

    2* Referanslara ilk deger veren sol taraf degeri ile reference turu ayni olmak zorunda.
    -> int ival = 10;
    -> double &r   = ival;                       ❌ - ERROR                  
       double &r   = (double&)ival;              ✔  - OK 
       int &r      = ival;                       ✔  - OK
    
    3* Bir rvalue expression bir lvalue referansa ilk deger veremez. 
    -> int x     = 10;
       int &r    = x + 10;                       ❌ - ERROR 
       double &r = (double)ival;                 ❌ - ERROR 

    4* Bir referans bir nesneye baglanir, sonrasinda baska bir nesneye baglanamaz(Pointer Ref haric). Yani gosterdigi adres sonradan degistirilemez(const* ptr gibi)
    -> int x     = 10;
       int &r    = x + 10;                       ❌ - ERROR
       double &r = (double)ival;                 ❌ - ERROR

    5* Bir pointer kendisine referans alabilir.
    -> int x     = 10;           (int x)
       int *ptr  = &x;           (int * ptr)  = (int *)x 
       int *&rp  = ptr;          (int * &rp)  = ptr
                   
    6* Bir dizi kendisine referans alabilir.
    -> int a[5]      = {0,1,2,3,4};  
       int (&ra)[5]  = a;           
                        
    7* Referans kullaniminda pointerda oldugu gibi NULL pointer semantigi yoktur.

    8* Elemanlari referans olan bir referans dizisi olamaz.

    9* "Tur &func(...)" prototipindeki bir fonksiyona "func() = ..." seklinde yapilan cagri ifadesi "lvalue expression" sol deger 
        ifadesidir. Bu sayede deger atanabilmektedir.
        func(...) fonksiyonu nesneyi referans olarak doner. Bu yuzden referansa ilk deger vermede de kullanılabilmektedir.
        
        -> func() = 10;
        -> Tur &r = func();
    
    10* Referans ile pointer kullanmak assembly kod acisindan neredeyse aynidir. Derleyici icin neredeyse bir fark yoktur.
    
    ---------------------------------------------------- R E F E R A N C E  ve  C O N S T ---------------------------------------
    

    1* Referance'lardki "Tur * const ptr" karsiligi      ❌  (tur * const ptr)
    -> int x = 10;
       int &const r = x;
       Bu kullanim dogru bir kullanim degildir. Cunku referanslarin gosterdigi nesne zaten degistirilemez, baska bir nesnenin yerine gecemez. 
       Dogustan kenidisi const'tur.
       Derleyici Syntax hatasi vermeyebilir fakat uyari verir. 

    2* Referance'lardki "const Tur *ptr" karsiligi        ✔  (const tur *ptr)
    -> int x = 10;
       const int &r = x;
    -> const Tur *foo(...)
       Bu kullanimla birlikte r'nin gosterdigi x yalnizca salt okunabilir olarak kullanilabilinecektir. x'in degeri degistirilemez.




    ---------------------------------------------------- N U L L ----------------------------------------------------------------
    C'de "NULL"  bir makrodur. Tanimi;
    #define NULL (void *)0
    -> int *ptr = NULL;
       ptr = 0;
    C++'de nullptr vardır.  nullptr bir sabittir ve bir turu vardır. Bu turun ismi nullptr_t'dir.
    typedef decltype(nullptr) nullptr_t; 
    -> int *ptr = nullptr_t;


******************************************************************************************************************************************************
*/
