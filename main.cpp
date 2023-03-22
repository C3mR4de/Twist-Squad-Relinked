/// Подключаемые библиотеки
#include "classes.hpp"

using namespace std; /// Пространство имён std (строки, вектора, вывод в консоль)
using namespace sf; /// Пространство имён sf (SFML)

/// Главная функция
int main() {

    /// Создание окна
    RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Twist Squad", Style::Fullscreen);

    window.setFramerateLimit(20);

    /// Время SFML
    Clock clock;

    /// Кириллица
    setlocale(LC_ALL, "rus");

    /// Сброс вида
    view.reset(FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

    /// Загрузка иконки
    icon.loadFromFile("resources/images/logotypes/icon.png");

    /// Установка иконки
    window.setIcon(128, 128, icon.getPixelsPtr());

    /// Игровой процесс
    while (window.isOpen()) {

        /// Выполнение функции в зависимости от статуса
        switch (status) {

            /// Меню
            case Menu:
                menu(window, clock);
                break;

            /// Настройки
            case Settings:
                settings(window, clock);
                break;

            /// Выбор персонажа
            case Characters:
                characters(window, clock);
                break;

            /// Выбор языка
            case Languages:
                language(window, clock);
                break;

            /// Игра
            case Game:
                game(window, clock);
                break;

        }

    }

    /// Выход из приложения
    return 0;

}
