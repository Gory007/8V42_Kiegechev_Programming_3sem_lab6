#include "include/model/Document.h"
#include <iostream>

// Инициализация статического счетчика документов
int Document::documentCounter = 0;

// ============================================================================
// Document Implementation
// ============================================================================

Document::Document(const std::string& name)
    : documentName(name) {
    documentId = ++documentCounter;
    std::cout << "[LOG] Создан документ №" << documentId 
              << " с именем '" << documentName << "'" << std::endl;
}

Document::~Document() {
    std::cout << "[LOG] Документ №" << documentId << " удален" << std::endl;
}

int Document::getId() const {
    return documentId;
}

std::string Document::getName() const {
    return documentName;
}

void Document::setName(const std::string& name) {
    documentName = name;
    std::cout << "[LOG] Документ №" << documentId 
              << " переименован на '" << documentName << "'" << std::endl;
}

void Document::addPrimitive(std::shared_ptr<Primitive> primitive) {
    if (!primitive) {
        std::cout << "[ERROR] Попытка добавить nullptr примитив" << std::endl;
        return;
    }
    primitives.push_back(primitive);
    std::cout << "[LOG] В документ №" << documentId 
              << " добавлен примитив " << primitive->getType() 
              << " №" << primitive->getId() << std::endl;
}

bool Document::removePrimitive(int primitiveId) {
    auto it = primitives.begin();
    while (it != primitives.end()) {
        if ((*it)->getId() == primitiveId) {
            std::cout << "[LOG] Из документа №" << documentId 
                      << " удален примитив №" << primitiveId << std::endl;
            primitives.erase(it);
            return true;
        }
        ++it;
    }
    std::cout << "[ERROR] Примитив №" << primitiveId 
              << " не найден в документе №" << documentId << std::endl;
    return false;
}

std::shared_ptr<Primitive> Document::getPrimitive(int primitiveId) const {
    for (const auto& prim : primitives) {
        if (prim->getId() == primitiveId) {
            return prim;
        }
    }
    return nullptr;
}

const std::vector<std::shared_ptr<Primitive>>& Document::getAllPrimitives() const {
    return primitives;
}

size_t Document::getPrimitiveCount() const {
    return primitives.size();
}

void Document::drawAll() const {
    std::cout << "\n========== Отрисовка документа №" << documentId 
              << " '" << documentName << "' ==========" << std::endl;
    std::cout << "Количество примитивов: " << primitives.size() << std::endl;
    
    for (const auto& prim : primitives) {
        prim->draw();
    }
    
    std::cout << "========== Конец отрисовки ==========" << std::endl << std::endl;
}

std::string Document::getDocumentInfo() const {
    std::string info = "Документ №" + std::to_string(documentId) + 
                      " '" + documentName + "' содержит " + 
                      std::to_string(primitives.size()) + " примитив(ов):\n";
    
    for (const auto& prim : primitives) {
        info += "  - " + prim->getInfo() + "\n";
    }
    
    return info;
}

void Document::clear() {
    primitives.clear();
    std::cout << "[LOG] Документ №" << documentId << " очищен" << std::endl;
}