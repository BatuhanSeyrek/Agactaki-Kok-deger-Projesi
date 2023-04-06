#include <stdio.h>
#include <stdlib.h>

// Düðüm yapýsý
struct Dugum {
    int deger;          // Dugumun degerini tanimladik
    struct Dugum* sol;  // Sol alt dugum degrini tanimladik ve oradaki '*' ifadesi isaretcidir
    struct Dugum* sag;  // Sag alt dugum degerini tanimladik ve oradaki '*' ifadesi isaretcidir
};


struct Dugum* dugumOlustur(int deger) {// Yeni bir dugum olusturur ve geri dondurur 
    struct Dugum* dugum = (struct Dugum*) malloc(sizeof(struct Dugum));//burdada malloc yasini kullandik
    dugum->deger = deger;//dugumdeki degeri ,deger degiskeni ile esitledik
    dugum->sol = NULL;//dugumdeki solu ,sýfýr degerine esitledik
    dugum->sag = NULL;//dugumdeki sagý ,sýfýr degerine esitledik
    return dugum;//dugum degerinin donmesini saglar
}


int altDugumToplami(struct Dugum* kok) {// Kok deger alt dugumlerin toplami mi? ifadesini cevabini bize verecek asil yer burasi
    if (kok == NULL || (kok->sol == NULL && kok->sag == NULL)) {//kok sifira esit ve kodeki 
        // Eger kok dugum yoksa veya kok dugum yaprak dugumse,
        // kok deger alt dugumlerin toplamidir.
        return 1;//bir degeri dondurur
    } else {
        int toplam = 0;//toplam degeri sifir degerine esitledik
        if (kok->sol != NULL) {//kokdeki sol degeri sifira esit degilse bu durum gerceklesir
            toplam += kok->sol->deger;  // Sol alt dugumun degerini toplami
        }
        if (kok->sag != NULL) {
            toplam += kok->sag->deger;  // Sag alt dugumun degerini toplami
        }
        // Kok dugumun degeri alt dugumlerin toplamina esit mi?
        // Sol ve sag alt dugumlerin de alt dugumleri ayni sekilde kontrol edilir.
        return (kok->deger == toplam && altDugumToplami(kok->sol) && altDugumToplami(kok->sag));
    }
}

int main() {
    // kulanicinin deger giribilecegi sekilde hazirladim
    int kok_deger, sol_deger, sag_deger;
    printf("Kok degerini girin: ");//kullanicidan kok degeri alinir 
    scanf("%d", &kok_deger);
    printf("Sol alt dugum degerini girin: ");//kullanicidan sol alt dugum degeri alinir 
    scanf("%d", &sol_deger);
    printf("Sag alt dugum degerini girin: ");//kullanicidan sað alt deger dugum degeri alinir 
    scanf("%d", &sag_deger);

    struct Dugum* kok = dugumOlustur(kok_deger);//dugum*kok ,dugum olustur(kok_deger)'e esitledik
    kok->sol = dugumOlustur(sol_deger);//kokdeki sol deðerine dugum olustur(sol_deger)'esitledik
    kok->sag = dugumOlustur(sag_deger);//kokdeki sag degerine dugum olustur(sag_deger)'esitledik

    
    if (altDugumToplami(kok)) {// Kontrol et ve sonucu yazdir
        printf("Kok deger alt dugumlerin toplamidir.\n");
    } else {
        printf("Kok deger alt dugumlerin toplami degildir.\n");
    }

    return 0;
}
