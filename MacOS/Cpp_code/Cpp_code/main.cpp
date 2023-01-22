/* ENUM
 
 - C'de enum türü arka planda derleyicinin kullandığı tür(underline type) integer olmak zorundadır.
 - C++'da enum türünün arkasında kullanığı veri tipinin garantisi yoktu. Numaratör değelerine bakılarak derleyici uygun veritipini seçebilirdi. Fakat Modern C++ ile birlikte gelen önemli eklentilerden birisi olan enum veri tipini(underline type ,baz türünü) kendimizin belirleyebilmemizdir.
 
 - C++'da normal enumlarda ve enum class'larda underline type belirlenebilmekte. Böylece numaratörlerin sahip olacağı veri tipi karmaşasının önüne geçilebilmektedir.
 
 - Diğer türlerden enum türüne dönüşüm yoktur fakat enum türünden diğer türlere dönüşüm bulunmaktadır.
 
 - ENUM türleri unscope olduğu için isimleri aynı iki farklı enum türünün içerisindeki numaratörler hata verecektir. Bu durumun önüne geçilmesi için C++'da enum class mevcuttur.

 - Enum class'lar aslında kapsamlandırılmış enumlardır. Yani içerisindeki numaratörlere unscope şekilde erişim imkanım olmuyor. Enum class ismi üzerinden ulaşabilmekteyim.
 - Enum class'lara da underline type geçilebilmektedir. Eğer geçilmezse default olarak int atanmaktadır.
 
 
*/


// Include
#include <iostream>


// Yapılar

/* 1 - Unscope ornek
 
// color.h
enum Color
{
    RED,
    YELLOW,
    GREEN
};

// traffic.h
enum TraficColor
{
    RED,
    YELLOW,
    GREEN
};
*/


enum Color
{
    RED,
    YELLOW,
    GREEN
};


// Underline type ENUM
enum Color_underline : int
{
    int_RED,
    int_YELLOW,
    int_GREEN
};


// ENUM CLASS
enum class Color_EC : unsigned int
{
    RED,
    YELLOW,
    GREEN
};

enum class Traffic_EC : unsigned int
{
    RED,
    YELLOW,
    GREEN
};



// Func


//
int main()
{
    
    // Tur donusumu
    {
        Color myu_color = RED;
        int x = myu_color;
    }
    
    
    // SCOPE
    {
        Color_EC color = Color_EC::RED;
    }

}
