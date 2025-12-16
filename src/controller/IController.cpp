#include "include/controller/IController.h"
#include "include/model/Document.h"
#include "include/view/IView.h"
#include <iostream>
#include <fstream>

// ============================================================================
// VectorEditorController Implementation
// ============================================================================

VectorEditorController::VectorEditorController(std::shared_ptr<IView> view)
    : view(view), primitiveIdCounter(0) {
    if (!view) {
        std::cerr << "[ERROR] Контроллер инициализирован с nullptr view" << std::endl;
    }
    std::cout << "[LOG] VectorEditorController инициализирован" << std::endl;
}

void VectorEditorController::createNewDocument(const std::string& documentName) {
    currentDocument = std::make_shared<Document>(documentName);
    primitiveIdCounter = 0;
    
    if (view) {
        view->showSuccess("Новый документ '" + documentName + "' создан");
    }
}

void VectorEditorController::openDocument(const std::string& filePath) {
    // Минимальная реализация для демонстрации
    std::cout << "[LOG] Попытка открыть документ из файла: " << filePath << std::endl;
    
    std::ifstream file(filePath);
    if (!file.is_open()) {
        if (view) {
            view->showError("Не удалось открыть файл: " + filePath);
        }
        return;
    }
    
    // Создаем новый документ с названием файла
    currentDocument = std::make_shared<Document>(filePath);
    file.close();
    
    if (view) {
        view->showSuccess("Документ загружен из файла: " + filePath);
    }
}

void VectorEditorController::saveDocument(const std::string& filePath) {
    if (!currentDocument) {
        if (view) {
            view->showError("Нет открытого документа для сохранения");
        }
        return;
    }
    
    // Минимальная реализация для демонстрации
    std::ofstream file(filePath);
    if (!file.is_open()) {
        if (view) {
            view->showError("Не удалось создать файл: " + filePath);
        }
        return;
    }
    
    std::cout << "[LOG] Сохраняем документ №" << currentDocument->getId() 
              << " в файл: " << filePath << std::endl;
    
    file << "Document: " << currentDocument->getName() << std::endl;
    file << "Primitives: " << currentDocument->getPrimitiveCount() << std::endl;
    file.close();
    
    if (view) {
        view->showSuccess("Документ сохранен в: " + filePath);
    }
}

void VectorEditorController::addCircle(double radius) {
    if (!currentDocument) {
        if (view) {
            view->showError("Нет открытого документа. Создайте новый документ");
        }
        return;
    }
    
    auto circle = std::make_shared<Circle>(++primitiveIdCounter, radius);
    currentDocument->addPrimitive(circle);
    
    if (view) {
        view->showSuccess("Круг добавлен: радиус = " + std::to_string(radius));
    }
}

void VectorEditorController::addRectangle(double width, double height) {
    if (!currentDocument) {
        if (view) {
            view->showError("Нет открытого документа. Создайте новый документ");
        }
        return;
    }
    
    auto rectangle = std::make_shared<Rectangle>(++primitiveIdCounter, width, height);
    currentDocument->addPrimitive(rectangle);
    
    if (view) {
        view->showSuccess("Прямоугольник добавлен: " + std::to_string(width) + 
                         " x " + std::to_string(height));
    }
}

void VectorEditorController::addLine(double x1, double y1, double x2, double y2) {
    if (!currentDocument) {
        if (view) {
            view->showError("Нет открытого документа. Создайте новый документ");
        }
        return;
    }
    
    auto line = std::make_shared<Line>(++primitiveIdCounter, x1, y1, x2, y2);
    currentDocument->addPrimitive(line);
    
    if (view) {
        view->showSuccess("Линия добавлена: (" + std::to_string(x1) + ", " + 
                         std::to_string(y1) + ") -> (" + std::to_string(x2) + 
                         ", " + std::to_string(y2) + ")");
    }
}

void VectorEditorController::removePrimitive(int primitiveId) {
    if (!currentDocument) {
        if (view) {
            view->showError("Нет открытого документа");
        }
        return;
    }
    
    if (currentDocument->removePrimitive(primitiveId)) {
        if (view) {
            view->showSuccess("Примитив №" + std::to_string(primitiveId) + " удален");
        }
    } else {
        if (view) {
            view->showError("Примитив №" + std::to_string(primitiveId) + " не найден");
        }
    }
}

void VectorEditorController::displayDocument() {
    if (!currentDocument) {
        if (view) {
            view->showError("Нет открытого документа для отображения");
        }
        return;
    }
    
    if (view) {
        view->displayDocument(currentDocument);
        view->showDocumentInfo(currentDocument->getDocumentInfo());
    }
}

std::shared_ptr<Document> VectorEditorController::getCurrentDocument() const {
    return currentDocument;
}