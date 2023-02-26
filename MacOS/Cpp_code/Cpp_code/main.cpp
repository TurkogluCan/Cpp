/* Classes - 2
 
 Class Member Function:
 ->i: Sınıfların üye fonksiyonları sınıf scope'u içerisinde overload edilebilir. Public ve private alanda olması overloadinge engel değildir, önemli olan scope'tur. Public, private ve protected alanlar aynı scope alanı içerisindedir.
 
 // Function overloading
 class Data
 {
 private:
     void func();
 public:
     void func(int);
     void func(int,int);
 };
 
 
 ->i: Sınıfların üye fonksiyonlarının sınıf türünün sizeof'uyla bir ilgisi yoktur. Yani sınıf türünden yaratılan her nesne için fonksiyon tekrar yaratılmaz, sınıf nesnelerinin boyutunu arttırmaz.
 
 
 ->i: Sınıf içerisindeki non-static üye fonksiyonlarının ilk parametresi yaratılan, fonksiyona ulaşan, nesnenin adresini içerir. Bu parametre gizli bir parametredir ve kullanıcının yaratacağı fonksiyonun girdilerinden bağımsızdır. Non-static olduğu için fonksiyon çağrıldığında çağıran nesnein adresini içeriye almalı ki nesne üzerinde işlemlerini gerçekleştirebilsin. Member functionlar içerisinde çağırılan data member'lara atomic göstergeler olmadan ulaşılmasının sebebi de gizli parametredir. Gizli parametre olmasına rağmen data member'lara "this" anahtar kelimesi ile de ulaşılabilmektedir.
    Fakat static member function'lar sınıftan yaratılacak olan nesnelerden bağımsız ve tek olduğu için static ömürlü member functionlara sınıf ismi ve çözünürlük operatörüyle ulaşılabilmektedir çünkü gizli bir parametresi yoktur.
 
 // Function overloading
 class Data
 {
 private:
 public:
             void func(int);
     static  void staticfunc(int);
 };
 // Member function gizli parametre
 {
     Data::func(12);         // Gecersiz, non-static
     Data::staticfunc(12);   // Gecerli,  static
 }
 
*/


// Include
#include <iostream>
// Yapılar


// Function overloading
class Data
{
private:
public:
            void func(int);
    static  void staticfunc(int);
};



//
int main()
{
    // Member function gizli parametre
    {
        Data::func(12);         // Gecersiz, non-static
        Data::staticfunc(12);   // Gecerli,  static
    }

}
