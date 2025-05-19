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

Было получено задание добавления функционала получения идеального времени в пути. Реализация - функция `IdealTime()`. Дополнительно расширился класс TContainer функцией `Get(int)`, аналогом `.at(int)`. Добавлены тесты, как на функцию `IdealTime()`, так и на `Get(int)`, дополнен ожидаемый результат вывода в тесте `ReadAndPrint` в файле `testcontainer.cpp`.

## Новые Зависимости Артефактов

Новых зависимостей нет

## Изменения в Модульной Структуре

Изменений в Модульной Структуре нет

## Тесты

Добавлены новые тесты внутри `testtransport.cpp` и `testcontainer.cpp`.

# Task 4

## Описание

Было получено задание добавления нового поля Вес для транспорта. Что привело к изменению в тестах, функциях вывода каждого из реализуемых классов транспорта.

# Task 5

## Описание

Было получено задание добавления функции вывода только для Самолетов внутри Контейнера. Добавлена функция `PrintAirplanes(std::ostream&)`, `enum Type` типов транспортных средств внутри `transport.h` и функция `GetType()`, возвращающая этот самый тип. Добавлен тест на функцию `PrintAirplanes(std::ostream&)`.

## Новые Зависимости Артефактов

| Артефакт | Прямая зависимость | Косвенная зависимость |
|-------------|-------------|-------------|
|TAirplane::GetType|ITransport::Type||
|TTrain::GetType|ITransport::Type||
|TBoat::GetType|ITransport::Type||
|ITransport::GetType|TAirplane::GetType, TTrain::GetType, TBoat::GetType

## Изменения в Структуре Модулей

Добавлен новый модуль `container_airplanes.cpp`, реализующий функцию `PrintAirplanes`, является косвенно подключенным к `main.cpp`