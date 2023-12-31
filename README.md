# digital-signal-processing

## Технологии и ограничения:
- Языки программирования: Java, Python, C++;
- Дополнительные библиотеки: Apache math3;

## Общие требования по выполнению:
1. Код должен быть написан понятно и аккуратно, с соблюдением табуляции и прочих элементов написания, без лишних элементов и функций, не имеющих отношения к функционалу тестового задания, снабжен понятными комментариями.
2. Чистота и оформление кода — не менее важный фактор. Код должен быть написан в едином стиле (желательно в рекомендуемом для конкретного языка). Также к чистоте относятся отсутствие копипаста и дублирования логики.
3. Исходные коды должны быть в Git. Желательно делать частые информативные коммиты, активно использовать ветки.
4. Должна быть инструкция по сборке и разворачиванию, а также должен быть описан порядок развертывания и запуска проекта в среде разработки (включая настройку БД, дамп схемы БД, настройку сервера приложения для запуска и т.д.)
5. Сервисы (серверная часть) должны быть максимально покрыты модульными тестами
6. Интерфейс должен отвечать требованиям usability

## Зависимости
Для С++ присутствует единственная зависимость The Fastest Fourier Transform in the West (FFTW) - это библиотека для вычисления дискретного преобразования Фурье (ДПФ) в одном или нескольких измерениях, произвольного входного размера и как действительных, так и комплексных данных(а также четных/нечетных данных, то есть дискретных косинусных/синусных преобразований). Для Python, который используется для визуализации данных требуется matplotlib.

## Сборка
Необходимо заранее установить самостоятельно FFTW и matplotlib перед сборкой проекта
```
mkdir build
cd build
cmake ..
make
```

## Запуск
Для запуска необходимо запустить исполняемый файл digital-signal-processing/digital-signal-processing.exe и выполнить run-plotter.sh/run-plotter.cmd, которому при необходимости выдать права на исполнение с помощью команды
```
chmod +x run-plotter.sh
```

## Выполнение работы
* **NoiseGenerator, NoiseSignalGenerator, SignalFunction, и SignalGenerate**
  * Сигналы генерируются по формуле:
    $$ A\sin{\pi t * \nu + offset}, $$
    где t - время, A - амплитуда, $\nu$ - частота, $offset$ - сдвиг.

* **WindowingFilter**
  * Сглаживание скользящим окном происходит по формуле:
    $$ x_i = \frac{\sum\limits_{j = i - w}^{i + w} x_j}{w}, $$
    где $x_i$ - i-ый элемент, w - размер окна сглаживания.

  * Также отдельно рассматриваются случаи, когда размер окна слева или справа больше количества элементов.

* **AutocorrelationFunction, FFTAutoCorrelation и RingShiftFunction**
  * Кольцевая автокорреляция вычисляется с помощью:
    $$ cross_correlation = (product - mean_original * mean_shifted) / (rms_original * rms_shifted), $$
    где $product$ - это сумма произведений элементов соответствующих сигналов, $mean\_original$ и $mean\_shifted$ - средние значения элементов в каждом сигнале, $rms\_original$ и $rms\_shifted$ - среднеквадратичные значения элементов в каждом сигнале.

  * Автокорреляционная функция с использованием быстрого преобразования Фурье (БПФ) использует формулы:
    $$ \Phi(\tau) = Re fft^{-1}(|fft(\Vec{x})|^2), $$
    где fft и $fft^{-1}$ - прямое и обратное БПФ, Re - вещественная часть комплексного числа.

  * Также необходима формула вычисления комплексного модуля:
    $$ |\Vec{a}|^2 = {Re^2a_i + Im^2a_i}, $$
    где Re и Im - вещественная и мнимая части комплексного числа.

  * Если нет погрешностей вычисления, мнимая часть будет равна нулю. Также необходимо поделить на коэффициент пропорциональности $\Phi(0)$.

  * Однако перед всем этим необходимо вычесть из ряда среднее арифметическое и преобразовать в комплексные числа. После дополнить нулями до $2^k$. Затем дописать в конец ещё $2^k$ нулей.

* **DistributionFunction**
  * Стандартная реализация функции распределения, заданная по формуле:
    $$ F(x) = P(X < x), $$
    где X - величина сигнала.


## Пример работы программы

Результат работы программы можно наглядно продемонстрировать на графиках

### CLI интерфейс
![image](assets/pics/cli/cli.jpg)
### Сгенерированный сигнал
![image](assets/pics/plotters/signal.jpg)
### Фильтрация на основе скользящего окна
![image](assets/pics/plotters/filter.jpg)
### Автокорреляционная функция
![image](assets/pics/plotters/autocorr.jpg)
### Функция распределения
![image](assets/pics/plotters/dist.jpg)

### Примечание
Числовые значения отработанных функций передаются в файл result.txt по умолчанию
