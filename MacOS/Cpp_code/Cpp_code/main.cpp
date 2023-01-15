
/* CONSTEXPR
 *************************************
 - Sabit ifadeler, derleyicinin koda bakarak doğrudan bir sabit elde ettiği ifadelere denir. Yani
   ifadenin değeri runtime değil compiler time'da bellidir.
 
 - *** CONSTEXPR fonksiyon; girdileri, içerisinde yapılan işlemler ve dönüşü sabit olan fonksiyonlara denir. Bu tip fonksiyonların
   içeriği sabit olduğu için fonksiyonun geri dönüş değeri de diğer sabitler gibi runtime'da değil de compiler time'da elde edilir.
 - *** constexpr fonksiyonların çıktıları compiler time'da elde edildiği için bu fonksiyonun içerisine yazılan kodlar gizlenemez. Eğer
   lib yapılmak istenirse veya fonksiyon başka dosyalardan çağırılacaksa başlık dosyasına yazılmalıdır ki derleyici compiler time'da sonucu üretebilsin.
   *** Bu yüzden CONSTEXPR FONKSİYONLARIN İÇERİĞİ KESİNLİKLE GİZLENEMEZ.
 - constexpr fonksiyonlar inline fonksiyonlardır.
 
 - constexpr belirteci ile yapılan tanımlamalar sabit olarak kabul edilir.
 - constexpr ile tanımlanan değişkenlerin kullanıldığı ifadeler de birer sabit ifadeleridir.
 
 **************************************/

// Include
#include <iostream>


// Func
constexpr int sum_square(int x, int y)
{
    return x*x + y*y;
}


//
int main()
{
    // Sabit ifadeler, dizi tanımlaması sırasında index constexpr ifadeler ile yapılmıştır. Const anahtar sözcüğü ile de geçerlidir.
    // Bu ifade C'de geçersizdir.
    {
        constexpr int x = 10;
        constexpr int y = 20;
        
        int a[x+y]{};   // Dogru
    }
    
    //** Const anahtar sözcüğü kullanarak sabit olmayan ifadelerle yapılan tanımlamanın sonucu da const değildir. Fakat hata da değildir.
    {
        int x = 10;
        int y = 20;
        const int b = x+y;
        int a[b]{};             // HATA
    }
    
    //** Constexpr anahtar sözcüğü kullanarak sabit olmayan ifadelerle yapılan tanımlama GEÇERSİZDİR.
    {
        int x = 10;
        int y = 20;
        constexpr int b = x+y;        // HATA
    }
    
    // Constexpr örnek ifade
    {
        const int x = 10;
        const int y = 20;
        constexpr int b = x*x + y*y;        // GEÇERLİ
    }
    
    // Constexpr örnek ifade
    {
        constexpr int x = 10;
        constexpr int y = 20;
        constexpr int b = x*x + y*y;        // GEÇERLİ
    }
    
    //** CONST vs CONSTEXPR
    //   constexpr anahtar sözcüğü kullanılarak yapılan ilk değer atamasında kullanılan fonksiyon mutlaka "constexpr fonksiyon" olmalıdır.
    //   Bu zorunluluk const için yoktur.
    {
        int foo();
        
        const int x = foo();          // GEÇERLİ

        constexpr int y = foo();      // HATA
    }
    
    //** CONSTEXPR fonksiyon, girdileri, içerisinde yapılan işlemler ve dönüşü sabit olan fonksiyonlara denir. Bu tip fonksiyonların
    // içeriği sabit olduğu için fonksiyonun geri dönüş değeri de diğer sabitler gibi runtime'da değil de compiler time'da elde edilir.
    // Eğer fonksiyon içerisinde sabitliği bozan ifadeler kullanılırsa hata verir ve geçersizdir.
    {
        const int a = 2;
        const int b = 3;

        constexpr int y = sum_square(a+5, b*2);   // GECERLİ, Derleyici için sabit bir ifadedir.
        int arr[sum_square(a+5, b*2)]{};          // Sabit bir ifade olduğu için dizinin boyutu da yapılabilir
    }
    
    //** CONSTEXPR fonksiyon, HATALI
    {
        int a = 2;
        int b = 3;

        constexpr int y = sum_square(a,b);   // HATALI, fonksiyon parametreleri sabit olmalı
    }
    
}


