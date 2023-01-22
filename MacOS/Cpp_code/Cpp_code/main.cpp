/* DECLTYPE
 
 decltype(x)
 - Decltype anahtar sözcüğü, tür bilgisi kullanılan her yerde kullanılabilmektedir.
 - decltype(x) ifadesinde x'in türü neyse ifadenin sonucu da odur.
 - decltype ile auto arasında bazı çıkarımsal farklılıklar bulunmaktadır. auto kullanımı biraz daha tercihe bağlıdır fakat decltype bazı yerlerde zorunluluk olabilir.
 
 - decltype'da auto'da olduğu gibi cont düşmez.
 - decltype'da array to pointer conversion yapılmaz.
 
 - * decltype operandı eğer bir isimse, doğrudan ismin türünü alır.
 - * decltype operandı eğer bir ifadeyse aşağıdaki durumlara göre tür belirlenir.
 
 Eğer Decltype Operandı İfade ise Tür Durumları
 1- Eğer decltype'ın operandı olan ifade PR value kategoreisinde ise elde edilen tür(T) doğrudan ifadenin türüne(T) eşittir
 2- Eğer decltype'ın operandı olan ifade L  value kategoreisinde ise elde edilen tür(T) ifadenin türünün referansına(&T) eşittir
 3- Eğer decltype'ın operandı olan ifade PR value kategoreisinde ise elde edilen tür(T) ifadenin türünün refref(&&T) eşittir
 
 decltype(T), T bir ifade
 1- PR value ise tür ->   T türüdür
 2-  L value ise tür ->  &T türüdür
 3-  X value ise tür -> &&T türüdür
 
 
 !!! VALUE EXPRESSION
 - Bir isim şeklinde olan bütün ifadeler lvalue expression’dır.
 - Value kategorilerinden bahsedebilmek için bir ifade olması lazım. Bildirimlerin value kategorisi olmaz, ifadelerin olur.
 
*/


// Include
#include <iostream>


// Yapılar


// Func


//
int main()
{
    
    // - int a
    {
        int x = 10;
        decltype(x) a;
    }
    
    // - double a
    {
        int x = 10;
        decltype(x + 3.5) a;
    }
    
    // - int *ptr
    {
        int x = 10;
        decltype(x) *ptr;
    }
        
    // - const int *ptr
    {
        int x = 10;
        const decltype(x) *ptr;
    }
    
    // - const int *ptr, CONSTLUK DUSMEZ
    {
        const int x = 10;
        decltype(x) *ptr;
    }
    
    // - int b[10]
    {
        int a[10]{};
        decltype(a) b;
    }
    
    // - int &y
    {
        int x = 10;
        int &r = x;
        decltype(r) y = x;
    }
    
    
    
    //*** DECLTYPE DURUMLARI - Operand isim
    {
        int x = 10;
        decltype(x) a;  //int a
    }
    
    //*** DECLTYPE DURUMLARI - Operand L value
    {
        int x = 10;
        int b = 10;
        decltype((x)) a = b;   // int &a
        
        // !!! decltype(x) bir isim operandı iken decltype((x)) bir ifadedir ve L value expressiondır.
    }
    
    
    //*** DECLTYPE DURUMLARI - Operand L value
    {
        int x = 10;
        int b = 10;
        
        decltype(++x) a = b;   // int &
    }
    
    
    //*** DECLTYPE DURUMLARI - Operand X value
    {
        int &&foo();
        
        decltype(foo()) a = 10;   // int &&
    }
    
    
    //*** DECLTYPE DURUMLARI - Operand PR value
    {
        int x = 10;
        
        decltype(x+5) a;   // int
    }
    
    
    //*** DECLTYPE DURUMLARI - Operand PR value
    {
        int x = 10;
        
        decltype(x++) a;   // int
    }

}
