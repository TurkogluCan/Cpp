/* FUNTION OVERLOADING(Fonksiyon Yüklemesi).2
  - Funciton overloading giriş seviye örnekleri
*/


// Include
#include <iostream>
// Yapılar

// Func
int foo(int, int);
 foo(int, int);


//
int main()
{

    // - Function redeclaration, overloading değil
    {
        int foo(int, int);
        int foo(int, int);
    }
    
    // - Hatalı kullanım, imzaları aynı ama geri dönüşü farklı
    {
        int    foo(int, int);
        double foo(int, int);
    }
    
    // - CONST: Kullanıcıyı korumak yoluyla yapılan constlar, top level constlar, imzayı değiştirmez.
    //  Bu yüzden aşağıdakiler overloading değil, redeclaration'dır.
    {
        int foo(const int);
        int foo(int);
        
        int func(int *);
        int func(int *const);
    }
    
    // + const: "Const Overloading"
    {
        int func(const int *);
        int func(int *);
        
        int foo(const int &);
        int foo(int &);
    }
    
    // - Default Arg, Function redeclaration
    {
        int func(int x);
        int func(int x=10);
    }
    
    // + Default arg
    {
        int func(int x);
        int func(int x, int y=10);
    }
   
    // + Referans, ÇOK TEHLİKELI
    {
        int func(int &x);
        int func(int x );
    }
    
    // + Referans ve pointer
    {
        int func(int &);
        int func(int *);
    }
   
}
