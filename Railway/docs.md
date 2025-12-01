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
Kulab - Train 3 at 11:51:51 station.
Vahdat - Train 4 at 11:51:51 station.
Yavan - Train 6 at 11:51:51 station.
Olimtoy - Train 5 at 11:51:51 station.
Dushanbe-1 - Train 2 at 11:51:51 station.
Dangara - Train 7 at 11:51:51 station.
Kurgan-Tube - Train 8 at 11:51:51 station.
Sangtuda - Train 9 at 11:51:51 station.
Ilyak - Train 4 at 11:51:52 station.
Rokhata - Train 2 at 11:51:52 station.
Vahdat - Train 2 at 11:51:53 station.
Sangtuda - Train 7 at 11:51:54 station.
Dangara - Train 5 at 11:51:54 station.
Kurgan-Tube - Train 9 at 11:51:54 station.
Kurbonshahid - Train 3 at 11:51:54 station.
Vahsh - Train 6 at 11:51:55 station.
Ilyak - Train 2 at 11:51:56 station.
Yavan - Train 4 at 11:51:56 station.
Kurgan-Tube - Train 7 at 11:51:56 station.
Sangtuda - Train 8 at 11:51:56 station.
Vahsh - Train 9 at 11:51:57 station.
Olimtoy - Train 3 at 11:51:57 station.
Kurgan-Tube - Train 6 at 11:51:58 station.
Sangtuda - Train 5 at 11:51:59 station.
Dangara - Train 8 at 11:51:59 station.
Yavan - Train 2 at 11:52:00 station.
Vahsh - Train 7 at 11:52:00 station.
Dangara - Train 3 at 11:52:01 station.
Olimtoy - Train 8 at 11:52:01 station.
Kurgan-Tube - Train 5 at 11:52:01 station.
Sangtuda - Train 6 at 11:52:01 station.
Yavan - Train 9 at 11:52:03 station.
Vahsh - Train 4 at 11:52:04 station.
Kurbonshahid - Train 8 at 11:52:04 station.
Sangtuda - Train 3 at 11:52:04 station.
Dangara - Train 6 at 11:52:04 station.
Vahsh - Train 2 at 11:52:06 station.
Kurgan-Tube - Train 4 at 11:52:06 station.
Olimtoy - Train 6 at 11:52:06 station.
Kulab - Train 8 at 11:52:07 station.
Yavan - Train 7 at 11:52:07 station.
Ilyak - Train 9 at 11:52:07 station.
Vahdat - Train 9 at 11:52:08 station.
Vahsh - Train 5 at 11:52:08 station.
Kurgan-Tube - Train 3 at 11:52:09 station.
Sangtuda - Train 4 at 11:52:09 station.
Rokhata - Train 9 at 11:52:09 station.
Kurbonshahid - Train 6 at 11:52:09 station.
Dushanbe-1 - Train 9 at 11:52:10 station.
Kurgan-Tube - Train 2 at 11:52:11 station.
Rokhata - Train 9 at 11:52:11 station.
Dangara - Train 4 at 11:52:11 station.
Ilyak - Train 7 at 11:52:11 station.
Yavan - Train 5 at 11:52:12 station.
Vahsh - Train 3 at 11:52:12 station.
Vahdat - Train 7 at 11:52:12 station.
Kulab - Train 6 at 11:52:12 station.
Kurbonshahid - Train 8 at 11:52:12 station.
Sangtuda - Train 2 at 11:52:13 station.
Vahdat - Train 9 at 11:52:13 station.
Rokhata - Train 7 at 11:52:13 station.
Olimtoy - Train 4 at 11:52:13 station.
Ilyak - Train 9 at 11:52:14 station.
Dushanbe-1 - Train 7 at 11:52:14 station.
Rokhata - Train 7 at 11:52:15 station.
Kurbonshahid - Train 6 at 11:52:15 station.
Yavan - Train 3 at 11:52:16 station.
Dangara - Train 2 at 11:52:16 station.
Vahdat - Train 7 at 11:52:16 station.
Olimtoy - Train 8 at 11:52:16 station.
Ilyak - Train 5 at 11:52:18 station.
Ilyak - Train 7 at 11:52:18 station.
Vahdat - Train 5 at 11:52:18 station.
Olimtoy - Train 2 at 11:52:18 station.
Dangara - Train 8 at 11:52:18 station.
Kurbonshahid - Train 4 at 11:52:18 station.
Yavan - Train 9 at 11:52:20 station.
Rokhata - Train 5 at 11:52:20 station.
Dushanbe-1 - Train 5 at 11:52:20 station.
Sangtuda - Train 8 at 11:52:21 station.
Kulab - Train 4 at 11:52:21 station.
Rokhata - Train 5 at 11:52:21 station.
Olimtoy - Train 6 at 11:52:22 station.
Kurbonshahid - Train 2 at 11:52:22 station.
Ilyak - Train 3 at 11:52:22 station.
Vahdat - Train 5 at 11:52:23 station.
Vahdat - Train 3 at 11:52:23 station.
Ilyak - Train 5 at 11:52:23 station.
Yavan - Train 7 at 11:52:23 station.
Vahsh - Train 9 at 11:52:23 station.
Kurgan-Tube - Train 8 at 11:52:24 station.
Dangara - Train 6 at 11:52:24 station.
Kulab - Train 2 at 11:52:24 station.
Kurbonshahid - Train 4 at 11:52:24 station.
Rokhata - Train 3 at 11:52:25 station.
Dushanbe-1 - Train 3 at 11:52:25 station.
Kurgan-Tube - Train 9 at 11:52:26 station.
Vahsh - Train 8 at 11:52:26 station.
Rokhata - Train 3 at 11:52:26 station.
Sangtuda - Train 6 at 11:52:26 station.
Yavan - Train 5 at 11:52:27 station.
Olimtoy - Train 4 at 11:52:28 station.
Kurbonshahid - Train 2 at 11:52:28 station.
Vahdat - Train 3 at 11:52:28 station.
Ilyak - Train 3 at 11:52:28 station.
Sangtuda - Train 9 at 11:52:29 station.
Kurgan-Tube - Train 6 at 11:52:29 station.
Vahsh - Train 7 at 11:52:29 station.
Dangara - Train 4 at 11:52:30 station.
Olimtoy - Train 2 at 11:52:31 station.
Yavan - Train 8 at 11:52:31 station.
Kurgan-Tube - Train 7 at 11:52:31 station.
Vahsh - Train 6 at 11:52:31 station.
Dangara - Train 9 at 11:52:32 station.
Sangtuda - Train 4 at 11:52:32 station.
Olimtoy - Train 9 at 11:52:34 station.
Dangara - Train 2 at 11:52:34 station.
Sangtuda - Train 7 at 11:52:35 station.
Kurgan-Tube - Train 4 at 11:52:35 station.
Ilyak - Train 8 at 11:52:35 station.
Yavan - Train 3 at 11:52:35 station.
Vahsh - Train 5 at 11:52:35 station.
Vahdat - Train 8 at 11:52:35 station.
```
