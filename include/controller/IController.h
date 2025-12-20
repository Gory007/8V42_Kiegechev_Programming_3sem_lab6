#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <memory>
#include <string>

class Document;
class IView;
class Primitive;

/**
 * @class IController
 * @brief Интерфейс для контроллера (Controller)
 * 
 * Определяет контракт между View и Model
 * Обрабатывает пользовательские действия
 */
class IController {
public:
    virtual ~IController() = default;

    /**
     * @brief Создать новый документ
     */
    virtual void createNewDocument(const std::string& documentName) = 0;

    /**
     * @brief Открыть документ из файла
     */
    virtual void openDocument(const std::string& filePath) = 0;

    /**
     * @brief Сохранить документ в файл
     */
    virtual void saveDocument(const std::string& filePath) = 0;

    /**
     * @brief Добавить примитив (круг)
     */
    virtual void addCircle(double radius) = 0;

    /**
     * @brief Добавить примитив (прямоугольник)
     */
    virtual void addRectangle(double width, double height) = 0;

    /**
     * @brief Добавить примитив (линию)
     */
    virtual void addLine(double x1, double y1, double x2, double y2) = 0;

    /**
     * @brief Удалить примитив
     */
    virtual void removePrimitive(int primitiveId) = 0;

    /**
     * @brief Отобразить текущий документ
     */
    virtual void displayDocument() = 0;

    /**
     * @brief Получить текущий документ
     */
    virtual std::shared_ptr<Document> getCurrentDocument() const = 0;
};

/**
 * @class VectorEditorController
 * @brief Конкретная реализация контроллера
 * 
 * Координирует работу Model и View
 */
class VectorEditorController : public IController {
private:
    std::shared_ptr<Document> currentDocument;
    std::shared_ptr<IView> view;
    int primitiveIdCounter;

public:
    VectorEditorController(std::shared_ptr<IView> view);
    ~VectorEditorController() override = default;

    void createNewDocument(const std::string& documentName) override;
    void openDocument(const std::string& filePath) override;
    void saveDocument(const std::string& filePath) override;

    void addCircle(double radius) override;
    void addRectangle(double width, double height) override;
    void addLine(double x1, double y1, double x2, double y2) override;

    void removePrimitive(int primitiveId) override;
    void displayDocument() override;

    std::shared_ptr<Document> getCurrentDocument() const override;
};

#endif // ICONTROLLER_H