#include <stdio.h>
#include <stdlib.h>

// D���m yap�s�
struct Dugum {
    int deger;          // D���m�n de�erini tan�mlad�k
    struct Dugum* sol;  // Sol alt d���m de�rini tan�mlad�k ve oradaki '*' ifadesi i�aret�idir
    struct Dugum* sag;  // Sa� alt d���m de�erini tan�mlad�k ve oradaki '*' ifadesi i�aret�idir
};


struct Dugum* dugumOlustur(int deger) {// Yeni bir d���m olu�turur ve geri d�nd�r�r 
    struct Dugum* dugum = (struct Dugum*) malloc(sizeof(struct Dugum));//burdada malloc yas�n� kulland�k
    dugum->deger = deger;//d���mdeki de�eri ,de�er de�i�keni ile e�itledik
    dugum->sol = NULL;//d���mdeki solu ,s�f�r de�erine e�itledik
    dugum->sag = NULL;//d���mdeki sa�� ,s�f�r de�erine e�itledik
    return dugum;//d���m de�erinin d�nmesini sa�lar
}


int altDugumToplami(struct Dugum* kok) {// K�k de�er alt d���mlerin toplam� m�? ifadesini cevab�n� bize verecek as�l yer buras�
    if (kok == NULL || (kok->sol == NULL && kok->sag == NULL)) {//k�k s�f�ra e�it ve kodeki 
        // E�er k�k d���m yoksa veya k�k d���m yaprak d���mse,
        // k�k de�er alt d���mlerin toplam�d�r.
        return 1;//bir de�eri d�nd�r�r
    } else {
        int toplam = 0;//toplam de�eri s�f�r de�erine e�itledik
        if (kok->sol != NULL) {//k�kdeki sol de�eri s�f�ra e�it de�ilse bu durum ger�ekle�ir
            toplam += kok->sol->deger;  // Sol alt d���m�n de�erini toplam�
        }
        if (kok->sag != NULL) {
            toplam += kok->sag->deger;  // Sa� alt d���m�n de�erini toplam�
        }
        // K�k d���m�n de�eri alt d���mlerin toplam�na e�it mi?
        // Sol ve sa� alt d���mlerin de alt d���mleri ayn� �ekilde kontrol edilir.
        return (kok->deger == toplam && altDugumToplami(kok->sol) && altDugumToplami(kok->sag));
    }
}

int main() {
    // kulan�c�n�n de�er giribilece�i �ekilde haz�rlad�m
    int kok_deger, sol_deger, sag_deger;
    printf("Kok degerini girin: ");//kullan�c�dan k�k de�eri al�n�r 
    scanf("%d", &kok_deger);
    printf("Sol alt dugum degerini girin: ");//kullan�c�dan sol alt d���m de�eri al�n�r 
    scanf("%d", &sol_deger);
    printf("Sag alt dugum degerini girin: ");//kullan�c�dan sa� alt de�er d���m de�eri al�n�r 
    scanf("%d", &sag_deger);

    struct Dugum* kok = dugumOlustur(kok_deger);//dugum*kok ,dugumolu�tur(kok_deger)'e e�itledik
    kok->sol = dugumOlustur(sol_deger);//kokdeki sol de�erine dugumolu�tur(sol_deger)'e�itledik
    kok->sag = dugumOlustur(sag_deger);//kokdeki sa� de�erine dugumolu�tur(sa�_deger)'e�itledik

    
    if (altDugumToplami(kok)) {// Kontrol et ve sonucu yazd�r
        printf("Kok deger alt dugumlerin toplamidir.\n");
    } else {
        printf("Kok deger alt dugumlerin toplami degildir.\n");
    }

    return 0;
}
