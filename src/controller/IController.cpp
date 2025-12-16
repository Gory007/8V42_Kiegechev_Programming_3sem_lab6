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
        std::cerr << "[ERROR] Controller initialized with nullptr view" << std::endl;
    }
    std::cout << "[LOG] VectorEditorController initialized" << std::endl;
}

void VectorEditorController::createNewDocument(const std::string& documentName) {
    currentDocument = std::make_shared<Document>(documentName);
    primitiveIdCounter = 0;
    
    if (view) {
        view->showSuccess("New document '" + documentName + "' created");
    }
}

void VectorEditorController::openDocument(const std::string& filePath) {
    // Minimal implementation for demonstration
    std::cout << "[LOG] Attempting to open document from file: " << filePath << std::endl;
    
    std::ifstream file(filePath);
    if (!file.is_open()) {
        if (view) {
            view->showError("Failed to open file: " + filePath);
        }
        return;
    }
    
    // Create new document with file name
    currentDocument = std::make_shared<Document>(filePath);
    file.close();
    
    if (view) {
        view->showSuccess("Document loaded from file: " + filePath);
    }
}

void VectorEditorController::saveDocument(const std::string& filePath) {
    if (!currentDocument) {
        if (view) {
            view->showError("No open document to save");
        }
        return;
    }
    
    // Minimal implementation for demonstration
    std::ofstream file(filePath);
    if (!file.is_open()) {
        if (view) {
            view->showError("Failed to create file: " + filePath);
        }
        return;
    }
    
    std::cout << "[LOG] Saving document #" << currentDocument->getId() 
              << " to file: " << filePath << std::endl;
    
    file << "Document: " << currentDocument->getName() << std::endl;
    file << "Primitives: " << currentDocument->getPrimitiveCount() << std::endl;
    file.close();
    
    if (view) {
        view->showSuccess("Document saved to: " + filePath);
    }
}

void VectorEditorController::addCircle(double radius) {
    if (!currentDocument) {
        if (view) {
            view->showError("No open document. Create new document first");
        }
        return;
    }
    
    auto circle = std::make_shared<Circle>(++primitiveIdCounter, radius);
    currentDocument->addPrimitive(circle);
    
    if (view) {
        view->showSuccess("Circle added: radius = " + std::to_string(radius));
    }
}

void VectorEditorController::addRectangle(double width, double height) {
    if (!currentDocument) {
        if (view) {
            view->showError("No open document. Create new document first");
        }
        return;
    }
    
    auto rectangle = std::make_shared<Rectangle>(++primitiveIdCounter, width, height);
    currentDocument->addPrimitive(rectangle);
    
    if (view) {
        view->showSuccess("Rectangle added: " + std::to_string(width) + 
                         " x " + std::to_string(height));
    }
}

void VectorEditorController::addLine(double x1, double y1, double x2, double y2) {
    if (!currentDocument) {
        if (view) {
            view->showError("No open document. Create new document first");
        }
        return;
    }
    
    auto line = std::make_shared<Line>(++primitiveIdCounter, x1, y1, x2, y2);
    currentDocument->addPrimitive(line);
    
    if (view) {
        view->showSuccess("Line added: (" + std::to_string(x1) + ", " + 
                         std::to_string(y1) + ") -> (" + std::to_string(x2) + 
                         ", " + std::to_string(y2) + ")");
    }
}

void VectorEditorController::removePrimitive(int primitiveId) {
    if (!currentDocument) {
        if (view) {
            view->showError("No open document");
        }
        return;
    }
    
    if (currentDocument->removePrimitive(primitiveId)) {
        if (view) {
            view->showSuccess("Primitive #" + std::to_string(primitiveId) + " removed");
        }
    } else {
        if (view) {
            view->showError("Primitive #" + std::to_string(primitiveId) + " not found");
        }
    }
}

void VectorEditorController::displayDocument() {
    if (!currentDocument) {
        if (view) {
            view->showError("No open document to display");
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