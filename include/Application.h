#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

class IController;
class IView;

/**
 * @class Application
 * @brief Главное приложение - точка входа для MVC архитектуры
 * 
 */
class Application {
private:
    std::shared_ptr<IView> view;
    std::shared_ptr<IController> controller;

public:
    Application();
    ~Application();

    /**
     * @brief Инициализировать приложение
     */
    void initialize();

    /**
     * @brief Запустить приложение
     */
    void run();

    /**
     * @brief Получить контроллер
     */
    std::shared_ptr<IController> getController() const;

    /**
     * @brief Получить представление
     */
    std::shared_ptr<IView> getView() const;
};

#endif // APPLICATION_H