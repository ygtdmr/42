#include <iostream>
#include <cassert>
#include "vect2.hpp"

int main() {
    // 1. Constructor ve Değer Atama Testi
    std::cout << "--- Test 1: Constructor ve Temel Bilgiler ---" << std::endl;
    vect2 v1(3, 5);
    vect2 v2(10, 20);
    std::cout << "v1: " << v1 << " (Beklenen: {3, 5})" << std::endl;
    std::cout << "v2: " << v2 << " (Beklenen: {10, 20})" << std::endl;

    // 2. Operatör [] Testi (Erişim ve Değiştirme)
    std::cout << "\n--- Test 2: Operatör [] ---" << std::endl;
    assert(v1[0] == 3);
    assert(v1[1] == 5);
    v1[0] = 7; // Değer değiştirme
    std::cout << "v1 güncellendi: " << v1 << " (Beklenen: {7, 5})" << std::endl;

    // 3. Toplama ve Çıkarma Testi
    std::cout << "\n--- Test 3: Toplama ve Cikarma ---" << std::endl;
    vect2 v3 = v1 + v2; // {7+10, 5+20} = {17, 25}
    vect2 v4 = v2 - v1; // {10-7, 20-5} = {3, 15}
    std::cout << "v1 + v2 = " << v3 << " (Beklenen: {17, 25})" << std::endl;
    std::cout << "v2 - v1 = " << v4 << " (Beklenen: {3, 15})" << std::endl;

    // 4. Skaler Çarpma Testi (vect2 * int)
    std::cout << "\n--- Test 4: Skaler Carpma ---" << std::endl;
    vect2 v5 = v1 * 3;     // {7*3, 5*3} = {21, 15}
    vect2 v6 = v1 * 0;     // Sıfır ile çarpma
    vect2 v7 = v1 * -2;    // Negatif ile çarpma
    std::cout << "v1 * 3  = " << v5 << " (Beklenen: {21, 15})" << std::endl;
    std::cout << "v1 * 0  = " << v6 << " (Beklenen: {0, 0})" << std::endl;
    std::cout << "v1 * -2 = " << v7 << " (Beklenen: {-14, -10})" << std::endl;

    // 5. Karşılaştırma Testi (==)
    // Not: Ödevde '==' operatörünün sağlanması istenmiş (v*2 == v2)
    std::cout << "\n--- Test 5: Mantiksal Karsilastirma (==) ---" << std::endl;
    vect2 a(4, 4);
    vect2 b(2, 2);
    if (b * 2 == a) {
        std::cout << "Basarili: (2,2) * 2 == (4,4)" << std::endl;
    } else {
        std::cout << "HATA: Karsilastirma operatoru yanlis calisiyor!" << std::endl;
    }

    // 6. Zincirleme İşlem Testi
    std::cout << "\n--- Test 6: Zincirleme Islemler ---" << std::endl;
    vect2 vComplex = (v1 + v2) * 2 - v1; 
    // İşlem: ({7,5} + {10,20}) * 2 - {7,5}
    // {17,25} * 2 - {7,5} = {34,50} - {7,5} = {27,45}
    std::cout << "Kompleks sonuc: " << vComplex << " (Beklenen: {27, 45})" << std::endl;

    std::cout << "\n--- TUM TESTLER TAMAMLANDI ---" << std::endl;

    return 0;
}