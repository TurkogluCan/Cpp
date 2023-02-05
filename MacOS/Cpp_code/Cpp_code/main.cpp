/* Classes
    
 Class Member Erişim Alanları
 ----------------------------
 C++'da isim arama(name lookup) tamamlandıktan sonra access kontrolü yapılmaktadır. Bu access kontrolünde ise sınıfın üyesi olan ismin aşağıda belirtilen yetkileri  kontrol edilmektedir.
 
 class Data
 {
    public: Sınıfın public bölümü herkese açık bölümüdür. Yani sınıfın bu alanındaki isimleri herkes kullanabilir.
 
    private: Sadece sınıfın kendi içerisinde kullanılabilen, client kodlar tarafından kullanılamayan isimlerdir.
 
    protected: Kalıtım konusuyla ilgilidir, daha sonra değinilecektir.
 };

 
 - Classlar tanımlanırken kendi içerisinde "public", "private" ve "protected" anahtar sözcükleri kullanılarak ilgili alanlara ayrılabilir.
 -- Class'ın kendi içerisindeki alan default olarak "private" alandır. Yani class içerisinde hiçbir alan anahtar sözcüğü kullanılmazsa, içerisindeki üyeler private alanlı olacaktır.
 -- Struct'ın kendi içerisindeki alan default olarak "public" alandır. Yani struct içerisinde hiçbir alan anahtar sözcüğü kullanılmazsa, içerisindeki üyeler public alanlı olacaktır.
 
 
 class Data
 {
            // PRIVATE ALAN
    public:
            // PUBLIC ALAN
    private:
            // PRIVATE ALAN
    public:
            // PUBLIC ALAN
    protected:
            // PROTECTED ALAN
 }
 
 MEMBER
 ------
 Classın "member function" ve "Data member"ları static ve non-static olarak 2'ye ayrılmaktadır.
 
 1) Eğer sınıfın üyesinin bildiriminde static anahtar sözcüğü varsa bu member static ömürlüdür ve ilgili sınıf için tektir. Bu sınıftan ne kadar nesne yaratılırsa yaratılsın bütün nesneler aynı membera erişir, her nesne için yeniden yaratılmaz.
 2) Eğer sınıfın üyesinin bildiriminde anahtar sözcüğü yoksa bu member static ömürlü değildir ve ilgili sınıftan yaratılacak olan nesneler için yeniden oluşturulur. Bütün nesneler için farklıdır.
 
 
*/


// Include
#include <iostream>
// Yapılar


class Data
{
    int mx;             // Data member
    void func(int);     // Member function
    typedef int Word;   // Type member(member type, nested type)
};


//
int main()
{

}
