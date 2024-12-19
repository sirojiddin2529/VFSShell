# VFSShell

VFSShell - bu oddiy buyruq satr dasturi bo'lib, virtual fayl tizimi qobig'ini simulyatsiya qiladi. Foydalanuvchilarga daraxt strukturasidagi katalogni navigatsiya qilish, fayllar va kataloglarni yaratish, va asosiy fayl tizimi operatsiyalarini bajarish imkonini beradi.

## Xususiyatlar

- **Fayl va Katalog Boshqaruvi**
  - `touch` buyrug'i bilan fayllarni yaratish.
  - `mkdir` buyrug'i bilan kataloglarni yaratish.
- **Navigatsiya**
  - `enter` buyrug'i yordamida kataloglarga kirish.
  - `back` buyrug'i yordamida ota katalogga qaytish.
  - `pwd` buyrug'i bilan joriy yo'lni ko'rsatish.
- **Ro'yxatlash va Qidirish**
  - `ls` buyrug'i yordamida joriy katalogdagi fayllar va kataloglarni ko'rish.
  - `find` buyrug'i yordamida fayl yoki katalogni nomi bo'yicha qidirish.
- **Daraxt Ko'rinishi**
  - `print_tree` funksiyasi yordamida katalog strukturasini rekursiv ravishda ko'rsatish.
- **Chiqish**
  - `exit` buyrug'i yordamida qobiqdan chiqish.

## Ishlash Tartibi

VFSShell fayl tizimini simulyatsiya qilish uchun daraxt ma'lumotlar tuzilmasidan foydalanadi:

- Har bir katalog yoki fayl `Node` strukturasi sifatida taqdim etiladi.
- Tugunlar nom, tur (fayl yoki katalog) va ularning ota, bola va aka-uka tugunlariga ko'rsatgichlarga ega.
- "root" katalogi ildiz sifatida ishga tushiriladi va barcha operatsiyalar unga nisbatan amalga oshiriladi.

## Buyruqlar

| Buyruq      | Tavsif                                           |
|-------------|-------------------------------------------------|
| `pwd`       | Joriy katalogning to'liq yo'lini ko'rsatadi.    |
| `ls`        | Joriy katalogdagi barcha fayllar va kataloglarni ro'yxatlaydi. |
| `touch <name>` | Joriy katalogda yangi fayl yaratadi.            |
| `mkdir <name>` | Joriy katalogda yangi katalog yaratadi.         |
| `enter <name>` | Ko'rsatilgan katalogga kiradi.                  |
| `back`      | Ota katalogga qaytadi.                          |
| `find <name>` | Fayl yoki katalogni nomi bo'yicha qidiradi.     |
| `exit`      | Qobiqdan chiqadi.                               |

## Foydalanish

1. Dastur kodini C kompilyatori yordamida kompilyatsiya qiling:

   ```bash
   gcc vfsshell.c -o vfsshell
   ```

2. Tayyor dasturni ishga tushiring:

   ```bash
   ./vfsshell
   ```

3. Yuqoridagi buyruqlar yordamida virtual fayl tizimini navigatsiya qiling va boshqaring.

## Misol

```bash
➜ root mkdir docs
➜ root enter docs
➜ docs touch file1.txt
➜ docs mkdir images
➜ docs enter images
➜ images pwd
root/docs/images/
➜ images back
➜ docs ls
file1.txt
images/
➜ docs find file1.txt
root/docs/file1.txt/
➜ docs exit
```

## Kod Haqida Umumiy Ma'lumot

### Asosiy Funksiyalar

- `init()`: Root katalogini ishga tushiradi.
- `create_node()`: Yangi tugun (fayl yoki katalog) yaratadi.
- `insert_node()`: Tugunni bola yoki aka-uka sifatida joriy katalogga qo'shadi.
- `search_node()`: Bolalar orasidan nomi bo'yicha tugunni qidiradi.
- `print_tree()`: Daraxt strukturasini rekursiv ravishda chop etadi.
- `find()`: Butun fayl tizimidan tugunni qidiradi va uning yo'lini chop etadi.

### Ma'lumotlar Tuzilmasi

```c
typedef struct Node {
    char name[50];
    int is_file;
    struct Node *next;
    struct Node *child;
    struct Node *parent;
} Node;
```

## Kelajakdagi Takomillashtirishlar

- Fayllar va kataloglarni o'chirish funksiyasini qo'shish.
- Ruxsatnomalar va fayl o'lchamlari atributlarini joriy qilish.
- Buyruqlar tarixini va avtomatik to'ldirish funksiyasini qo'shish.
- Dinamik kiritish o'lchamlarini boshqarish uchun xotira boshqaruvini yaxshilash.

## Litsenziya

Ushbu loyiha MIT Litsenziyasi ostida chiqarilgan.

---

VFSShell bilan kodlashdan zavqlaning!
