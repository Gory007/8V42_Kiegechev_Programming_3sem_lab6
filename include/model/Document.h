#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Primitive.h"
#include <vector>
#include <memory>
#include <string>

/**
 * @class Document
 * @brief Модель документа - содержит коллекцию примитивов
 * 
 * Отвечает за управление графическими примитивами
 */
class Document {
private:
    int documentId;
    std::string documentName;
    std::vector<std::shared_ptr<Primitive>> primitives;
    static int documentCounter;

public:
    Document(const std::string& name = "Untitled");
    ~Document();

    /**
     * @brief Получить ID документа
     */
    int getId() const;

    /**
     * @brief Получить имя документа
     */
    std::string getName() const;

    /**
     * @brief Установить имя документа
     */
    void setName(const std::string& name);

    /**
     * @brief Добавить примитив в документ
     */
    void addPrimitive(std::shared_ptr<Primitive> primitive);

    /**
     * @brief Удалить примитив по ID
     */
    bool removePrimitive(int primitiveId);

    /**
     * @brief Получить примитив по ID
     */
    std::shared_ptr<Primitive> getPrimitive(int primitiveId) const;

    /**
     * @brief Получить все примитивы
     */
    const std::vector<std::shared_ptr<Primitive>>& getAllPrimitives() const;

    /**
     * @brief Количество примитивов в документе
     */
    size_t getPrimitiveCount() const;

    /**
     * @brief Отрисовать все примитивы (log-информация)
     */
    void drawAll() const;

    /**
     * @brief Получить информацию о документе
     */
    std::string getDocumentInfo() const;

    /**
     * @brief Очистить документ (удалить все примитивы)
     */
    void clear();
};

#endif // DOCUMENT_H