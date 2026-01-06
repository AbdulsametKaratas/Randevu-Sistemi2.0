# 🏛️ IMU Salon Yönetim Motoru v5.0

İstanbul Medeniyet Üniversitesi (IMU) için geliştirilen bu proje, gelişmiş veri yapıları ve algoritmalar kullanarak akıllı bir salon rezervasyon ve analiz sistemi sunar. Sistem, backend (C) ve frontend (HTML/JS) katmanlarından oluşarak veriyi hibrit bir mimaride yönetir.

## 🚀 Öne Çıkan Özellikler

- **Akıllı Çakışma Denetimi:** Interval Tree mantığı ile randevu saatlerinin çakışması $O(\log n)$ karmaşıklığında denetlenir.
- **Gelişmiş Veri Kalıcılığı:** Veriler hem `randevular.csv` (kalıcı depolama) hem de `data.json` (frontend senkronizasyonu) formatlarında tutulur.
- **Dinamik Geri Al (Undo):** Stack veri yapısı kullanılarak son yapılan işlemler anında geri alınabilir.
- **Görev Kuyruğu (Task Queue):** Çakışan randevular reddedilmez, FIFO (İlk Giren İlk Çıkar) prensibiyle bekleme listesine alınır.
- **Grafik Analizi:** Dijkstra algoritması ile salonlar arası en kısa ulaşım mesafeleri hesaplanır.

## 🛠️ Kullanılan Teknolojiler ve Algoritmalar

### Veri Yapıları
| Yapı | Kullanım Amacı | Karmaşıklık |
| :--- | :--- | :--- |
| **AVL Tree** | Dengeli randevu depolama ve hızlı erişim | $O(\log n)$ |
| **Interval Tree** | Zaman aralığı çakışma tespiti | $O(\log n)$ |
| **Stack** | İşlem geçmişi ve Geri Al (Undo) fonksiyonu | $O(1)$ |
| **Queue** | Bekleme listesi yönetimi | $O(1)$ |

### Algoritmalar
- **Dijkstra:** Salonlar arası en kısa yol analizi ($O(V^2)$).
- **Quicksort:** Verilerin ID bazlı hızlı sıralanması ($O(n \log n)$).
- **Binary Search:** Sıralı listede yüksek hızlı ID sorgulama ($O(\log n)$).
- **BFS (Breadth-First Search):** AVL ağacının hiyerarşik katmanlar halinde görselleştirilmesi.

## 🖥️ Kurulum ve Çalıştırma

### Backend (C)
Sistemi derlemek için GCC veya benzeri bir C derleyicisi kullanın:
```bash
gcc randevusistemi.c algoritmalar.c -o randevusistemi.exe
./randevusistemi.exe# Randevu-Sistemi
Veri Yapıları ve Algoritmaları dersi proje ödevi
