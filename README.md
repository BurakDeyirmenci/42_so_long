# So Long - Grafik Projesi

## Açıklama

Bu proje, MiniLibX kütüphanesini kullanarak C dilinde geliştirilmiş basit bir 2D oyundur. Oyunun amacı, oyuncunun haritadaki tüm toplanabilir nesneleri toplaması ve ardından en kısa yolunu seçerek kaçmasıdır. Oyuncu, yukarı, sola, aşağı ve sağa hareket etmek için sırasıyla W, A, S ve D tuşlarını kullanarak ana karakteri kontrol eder.

## Özellikler

- W, A, S ve D tuşlarıyla oyuncu hareketi
- Toplanabilir nesneler
- Duvarlar, toplanabilir nesneler ve boş alanları içeren harita
- Geçerli hareket sayısının görüntülenmesi
- Pencere yönetiminin düzgün bir şekilde yapılması
- ESC tuşu veya pencere kapatma düğmesi ile temiz çıkış

## Harita Formatı

Harita aşağıdaki bileşenlerle oluşturulmuştur:
- Duvarlar '1' ile temsil edilir
- Toplanabilir nesneler 'C' ile temsil edilir
- Boş alanlar '0' ile temsil edilir
- Harita çıkışı 'E' ile temsil edilir
- Oyuncunun başlangıç konumu 'P' ile temsil edilir

Geçerli bir harita örneği:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Kullanım

Projeyi derlemek için aşağıdaki komutu çalıştırın:
`make`
Harita dosyası ile programı çalıştırmak için şu komutu kullanın:
`./so_long harita.ber`
Derlenmiş dosyaları temizlemek için aşağıdaki komutu çalıştırın:
`make clean`
## Bağımlılıklar

- MiniLibX kütüphanesi