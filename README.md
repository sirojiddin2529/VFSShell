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

- Har bir katalog yoki fayl `Node` strukturasi sifatida taqdim etiladi (`Tree Data Structure`).
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
| `tree` | Joriy katologning tuzilishini daraxt ko'rinishida chiqaradi. |
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
➜ docs tree
docs/
  file1.txt
  images/
➜ docs exit
```

## Kod Haqida Umumiy Ma'lumot

### Kodning asosiy qismlari va funksiyalari:
1. **Ma'lumot tuzilmasi (`struct Node`)**:
   - Har bir `Node` papka yoki faylni ifodalaydi.
   - `name`: Fayl yoki papka nomi.
   - `is_file`: Fayl yoki papka ekanligini bildiradi (1 - fayl, 0 - papka).
   - `next`: Bitta papka ichidagi navbatdagi elementga ishora qiladi.
   - `child`: Papka ichidagi birinchi elementga ishora qiladi.
   - `parent`: Yuqori darajadagi papkaga ishora qiladi.
   - `size`: Fayl yoki papkaning hajmi ifodalaydi.
   - `created_at`: Fayl yoki papkani qachon yaratilganligini ifodalaydi.
   - `updated_at`: Fayl yoki papkaga qachon o'zgartirish kiritilganligini ifodalaydi.

2. **Global o'zgaruvchilar**:
   - `root`: Fayl tizimining ildizi.
   - `current`: Hozirgi papka.

3. **Asosiy funksiyalar**:
   - **`init()`**: Fayl tizimini boshlang'ich holatga keltiradi, `root` papkasini yaratadi.
   - **`prompt()`**: Joriy papka nomini ko'rsatadi.
   - **`create_node()`**: Yangi fayl yoki papka yaratadi.
   - **`insert_node()`**: Yangi fayl yoki papkani hozirgi papkaga qo'shadi.
   - **`search_node()`**: Joriy papkada berilgan nom bilan fayl yoki papkani qidiradi.
   - **`print_tree()`**: Fayl tizimini daraxt ko'rinishida ko'rsatadi.
   - **`path()`**: Hozirgi yoki ko'rsatilgan tugunning to'liq yo'lini chiqaradi.

4. **Buyruqlar**:
   - **`touch <nom>`**: Fayl yaratadi.
   - **`mkdir <nom>`**: Papka yaratadi.
   - **`ls`**: Hozirgi papkada mavjud fayl va papkalarni ro'yxat qiladi.
   - **`enter <nom>`**: Ko'rsatilgan papkaga kiradi.
   - **`back`**: Bir daraja yuqori papkaga qaytadi.
   - **`pwd`**: Joriy papkaning to'liq yo'lini ko'rsatadi.
   - **`find <nom>`**: Fayl tizimida berilgan nomdagi fayl yoki papkani qidiradi.
   - **`tree`**: Fayl tizimini daraxt ko'rinishida ko'rsatadi.
   - **`exit`**: Dasturdan chiqadi.

5. **Boshlanishi (`main`)**:
   - Fayl tizimini boshlaydi (`init()`).
   - Foydalanuvchi kiritgan buyruqlarni o'qiydi va tegishli funksiyalarni bajaradi.

## Kelajakdagi Takomillashtirishlar

- Fayllar va kataloglarni o'chirish funksiyasini qo'shish.
- Ruxsatnomalar va fayl o'lchamlari atributlarini joriy qilish.
- Buyruqlar tarixini va avtomatik to'ldirish funksiyasini qo'shish.
- Dinamik kiritish o'lchamlarini boshqarish uchun xotira boshqaruvini yaxshilash.

---

VFSShell bilan kodlashdan zavqlaning!
