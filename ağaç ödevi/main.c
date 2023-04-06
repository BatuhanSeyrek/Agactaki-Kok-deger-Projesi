#include <stdio.h>
#include <stdlib.h>

// Düðüm yapýsý
struct Dugum {
    int deger;          // Düðümün deðerini tanýmladýk
    struct Dugum* sol;  // Sol alt düðüm deðrini tanýmladýk ve oradaki '*' ifadesi iþaretçidir
    struct Dugum* sag;  // Sað alt düðüm deðerini tanýmladýk ve oradaki '*' ifadesi iþaretçidir
};


struct Dugum* dugumOlustur(int deger) {// Yeni bir düðüm oluþturur ve geri döndürür 
    struct Dugum* dugum = (struct Dugum*) malloc(sizeof(struct Dugum));//burdada malloc yasýný kullandýk
    dugum->deger = deger;//düðümdeki deðeri ,deðer deðiþkeni ile eþitledik
    dugum->sol = NULL;//düðümdeki solu ,sýfýr deðerine eþitledik
    dugum->sag = NULL;//düðümdeki saðý ,sýfýr deðerine eþitledik
    return dugum;//düðüm deðerinin dönmesini saðlar
}


int altDugumToplami(struct Dugum* kok) {// Kök deðer alt düðümlerin toplamý mý? ifadesini cevabýný bize verecek asýl yer burasý
    if (kok == NULL || (kok->sol == NULL && kok->sag == NULL)) {//kök sýfýra eþit ve kodeki 
        // Eðer kök düðüm yoksa veya kök düðüm yaprak düðümse,
        // kök deðer alt düðümlerin toplamýdýr.
        return 1;//bir deðeri döndürür
    } else {
        int toplam = 0;//toplam deðeri sýfýr deðerine eþitledik
        if (kok->sol != NULL) {//kökdeki sol deðeri sýfýra eþit deðilse bu durum gerçekleþir
            toplam += kok->sol->deger;  // Sol alt düðümün deðerini toplamý
        }
        if (kok->sag != NULL) {
            toplam += kok->sag->deger;  // Sað alt düðümün deðerini toplamý
        }
        // Kök düðümün deðeri alt düðümlerin toplamýna eþit mi?
        // Sol ve sað alt düðümlerin de alt düðümleri ayný þekilde kontrol edilir.
        return (kok->deger == toplam && altDugumToplami(kok->sol) && altDugumToplami(kok->sag));
    }
}

int main() {
    // kulanýcýnýn deðer giribileceði þekilde hazýrladým
    int kok_deger, sol_deger, sag_deger;
    printf("Kok degerini girin: ");//kullanýcýdan kök deðeri alýnýr 
    scanf("%d", &kok_deger);
    printf("Sol alt dugum degerini girin: ");//kullanýcýdan sol alt düðüm deðeri alýnýr 
    scanf("%d", &sol_deger);
    printf("Sag alt dugum degerini girin: ");//kullanýcýdan sað alt deðer düðüm deðeri alýnýr 
    scanf("%d", &sag_deger);

    struct Dugum* kok = dugumOlustur(kok_deger);//dugum*kok ,dugumoluþtur(kok_deger)'e eþitledik
    kok->sol = dugumOlustur(sol_deger);//kokdeki sol deðerine dugumoluþtur(sol_deger)'eþitledik
    kok->sag = dugumOlustur(sag_deger);//kokdeki sað deðerine dugumoluþtur(sað_deger)'eþitledik

    
    if (altDugumToplami(kok)) {// Kontrol et ve sonucu yazdýr
        printf("Kok deger alt dugumlerin toplamidir.\n");
    } else {
        printf("Kok deger alt dugumlerin toplami degildir.\n");
    }

    return 0;
}
