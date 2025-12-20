#include "include/model/Document.h"
#include <iostream>

// Document static counter initialization
int Document::documentCounter = 0;



Document::Document(const std::string& name)
    : documentName(name) {
    documentId = ++documentCounter;
    std::cout << "[LOG] Document #" << documentId 
              << " created with name '" << documentName << "'" << std::endl;
}

Document::~Document() {
    std::cout << "[LOG] Document #" << documentId << " deleted" << std::endl;
}

int Document::getId() const {
    return documentId;
}

std::string Document::getName() const {
    return documentName;
}

void Document::setName(const std::string& name) {
    documentName = name;
    std::cout << "[LOG] Document #" << documentId 
              << " renamed to '" << documentName << "'" << std::endl;
}

void Document::addPrimitive(std::shared_ptr<Primitive> primitive) {
    if (!primitive) {
        std::cout << "[ERROR] Attempt to add nullptr primitive" << std::endl;
        return;
    }
    primitives.push_back(primitive);
    std::cout << "[LOG] Added primitive " << primitive->getType() 
              << " #" << primitive->getId() << " to document #" << documentId << std::endl;
}

bool Document::removePrimitive(int primitiveId) {
    auto it = primitives.begin();
    while (it != primitives.end()) {
        if ((*it)->getId() == primitiveId) {
            std::cout << "[LOG] Removed primitive #" << primitiveId 
                      << " from document #" << documentId << std::endl;
            primitives.erase(it);
            return true;
        }
        ++it;
    }
    std::cout << "[ERROR] Primitive #" << primitiveId 
              << " not found in document #" << documentId << std::endl;
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
    std::cout << "\n========== Document #" << documentId 
              << " '" << documentName << "' Drawing ==========" << std::endl;
    std::cout << "Number of primitives: " << primitives.size() << std::endl;
    
    for (const auto& prim : primitives) {
        prim->draw();
    }
    
    std::cout << "========== End of Drawing ==========" << std::endl << std::endl;
}

std::string Document::getDocumentInfo() const {
    std::string info = "Document #" + std::to_string(documentId) + 
                      " '" + documentName + "' contains " + 
                      std::to_string(primitives.size()) + " primitive(s):\n";
    
    for (const auto& prim : primitives) {
        info += "  - " + prim->getInfo() + "\n";
    }
    
    return info;
}

void Document::clear() {
    primitives.clear();
    std::cout << "[LOG] Document #" << documentId << " cleared" << std::endl;
}