/* Constructor - Destructor
 
 
 Constructor: Nesneyi hayata getiren fonksiyon. Construct: Kurmak
 Destructor : Nesnenin hayatını sonlandıran fonksiyon. Destroy: Yok etmek
 
 - Bütün nesnelerin hayatı constructor ile başlamak ve destructor ile sonlanmak zorundadır. C'deki handle sistemine benzemektedir.
 - Geri dönüşleri yoktur.
 
 - Fonksiyonun ismi yapının(class) ismiyle aynı olmak zorunda.
 - const üye fonksiyon olamaz.
 - inline olarak da tanımlanabilir.
 
 - Destructure başında tilda ~ ön eki bulunur.
 - Bir sınıfın birden fazla ctor olabilir fakat dtor'u olamaz.
 - Destructure geri dönüş değeri ve parametresi bulunamaz.
 - Destructure özel üye fonksiyonudur. Yani uygun şartlar sağlanırsa kullanıcı yazmazsa da derleyici bunu yazacaktır.

 *->i: Nesne yaratıldığında Consructure çağırılır, nesnenin yaratıldığı scope sonlandığında ise Destructure çağırılır.
 *->i: Global sınıf nesneleri, normal olarak main fonksiyonundan önce hayata gelir. Program sonlandığında destructure çağırılır ve ömrü sonlandırılır.
 *->i: Bir fonksiyon içerisinde tanımlanan Static yerel nesneler sadece ilk çağırıldığında hayata gelir ve ctor'ları çağırılır. Diğer fonksiyon çağrılarında tekrar hayata gelmez. Program sonlandığında destructure çağırılır ve ömrü sonlandırılır.
 
 
 
 Special Member Functions
 ------------------------
 C++'da sınıfın bazı fonksiyonları özel üye fonksiyonlardır. Bu özel üye fonksiyonlar, belirli koşullar sağladığında derleyici tarafından yazılabilmektedir. Bu özel üye fonksiyonlar;

     1-) Default ctor
     2-) Destructure
     3-) Copy ctor
     4-) Move ctor
     5-) Copy assignment
     6-) Move assignment
 
 
 
 Default COTR
 ------------
    Bir sınıfın parametre değişkeni olmayan ya da tüm parametreleri varsayılan argüman olan, yani parametre gönderilmeden çağırılabilen constructure'a default cotr denir.
    Special member function olan default ctor, eğer kullanıcı tarafından class içerisine bir cotr yazılmaması durumunda derleyici tarafından default cotr yazılır. 
*/


// Include
#include <iostream>
// Yapılar


//
class Data
{
public:
    Data();
    ~Data();
};


// Constructure
Data::Data()
{
    std::cout << "Data default ctor  this = " << this << "\n";
}

// Destructure
Data::~Data()
{
    std::cout << "Data Desturcture  this = " << this << "\n";
}




//
int main()
{

    std::cout << "main basladi" << "\n";

    {
        Data mydata;
        std::cout << "&mydata = " << &mydata << "\n";
    }
    
    std::cout << "main devam ediyor" << "\n";
        
    
}
