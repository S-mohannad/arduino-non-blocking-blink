# ⏱️ Non-Blocking LED Blink with millis()

> **Arduino Project #21** — وميض LED بدون delay() باستخدام millis()

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Intermediate-orange?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

مشروع يومض LED كل 500ms دون تجميد البرنامج باستخدام `millis()`:

- يتحقق في كل دورة إذا مرّت 500ms من آخر تغيير
- إذا مرّت → يعكس حالة LED باستخدام `!s`
- يحفظ وقت آخر تغيير في `t2` للمقارنة في الدورة القادمة
- البرنامج لا يتوقف أبداً — `loop()` تعمل بحرية كاملة

---

## 🔌 Circuit

```
Arduino UNO
┌─────────────────┐
│            13 ●─┼──[220Ω]──💡 LED ── GND
└─────────────────┘
```

- 💡 LED على Pin 13 مع مقاومة 220Ω

---

## 💡 Concepts Used

- `millis()` — قراءة الوقت المنقضي منذ تشغيل Arduino بالـ ms
- **Non-blocking timing** — بديل عن `delay()` يتيح تشغيل كود آخر بالتوازي
- `unsigned long` — نوع بيانات لتخزين قيم `millis()` الكبيرة بدون overflow
- `bool s` — متغير منطقي لتتبع حالة LED (HIGH/LOW)
- `!s` — عكس الحالة في كل مرة

---

## 📊 Behavior

| الحدث | التفاصيل |
|-------|---------|
| كل 500ms | تُعكس حالة LED (HIGH → LOW أو LOW → HIGH) |
| بين التغييرات | `loop()` تعمل بحرية دون أي توقف |

---

## 🆚 delay() vs millis()

| `delay()` | `millis()` |
|-----------|-----------|
| يجمّد البرنامج كاملاً | البرنامج يستمر بالعمل |
| لا يمكن تنفيذ كود آخر أثناء الانتظار | يمكن تشغيل مهام متعددة بالتوازي |
| مناسب للمشاريع البسيطة | مناسب للمشاريع المتقدمة |

---

## 🔗 Code

```cpp
unsigned long t1 = 0, t2 = 0;
bool s = 0;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  t1 = millis();
  if (t1 > t2 + 500) {
    s = !s;
    digitalWrite(13, s);
    t2 = t1;
  }
}
```

---

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل LED على pin 13 مع مقاومة 220Ω
3. انسخ الكود والصقه في المحرر
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. راقب LED يومض كل 500ms بدون أي `delay()`

---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
