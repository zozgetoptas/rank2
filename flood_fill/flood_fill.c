#include "flood_fill.h"
#include "flood_fill.h" // t_point yapısını ve fonksiyon prototipini içerir
#include <stdio.h> // Sadece test için printf içerebilir

void flood_fill(char **tab, t_point size, t_point begin)
{
    if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y || tab == NULL)
        return;

    char original_char = tab[begin.y][begin.x];
    if (original_char == 'F' || original_char == '\0')
        return;

    // 3. Bölgeyi doldur
    //    - Başlangıç noktasındaki karakteri 'F' ile değiştir.
    tab[begin.y][begin.x] = 'F';

    // 4. Komşuları kontrol et ve fonksiyonu tekrar çağır
    //    - Yukarı komşu
    if (begin.y > 0 && tab[begin.y - 1][begin.x] == original_char)
    {
        t_point up = {begin.x, begin.y - 1};
        flood_fill(tab, size, up);
    }
    //    - Aşağı komşu
    if (begin.y < size.y - 1 && tab[begin.y + 1][begin.x] == original_char)
    {
        t_point down = {begin.x, begin.y + 1};
        flood_fill(tab, size, down);
    }
    //    - Sol komşu
    if (begin.x > 0 && tab[begin.y][begin.x - 1] == original_char)
    {
        t_point left = {begin.x - 1, begin.y};
        flood_fill(tab, size, left);
    }
    //    - Sağ komşu
    if (begin.x < size.x - 1 && tab[begin.y][begin.x + 1] == original_char)
    {
        t_point right = {begin.x + 1, begin.y};
        flood_fill(tab, size, right);
    }
}