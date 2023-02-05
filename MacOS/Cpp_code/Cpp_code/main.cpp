/* Classes
    
 Class Elemanları
 ----------------
 class Data
 {
     int mx;             // Data member
     void func(int);     // Member function
     typedef int Word;   // Type member(member type, nested type)
 };

 Class Scope
 -----------
 Bir sınıfın tanımı içerisinde bildirilen tüm isimler "class scope" denilen özel bir kapsama sahiptir.
 
 
 Şu durumlarda bir isim class scope içinde aranır(Name lookup);
 
 1) "."  operatörünün sağ operandı olan isimler
 2) "->" operatörünün sağ operandı olan isimler
 3) "::" (scope resolution) operatörünün sağ operandı olan isimler
 
Unary: Tek operantlı scope resolution kullanımı. Eğer isimle ilgili bir işlemde, örneğin int tipinden bir değişken, unary çözünürlük operatörü kullanılırsa bu, derleyiciye ismi namespace scope'ta, global alanda ara demek olur(name lookup aşaması). Yerel scope'ta x değişkeni, ismi yer alsa bile global alanda arama yapılır.
 Örn. "::x"

 //
 int g = 10;

 int main()
 {
     int g = 20;
     
     ::g += g;           // Global alandaki g(::g(Unary)) ile localdeki g'nin toplamı
 }
 //
 
Binary: Çift operantlı scope resolution kullanımı. Binary çözünürlük operatörünün sol operandı olan isim ya bir namespace ismi, ya da bir class ismidir. Sağ operandındaki isim ise buna bağlı olarak class veya ilgili namespace scope'ta aranacaktır.
Örn. "a::b"
 
 
 Namespace (İsim Alanı)
 ----------------------
 İsimleri birbirinden gizlemek için kullanılan bir araçtır. Gloabal alandaki isimlerin birbirleriyle karışmasını engellemek için oluşturulmuş isim bölgeleridir. Namespace global alanı parselleyerek kendine özgü isim alanları yaratır.

 namespace Neco
 {
     int x = 64;
 }

 //
 int main()
 {
     int x = 1;

     std::cout << x << '\n';         // x = 1;
     std::cout << Neco::x << '\n';   // x = 64;
 }

*/


// Include
#include <iostream>
// Yapılar


class Data
{
    int mx;             // Data member
    void func(int);     // Member function
    typedef int Word;   // Type member(member type, nested type)
};



namespace Neco
{
    int x = 64;
}

//
int main()
{
    int x = 1;

    std::cout << x << '\n';         // x = 1;
    std::cout << Neco::x << '\n';   // x = 64;
}
