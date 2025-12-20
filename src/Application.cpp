#include "include/Application.h"
#include "include/controller/IController.h"
#include "include/view/IView.h"
#include <iostream>


// Application Implementation

Application::Application() {
    std::cout << "[LOG] Application initialization..." << std::endl;
}

Application::~Application() {
    std::cout << "[LOG] Application shutdown" << std::endl;
}

void Application::initialize() {
    // Create View (console representation)
    view = std::make_shared<ConsoleView>();
    std::cout << "[LOG] ConsoleView created" << std::endl;
    
    // Create Controller with View binding
    controller = std::make_shared<VectorEditorController>(view);
    std::cout << "[LOG] VectorEditorController created and bound to View" << std::endl;
    
    std::cout << "[LOG] Application successfully initialized" << std::endl;
}

void Application::run() {
    std::cout << "\n====================================================" << std::endl;
    std::cout << "     VECTOR EDITOR DEMONSTRATION" << std::endl;
    std::cout << "====================================================" << std::endl << std::endl;
    
    if (!controller) {
        std::cerr << "[ERROR] Controller not initialized" << std::endl;
        return;
    }
    
    // ========== DEMONSTRATION 1: Create document ==========
    std::cout << "\n>>> Step 1: Create new document" << std::endl;
    controller->createNewDocument("My First Vector");
    
    // ========== DEMONSTRATION 2: Add primitives ==========
    std::cout << "\n>>> Step 2: Add graphic primitives" << std::endl;
    
    controller->addCircle(5.0);
    controller->addCircle(10.0);
    controller->addRectangle(20.0, 15.0);
    controller->addRectangle(30.0, 25.0);
    controller->addLine(0.0, 0.0, 100.0, 100.0);
    controller->addLine(50.0, 50.0, 150.0, 75.0);
    
    // ========== DEMONSTRATION 3: Display document ==========
    std::cout << "\n>>> Step 3: Display document content" << std::endl;
    controller->displayDocument();
    
    // ========== DEMONSTRATION 4: Remove primitive ==========
    std::cout << "\n>>> Step 4: Remove primitive number 3" << std::endl;
    controller->removePrimitive(3);
    
    // ========== DEMONSTRATION 5: Display again ==========
    std::cout << "\n>>> Step 5: Display document after removal" << std::endl;
    controller->displayDocument();
    
    // ========== DEMONSTRATION 6: Save document ==========
    std::cout << "\n>>> Step 6: Save document to file" << std::endl;
    controller->saveDocument("document_output.txt");
    
    // ========== DEMONSTRATION 7: Create second document ==========
    std::cout << "\n>>> Step 7: Create second document" << std::endl;
    controller->createNewDocument("Second Document");
    controller->addCircle(8.0);
    controller->addRectangle(40.0, 30.0);
    controller->displayDocument();
    
    // ========== SUMMARY ==========
    std::cout << "\n====================================================" << std::endl;
    std::cout << "              DEMONSTRATION COMPLETED" << std::endl;
    std::cout << "====================================================" << std::endl << std::endl;
}

std::shared_ptr<IController> Application::getController() const {
    return controller;
}

std::shared_ptr<IView> Application::getView() const {
    return view;
}