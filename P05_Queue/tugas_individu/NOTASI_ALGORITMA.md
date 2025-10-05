# NOTASI ALGORITMA - PROGRAM PENJADWALAN PROSES CPU

**NIM/Nama:** 24060124130069/Muhammad Fikri  
**Tanggal:** 5 Oktober 2025  
**Deskripsi:** Simulasi penjadwalan proses CPU dengan algoritma Round Robin menggunakan ADT Queue dan ADT Proses

---

## 1. ADT PROSES (tproses.c)

### createProses
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
procedure createProses(output P: tProses, input c: character, input n: integer)
{I.S.: c dan n terdefinisi}
{F.S.: P terdefinisi dengan idProses = c dan burstTime = n}
{Proses: mengisi struktur proses dengan ID dan burst time yang diberikan}
{Contoh:
  createProses(P, 'A', 5) → P.idProses = 'A', P.burstTime = 5
  createProses(P, 'B', 3) → P.idProses = 'B', P.burstTime = 3}
```

**BODY/REALISASI PROTOTIPE**
```
procedure createProses(output P: tProses, input c: character, input n: integer)
Kamus
  {tidak ada variabel lokal}
Algoritma
  P.idProses ← c
  P.burstTime ← n
```

### idProses
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
function idProses(P: tProses) → character
{I.S.: P terdefinisi}
{F.S.: mengembalikan nilai idProses dari P}
{Proses: mengakses field idProses dari struktur tProses}
```

**BODY/REALISASI PROTOTIPE**
```
function idProses(P: tProses) → character
Kamus
  {tidak ada variabel lokal}
Algoritma
  → P.idProses
```

### burstTime
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
function burstTime(P: tProses) → integer
{I.S.: P terdefinisi}
{F.S.: mengembalikan nilai burstTime dari P}
{Proses: mengakses field burstTime dari struktur tProses}
```

**BODY/REALISASI PROTOTIPE**
```
function burstTime(P: tProses) → integer
Kamus
  {tidak ada variabel lokal}
Algoritma
  → P.burstTime
```

---

## 2. ADT QUEUE (tqueue2.c)

### createQueue2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
procedure createQueue2(output Q: tqueue2)
{I.S.: -}
{F.S.: Q terdefinisi dan kosong}
{Proses: menginisialisasi queue dengan semua elemen kosong, head = 0, tail = 0}
{Elemen kosong direpresentasikan dengan tProses('#', 0)}
```

**BODY/REALISASI PROTOTIPE**
```
procedure createQueue2(output Q: tqueue2)
Kamus
  i: integer
  prosesKosong: tProses
Algoritma
  i ← 1
  createProses(prosesKosong, '#', 0)
  for i to 5 do
    Q.wadah[i] ← prosesKosong
  {endfor}
  Q.head ← 0
  Q.tail ← 0
```

### head2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
function head2(Q: tqueue2) → integer
{I.S.: Q terdefinisi}
{F.S.: mengembalikan posisi head dari queue}
```

**BODY/REALISASI PROTOTIPE**
```
function head2(Q: tqueue2) → integer
Kamus
  {tidak ada variabel lokal}
Algoritma
  → Q.head
```

### tail2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
function tail2(Q: tqueue2) → integer
{I.S.: Q terdefinisi}
{F.S.: mengembalikan posisi tail dari queue}
```

**BODY/REALISASI PROTOTIPE**
```
function tail2(Q: tqueue2) → integer
Kamus
  {tidak ada variabel lokal}
Algoritma
  → Q.tail
```

### isEmptyQueue2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
function isEmptyQueue2(Q: tqueue2) → boolean
{I.S.: Q terdefinisi}
{F.S.: mengembalikan true jika queue kosong}
{Proses: queue kosong jika head = 0 dan tail = 0}
```

**BODY/REALISASI PROTOTIPE**
```
function isEmptyQueue2(Q: tqueue2) → boolean
Kamus
  {tidak ada variabel lokal}
Algoritma
  → (head2(Q) = 0) and (tail2(Q) = 0)
```

### isFullQueue2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
function isFullQueue2(Q: tqueue2) → boolean
{I.S.: Q terdefinisi}
{F.S.: mengembalikan true jika queue penuh}
{Proses: queue penuh jika head = 1 dan tail = 5}
```

**BODY/REALISASI PROTOTIPE**
```
function isFullQueue2(Q: tqueue2) → boolean
Kamus
  {tidak ada variabel lokal}
Algoritma
  → (head2(Q) = 1) and (tail2(Q) = 5)
```

### sizeQueue2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
function sizeQueue2(Q: tqueue2) → integer
{I.S.: Q terdefinisi}
{F.S.: mengembalikan jumlah elemen dalam queue}
{Proses: jika kosong return 0, selain itu return tail - head + 1}
```

**BODY/REALISASI PROTOTIPE**
```
function sizeQueue2(Q: tqueue2) → integer
Kamus
  {tidak ada variabel lokal}
Algoritma
  if isEmptyQueue2(Q) then
    → 0
  else
    → tail2(Q) - head2(Q) + 1
  {endif}
```

### enqueue2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
procedure enqueue2(input/output Q: tqueue2, input P: tProses)
{I.S.: Q dan P terdefinisi}
{F.S.: P ditambahkan ke queue jika belum penuh}
{Proses: 
  - Jika queue kosong, set head = 1 dan tail = 1
  - Jika tidak kosong dan masih ada ruang, increment tail
  - Masukkan P ke posisi tail}
```

**BODY/REALISASI PROTOTIPE**
```
procedure enqueue2(input/output Q: tqueue2, input P: tProses)
Kamus
  {tidak ada variabel lokal}
Algoritma
  if not isFullQueue2(Q) then
    if isEmptyQueue2(Q) then
      Q.head ← 1
      Q.tail ← 1
      Q.wadah[1] ← P
    else if tail2(Q) < 5 then
      Q.tail ← tail2(Q) + 1
      Q.wadah[tail2(Q)] ← P
    {endif}
  {endif}
```

### dequeue2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
procedure dequeue2(input/output Q: tqueue2, output P: tProses)
{I.S.: Q terdefinisi}
{F.S.: elemen head dikeluarkan dari queue dan disimpan di P}
{Proses:
  - Jika queue tidak kosong, ambil elemen head
  - Jika tinggal 1 elemen, set head = 0 dan tail = 0
  - Selain itu, increment head
  - Jika queue kosong, set P dengan proses '@'}
```

**BODY/REALISASI PROTOTIPE**
```
procedure dequeue2(input/output Q: tqueue2, output P: tProses)
Kamus
  prosesKosong: tProses
Algoritma
  createProses(prosesKosong, '#', 0)
  if not isEmptyQueue2(Q) then
    P ← infoHead2(Q)
    Q.wadah[head2(Q)] ← prosesKosong
    if isOneElement2(Q) then
      Q.head ← 0
      Q.tail ← 0
    else
      Q.head ← head2(Q) + 1
    {endif}
  else
    createProses(P, '@', 0)
  {endif}
```

### viewQueue2
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
procedure viewQueue2(input Q: tqueue2)
{I.S.: Q terdefinisi}
{F.S.: menampilkan elemen aktif dalam queue ke layar}
{Proses: mencetak semua elemen dari head hingga tail dalam format [id,burst]}
```

**BODY/REALISASI PROTOTIPE**
```
procedure viewQueue2(input Q: tqueue2)
Kamus
  i: integer
Algoritma
  if not isEmptyQueue2(Q) then
    output("Active processes: ")
    for i ← head2(Q) to tail2(Q) do
      output("[", Q.wadah[i].idProses, ",", Q.wadah[i].burstTime, "] ")
    {endfor}
    output("\n")
  else
    output("Queue is empty\n")
  {endif}
```

---

## 3. PROGRAM UTAMA (main_program.c)

### main (Program PenjadwalanProsesCPU)
**DEKLARASI/DEFINISI & SPESIFIKASI TIPE & PROTOTIPE**
```
program PenjadwalanProsesCPU
{I.S.: -}
{F.S.: simulasi penjadwalan Round Robin selesai dan ditampilkan ke layar}
{Proses:
  1. Membuat 5 proses berdasarkan 5 digit terakhir NIM (30069)
  2. Memasukkan semua proses ke queue
  3. Melakukan simulasi Round Robin dengan quantum time = 5
  4. Menampilkan urutan eksekusi, waktu mulai, dan waktu selesai}
{Algoritma Round Robin:
  - Ambil proses dari head queue
  - Eksekusi selama quantum time atau sampai selesai
  - Jika belum selesai, masukkan kembali ke tail queue
  - Ulangi sampai semua proses selesai}
```

**BODY/REALISASI PROTOTIPE**
```
program PenjadwalanProsesCPU
Kamus
  Q: tqueue2                    {antrian proses di CPU}
  P1, P2, P3, P4, P5: tProses   {5 proses yang akan dijadwalkan}
  currentProses: tProses        {proses yang sedang dieksekusi}
  quantumTime: integer          {quantum time untuk Round Robin}
  currentTime: integer          {waktu sistem saat ini}
  processCount: integer         {counter untuk nomor eksekusi}
  startTime: integer            {waktu mulai eksekusi proses}
  executionTime: integer        {waktu eksekusi aktual}

Algoritma
  {Inisialisasi}
  quantumTime ← 5
  currentTime ← 0
  processCount ← 1
  
  output("=== SIMULASI PENJADWALAN PROSES CPU - ROUND ROBIN ===")
  output("NIM: 24060124130069")
  output("Quantum Time: ", quantumTime, " satuan waktu")
  
  {Pembentukan 5 proses berdasarkan 5 digit terakhir NIM: 30069}
  output("=== PEMBENTUKAN PROSES BERDASARKAN NIM ===")
  output("5 digit terakhir NIM: 30069")
  
  createProses(P1, 'A', 3)      {BT = 3}
  output("Proses A: BT = 3")
  
  createProses(P2, 'B', 6)      {BT = 0 → 3+3 = 6}
  output("Proses B: BT = 0 -> 3+3 = 6")
  
  createProses(P3, 'C', 9)      {BT = 0 → 6+3 = 9}
  output("Proses C: BT = 0 -> 6+3 = 9")
  
  createProses(P4, 'D', 6)      {BT = 6}
  output("Proses D: BT = 6")
  
  createProses(P5, 'E', 9)      {BT = 9}
  output("Proses E: BT = 9")
  
  {Inisialisasi antrian dan memasukkan proses}
  createQueue2(Q)
  
  output("=== URUTAN KEDATANGAN PROSES ===")
  enqueue2(Q, P1)
  output("Proses A masuk antrian (BT: 3)")
  
  enqueue2(Q, P2)
  output("Proses B masuk antrian (BT: 6)")
  
  enqueue2(Q, P3)
  output("Proses C masuk antrian (BT: 9)")
  
  enqueue2(Q, P4)
  output("Proses D masuk antrian (BT: 6)")
  
  enqueue2(Q, P5)
  output("Proses E masuk antrian (BT: 9)")
  
  {Tampilkan antrian awal}
  output("=== ANTRIAN PROSES AWAL ===")
  viewQueue2(Q)
  
  {Simulasi penjadwalan Round Robin}
  output("=== SIMULASI EKSEKUSI DENGAN ROUND ROBIN ===")
  output("Eksekusi | Proses | Waktu Mulai | Waktu Selesai | Burst Time Sisa")
  output("---------|--------|-------------|---------------|----------------")
  
  while not isEmptyQueue2(Q) do
    {Ambil proses dari head antrian}
    dequeue2(Q, currentProses)
    
    {Tentukan waktu mulai eksekusi}
    startTime ← currentTime
    
    {Tentukan waktu eksekusi}
    if burstTime(currentProses) ≤ quantumTime then
      executionTime ← burstTime(currentProses)
      currentProses.burstTime ← 0
    else
      executionTime ← quantumTime
      currentProses.burstTime ← burstTime(currentProses) - quantumTime
    {endif}
    
    {Update waktu sistem}
    currentTime ← currentTime + executionTime
    
    {Tampilkan informasi eksekusi}
    output(processCount, " | ", currentProses.idProses, " | ", 
           startTime, " | ", currentTime, " | ", currentProses.burstTime)
    
    processCount ← processCount + 1
    
    {Jika proses belum selesai, masukkan kembali ke antrian}
    if currentProses.burstTime > 0 then
      enqueue2(Q, currentProses)
    {endif}
  {endwhile}
  
  {Tampilkan hasil akhir}
  output("=== SIMULASI SELESAI ===")
  output("Total waktu eksekusi: ", currentTime, " satuan waktu")
  output("Semua proses telah selesai dieksekusi.")
```

---

## 4. PENJELASAN ALGORITMA ROUND ROBIN

**Karakteristik Round Robin:**
1. **Preemptive scheduling** - proses dapat dihentikan paksa
2. **Time quantum** - setiap proses diberi waktu maksimal untuk eksekusi
3. **Circular queue** - proses yang belum selesai dikembalikan ke akhir antrian
4. **Fair scheduling** - semua proses mendapat kesempatan yang sama

**Langkah-langkah Round Robin:**
1. Ambil proses dari head queue
2. Eksekusi proses selama quantum time atau sampai selesai (yang lebih kecil)
3. Jika proses belum selesai, masukkan kembali ke tail queue
4. Ulangi sampai semua proses selesai

**Pembentukan Burst Time dari NIM 24060124130069:**
- 5 digit terakhir: **30069**
- Aturan: jika digit = 0, ganti dengan digit sebelumnya + 3
- Hasil: 3, 6, 9, 6, 9

**Contoh Eksekusi dengan Quantum Time = 5:**
```
Proses | Burst Time Awal | Eksekusi 1 | Eksekusi 2 | Eksekusi 3
-------|-----------------|------------|------------|------------
A      | 3               | 3 (selesai)|            |
B      | 6               | 5          | 1 (selesai)|
C      | 9               | 5          | 4 (selesai)|
D      | 6               | 5          | 1 (selesai)|
E      | 9               | 5          | 4 (selesai)|
```

---

**Output Program:**
Program akan menampilkan:
1. Pembentukan proses berdasarkan NIM
2. Urutan kedatangan proses
3. Antrian proses awal
4. Simulasi eksekusi Round Robin dengan informasi:
   - Nomor eksekusi
   - ID proses
   - Waktu mulai
   - Waktu selesai
   - Burst time yang tersisa
5. Total waktu eksekusi

**Kompleksitas Waktu:** O(n × (total_burst_time / quantum_time))  
**Kompleksitas Ruang:** O(n) untuk menyimpan n proses dalam queue