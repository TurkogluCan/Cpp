/* Class Initializer
 
 
 COTR İçi Initialize
 -------------------
 Class içerisinde tanımlanan üye elemanları, COTR içerisinde initialize edilebilir, ilk değer atanabilir. Eğer üye elemanları const veya referans ise initialize etmek zorunlu olacak fakat bu şekilde initialize etmek mümkün olayacaktır. Bu veri elemanlara COTR initialize list ile ilk değer verilmelidir.
 Tanımın örnekleri aşağıda gösterilmektedir. Static elemanlar COTR içerisinde initialize edilemez.
 

 //
 class Data
 {
     int mx;
     int my;
 public:
     Data();
     ~Data();
 };

 // 1 - Gecerli
 Data::Data()
 {
    mx = 15;
    my = 23;
 }
 
 //
 class Data
 {
     const int cmx;
           int &mr;
 public:
     Data(int &r);
     ~Data();
 };
 
 
 // 2 - Gecersiz X
 Data::Data(int &r)
 {
    cmx = 15;    // HATALI X
    mr  = r;     // HATALI X
 }
 

 COTR Initializer List
 ---------------------
 Class içerisinde tanımlanan üye elemanları, COTR ile birlikte initialize edilebilir, ilk değer atanabilir. COTR içi ilk değer atamada hatalı olan const ve referans initializeları burada geçerlidir ve ilk değer verilmesi zorunludur. Tanımın örnekleri aşağıda gösterilmektedir. Static elemanlar bu şekilde initialize edilemez.
 
 //
 class Data
 {
     int mx;
     int my;
 public:
     Data();
     ~Data();
 };


 // Yontem-1
 Data::Data()  :  mx(0) , my(10) { }
 
 // Yontem-2
 Data::Data()  :  mx{0} , my{10} { }
 
 // Yontem-3
 // Default olarak 0 ve null atanır
 Data::Data()  :  mx{}  , my{}   { }

 
 
 COTR içerisinde tanımlanan üye elemanlarının hayata gelme sıraları bildirimdeki sıralarıyla aynıdır. Yani önce mx daha sonra ise my hayata gelecektir. Hayata gelme durumları COTR initialize sırasında önem kazanabilir. Eğer mx ve my initializeları birbirine bağımlı yapılırsa yaratılma sıraları göz önünde bulundurulmalıdır.
 
 // my, mx'e bağlı. my'ye 10 atanır.
 Data::Data()  :  mx{10}  , my{mx}   { }

 // mx, my'ye bağlı. mx'e çöp değer atanır.
 Data::Data()  :  mx{my}  , my{10}   { }


 
 //+++ CONST ve REFERANS INIT
 class Data
 {
       int mx;
       int my;
 const int cmx;
       int &mr;
 
 public:
     Data();
     ~Data();
 };

 // Constructure
 Data::Data(int &a) : mr(a), cmx(111) { }

 
 
 COTR Argümanlarının Atanması
 ----------------------------
 Argüana sahip olan COTR fonksiyonuna, nesne bildirimi yapılırken aşağıdaki yöntemlerden birisiyle atanmalıdır.
 
 
 //
 class Data
 {
     int mx, my;
 public:
     Data(int);
 };

 //
 int main()
 {
     // Direct initialization
     Data mydatax(11);
     // Copy initialization, bazı kullanım şartları bulunmaktadır
     Data mydatay = 11;
     // Direct list initialization
     Data mydataz{11};
 }

 
 
 
 */


// Include
#include <iostream>
// Yapılar


//
class Data
{
    int mx, my;
public:
    Data(int);
};

//
int main()
{
    // Direct initialization
    Data mydatax(11);
    // Copy initialization, bazı kullanım şartları bulunmaktadır
    Data mydatay = 11;
    // Direct list initialization
    Data mydataz{11};
}
