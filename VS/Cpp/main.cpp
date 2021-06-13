#include <iostream>

int main()
{
    int x = 10;
    int y = 20;
    int *ptr = &x;
    int *&rp = ptr;

    *rp = 11;

    std::cout << "x = " << x << "\n";
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
                        
******************************************************************************************************************************************************
*/