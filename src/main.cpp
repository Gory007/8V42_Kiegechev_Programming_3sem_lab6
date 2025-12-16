#include "include/Application.h"
#include <iostream>
#include <windows.h>

/**
 * @file main.cpp
 * @brief Точка входа приложения - Векторный редактор (MVC архитектура)
 * 
 * Это основной файл, который демонстрирует:
 * - Инициализацию MVC архитектуры
 * - Создание и управление документами
 * - Работу с графическими примитивами
 * - Применение архитектурных принципов (SOLID, DRY, SoC)
 */

int main() {
    try {

        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);


        // Создание экземпляра приложения
        Application app;
        
        // Инициализация MVC компонентов
        app.initialize();
        
        // Запуск демонстрации
        app.run();
        
        std::cout << "Приложение корректно завершило работу." << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Неизвестная ошибка" << std::endl;
        return 1;
    }
}