# Şifreleme Uygulaması (Encryption Application)

Lütfen Bir Dil seçin / Please select a language
[Türkçe](#türkçe) / [English](#english)

---

# Türkçe

Bu proje, kullanıcılara Türkçe ve İngilizce dillerinde metin şifreleme ve deşifreleme işlemleri yapma imkanı sunan basit bir konsol tabanlı uygulamadır.

## İçindekiler

- [Özellikler](#özellikler)
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Proje Mantığı](#proje-mantığı)
- [Lisans](#lisans)

## Özellikler

*   **Çoklu Dil Desteği:** Uygulama başlangıcında Türkçe veya İngilizce dil seçeneği sunar.
*   **Şifreleme:** Seçilen dilde metinleri şifreleyebilir.
*   **Deşifreleme:** Seçilen dilde şifrelenmiş metinleri deşifreleyebilir.
*   **Konsol Tabanlı Arayüz:** Kullanıcı dostu komut satırı arayüzü ile etkileşim sağlar.

## Kurulum

Projeyi yerel makinenizde çalıştırmak için aşağıdaki adımları takip edin:

### Önkoşullar

*   Bir C derleyicisi (örn. GCC). [GCC'yi buradan indirebilirsiniz](https://gcc.gnu.org/install/).

### Adımlar

1.  **Depoyu Klonlayın:**
    ```bash
    git clone https://github.com/HeJo-1/crypto
    cd crypto
    ```
    *Eğer Git kullanmıyorsanız, proje dosyalarını doğrudan indirip bir klasöre çıkarın.*

2.  **Derleme:**
    Projenizi derlemek için aşağıdaki komutu kullanın. Bu komut, `main.c`, `encrypt.c`, `decrypt.c` `ing_decrypt.c` ve `ing_encrypt.c` dosyalarını birleştirerek `program` adında çalıştırılabilir bir dosya oluşturacaktır.

    ```bash
    gcc main.c encrypt.c decrypt.c ing_encrypt.c ing_decrypt.c -o program
    ```

## Kullanım

Uygulamayı derledikten sonra, terminalden aşağıdaki komutla çalıştırabilirsiniz:

```bash
./program
```
### Örnek Çıktı
```bash
Hoşgeldiniz
Welcome


Lütfen bir dil seçiniz
Please select a language
1- Türkçe
2- English
1
Şifreleme Uygulamasına hoşgeldiniz
1- Şifrele
2- Şifreyi Çöz
Bir işlem giriniz : 1
Lütfen bir metin girin: selam dünya

--- Sonuçlar ---
s : 16302
e : 2470
l : 8645
a : 494
m : 17290
  : 13
d : 1235
ü : 2622
n : 115115
n : 25935
y : 38038
a : 494

Dosyaya başarıyla kaydedildi.
```
 ## Proje Mantığı
 Projede şifrelemek için önce string ifade alınır ve binary koda çevrilir her binary basamağına bir asal sayı verilir sağdan sola doğru 2,3,5,7....
 daha sonrasında hangi basamakta 1 varsa o basamağa verilen asal sayılar çarpılır.

 
 <img width="2000" height="1414" alt="binary" src="https://github.com/user-attachments/assets/14c8399e-eeee-40cb-a1c4-dfe92b650c02" />

## Lisans
Bu proje MIT ile lisanslanmıştır. Daha fazla bilgi için LICENSE dosyasına bakınız.

---

# English

This project is a simple console-based application that allows users to encrypt and decrypt text in both Turkish and English.

## Table of Contents

* [Features](#features)
* [Installation](#installation)
* [Usage](#usage)
* [Project Structure](#license)
* [License](#license)

## Features

* **Multi-Language Support:** The application offers a choice between Turkish and English at startup.
* **Encryption:** Can encrypt text in the selected language.
* **Decryption:** Can decrypt encrypted text in the selected language.
* **Console-Based Interface:** Provides interaction through a user-friendly command-line interface.

## Installation

Follow the steps below to run the project on your local machine:

### Prerequisites

* A C compiler (e.g., GCC). [You can download GCC here](https://gcc.gnu.org/install/).

### Steps

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/HeJo-1/crypto
   cd crypto
   ```

   *If you don’t use Git, download the project files directly and extract them into a folder.*

2. **Compile:**
   Use the following command to compile the project. This command will combine `main.c`, `encrypt.c`, `decrypt.c`, `ing_encrypt.c`, and `ing_decrypt.c` into an executable file named `program`.

   ```bash
   gcc main.c encrypt.c decrypt.c ing_encrypt.c ing_decrypt.c -o program
   ```

## Usage

After compiling the application, you can run it from the terminal using the following command:

```bash
./program
```

### Example Output

```bash
Hoşgeldiniz
Welcome

Lütfen bir dil seçiniz
Please select a language
1- Türkçe
2- English
1
Welcome to the Encryption Application
1- Encrypt
2- Decrypt
Enter an option: 1
Please enter a text: selam dünya

--- Results ---
s : 16302
e : 2470
l : 8645
a : 494
m : 17290
  : 13
d : 1235
ü : 2622
n : 115115
n : 25935
y : 38038
a : 494

Successfully saved to file.
```

## Project Logic

In this project, to encrypt a string:

1. The input string is converted into binary.
2. Each binary digit is assigned a prime number from right to left: 2, 3, 5, 7…
3. Then, for each binary digit that is 1, the corresponding prime numbers are multiplied.

<img width="2000" height="1414" alt="binary" src="https://github.com/user-attachments/assets/14c8399e-eeee-40cb-a1c4-dfe92b650c02" />

## License

This project is licensed under the MIT License. See the LICENSE file for more details.


