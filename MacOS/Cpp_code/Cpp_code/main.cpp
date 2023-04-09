/* Copy Constructor
 
 
 Copy Constructor
 -------------
 
Bir sınıf nesnesi eğer hayata aynı bir türden bir başka sınıf nesnesinden değer alarak gelecekse bu durumda sınıfın copy contructor denen özel üye fonksiyonu çağırılır. Her sınıfın mutlaka copy constructor'ı bulunur.
 
class MyClass
 {
 public:
     MyClass()
     {
         std::cout << "Default CTOR \n";
     };
     ~MyClass()
     {
         std::cout << "Destructor \n";
     };
 };
 
 //main
 MyClass mx;         // Default Constructor çağırılır
 MyClass my = mx;    // Default Constructor çağırılmaz, copy constructor çağırılır

 -->i: mx için default constructor çağırılır fakat my için default değil copy contstructor çağırılır. O yüzden consola sadece 1 defa default COTR yazdırılır. Ömürleri bittiğinde ise 2 defa Destructor yazdırılır.
 
 -->i: Aşağıdaki copy constructor atamaları özdeştir.
 
 //
 MyClass mx;
 MyClass my = mx;
 MyClass mz(mx);
 MyClass mt{mx};

 
 -->i: Fonksiyonların aynı sınıf türünden olan parametrelerine olan çağrılar da copy constructorları çağırır.
 
 void func(MyClass myclas)
 {
     
 }
 
 int main()
 {
     MyClass mx;         // Default Constructor çağırılır
     func(mx);           // Copy Constructor çağırılır
 }
 
 
 -->i: Fonksiyonların aynı sınıf türünden olan return dönüşleri için de geçici olarak yaratılan nesnelerin copy constructorları çağırılır.
 
 MyClass foo();
 
 
 ***
 --i: Eğer derleyici bizim için bir copy constructor yazarsa derleyicinin yazdığı COTR sınıfın;
 * non-static
 * public
 * inline üye fonksiyonu olacaktır.
 
 
 Derleyici tarafından yazılacak olan örnek copy ctor

 class MyClass
 {
 public:
     MyClass (const MyClass &r);
 };
 
 -->i: Eğer programlayıcının işini görüyorsa copy ctor yazma işi derleyiciye bırakılır.
 -->i: Aşağıdaki şekilde programlayıcı tarafından copy constructor yazılabilir. Aşağıdaki copy cotr, derleyicinin yazacağıyla aynıdır. Programlayıcı düzenleyebilir.
 
 //
 class MyClass
 {
 private:
     int a,b,c;
 public:
     MyClass (const MyClass &other) : a(other.a), b(other.b), c(other.c)
     {
         
     }
 
 
 -->i: Aynı türden sınıflara ait nesnelerin hayata getirilirken kopyalanması, Copy constructor delete edilerek syntax hatası haline getirilebilir.
 //
 class MyClass
 {
 public:
     MyClass();
     MyClass (const MyClass &) = delete;
 };

 int main()
 {
     MyClass mx;
     MyClass my=mx;  // HATA: Call to deleted constructor of "MyClass"
     
 }
 
 */


// Include
#include <iostream>
// Yapılar


//
class MyClass
{
public:
    MyClass();
    MyClass (const MyClass &) = delete;
};



//
int main()
{
    MyClass mx;
    MyClass my=mx;  // HATA: Call to deleted constructor of "MyClass"
    
}
