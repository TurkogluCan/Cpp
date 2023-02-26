/* Classes Member Functions - 2
 
 
 Member Function Definition
 --------------------------
 ->i: Member functionlar tanımlanırken bildirimleri sınıfın ismi ve çözünürlük operatörü kullanılarak yapılır. Eğer sınıf ismi kullanılmadan yapılırsa bu sınıfa ait bir fonksiyon olmaz.

 class Data {
 private:
     int mx;
     
 public:
     void func(int x);
 };
 
 // Sınıfa ait degil
 void func(<#int x#>)
 {
    // Normal bir fonksiyon
 }
 
 // Sınıfa ait
 void Data::func(<#int x#>)
 {
     mx = 10;
 }

 
 this
 ----
 ->i: this anahtar sözcüğü c++'da sınıf türünden yaratılmış olan bir nesnenin adresini ifade etmektedir. O yüzden ismi "this pointer"dır. Member functionlar içerisinden ulaşılacak olan data memberlar nasıl gizli parametreyle sadece member ismi kullanılarak ulaşılabiliyorsa(mx), this pointer kullanılarak da ulaşılabilir(this->mx)

 class Data {
 private:
     int mx;
     
 public:
     void func(int x);
 };

 // Asagida yapilan atamalar ozdestir
 void Data::func(int x)
 {
     mx = x;
     this->mx = x;
     Data::mx = x;
 }

 
 
 
*/


// Include
#include <iostream>
// Yapılar


//
class Data {
private:
    int mx;
    
public:
    void func(int x);
};



void Data::func(int x)
{
    mx = 9;
    this->mx = 10;
    Data::mx = 11;
}

//
int main()
{
    Data mydata;
    
    mydata.func(10);
    
    //
    {

    }

}
