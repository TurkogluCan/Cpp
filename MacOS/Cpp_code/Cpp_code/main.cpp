/* COTR Bildirim Çeşitleri
 
 
 Doesn't Exist
 -------------
 Programlayıcı ve derleyici tarafından yazılmamış, olmayan COTR durumu
 
 Aşağıdaki durumda programlayıcı parametreli COTR prototipini yazmış fakat bildirmemiştir. Bu durumda derleyici parametreli bir COTR bulunduğu için default COTR de yazmayacaktır.
 //
 class MyClass
 {
 public:
     MyClass(int);
 };
 
 
 ->i: Programlayıcının COTR bildirmediği durumlarda derleyici tarafından otomatik olarak COTR bildirilir. Bunlar;
 
    DERLEYICI TARAFINDAN
 --------------------------------
 Implicitly Declared Defaulted  |
 Implicitly Declared Deleted    |
 --------------------------------
 
 Implicitly Declared Defaulted:
 ------------------------------
 Derleyici, sınıfın özel üye fonksiyonunu(COTR) bizim için bildirir.
 
 
 Eğer aşağıdaki MyClass kullanıcı tarafından oluşturulmazsa derleyici tarafından aşağıdaki şekilde default olarak oluşturulur
 //
 class MyClass
 {
 public:
     MyClass() { }
 };

 
 
 Implicitly Declared Deleted:
 ----------------------------
 Derleyici, sınıfın özel üye fonksiyonunu(COTR) bizim için deleted olarak bildirir. Bu fonksiyona yapılan çağrı syntax hatasıdır.
 *** Örneğin sınıfın üye elemanlarında birisi cont olsun. Eğer const üye elemana sahip bir sınıf varsa COTR list initialize sırasında ilk değer atanması lazımdır. Eğer programlayıcı COTR yazmamışsa derleyici default COTR yazar fakat const ataması yapılmadığı için syntax hatası vereceğinden bunu delete eder.
 
 
 Eğer aşağıdaki MyClass kullanıcı tarafından oluşturulmazsa derleyici tarafından aşağıdaki şekilde default olarak oluşturulur ve yine derleyici tarafından delete edilir
 //
 class MyClass
 {
    const int cmx;
 public:
     MyClass() = delete;
 };


 Programlayıcı tarafından bildirilen COTR fonksiyonları aşağıdaki yöntemlerle bildirilebilir.

 PROGRAMLAYICI TARAFINDAN
-------------------------
User Declared            |
User Declared Defaulted  |
User Declared Deleted    |
User Declared Defined    |
-------------------------
 
 User Declared
 -------------
 Programlayıcı tarafından bildirilen COTR'lardır.
 //
 class MyClass
 {
 public:
     MyClass();
 };
 
 User Declared Defaultted
 -------------------------
 Programlayıcı tarafından bildirilen fakat derleyiciye yazdırılan COTR'lardır.
 //
 class MyClass
 {
 public:
     MyClass() = default;
 };
 
 User Declared Deleted
 -------------------------
 Programlayıcı tarafından bildirilen fakat yapılan çağrıların syntax hatası olduğu COTR'lardır.
 //
 class MyClass
 {
 public:
     MyClass() = delete;
 };
 
 
 
 -->i: Bir sınıftan türetilmiş pointer veya referans'lar için constructor çağrısında bulunulmaz çünkü nesne değillerdir, nesneyi gösterirler.
 
 MyClass  mx;            // CTOR çağırılır
 MyClass  &r{mx};        // CTOR çağırılmaz
 MyClass  *p = &mx;      // CTOR çağırılmaz
 
 
 
 */


// Include
#include <iostream>
// Yapılar


//
class MyClass
{
public:
    MyClass() = delete;
};

//
int main()
{

    
    
}
