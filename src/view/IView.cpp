#include "include/view/IView.h"
#include "include/model/Document.h"
#include <iostream>

// ============================================================================
// ConsoleView Implementation
// ============================================================================

void ConsoleView::displayDocument(const std::shared_ptr<Document>& document) {
    if (!document) {
        showError("Документ не инициализирован");
        return;
    }
    
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        ОТОБРАЖЕНИЕ ДОКУМЕНТА              ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    document->drawAll();
}

void ConsoleView::showDocumentInfo(const std::string& info) {
    std::cout << "\n┌────────────────────────────────────────┐" << std::endl;
    std::cout << "│          ИНФОРМАЦИЯ О ДОКУМЕНТЕ        │" << std::endl;
    std::cout << "└────────────────────────────────────────┘" << std::endl;
    std::cout << info << std::endl;
}

void ConsoleView::showError(const std::string& errorMsg) {
    std::cout << "\n❌ [ОШИБКА]: " << errorMsg << std::endl;
}

void ConsoleView::showSuccess(const std::string& message) {
    std::cout << "\n✓ [УСПЕХ]: " << message << std::endl;
}

void ConsoleView::clear() {
    // Очистка консоли (кроссплатформенно)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "Консоль очищена" << std::endl;
}