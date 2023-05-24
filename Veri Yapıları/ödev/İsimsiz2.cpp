#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int okul_no;
    char isim[50];
    char soyad[50];
    char dersler[4][50];

    struct node* next;
    struct node* previous;
};

struct node* head = NULL;
struct node* tail = NULL;

void SonaEkleme() {
    struct node* tmp, * ptr;
    tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Yetersiz Bellek");
        return;
    }
    printf("Okul no girin: ");
    scanf("%d", &tmp->okul_no);

    printf("Isim yaziniz: ");
    scanf("%s", tmp->isim);

    printf("Soyad yaziniz: ");
    scanf("%s", tmp->soyad);

    printf("\n");
    printf("Lutfen dersleri yaziniz, 4 ders girme hakkiniz var.\n");
    printf("Ders 1: ");
    scanf("%s", tmp->dersler[0]);
    printf("Ders 2: ");
    scanf("%s", tmp->dersler[1]);
    printf("Ders 3: ");
    scanf("%s", tmp->dersler[2]);
    printf("Ders 4: ");
    scanf("%s", tmp->dersler[3]);

    tmp->next = NULL;
    tmp->previous = NULL;

    if (head == NULL) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tmp->previous = tail;
        tail = tmp;
    }
}

void Goster() {
    struct node* ptr;
    if (head == NULL) {
        printf("Liste bos");
        return;
    }

    ptr = head;
    while (ptr != NULL) {
        printf("Isim: %s \n", ptr->isim);
        printf("Soyad: %s \n", ptr->soyad);
        printf("Okul No: %d \n", ptr->okul_no);
        printf("Ders 1: %s \n", ptr->dersler[0]);
        printf("Ders 2: %s \n", ptr->dersler[1]);
        printf("Ders 3: %s \n", ptr->dersler[2]);
        printf("Ders 4: %s \n", ptr->dersler[3]);

        ptr = ptr->next;
    }
}

void VeriYapilariDersiGoster() {
    struct node* ptr;
    int found = 0;

    if (head == NULL) {
        printf("Liste bos");
        return;
    }

    ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->dersler[0], "VeriYapilari") == 0 || strcmp(ptr->dersler[1], "VeriYapilari") == 0 || strcmp(ptr->dersler[2], "VeriYapilari") == 0 || strcmp(ptr->dersler[3], "VeriYapilari") == 0) {
            printf("Isim: %s \n", ptr->isim);
            printf("Soyad: %s \n", ptr->soyad);
            printf("Okul No: %d \n", ptr->okul_no);
            printf("Ders 1: %s \n", ptr->dersler[0]);
            printf("Ders 2: %s \n", ptr->dersler[1]);
            printf("Ders 3: %s \n", ptr->dersler[2]);
            printf("Ders 4: %s \n", ptr->dersler[3]);

            found = 1;
        }

        ptr = ptr->next;
    }

    if (!found) {
        printf("VeriYapilari dersi alinmamis.\n");
    }
}

void SiralaListe(struct node* bas, struct node* son) {
    if (bas == NULL || bas == son || bas->next == son) {
        return;
    }

    struct node* pivot = Partition(bas, son);
    SiralaListe(bas, pivot);
    SiralaListe(pivot->next, son);
}

struct node* Partition(struct node* bas, struct node* son) {
    char pivot[50];
    strcpy(pivot, son->isim);

    struct node* i = bas->previous;

    for (struct node* j = bas; j != son; j = j->next) {
        if (strcmp(j->isim, pivot) <= 0) {
            i = (i == NULL) ? bas : i->next;

            Swap(i, j);
        }
    }

    i = (i == NULL) ? bas : i->next;
    Swap(i, son);

    return i;
}

void Swap(struct node* a, struct node* b) {
    int temp_no = a->okul_no;
    char temp_isim[50];
    char temp_soyad[50];
    char temp_dersler[4][50];

    strcpy(temp_isim, a->isim);
    strcpy(temp_soyad, a->soyad);
    for (int i = 0; i < 4; i++) {
        strcpy(temp_dersler[i], a->dersler[i]);
    }

    a->okul_no = b->okul_no;
    strcpy(a->isim, b->isim);
    strcpy(a->soyad, b->soyad);
    for (int i = 0; i < 4; i++) {
        strcpy(a->dersler[i], b->dersler[i]);
    }

    b->okul_no = temp_no;
    strcpy(b->isim, temp_isim);
    strcpy(b->soyad, temp_soyad);
    for (int i = 0; i < 4; i++) {
        strcpy(b->dersler[i], temp_dersler[i]);
    }
}

int main() {
    SonaEkleme();
    Goster();
    VeriYapilariDersiGoster();

    printf("\nSiralama sonrasi:\n");
    SiralaListe(head, tail);
    Goster();
    VeriYapilariDersiGoster();

    return 0;
}

