Данная работа содержит пример простейшего приложения на многопроцессорность 
Приложение написано на С++ с использованием Windows API

Алгоритм работы:
1. В начале задается количество процессов
2. Затем функция Windows API CreateProcess используется для создания указанного количества дочерних процессов в Windows. Каждый процесс может выполнять свою собственную логику
   В CreateProcess передается:

            L"path", // путь к программе

            nullptr, // Аргументы командной строки (при необходимости)

            nullptr, // Атрибуты процесса

            nullptr, // Атрибуты потока

            FALSE,   // Наследовать дескрипторы

            0,       // Флаги создания

            nullptr, // Среда (по умолчанию - текущая среда)

            nullptr, // Текущий каталог (по умолчанию - текущий каталог)

            &si,     // STARTUPINFO

            &pi      // PROCESS_INFORMATION

3. Выводится сообщение об успешном создании процесса, либо если произошла ошибка, выводится сообщение об ошибке
