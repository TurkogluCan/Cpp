/* Type Casting (Tur Donusumu)
    
 C'de kullanılmakta olan casting operatörleri C++'da geçerli olmakla birlikte önerilmez. C++'da tür dönüşümleri için özelleşmiş tür dönüşüm operatörleri bulunmaktadır. Bunlar;
 
 1-) Static Cast ( static_cast<T>(ifade), Örn. T = int )
 
 - Static tür dönüşümleri için kullanılmaktadır. Mesela aritmetik türler arasındaki dönüşümler için kullanılır. int->double, double->int, long->char vb. kullanımları static tür dönüşümüne örnektir. Enum typelar ile aritmetik türler arasında olan veya enum typeların kendileri arasındaki dönüşümleri de statik tür dönüşümlerine birer örnektir.
 - İstisna olarak (void *)->(T *) olan dönüşümler de statik tür dönüşümüne örnektir.
 
 
 2-) Const Cast ( const_cast<T>(ifade), T = char, char * )
 
 - cv qualified(bir türün const veya volatile anahtar sözcüğü ile nitelenmiş hali) olarak nitelenmiş ifadelerin constluğunu kaldırmak için kullanılır.
 - const_cast işlemcisi, işlem yapılan nesnenin sabit ve/veya volatile özelliğini kaldırır veya yeniden kazandırır. Aslında, bir nesnenin const özelliğini kaldırma, o nesnenin bellekteki değerini değiştirmeden, sadece const olmayan bir değer kabul edilen bir ifade veya fonksiyon parametresinde kullanılmasını sağlar.
 
 
 3-)Reinterpret Cast ( reinterpret_cast <T> (ifade) )
 
 - reinterpret_cast işlemcisi bir veri türünü tamamen farklı bir veri türüne dönüştürür.
 
 
 4-) Dynamic Cast
 
 - Inheritance kısmında değinilecektir.

*/


// Include
#include <iostream>
// Yapılar



//
int main()
{

    
    
}
