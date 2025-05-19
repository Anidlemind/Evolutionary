# Evolutionary programming C++

# Task 1

## Описание

Было получено задание реализации контейнера транспортных средств на базе массива с ограничением по размеру.

## Зависимости Артефактов

| Артефакт | Прямая зависимость | Косвенная зависимость |
|-------------|-------------|-------------|
|TAirplane|||
|TTrain|||
|ITransport|TAirplane, TTrain||
|TAirplane::Read (сигнатура)|||
|TAirplane::Read (тело)|TAirplane||
|TTrain::Read (сигнатура)|||
|TTrain::Read (тело)|TTrain||
|Transport::Read (сигнатура)|||
|Transport::Read (тело)|ITransport [TAirplane, TTrain], TAirplane::Read, TTrain::Read||
|TContainer::Read (сигнатура)|||
|TContainer::Read (тело)|Transport::Read||
|TAirplane::Print (сигнатура)|||
|TAirplane::Print (тело)|TAirplane||
|TTrain::Print (сигнатура)|||
|TTrain::Print (тело)|TTrain||
|Transport::Print (сигнатура)|||
|Transport::Print (тело)|ITransport [TAirplane, TTrain], TAirplane::Print, TTrain::Print||
|TContainer::Print (сигнатура)|||
|TContainer::Print (тело)|Transport::Print||

## Тесты

Все тесты и ожидаемые результаты выполнения описаны внутри папки `tests/`

# Task 2

## Описание

Было получено задание добавления новой альтернативы транспортного средства.
Была добавлена альтернатива Лодка с характеристиками: Вместительность и Количество Мачт.

## Новые Зависимости Артефактов

| Артефакт | Прямая зависимость | Косвенная зависимость |
|-------------|-------------|-------------|
|TBoat||
|ITransport|TBoat||
|TBoat::Read (сигнатура)|||
|TBoat::Read (тело)|TBoat||
|Transport::Read (тело)|ITransport [TBoat], TBoat::Read||
|TBoat::Print (сигнатура)|||
|TBoat::Print (тело)|TBoat||
|Transport::Print (тело)|ITransport [TBoat], TBoat::Print||

## Тесты

Добавлен новый, аналогичный предыдущим, тест в testtransport.cpp 

# Task 3

## Описание

Было получено задание добавления функционала получения идеального времени в пути. Реализация - функция `IdealTime()`. Добавлены тесты, как на функцию `IdealTime()`, дополнен ожидаемый результат вывода в тесте `ReadAndPrint` в файле `testcontainer.cpp`.

## Новые Зависимости Артефактов

| Артефакт | Прямая зависимость | Косвенная зависимость |
|-------------|-------------|-------------|
|IdealTime|ITransport||

## Изменения в Модульной Структуре

Добавлен Модуль `idealtime`, зависящий от `transport`, модуль `container` теперь зависит от `idealtime`

# Task 4

## Описание

Было получено задание добавления нового поля Вес для транспорта. Что привело к изменению в тестах, функциях вывода каждого из реализуемых классов транспорта.
