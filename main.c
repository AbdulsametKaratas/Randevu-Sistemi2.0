#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. VERİ YAPILARI TANIMLARI
// Randevu bilgilerini tutan yapı
typedef struct Randevu {
    int id;
    char isim[50];
    int baslangic; // Dakika cinsinden (Örn: 540 = 09:00)
    int bitis;
} Randevu;

// Interval Tree (Aralık Ağacı) Düğümü - Çakışma kontrolü için [cite: 63]
typedef struct Node {
    Randevu veri;
    int max_bitis; 
    struct Node *sol, *sag;
    int yukseklik; // AVL dengelemesi için [cite: 12]
} Node;

// 2. CSV DOSYA İŞLEMLERİ 
void csvKaydet(Randevu r) {
    FILE *fp = fopen("randevular.csv", "a");
    if (fp == NULL) return;
    fprintf(fp, "%d,%s,%d,%d\n", r.id, r.isim, r.baslangic, r.bitis);
    fclose(fp);
}

// 3. SIRALAMA ALGORİTMALARI [cite: 14]
// Liste görünümü için Quicksort veya Mergesort kullanılacak.

int main() {
    printf("--- Randevu ve Salon Rezervasyon Sistemi ---\n");
    printf("Veri Yapilari Final Projesi Baslatildi.\n");

    // Basit bir test verisi
    Randevu yeni = {101, "Toplanti Salonu A", 600, 720}; // 10:00 - 12:00
    
    printf("Randevu eklendi: %s (%d - %d)\n", yeni.isim, yeni.baslangic, yeni.bitis);
    
    // Bir sonraki aşamada Interval Tree ekleme fonksiyonunu buraya yazacağız.

    return 0;
}