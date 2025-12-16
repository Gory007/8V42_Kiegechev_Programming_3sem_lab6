#include "include/view/IView.h"
#include "include/model/Document.h"
#include <iostream>

// ============================================================================
// ConsoleView Implementation
// ============================================================================

void ConsoleView::displayDocument(const std::shared_ptr<Document>& document) {
    if (!document) {
        showError("Document is not initialized");
        return;
    }
    
    std::cout << "\n====================================================" << std::endl;
    std::cout << "         DOCUMENT DISPLAY" << std::endl;
    std::cout << "====================================================" << std::endl;
    
    document->drawAll();
}

void ConsoleView::showDocumentInfo(const std::string& info) {
    std::cout << "\n========== DOCUMENT INFORMATION ==========" << std::endl;
    std::cout << info << std::endl;
}

void ConsoleView::showError(const std::string& errorMsg) {
    std::cout << "\n[ERROR]: " << errorMsg << std::endl;
}

void ConsoleView::showSuccess(const std::string& message) {
    std::cout << "\n[OK]: " << message << std::endl;
}

void ConsoleView::clear() {
    // Clear console (cross-platform)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "Console cleared" << std::endl;
}