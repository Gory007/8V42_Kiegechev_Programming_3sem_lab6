#include "include/Application.h"
#include <iostream>

/**
 * @file main.cpp
 * @brief Точка входа приложения - Векторный редактор
 * 
 */

int main() {
    try {

        // Создание экземпляра приложения
        Application app;
        
        // Инициализация компонентов
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