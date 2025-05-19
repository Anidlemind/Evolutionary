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