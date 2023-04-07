# Kök Değer Alt Düğümlerin Toplamı

Bu program, kullanıcının girdiği üç sayıdan oluşan bir ağacın, kök değerinin alt düğümlerin toplamı mı olduğunu kontrol eder.

Program, ağaç yapısını oluşturmak için dinamik bellek yönetimi için malloc() fonksiyonunu kullanır ve düğüm yapısı struct Dugum'u kullanır. Program, her bir düğümün değerini ve her düğümün sol ve sağ alt düğümlerinin adreslerini tutar.

Kullanıcı, programın çalışmasını başlatmadan önce, kök düğümün değerini ve her alt düğümün değerini girmesi gerekir.

Program, bir düğümün yaprak düğüm olup olmadığını kontrol eder ve kök düğümün alt düğümlerinin toplamının kök düğüm değerine eşit olup olmadığını kontrol eder. Eğer kök düğüm değeri alt düğümlerin toplamına eşitse, program bunu ekrana yazdırır. Aksi takdirde, program "Kök değer alt düğümlerin toplami değildir" mesajını yazdırır.

## Nasıl kullanılır
Bu kod bir binary tree yapısında kök düğümünün alt düğümlerinin toplamının kök düğümünün değerine eşit olup olmadığını kontrol eder. Program, kullanıcının kök düğümünün değeri, sol alt düğümün değeri ve sağ alt düğümün değeri gibi girdileri okuyarak bir binary tree oluşturur ve sonra alt düğümlerin toplamı kök düğümünün değerine eşit olup olmadığını kontrol eder.

Programı çalıştırdıktan sonra, kullanıcıya kök düğümünün değerini, sol alt düğümün değerini ve sağ alt düğümün değerini girmesi istenir.

Kullanıcı girdileri girer ve enter tuşuna basar.

Program, girilen girdilerle bir binary tree oluşturur ve alt düğümlerin toplamının kök düğümünün değerine eşit olup olmadığını kontrol eder.

Sonuç, "Kok deger alt dugumlerin toplamidir." veya "Kok deger alt dugumlerin toplami degildir." şeklinde ekrana yazdırılır.
## Nasıl Çalışır
Bu kod, bir ikili ağacın kök düğümünün değerinin sol ve sağ alt düğümlerin değerlerinin toplamına eşit olup olmadığını kontrol eder. Program, kullanıcı tarafından girilen üç sayıyı (kök değeri, sol alt düğüm değeri ve sağ alt düğüm değeri) alır ve bu değerlere göre bir ikili ağaç oluşturur.

Kök düğüm oluşturulduktan sonra, sol ve sağ alt düğümler aynı şekilde oluşturulur. Daha sonra, altDugumToplami adlı bir fonksiyon, kök düğümün alt düğümlerinin toplamının kök değerine eşit olup olmadığını kontrol eder. Bu işlem, özyinelemeli bir işlev kullanılarak yapılır, yani alt düğümlerin alt düğümleri de kontrol edilir.

Eğer kök düğüm yoksa veya kök düğüm yaprak düğümse (sol ve sağ alt düğümler boş ise), kök değer alt düğümlerin toplamı olarak kabul edilir. Aksi takdirde, sol ve sağ alt düğümlerin değerleri toplanır ve bu değerlerin kök düğümünün değerine eşit olup olmadığı kontrol edilir. Sol ve sağ alt düğümlerin de alt düğümleri aynı şekilde kontrol edilir.

Son olarak, program, altDugumToplami fonksiyonunun dönüş değerine göre, kök değerin alt düğümlerinin toplamı olup olmadığını kullanıcıya bildirir.

## Örnek Çalışma

Örnek 1:

Kok degerini girin: 10

Sol alt dugum degerini girin: 3

Sag alt dugum degerini girin: 7

Kok deger alt dugumlerin toplamidir.

Bu senaryoda, kullanıcı 10, 3 ve 7 değerlerini girerek bir binary tree oluşturur. Alt düğümlerin toplamı 3 + 7 = 10 olduğu için sonuç "Kok deger alt dugumlerin toplamidir." şeklinde ekrana yazdırılır.

Örnek 2:

Kok degerini girin: 5

Sol alt dugum degerini girin: 2

Sag alt dugum degerini girin: 9

Kok deger alt dugumlerin toplami degildir.

Bu senaryoda, kullanıcı 5, 2 ve 9 değerlerini girerek bir binary tree oluşturur. Alt düğümlerin toplamı 2 + 9 = 11 olduğu için sonuç "Kok deger alt dugumlerin toplami degildir." şeklinde ekrana yazdırılır.

***Not:*** Bu sadece bir örnek kullanım senaryosudur. Program, daha farklı kullanım senaryolarına da uygun olarak düzenlenebilir.
