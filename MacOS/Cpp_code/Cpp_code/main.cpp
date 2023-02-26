/* const member func, mutable, default member initialize
 
 
 Const Member Function
 ---------------------
 ->i: Gizli parametrenin const olması istenen durumlarda, fonksiyonun sınıf içerisindeki ve tanımalama sırasındaki bildirimi sırasında bildirimin sonuna "const" anahtar sözcüğü koyulur. Eğer koyulmazsa default olarak const olmayan bir gizli parametreye sahip fonksyion yaratılır. Const koyulan fonksiyon üyelerini "get(...)", koyulmayanları ise birer "set(...)" fonksiyonlar olarak düşünebiliriz.
 
 //
 class Data {
 private:
     int mx;
     
 public:
     void getfunc(int x)const;
     void setfunc(int x);
 };



 void Data::setfunc(int x)
 {
     mx = x;
 }

 void Data::getfunc(int x)const
 {
     mx = x;    // HATA
 }
 
 
 // 2
 class Data {
 private:
     int mx;
     
 public:
     Data *foo();
     Data &func();
 };

 Data* Data::foo()
 {
     //...
     return this;
 }

 Data& Data::func()
 {
     //...
     return *this;
 }
 
 
 mutable
 -------
 ->i: Sınıfın bir veri elemanını mutable anahtar sözüğü ile tanımlamak şu anlama gelir, kodu okuyan sevgili kişi, bu veri elemanının değişmesi, sınıf türünden yaratılan bir nesnenin problem domainindeki anlamını değiştirmez. Yani bu değişse de değişmese de seni etkilemez. Örneğin sınıf içerisinde kullanılan ve dışarıyı etkilemeyen sayaçlar
 ->i: Mutable data memberlar const functionlar içeriside değiştirilebilir.
 
 //
 class Data {
 private:
     mutable int msayac;
     
 public:
     void getfunc(int x)const;
     void setfunc(int x);
 };

 void Data::getfunc(int x)const
 {
     msayac++;    // Dogru
 }

 
 Default member initializer
 ---------------------------
 ->i: Modern c++ ile birlikte gelen bir kullanımdır. Bir sınıf nesnesinin hayata getirilmesi durumunda onun veri elemanına ilk değer verilebilir.
 
 //
 class Data {
 private:
     int mx = 10;;
     
 public:
     Data &f1();
     Data &f2();
     Data &f3();
     
     int gmx = 20;
 };
 

*/


// Include
#include <iostream>
// Yapılar


//
class Data {
private:
    int mx = 10;;
    
public:
    Data &f1();
    Data &f2();
    Data &f3();
    
    int gmx = 20;
};




Data& Data::f1()
{
    //...
    return *this;
}


//
int main()
{
    Data mydata;

    // Bu kullanım geçerli ve doğrudur. Fonksiyon dönüşün nesnenin referansı olduğu için o referansla
    // tekrar farklı bir fonksiyon çağrısı yapmak veya data membera ulaşmak da mümkündür.
    mydata.f1().f2().f3();
    mydata.f1().f2().f3().gmx = 10;
    
    // mydata.f1() dönüşü -> mydata, bu yüzden dönüş üzerinden başka bir membera ulaşmak mümkündür.
    
    //
    {

    }

}
