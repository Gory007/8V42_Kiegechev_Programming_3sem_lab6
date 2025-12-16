#ifndef IVIEW_H
#define IVIEW_H

#include <memory>
#include <string>

class Document;

/**
 * @class IView
 * @brief Интерфейс для представления (View)
 * 
 * Определяет контракт для любой реализации представления
 * Соответствует принципу Interface Segregation (SOLID)
 */
class IView {
public:
    virtual ~IView() = default;

    /**
     * @brief Отобразить документ
     */
    virtual void displayDocument(const std::shared_ptr<Document>& document) = 0;

    /**
     * @brief Показать информацию о документе
     */
    virtual void showDocumentInfo(const std::string& info) = 0;

    /**
     * @brief Показать сообщение об ошибке
     */
    virtual void showError(const std::string& errorMsg) = 0;

    /**
     * @brief Показать сообщение об успехе
     */
    virtual void showSuccess(const std::string& message) = 0;

    /**
     * @brief Очистить представление
     */
    virtual void clear() = 0;
};

/**
 * @class ConsoleView
 * @brief Консольная реализация представления
 * 
 * Выводит информацию в консоль (для демонстрации)
 */
class ConsoleView : public IView {
public:
    ConsoleView() = default;
    ~ConsoleView() override = default;

    void displayDocument(const std::shared_ptr<Document>& document) override;
    void showDocumentInfo(const std::string& info) override;
    void showError(const std::string& errorMsg) override;
    void showSuccess(const std::string& message) override;
    void clear() override;
};

#endif // IVIEW_H