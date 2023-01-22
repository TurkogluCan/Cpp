/* DEFAULT ARGUMENTS

 - Varsayılan argüman öyle bir mekanizmadır ki fonksiyon bildiriminde yapılan bir belirtmeyle, fonksiyon çağrısı sırasında argüman gönderilmeyen parametre değişkenlerine, fonksiyon bildirimi veya tanımlaması sırasında, daha önceden, geçilmiş olan varsayılan argüman değerleriyle fonksiyona çağrıda bulunulması.
 - Yani, ben bu parametreye argüman göndermiyorum, sevgili derleyici bildirimde belirtilen argümanla bu fonksiyonu çağır
 - Fonksiyon bildirilerinde fonksiyon parametresine geçilecek olan "varsayılan argümanlar" sabit, değişken, fonksiyon geribildirimleri gibi ifadeler olabilir.
 - Varsayılan argümanlar istenilen parametreden verilmeye başlanılabilir fakat varsayılan argüman verilen parametrenin sağındaki bütün parametrelere de varsayılan argüman geçilmelidir. Solundaki parametrelere verilme zorunluluğu yoktur.
 - Eğer varsayılan argümanlar fonksiyonun bildiriminde geçilmişse, fonksiyon tanımında tekrardan yazılması syntax error'a sebep olur. Bunun tersi de geçerlidir. Yani varsayılan argümanlar ya bildirimde ya da tanımda geçilebilir.
*/


// Include
#include <iostream>



// Func


// 1
int func ( int x, int y = 10);

// 2
int func_2 ( int x = 5, int y = 10 );

// 3 - HATA
int func_3 ( int x = 10, int y );

// 4
int foo();
int func_4 ( int x, int y = foo());

// 5
int ab;
int func_5 ( int x, int y = ab);

// 6
int g = 10;
int func_5 ( int &r = g);


// 8
int func_8 ( int d = 100, int m = 200, int y = 300);


// 7 - HATA, redefiniton of default argument
int func_7 ( int d = 10, int m = 1, int y = -1);

int func_7 ( int d = 10, int m = 1, int y = -1)
{
    
}

// 9
int func_9 ( int , int , int );

int func_9 ( int d = 10, int m = 1, int y = -1)
{
    
}


// 10
int func_10 ( int , int = 3, int = 45);

int func_10 ( int d , int m , int y )
{
    
}




//
int main()
{
    
    func_8();           // d = 100, m = 200, y = 300
    func_8(1);          // d = 1,   m = 200, y = 300
    func_8(1,2);        // d = 1,   m = 2  , y = 300
    func_8(1,2,3);      // d = 1,   m = 2  , y = 3
    
    
}
