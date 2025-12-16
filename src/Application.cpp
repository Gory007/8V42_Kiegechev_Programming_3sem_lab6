#include "include/Application.h"
#include "include/controller/IController.h"
#include "include/view/IView.h"
#include <iostream>

// ============================================================================
// Application Implementation
// ============================================================================

Application::Application() {
    std::cout << "[LOG] Приложение инициализируется..." << std::endl;
}

Application::~Application() {
    std::cout << "[LOG] Приложение завершает работу" << std::endl;
}

void Application::initialize() {
    // Создание View (консольное представление)
    view = std::make_shared<ConsoleView>();
    std::cout << "[LOG] ConsoleView создан" << std::endl;
    
    // Создание Controller с привязкой к View
    controller = std::make_shared<VectorEditorController>(view);
    std::cout << "[LOG] VectorEditorController создан и привязан к View" << std::endl;
    
    std::cout << "[LOG] Приложение успешно инициализировано (MVC архитектура готова)" << std::endl;
}

void Application::run() {
    std::cout << "\n╔══════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║     ДЕМОНСТРАЦИЯ ВЕКТОРНОГО РЕДАКТОРА (MVC)          ║" << std::endl;
    std::cout << "║            Принципы SOLID и DRY                      ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════════╝\n" << std::endl;
    
    if (!controller) {
        std::cerr << "[ERROR] Контроллер не инициализирован" << std::endl;
        return;
    }
    
    // ========== ДЕМОНСТРАЦИЯ 1: Создание документа ==========
    std::cout << "\n>>> Шаг 1: Создание нового документа" << std::endl;
    controller->createNewDocument("Мой первый вектор");
    
    // ========== ДЕМОНСТРАЦИЯ 2: Добавление примитивов ==========
    std::cout << "\n>>> Шаг 2: Добавление графических примитивов" << std::endl;
    
    controller->addCircle(5.0);
    controller->addCircle(10.0);
    controller->addRectangle(20.0, 15.0);
    controller->addRectangle(30.0, 25.0);
    controller->addLine(0.0, 0.0, 100.0, 100.0);
    controller->addLine(50.0, 50.0, 150.0, 75.0);
    
    // ========== ДЕМОНСТРАЦИЯ 3: Отображение документа ==========
    std::cout << "\n>>> Шаг 3: Отображение содержимого документа" << std::endl;
    controller->displayDocument();
    
    // ========== ДЕМОНСТРАЦИЯ 4: Удаление примитива ==========
    std::cout << "\n>>> Шаг 4: Удаление примитива №3" << std::endl;
    controller->removePrimitive(3);
    
    // ========== ДЕМОНСТРАЦИЯ 5: Повторное отображение ==========
    std::cout << "\n>>> Шаг 5: Повторное отображение документа после удаления" << std::endl;
    controller->displayDocument();
    
    // ========== ДЕМОНСТРАЦИЯ 6: Сохранение документа ==========
    std::cout << "\n>>> Шаг 6: Сохранение документа в файл" << std::endl;
    controller->saveDocument("document_output.txt");
    
    // ========== ДЕМОНСТРАЦИЯ 7: Создание второго документа ==========
    std::cout << "\n>>> Шаг 7: Создание второго документа" << std::endl;
    controller->createNewDocument("Второй документ");
    controller->addCircle(8.0);
    controller->addRectangle(40.0, 30.0);
    controller->displayDocument();
    
    // ========== ИТОГИ ==========
    std::cout << "\n╔══════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║              ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА                   ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════════╝\n" << std::endl;
}

std::shared_ptr<IController> Application::getController() const {
    return controller;
}

std::shared_ptr<IView> Application::getView() const {
    return view;
}