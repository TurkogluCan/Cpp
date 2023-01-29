/* FUNTION OVERLOADING(Fonksiyon Yüklemesi.3
 
 Derleyicinin Çağırılacak Olan Fonksiyonu Belirlemesi(Function Overload Resolution)
 ----------------------------------------------------------------------------------
 Kullanıcı bir fonksiyon çağrısında bulunur. Derleyici, overload edilmiş olan fonksiyonlara bakar ve hangisi bu çağrı için uygundur diye karar verir fakat
 
 - Nomatch  : Çağırılan fonksiyon, overload edilen fonksiyonlardan hiçbirisine uymuyorsa "Nomatch" durumu vardır. Overloaddan dolayı değil, fonksiyon çağrısı fonksiyon bildirilerine uymadığı için hataya sebep olur.
 
 - Ambiguity(İkilem): Derleyicinin, fonksiyon çağrısına uygun olan overload edilen fonksiyona karar verememesi durumu.
 
    void func(long double);
    void func(char);
 
    int main()
    {
        func(2.3);     // - HATA, HANGİSİNİN SEÇİLECEĞİNE KARAR VERİLEMEZ, Ambiguity
    }
 
 Fonksiyon Overloading Karar Esasları
 ------------------------------------
 Overload edilen fonksiyonlara çağrı yapıldıktan sonra karasız kalma durumlarında aşağıdaki esaslara göre karar verilir.
 
 1) Variadic (En az şansı olan)
      foo(int, ...);
 
 2) User Defined Conversion (Orta seviye şans)
    
    struct A
    {
        A();
        A(int);
    }
 
    void func(A);
 
     int main()
     {
        func(10);
     }

 3) Standart Conversion (En şanslısı):
    ---------------------------------
    Dil tarafından syntax kurallarıyla belirli dönüşümlerdir. Veritipleri arasındaki dönüşümler, int->double, char-> int .....
    Buarada dilin kurallarınca LEGAL kabul edilen ifadeler geçerlidir. Örneğin double->int dönüştürdüm veri kaybı olmaz mı gibi şeyler karar aşaması için önemli değildir.
 
    Standart conversion içerisinde aşağıdaki 3 maddeye göre fonksiyona karar verilir. İki yada daha fazla uygun fonksiyon arasında argümandan parametre değişkenine yapılan dönüşümlerin kazanma sıraları "Exact math -> Promotion -> Conversion"dır.
 
 
    3.1) Exact Match (Tam uyum) : Argüman olan ifadenin türünün, parametre değişkeninin türüyle tamamen aynı olması.
         ------------------------
        void func(int);
        func(12);
    
    // const conversion, const olmasına rağmen exact match kabul edilir.
        void foo(const int *);
        int x = 10;
        func(&x);
 
 
    3.2) Promotion   (Yükseltme): Int altı türlerin int türüne olan ve float'dan double'a yapılan yükseltmelerdir, argüman -> parametre
         ------------------------
 
    int altı türler:
 
        bool
        
        char
        unsigned char
        signed char
        
        unsigned short
        signed short

 
    3.3) Conversion  (Dönüşüm)  :  Bu iki madde harici. Argümandan parametreye dönüşümü varsa. En basit olarak int->float
         ------------------------
 
    Çoklu Argüman Fonksiyon Kararı
    ------------------------------
    Çoklu parametreye sahip overload fonksiyonlarda karar verilirken;
    Argümanlardan en az biri için ilgili parametre değişkenine dönüşüm kalitesi diğerlerine göre daha iyi olacak, ancak diğer argümanları için de daha kötü olmayacak.
    L.193
 
 
    Funtion Delete
    ------------
    C++'da fonksiyonlar delete edilebilir. Bir fonksiyonun delete edilmesi, bu fonksiyon var ama çağırılsa hata olacak demektir.
    
    void func(int) = delete;
 
    // -, Function Delete, fonksiyon var ama delete edildiği için syntax hatası verir.
    {
     void foo(int) = delete;
     void foo(char) = delete;
     void foo(double);
     
     {
         foo(12);
     }
 
*/


// Include
#include <iostream>
// Yapılar



//
int main()
{

    // -, Ambiguity, conversion
    {
        int foo(long double);
        int foo(char);
        
        {
            foo(12.);
        }
    }
    
    // +, const int *
    {
        int foo(int *);
        int foo(const int*);
        
        {
            int x = 10;
            const int y = 20;
            
            foo(&x);  //1
            foo(&y);  //2
        }
    }
    
    // +, const int &
    {
        int foo(int &);
        int foo(const int&);
        
        {
            int x = 10;
            const int y = 20;
            
            foo(x);  //1
            foo(y);  //2
        }
    }
    
    // -, Ambiguity, Default argument
    {
        int foo(int, int = 10);
        int foo(int);
        
        {
            foo(12);
        }
    }
    
    // -, Ambiguity, referans ve değer
    {
        int foo(int &);
        int foo(int  );
        
        {
            int x = 10;
            
            foo(x);  //1
        }
    }
    
    // +, Exact match ve promotion
    {
        int foo(bool );
        int foo(int  );
        
        {
            foo(12);    // 2
            foo(12>4);  // 1
        }
    }
    
    // +, rvalue
    {
        int foo(int &);
        int foo(int &&);
        
        {
            int x = 10;
            
            foo(x);     //1
            foo(x+3);   //2
        }
    }
    
    // +, İstisnai bir durum. Her ikisi de conversion olmasına rağmen ambiguity olmaz.
    {
        int foo(bool  );
        int foo(void *);
        
        {
            int x = 10;
            
            foo(x);     //1
        }
    }
    
    
    // -+, Birden fazla elemanla karar verme
    {
        int foo(int,   double,       long  );
        int foo(char,  int,          long  );
        int foo(double,unsigned int, double);
        
        {
            foo(12, 12,   13L);    //-
            foo(12, 12.L, 34U);    //+
        }
    }
    
    // -, Function Delete, fonksiyon var ama delete edildiği için syntax hatası verir.
    {
        void foo(int) = delete;
        void foo(char) = delete;
        void foo(double);
        
        {
            foo(12);
        }
    }
   
}
