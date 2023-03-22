/// ������������ ����������
#include "classes.hpp"

using namespace std; /// ������������ ��� std (������, �������, ����� � �������)
using namespace sf; /// ������������ ��� sf (SFML)

/// ������� �������
int main() {

    /// �������� ����
    RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Twist Squad", Style::Fullscreen);

    window.setFramerateLimit(20);

    /// ����� SFML
    Clock clock;

    /// ���������
    setlocale(LC_ALL, "rus");

    /// ����� ����
    view.reset(FloatRect(0, 0, VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));

    /// �������� ������
    icon.loadFromFile("resources/images/logotypes/icon.png");

    /// ��������� ������
    window.setIcon(128, 128, icon.getPixelsPtr());

    /// ������� �������
    while (window.isOpen()) {

        /// ���������� ������� � ����������� �� �������
        switch (status) {

            /// ����
            case Menu:
                menu(window, clock);
                break;

            /// ���������
            case Settings:
                settings(window, clock);
                break;

            /// ����� ���������
            case Characters:
                characters(window, clock);
                break;

            /// ����� �����
            case Languages:
                language(window, clock);
                break;

            /// ����
            case Game:
                game(window, clock);
                break;

        }

    }

    /// ����� �� ����������
    return 0;

}
