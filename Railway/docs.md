## Второе задание
1. Взять одну из жд веток Таджикистана, например, Душанбе-Пахтаабад или Душанбе-Куляб или какие-то маршруты около Худжанда.
2. Написать Си++ программу, соответствующую следующим условиям:
- Поезда стартуют из различных пунктов по своему маршруту. 
- Каждый поезд - это поток, у него должен быть уникальный номер. Минимальное количество поездов - 8 (то есть 8 потоков)
- Одновременно на станции должен быть только один поезд (то есть это ресурс, который блокируется). Другой поезд в это время не может заехать и ждёт очереди
- Все события (отбытия-прибытия поездов) должны логироваться в консоль с использованием текущего времени
- Перемещение между станциями не должно быть мгновенным. Назначьте разумные временные промежутки в течение которых поезд проезжает от одной станции к другой

### Решение
Файл: trains.cpp
Станции - это структуры с информацией о том, какие станции в какую сторону и как долго туда добираться. А потоки запускают функцию, по которой они начинают рекурсивно обходить все станции.

Для блокировки станций используется mutex, причём у каждой станции он свой.

Использованный маршрут с расстояниями в км:
Душанбе-1 - 8 - Рохаты - 14 - Вахдат - 5 - Иляк - 40 - Яван - 37 - Вахш - 19 - Курган-Тюбе - 26 - Сангтуда - 26 - Дангара - 20 - Олимтой - 32 - Курбоншахид - 27 - Куляб
 
Вывод программы:
```cmd
Kurgan-Tube - Train 7 at 13:00:57 station.
Olimtoy - Train 4 at 13:00:57 station.
Vahdat - Train 3 at 13:00:57 station.
Yavan - Train 5 at 13:00:57 station.
Dushanbe-1 - Train 1 at 13:00:57 station.
Kulab - Train 2 at 13:00:57 station.
Dangara - Train 6 at 13:00:57 station.
Sangtuda - Train 8 at 13:00:57 station.
Ilyak - Train 3 at 13:00:58 station.
Rokhata - Train 1 at 13:00:58 station.
Vahdat - Train 1 at 13:00:59 station.
Kurgan-Tube - Train 8 at 13:01:00 station.
Sangtuda - Train 7 at 13:01:00 station.
Dangara - Train 4 at 13:01:00 station.
Kurbonshahid - Train 2 at 13:01:00 station.
Vahsh - Train 5 at 13:01:01 station.
Yavan - Train 3 at 13:01:02 station.
Ilyak - Train 1 at 13:01:02 station.
Sangtuda - Train 6 at 13:01:02 station.
Dangara - Train 7 at 13:01:02 station.
Vahsh - Train 8 at 13:01:03 station.
Kurgan-Tube - Train 5 at 13:01:03 station.
Olimtoy - Train 2 at 13:01:03 station.
Sangtuda - Train 4 at 13:01:05 station.
Olimtoy - Train 7 at 13:01:05 station.
Dangara - Train 2 at 13:01:05 station.
Kurgan-Tube - Train 6 at 13:01:05 station.
Yavan - Train 1 at 13:01:06 station.
```
