/* Inline Function - ODR
  
 ->i:
 Normal koşullarda kod içerisinde çağırılan bir fonksiyon var ise derleyici, çağırılan fonksiyonun ismini external referance olarak .obj koda yazacak ve bağlama işlemini linker yapacak. Derleyci sadece fonksiyona giriş ve çıkış kodlarını oluşturur.
 Inline fonksiyonlarda ise derleyici bir analiz yapar ve madem ben bu fonksiyonun kodunu görüyorum, o zaman ben fonksiyonun derlenmiş halini direkt buraya gömeyim. Linker henüz devrede değil. Derleyici nerdeyse makro gibi derlenmiş fonksiyonu o satıra gömer.

 
 Derleyici inline fonksiyonu kullanabilmesi için;
1-) Çağıran fonksiyonun tanımıyla çağırılan fonksiyonun tanımı aynı dosyada olmalı çünkü henüz linker devreye girmeden gömülme işlemi yapılır. Ben bir yerde o fonksiyona çağrı yapıyorsam derleyici o dosya içerisinde fonksiyonun tanımını da görmek zorundadır. Bunun için aynı dosya içerisinde yazılıp kullanılır fakat diğer dosyalara da taşınmak istenirse .h dosyasına fonksiyonun tanımı(içeriği) yazılmalıdır. Bu durum kodun client kullanıcılar tarafından görülmesi istenmiyorsa uygun bir durum değildir.
 
2-) Bir fonksiyon inline diye derleyici tarafından gömülebilecek veya inline değil diye derleyici tarafından gömülemeyecek diye bir durum yoktur. Fonksiyon inline olmasına rağmen gömülmesi derleyicinin yararına değilse, performansı veya diğer şeyleri iyileştirmiyorsa gömülemeyebilir. Kod çok uzun olabilir, gömülmesi zararına olabilir.
 

inline int sum_square(int x, int y)
 {
    return x*x + y*y;
 }
 
 ODR
 ---
 ->i: ODR(One Definition Rule), varlıkların proje içerisinde tek bir tanımının olmasıdır. Kaç tane kaynak dosya olursa olsun tanımı sadece bir tane olacaktır.
 "int factorial(...)" fonksiyonu a.c ve b.c dosyalarında tanımlanmış olsun eğer c.c dosyası a ve b'yi çağırırsa ODR ihlal edilmiş olur ve tanımsız bir durum yaratılır. Fakat inline ve constexpr fonksiyonlar buna dahil değildir.
 Eğer bir fonksiyon birkaç dosyada inline olarak tanımlanmışsa derleyici token by token, atomik seviyede uyumluluğuna bakar. Eğer fonksiyonlar token by token aynı değilse tanımsız bir davranıştır.
 
 
 constexpr int sum(int x, int y)
  {
     return x + y;
  }
  
 
 inline int sum_square(int x, int y)
  {
     return x*x + y*y;
  }
 
 
 Başlık dosyasının içerisinde normalde kod olmaz fakat bu durum c++'da inline fonksiyonlar gibi bazı özel durumlarda geçerlidir.
    
 
 ->i:
 Class'ların üye fonksiyonları birer inline fonksiyon olursa;
    1-) Bildirim ve tanımlarının önüne inline eklenerek header file'da tanımlanabilir. En az birinde(bildiri veya tanım) inline ön eki olmalı.
    2-) Doğrudan class içerisinde inline fonksiyon tanımlanabilir. Class içerisinde tanımlanan fonksiyonlar zaten impicit olarak inline fonksiyon olmaktadır, inline ön eki koyulmasa da olur.

 //MyClass.h

 class MyClass
 {
     int x;
 public:
     
     int sum(int x, int y)   // Inline
     {
         return x+y;
     }
     
     inline int divide(int x, int y);   // Inline
 };

 inline int MyClass::divide(int x, int y)   // Inline
 {
     return x/y;
 }


 
 
*/


// Include
#include <iostream>
// Yapılar


//
#include "deneme.h"
#include "deneme_2.h"


//MyClass.h

class MyClass
{
    int x;
public:
    
    int sum(int x, int y)   // Inline
    {
        return x+y;
    }
    
    inline int divide(int x, int y);   // Inline
};

inline int MyClass::divide(int x, int y)   // Inline
{
    return x/y;
}


//
int main()
{
    std::cout << "sum = " << sum(1,2) << '\n';
    
}
