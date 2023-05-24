#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci {
    char ad[50];
    char soyad[50];
    int numara;
};

void Ekle(struct Ogrenci *ogrenci) {
    printf("Ad: ");
    scanf("%s", ogrenci->ad);
    printf("Soyad: ");
    scanf("%s", ogrenci->soyad);
    printf("Numara: ");
    scanf("%d", &ogrenci->numara);
}

void Takas(struct Ogrenci *a, struct Ogrenci *b) {
    struct Ogrenci temp;
    memcpy(&temp, a, sizeof(struct Ogrenci));
    memcpy(a, b, sizeof(struct Ogrenci));
    memcpy(b, &temp, sizeof(struct Ogrenci));
}

int Bol(struct Ogrenci *ogrenciler, int sol, int sag) {
    struct Ogrenci pivot = ogrenciler[sag];
    int i = (sol - 1);

    for (int j = sol; j <= sag - 1; j++) {
        if (strcmp(ogrenciler[j].ad, pivot.ad) < 0) {
            i++;
            Takas(&ogrenciler[i], &ogrenciler[j]);
        }
    }
    Takas(&ogrenciler[i + 1], &ogrenciler[sag]);
    return (i + 1);
}

void QuickSort(struct Ogrenci *ogrenciler, int sol, int sag) {
    if (sol < sag) {
        int pivotIndex = Bol(ogrenciler, sol, sag);
        QuickSort(ogrenciler, sol, pivotIndex - 1);
        QuickSort(ogrenciler, pivotIndex + 1, sag);
    }
}

void Listele(struct Ogrenci *ogrenciler, int ogrenciSayisi) {
    printf("Ogrenci Listesi:\n");
    for (int i = 0; i < ogrenciSayisi; i++) {
        printf("Ad: %s\n", ogrenciler[i].ad);
        printf("Soyad: %s\n", ogrenciler[i].soyad);
        printf("Numara: %d\n", ogrenciler[i].numara);
        printf("------------------------\n");
    }
}

int main() {
    int ogrenciSayisi;
    printf("Ogrenci sayisini girin: ");
    scanf("%d", &ogrenciSayisi);

    struct Ogrenci *ogrenciler = (struct Ogrenci *)malloc(ogrenciSayisi * sizeof(struct Ogrenci));

Ekle(1, "Ali", "Yilmaz", "VeriYapilari", "Matematik", "Fizik", "Kimya");
    Ekle(2, "Ayse", "Kara", "Matematik", "Biyoloji", "VeriYapilari", "Kimya");
    Ekle(3, "Mehmet", "Demir", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(1, "Ali", "Yýlmaz", "VeriYapilari", "Matematik", "Fizik", "Kimya");
    Ekle(2, "Ayþe", "Kara", "Matematik", "Biyoloji", "VeriYapilari", "Kimya");
    Ekle(3, "Mehmet", "Demir", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(4, "Zeynep", "Yýldýz", "Matematik", "Fizik", "Biyoloji", "VeriYapilari");
    Ekle(5, "Ahmet", "Can", "Fizik", "Kimya", "Matematik", "VeriYapilari");
    Ekle(6, "Elif", "Þahin", "Kimya", "VeriYapilari", "Matematik", "Biyoloji");
    Ekle(7, "Merve", "Öztürk", "Matematik", "VeriYapilari", "Fizik", "Kimya");
    Ekle(8, "Cem", "Kaya", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(9, "Selin", "Aydýn", "Biyoloji", "Matematik", "VeriYapilari", "Kimya");
    Ekle(10, "Canan", "Çelik", "Fizik", "VeriYapilari", "Matematik", "Kimya");
    Ekle(11, "Kemal", "Yýlmaz", "Kimya", "Matematik", "Fizik", "VeriYapilari");
    Ekle(12, "Ece", "Demir", "Matematik", "VeriYapilari", "Kimya", "Fizik");
    Ekle(13, "Mert", "Yýldýz", "VeriYapilari", "Fizik", "Kimya", "Matematik");
    Ekle(14, "Sevgi", "Aksoy", "Fizik", "Matematik", "VeriYapilari", "Biyoloji");
    Ekle(15, "Murat", "Aydýn", "Matematik", "Kimya", "VeriYapilari", "Fizik");
    Ekle(16, "Ceren", "Kaya", "VeriYapilari", "Matematik", "Biyoloji", "Kimya");
    Ekle(17, "Emre", "Þahin", "Kimya", "Fizik", "VeriYapilari", "Matematik");
    Ekle(18, "Aylin", "Öztürk", "Biyoloji", "VeriYapilari", "Matematik", "Fizik");
    Ekle(19, "Tolga", "Can", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(1, "Ali", "Yýlmaz", "VeriYapilari", "Matematik", "Fizik", "Kimya");
    Ekle(2, "Ayþe", "Kara", "Matematik", "Biyoloji", "VeriYapilari", "Kimya");
    Ekle(3, "Mehmet", "Demir", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(4, "Zeynep", "Yýldýz", "Matematik", "Fizik", "Biyoloji", "VeriYapilari");
    Ekle(5, "Ahmet", "Can", "Fizik", "Kimya", "Matematik", "VeriYapilari");
    Ekle(6, "Elif", "Þahin", "Kimya", "VeriYapilari", "Matematik", "Biyoloji");
    Ekle(7, "Merve", "Öztürk", "Matematik", "VeriYapilari", "Fizik", "Kimya");
    Ekle(8, "Cem", "Kaya", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(9, "Selin", "Aydýn", "Biyoloji", "Matematik", "VeriYapilari", "Kimya");
    Ekle(10, "Canan", "Çelik", "Fizik", "VeriYapilari", "Matematik", "Kimya");
    Ekle(11, "Kemal", "Yýlmaz", "Kimya", "Matematik", "Fizik", "VeriYapilari");
    Ekle(12, "Ece", "Demir", "Matematik", "VeriYapilari", "Kimya", "Fizik");
    Ekle(13, "Mert", "Yýldýz", "VeriYapilari", "Fizik", "Kimya", "Matematik");
    Ekle(14, "Sevgi", "Aksoy", "Fizik", "Matematik", "VeriYapilari", "Biyoloji");
    Ekle(15, "Murat", "Aydýn", "Matematik", "Kimya", "VeriYapilari", "Fizik");
    Ekle(16, "Ceren", "Kaya", "VeriYapilari", "Matematik", "Biyoloji", "Kimya");
    Ekle(17, "Emre", "Þahin", "Kimya", "Fizik", "VeriYapilari", "Matematik");
    Ekle(18, "Aylin", "Öztürk", "Biyoloji", "VeriYapilari", "Matematik", "Fizik");
    Ekle(19, "Tolga", "Can", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(1, "Ali", "Yýlmaz", "VeriYapilari", "Matematik", "Fizik", "Kimya");
    Ekle(2, "Ayþe", "Kara", "Matematik", "Biyoloji", "VeriYapilari", "Kimya");
    Ekle(3, "Mehmet", "Demir", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(4, "Zeynep", "Yýldýz", "Matematik", "Fizik", "Biyoloji", "VeriYapilari");
    Ekle(5, "Ahmet", "Can", "Fizik", "Kimya", "Matematik", "VeriYapilari");
    Ekle(6, "Elif", "Þahin", "Kimya", "VeriYapilari", "Matematik", "Biyoloji");
    Ekle(7, "Merve", "Öztürk", "Matematik", "VeriYapilari", "Fizik", "Kimya");
    Ekle(8, "Cem", "Kaya", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(9, "Selin", "Aydýn", "Biyoloji", "Matematik", "VeriYapilari", "Kimya");
    Ekle(10, "Canan", "Çelik", "Fizik", "VeriYapilari", "Matematik", "Kimya");
    Ekle(11, "Kemal", "Yýlmaz", "Kimya", "Matematik", "Fizik", "VeriYapilari");
    Ekle(12, "Ece", "Demir", "Matematik", "VeriYapilari", "Kimya", "Fizik");
    Ekle(13, "Mert", "Yýldýz", "VeriYapilari", "Fizik", "Kimya", "Matematik");
    Ekle(14, "Sevgi", "Aksoy", "Fizik", "Matematik", "VeriYapilari", "Biyoloji");
    Ekle(15, "Murat", "Aydýn", "Matematik", "Kimya", "VeriYapilari", "Fizik");
    Ekle(16, "Ceren", "Kaya", "VeriYapilari", "Matematik", "Biyoloji", "Kimya");
    Ekle(17, "Emre", "Þahin", "Kimya", "Fizik", "VeriYapilari", "Matematik");
    Ekle(18, "Aylin", "Öztürk", "Biyoloji", "VeriYapilari", "Matematik", "Fizik");
    Ekle(19, "Tolga", "Can", "VeriYapilari", "Kimya", "Fizik", "Matematik");

printf("\nGoster : \n");
    Goster();


    QuickSort(ogrenciler, 0, ogrenciSayisi - 1);


	printf("\A-Z : \n");
	
    Listele(ogrenciler, ogrenciSayisi);

    free(ogrenciler);
    



    return 0;
}

