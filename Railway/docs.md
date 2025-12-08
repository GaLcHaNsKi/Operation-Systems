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
11:58:20 - Train 1 at Dushanbe-1 station.
11:58:20 - Train 7 at Kurgan-Tube station.
11:58:20 - Train 2 at Kulab station.
11:58:20 - Train 4 at Olimtoy station.
11:58:20 - Train 5 at Yavan station.
11:58:20 - Train 3 at Vahdat station.
11:58:20 - Train 6 at Dangara station.
11:58:20 - Train 8 at Sangtuda station.
11:58:21 - Train 3 at Ilyak station.
11:58:21 - Train 1 at Rokhata station.
11:58:22 - Train 1 at Vahdat station.
11:58:23 - Train 4 at Dangara station.
11:58:23 - Train 6 at Sangtuda station.
11:58:23 - Train 8 at Kurgan-Tube station.
11:58:23 - Train 2 at Kurbonshahid station.
11:58:24 - Train 5 at Vahsh station.
11:58:25 - Train 1 at Ilyak station.
11:58:25 - Train 3 at Yavan station.
11:58:25 - Train 4 at Sangtuda station.
11:58:25 - Train 6 at Kurgan-Tube station.
11:58:26 - Train 8 at Vahsh station.
11:58:26 - Train 2 at Olimtoy station.
11:58:27 - Train 5 at Kurgan-Tube station.
11:58:28 - Train 7 at Sangtuda station.
11:58:28 - Train 2 at Dangara station.
11:58:29 - Train 1 at Yavan station.
11:58:30 - Train 6 at Vahsh station.
11:58:30 - Train 4 at Kurgan-Tube station.
11:58:31 - Train 5 at Sangtuda station.
11:58:31 - Train 7 at Dangara station.
11:58:33 - Train 8 at Yavan station.
11:58:33 - Train 7 at Olimtoy station.
```
