#include <windows.h>
#include <iostream>

int main() {
    int num_processes = 4; // Количество процессов

    for (int i = 0; i < num_processes; ++i) {
        STARTUPINFO si = {};
        PROCESS_INFORMATION pi = {};

        if (CreateProcess(
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
        )) {
            std::wcout << L"Child process created: " << pi.dwProcessId << std::endl;
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
        else {
            DWORD error = GetLastError();
            std::cerr << "Error creating process. Code: " << error << std::endl;
            return 1;
        }
    }

    return 0;
}