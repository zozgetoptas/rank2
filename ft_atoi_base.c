int ft_atoi_base(const char *str, int str_base)
{
    char    *number;
    int     result;
    int     sign;
    int     i;
    int     digit_value; // Mevcut karakterin sayısal değerini tutar

    i = 0;
    sign = 1;
    number = (char *)str; // const char* 'ı char* 'a atamak bazı derleyicilerde uyarı verebilir,
                          // ancak bu örnekte sadece okuma amaçlı kullanıldığı için sorun teşkil etmez.

    // Başlangıçtaki boşlukları atla (isteğe bağlı, ancak atoi'de yaygındır)
    // Ödev açıkça belirtmediği için, bu kısmı orijinal kodunuzda olmadığı gibi
    // devre dışı bıraktım.
    // while (number[i] == ' ' || number[i] == '\t' || number[i] == '\n' ||
    //        number[i] == '\v' || number[i] == '\f' || number[i] == '\r')
    // {
    //     i++;
    // }

    // Eksi işaretini kontrol et
    if (number[i] == '-')
    {
        sign *= -1;
        i++;
    }
    // Artı işaretini de kontrol edebiliriz (isteğe bağlı)
    else if (number[i] == '+')
    {
        i++;
    }

    result = 0; // Sonucu sıfırla

    while (number[i] != '\0') // Dizinin sonuna gelene kadar devam et
    {
        digit_value = -1; // Her döngüde başlangıç değeri -1 (geçersiz) olarak ayarla

        // Rakamları '0'-'9' aralığında kontrol et
        if (number[i] >= '0' && number[i] <= '9')
        {
            digit_value = number[i] - '0';
        }
        // Büyük harf heksadesimal rakamları 'A'-'F' aralığında kontrol et
        else if (number[i] >= 'A' && number[i] <= 'F')
        {
            digit_value = number[i] - 'A' + 10; // 'A' için 10, 'B' için 11 vb.
        }
        // Küçük harf heksadesimal rakamları 'a'-'f' aralığında kontrol et
        else if (number[i] >= 'a' && number[i] <= 'f')
        {
            digit_value = number[i] - 'a' + 10; // 'a' için 10, 'b' için 11 vb.
        }

        // Eğer karakter geçerli bir rakam değilse VEYA rakamın değeri tabana eşitse/büyükse,
        // dönüştürmeyi durdur.
        if (digit_value == -1 || digit_value >= str_base)
        {
            break; // Geçersiz karakter veya tabana uygun olmayan rakam
        }

        // Sonucu biriktir: result = result * taban + mevcut_rakam_değeri
        result = result * str_base + digit_value;
        i++; // Bir sonraki karaktere geç
    }
    return (sign * result); // İşareti uygula ve sonucu döndür
}
#include <stdio.h>
int main()
{
    printf("%d", ft_atoi_base("-aa",16));
}