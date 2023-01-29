/* FUNTION OVERLOADING(Fonksiyon Yüklemesi)
 
 
 Funtion Overloading Giriş:
 -------------------------
 Funtion overloading tanımına girmdeden önce şöyle bir örnek verelim.
 
 Aritmektik işlem operatörü olan '+' işaretinin kullanımı sırasında;
    Eğer 'int'   türünden değişkenlerle toplama yaparsam arka planda üreteceği makina kod farklı,
    Eğer 'float' türünden değişkenlerle toplama yaparsam arka planda üreteceği makina kod farklı olacaktır.
 Bu durumda derleyici bize tamsayılar için farklı gerçek sayılar için farklı bir operatör kullacaksın dese saçma ve gereksiz olurdur.
 İşte function overloading de buna benzemektedir.
 
 
 Funtion Overloading Genel Tanım:
 --------------------------------
 Aynı isme sahip ve aynı işlevi gerçekleştiren, farklı türden ve sayıdan parametre bildirilere sahip olan fonksiyonların tanımlanmasına ve kullanılmasına "Fonksiyon Overloading" denir. Funciton overolading'in ana kullanım amacı, ana işlevleri benzer olan fonksiyonların, parametre değişikliğine bağlı olarak farklılaşmasını engellemek, aynı isimle overload ederek farklı fonksiyonlar gibi kullanabilmektir. Overload edilen fonksiyonların içeriği birbirlerinden farklı olabilir ama fonksiyonun amacı aynı olmalı ki kullanıcı tarafından hatalı kullanım olmasın.
 
 ---------------------------

 Fonksiyon yüklemesinden söz edilebilmesi için iki koşulun sağlanması gerekir:

 1) Aynı isimli birden fazla fazla fonksiyon aynı kapsamda (scope) var olmalı.
 2) Fonksiyonların imzaları farklı olmalıdır.

 
 Function Signatur(Fonksiyon İmzası):
 ------------------------------------
 Bir fonksiyonun geri dönüş türü hariç, fonksiyonun ismi, parametre tipleri ve parametre sayısını belirten bilgiye "fonksiyonun imzası" denir.  Fonksiyonun geri dönüş değerinin türünü fonksiyonun imzasının bir parçası olarak görmeyeceğiz
    
 // Imzaları aynı
         int func(int)
         double func(int);

 
 Scope Kuralları:
 ----------------
 Bildirilen fonksiyonların scope'ları aynı olmalıdır. Eğer scopelar farklıysa Function Overloadingden BAHSEDİLEMEZ.
 
 //Scope Tipleri
    Namespace scope (file scope in C)
    Class     scope
    Block     scope
    Function prototype scope
    Function scope
    
 Token(Atom) ve Name Lookup(İsim Arama):
 ---------------------------------------
 Derleyici açısından kaynak kodun en küçük birimidir. Örneğin isimler. Derleyici kodu atomize eder. Kodun derlenme sırasında derleyicinin bir isimle karşılaşıp bu ismi araması durumuna "Name Lookup" denir.
 
 
 İsim arama kuralları:
 
 1)
 
 Derleyici ismi ararken önce kendi scope'una, sonra bütün kapsayan scope'lara, eğer yine bulamazsa bütün global olanlarda arar.
 Fakat C++'da "Scope Resolution, ::" operatörü kullanılarak derleyiciye, derleyici sen bu ismi global alanda ara diyerek farklı bir scope araması yaptırabiliriz.
 
 ------------
 int a;             // Global alan
 
 int main()
 {
    float a = 1.5f;
 
    cout << a;        // Burada derleyici öncelikle kendi scope'una bakacağı için gloabelde tanımlı olan a'nın hiçbir önemi yoktur.
 }
 
 ------------
 
 int main()
 {
    int printf = 10;
 
    printf("enescan");     // Burada derleyici öncelikle kendi scope'una bakacağı için standart kütüphanede
                           // tanımlı olan printf'in hiçbir hiçbir önemi yoktur.
 }

*/


// Include
#include <iostream>


// Yapılar


// Func


//
int main()
{
    
   
}
