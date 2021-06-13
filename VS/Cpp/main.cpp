#include <iostream>


void Swap(int &r1, int &r2)
{
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

int main()
{
    int x = 10;
    int y = 20;
    int &r1 = x;
    int &r2 = y;

    Swap(r1, r2);

    std::cout << "x = " << x << "\n" << "y = " << y << "\n";
}


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