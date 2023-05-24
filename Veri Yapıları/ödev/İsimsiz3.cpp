#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int okul_no;
    char isim[50];
    char soyad[50];
    char dersler[4][50];
    struct node *next;
    struct node *previous;
};

struct node *head = NULL, *tail = NULL;

void Ekle(int okul_no, const char *isim, const char *soyad, const char *ders1, const char *ders2, const char *ders3, const char *ders4) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->okul_no = okul_no;
    strcpy(newNode->isim, isim);
    strcpy(newNode->soyad, soyad);
    strcpy(newNode->dersler[0], ders1);
    strcpy(newNode->dersler[1], ders2);
    strcpy(newNode->dersler[2], ders3);
    strcpy(newNode->dersler[3], ders4);
    newNode->next = NULL;
    newNode->previous = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

void Goster() {
    struct node *ptr = head;

    if (head == NULL) {
        printf("Liste bos\n");
        return;
    }

    while (ptr != NULL) {
        int veriYapilariDersiAlani = 0;
        for (int i = 0; i < 4; i++) {
            if (strcmp(ptr->dersler[i], "VeriYapilari") == 0) {
                veriYapilariDersiAlani = 1;
                break;
            }
        }

        if (veriYapilariDersiAlani) {
            printf("Isim: %s\n", ptr->isim);
            printf("Soyad: %s\n", ptr->soyad);
            printf("Okul No: %d\n", ptr->okul_no);
            printf("Ders 1: %s\n", ptr->dersler[0]);
            printf("Ders 2: %s\n", ptr->dersler[1]);
            printf("Ders 3: %s\n", ptr->dersler[2]);
            printf("Ders 4: %s\n\n", ptr->dersler[3]);
        }

        ptr = ptr->next;
    }
}

// Dizi elemanlar�n� takas etmek i�in yard�mc� fonksiyon
void Takas(struct node *a, struct node *b) {
    int temp_no = a->okul_no;
    char temp_isim[50];
    char temp_soyad[50];
    strcpy(temp_isim, a->isim);
    strcpy(temp_soyad, a->soyad);
    memcpy(a->isim, b->isim, sizeof(b->isim));
    memcpy(a->soyad, b->soyad, sizeof(b->soyad));
    a->okul_no = b->okul_no;
    memcpy(b->isim, temp_isim, sizeof(temp_isim));
    memcpy(b->soyad, temp_soyad, sizeof(temp_soyad));
    b->okul_no = temp_no;
}

// Quick Sort algoritmas�
void QuickSort(struct node *low, struct node *high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        struct node *pivot = low;
        struct node *left = low;
        struct node *right = high;

        while (left != right) {
            while (left != right && left->okul_no <= pivot->okul_no)
                left = left->next;

            while (right != NULL && right->okul_no > pivot->okul_no)
                right = right->previous;

            if (left != NULL && right != NULL && left != right)
                Takas(left, right);
        }

        Takas(pivot, right);

        QuickSort(low, right->previous);
        QuickSort(right->next, high);
    }
}


// K�meleme s�ralama algoritmas� (Okul No'ya g�re s�ralama)
void KumelemeSiralama() {
    struct node *current = head;
    struct node *index = NULL;
    int temp_no;
    char temp_isim[50];
    char temp_soyad[50];

    if (head == NULL) {
        printf("Liste bos\n");
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->okul_no > index->okul_no) {
                    temp_no = current->okul_no;
                    strcpy(temp_isim, current->isim);
                    strcpy(temp_soyad, current->soyad);
                    memcpy(current->isim, index->isim, sizeof(index->isim));
                    memcpy(current->soyad, index->soyad, sizeof(index->soyad));
                    current->okul_no = index->okul_no;
                    memcpy(index->isim, temp_isim, sizeof(temp_isim));
                    memcpy(index->soyad, temp_soyad, sizeof(temp_soyad));
                    index->okul_no = temp_no;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// �simleri A'dan Z'ye s�ralama (ASCII de�erlerine g�re)
void ADanZyeSiralama() {
    struct node *current = head;
    struct node *index = NULL;
    char temp_isim[50];
    char temp_soyad[50];
    int swapped;

    if (head == NULL) {
        printf("Liste bos\n");
        return;
    } else {
        do {
            swapped = 0;
            current = head;

            while (current->next != index) {
                if (strcmp(current->isim, current->next->isim) > 0) {
                    strcpy(temp_isim, current->isim);
                    strcpy(temp_soyad, current->soyad);
                    memcpy(current->isim, current->next->isim, sizeof(current->next->isim));
                    memcpy(current->soyad, current->next->soyad, sizeof(current->next->soyad));
                    memcpy(current->next->isim, temp_isim, sizeof(temp_isim));
                    memcpy(current->next->soyad, temp_soyad, sizeof(temp_soyad));
                    swapped = 1;
                }
                current = current->next;
            }
            index = current;
        } while (swapped);
    }
}


int main() {
    // 50 tane ��renci ekleme i�lemi
    Ekle(1, "Ali", "Yilmaz", "VeriYapilari", "Matematik", "Fizik", "Kimya");
    Ekle(2, "Ayse", "Kara", "Matematik", "Biyoloji", "VeriYapilari", "Kimya");
    Ekle(3, "Mehmet", "Demir", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(1, "Ali", "Y�lmaz", "VeriYapilari", "Matematik", "Fizik", "Kimya");
    Ekle(2, "Ay�e", "Kara", "Matematik", "Biyoloji", "VeriYapilari", "Kimya");
    Ekle(3, "Mehmet", "Demir", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(4, "Zeynep", "Y�ld�z", "Matematik", "Fizik", "Biyoloji", "VeriYapilari");
    Ekle(5, "Ahmet", "Can", "Fizik", "Kimya", "Matematik", "VeriYapilari");
    Ekle(6, "Elif", "�ahin", "Kimya", "VeriYapilari", "Matematik", "Biyoloji");
    Ekle(7, "Merve", "�zt�rk", "Matematik", "VeriYapilari", "Fizik", "Kimya");
    Ekle(8, "Cem", "Kaya", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(9, "Selin", "Ayd�n", "Biyoloji", "Matematik", "VeriYapilari", "Kimya");
    Ekle(10, "Canan", "�elik", "Fizik", "VeriYapilari", "Matematik", "Kimya");
    Ekle(11, "Kemal", "Y�lmaz", "Kimya", "Matematik", "Fizik", "VeriYapilari");
    Ekle(12, "Ece", "Demir", "Matematik", "VeriYapilari", "Kimya", "Fizik");
    Ekle(13, "Mert", "Y�ld�z", "VeriYapilari", "Fizik", "Kimya", "Matematik");
    Ekle(14, "Sevgi", "Aksoy", "Fizik", "Matematik", "VeriYapilari", "Biyoloji");
    Ekle(15, "Murat", "Ayd�n", "Matematik", "Kimya", "VeriYapilari", "Fizik");
    Ekle(16, "Ceren", "Kaya", "VeriYapilari", "Matematik", "Biyoloji", "Kimya");
    Ekle(17, "Emre", "�ahin", "Kimya", "Fizik", "VeriYapilari", "Matematik");
    Ekle(18, "Aylin", "�zt�rk", "Biyoloji", "VeriYapilari", "Matematik", "Fizik");
    Ekle(19, "Tolga", "Can", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(1, "Ali", "Y�lmaz", "VeriYapilari", "Matematik", "Fizik", "Kimya");
    Ekle(2, "Ay�e", "Kara", "Matematik", "Biyoloji", "VeriYapilari", "Kimya");
    Ekle(3, "Mehmet", "Demir", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(4, "Zeynep", "Y�ld�z", "Matematik", "Fizik", "Biyoloji", "VeriYapilari");
    Ekle(5, "Ahmet", "Can", "Fizik", "Kimya", "Matematik", "VeriYapilari");
    Ekle(6, "Elif", "�ahin", "Kimya", "VeriYapilari", "Matematik", "Biyoloji");
    Ekle(7, "Merve", "�zt�rk", "Matematik", "VeriYapilari", "Fizik", "Kimya");
    Ekle(8, "Cem", "Kaya", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(9, "Selin", "Ayd�n", "Biyoloji", "Matematik", "VeriYapilari", "Kimya");
    Ekle(10, "Canan", "�elik", "Fizik", "VeriYapilari", "Matematik", "Kimya");
    Ekle(11, "Kemal", "Y�lmaz", "Kimya", "Matematik", "Fizik", "VeriYapilari");
    Ekle(12, "Ece", "Demir", "Matematik", "VeriYapilari", "Kimya", "Fizik");
    Ekle(13, "Mert", "Y�ld�z", "VeriYapilari", "Fizik", "Kimya", "Matematik");
    Ekle(14, "Sevgi", "Aksoy", "Fizik", "Matematik", "VeriYapilari", "Biyoloji");
    Ekle(15, "Murat", "Ayd�n", "Matematik", "Kimya", "VeriYapilari", "Fizik");
    Ekle(16, "Ceren", "Kaya", "VeriYapilari", "Matematik", "Biyoloji", "Kimya");
    Ekle(17, "Emre", "�ahin", "Kimya", "Fizik", "VeriYapilari", "Matematik");
    Ekle(18, "Aylin", "�zt�rk", "Biyoloji", "VeriYapilari", "Matematik", "Fizik");
    Ekle(19, "Tolga", "Can", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(1, "Ali", "Y�lmaz", "VeriYapilari", "Matematik", "Fizik", "Kimya");
    Ekle(2, "Ay�e", "Kara", "Matematik", "Biyoloji", "VeriYapilari", "Kimya");
    Ekle(3, "Mehmet", "Demir", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(4, "Zeynep", "Y�ld�z", "Matematik", "Fizik", "Biyoloji", "VeriYapilari");
    Ekle(5, "Ahmet", "Can", "Fizik", "Kimya", "Matematik", "VeriYapilari");
    Ekle(6, "Elif", "�ahin", "Kimya", "VeriYapilari", "Matematik", "Biyoloji");
    Ekle(7, "Merve", "�zt�rk", "Matematik", "VeriYapilari", "Fizik", "Kimya");
    Ekle(8, "Cem", "Kaya", "VeriYapilari", "Kimya", "Fizik", "Matematik");
    Ekle(9, "Selin", "Ayd�n", "Biyoloji", "Matematik", "VeriYapilari", "Kimya");
    Ekle(10, "Canan", "�elik", "Fizik", "VeriYapilari", "Matematik", "Kimya");
    Ekle(11, "Kemal", "Y�lmaz", "Kimya", "Matematik", "Fizik", "VeriYapilari");
    Ekle(12, "Ece", "Demir", "Matematik", "VeriYapilari", "Kimya", "Fizik");
    Ekle(13, "Mert", "Y�ld�z", "VeriYapilari", "Fizik", "Kimya", "Matematik");
    Ekle(14, "Sevgi", "Aksoy", "Fizik", "Matematik", "VeriYapilari", "Biyoloji");
    Ekle(15, "Murat", "Ayd�n", "Matematik", "Kimya", "VeriYapilari", "Fizik");
    Ekle(16, "Ceren", "Kaya", "VeriYapilari", "Matematik", "Biyoloji", "Kimya");
    Ekle(17, "Emre", "�ahin", "Kimya", "Fizik", "VeriYapilari", "Matematik");
    Ekle(18, "Aylin", "�zt�rk", "Biyoloji", "VeriYapilari", "Matematik", "Fizik");
    Ekle(19, "Tolga", "Can", "VeriYapilari", "Kimya", "Fizik", "Matematik");

	printf("\nGoster : \n");
    Goster();

	printf("\A-Z : \n");
	ADanZyeSiralama();
	
	printf("\K�meleme : \n");
	KumelemeSiralama();
	
	printf("\QuickSort : \n");
	QuickSort(head, tail);
    return 0;
}

