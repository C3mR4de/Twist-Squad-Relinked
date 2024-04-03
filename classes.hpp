#ifndef CLASSES_HPP
#define CLASSES_HPP

/// Подключаемые библиотеки
#include <SFML/Graphics.hpp> /// Библиотека SFML (графика)
#include <SFML/Audio.hpp> /// Библиотека SFML (звук)
#include <iostream> /// Ввод-вывод в консоль
#include <fstream> /// Ввод-вывод в файлы
#include <sstream> /// Не знаю что это, никогда не пользовался, но потом применю
#include <string> /// Строки
#include <vector> /// Вектора
#include <list> /// Двусвязные списки
#include <thread> /// Потоки
#include <cmath>
///#include <DiscordGameSDK/image_manager.h>

using namespace std; /// Пространство имён std
using namespace sf; /// Пространство имён sf
///using namespace discord;

/// Персонажи в перечислении
enum Type {

    Brics = 0,
    Fastquake,
    Epsilon,
    Vird,
    Vacks,
    Swap,
    Fox,
    Spinn,
    Tobi,
    Dixon,
    Chucky,
    Arbyte,
    Yerbek,
    Zinaida,
    Skrypak,
    Goliath,
    David,
    Ranger,
    Handy,
    Trueman,
    Crash

};

/// Редкости в перечислении
enum Rarity {

    Beginning = 0,
    Rare,
    Superrare,
    Epic,
    Mythic,
    Relict,
    Legendary,
    Divine,
    Mystic,
    Undefined

};

/// Направления движения
enum Direction {

    Left = 0,
    Right

};

/// Статус
enum Status {

    Menu = 0,
    Settings,
    Characters,
    Languages,
    Game

};

/// Язык
enum Language {

    English = 0,
    Russian,
    German

};

/// Настройки
bool setting[3] = {false, false, true};

/// Переменная статуса
Status status;

/// Выбранный персонаж
Type selChar = Brics;

/// Выбранный язык
Language selLang = Russian;

/// Никнейм
string nickname = "Player";

/// Иконка для игры
Image icon;

const int mapWidth = 100; /// Ширина карты в тайлах
const int mapHeight = 100; /// Высота карты в тайлах

const int blockSide = 96; /// Сторона тайла
const int screenWidth = 1920; /// Ширина экрана
const int screenHeight = 1080; /// Высота экрана

const int mapTileWidth = blockSide * mapWidth; /// Ширина карты в пикселях
const int mapTileHeight = blockSide * mapHeight; /// Высота карты в пикселях

View view; /// Вид на персонажа

float tempX;
float tempY;

/// Задание вида
View setPlayerCoordinateForView(float x, float y, int w, int h) {

    tempX = x + w / 2;
    tempY = y + h / 2;

    if (x < screenWidth / 2 - w / 2)
        tempX = screenWidth / 2;
    if (y < screenHeight / 2 - h / 2)
        tempY = screenHeight / 2;
    if (x > mapTileWidth - screenWidth / 2 - w / 2)
        tempX = mapTileWidth - screenWidth / 2;
    if (y > mapTileHeight - screenHeight / 2 - h / 2)
        tempY = mapTileHeight - screenHeight / 2;

    view.setCenter(tempX, tempY);

    return view;

}

inline float getTempX() {
    return tempX;
}

inline float getTempY() {
    return tempY;
}

/// Класс персонажа
class Character {

    /// Параметры персонажа
    private:

        /// Скорость передвижения
        float speed;

        /// Адрес модельки
        string skin;

        /// Максимальное здоровье и урон
        int maxHealth, damage;

        /// Редкость
        Rarity rarity;

        /// Тип
        Type type;

    /// Паблик
    public:

        /// Конструктор с параметрами
        Character(string skin, int maxHealth, float speed, int damage, Rarity rarity, Type type) {

            this->skin = skin;
            this->maxHealth = maxHealth;
            this->speed = speed;
            this->damage = damage;
            this->rarity = rarity;
            this->type = type;

        }

        Character() {

        }

        /// Установка значений
        void setValues(string skin, int maxHealth, float speed, int damage, Rarity rarity, Type type) {

            this->skin = skin;
            this->maxHealth = maxHealth;
            this->speed = speed;
            this->damage = damage;
            this->rarity = rarity;
            this->type = type;

        }

        /// Геттеры
        inline string getSkin() {
            return skin;
        }

        inline float getSpeed() {
            return speed;
        }

        inline int getMaxHealth() {
            return maxHealth;
        }

        inline int getDamage() {
            return damage;
        }

        inline Rarity getRarity() {
            return rarity;
        }

        inline Type getType() {
            return type;
        }

};

/// Список персонажей (среднее здоровье - 1000, средняя скорость - 0.8, средний урон - 400 (урон указывается за один снаряд, а их может быть несколько))
Character cBrics("resources/images/characters/brics/model.png", 1000, 1.1, 700, Mystic, Brics);
Character cFastquake("resources/images/characters/fastquake/model.png", 800, 1.3, 400, Mystic, Fastquake);
Character cEpsilon("resources/images/characters/epsilon/model.png", 1400, 0.7, 200, Undefined, Epsilon);
Character cVird("resources/images/characters/vird/model.png", 1000, 0.8, 400, Undefined, Vird);
Character cVacks("resources/images/characters/vacks/model.png", 850, 0.9, 150, Undefined, Vacks);
Character cSwap("resources/images/characters/swap/model.png", 900, 0.9, 350, Undefined, Swap);
Character cFox("resources/images/characters/fox/model.png", 700, 1.2, 600, Legendary, Fox);
Character cSpinn("resources/images/characters/spinn/model.png", 650, 1.2, 1200, Undefined, Spinn);
Character cTobi("resources/images/characters/tobi/model.png", 1700, 0.6, 500, Undefined, Tobi);
Character cDixon("resources/images/characters/dixon/model.png", 1200, 0.9, 450, Undefined, Dixon);
Character cChucky("resources/images/characters/chucky/model.png", 1000, 0.8, 400, Undefined, Chucky);
Character cArbyte("resources/images/characters/arbyte/model.png", 1000, 0.9, 300, Divine, Arbyte);
Character cYerbek("resources/images/characters/yerbek/model.png", 950, 0.9, 500, Undefined, Yerbek);
Character cZinaida("resources/images/characters/zinaida/model.png", 1300, 0.7, 100, Undefined, Zinaida);
Character cSkrypak("resources/images/characters/skrypak/model.png", 800, 0.7, 90, Undefined, Skrypak);
Character cGoliath("resources/images/characters/goliath/model.png", 1600, 0.8, 800, Undefined, Goliath);
Character cDavid("resources/images/characters/david/model.png", 900, 1.0, 600, Undefined, David);
Character cRanger("resources/images/characters/ranger/model.png", 1300, 0.7, 900, Undefined, Ranger);
Character cHandy("resources/images/characters/handy/model.png", 1000, 0.8, 400, Undefined, Handy);
Character cTrueman("resources/images/characters/trueman/model.png", 1000, 0.8, 400, Undefined, Trueman);
Character cCrash("resources/images/characters/crash/model.png", 1000, 0.8, 400, Beginning, Crash);

/// Функция получения угла
float getAngle(float x1, float y1, float x2, float y2) {

    /// Переменная угла и тангенса
    float angle = -1, tangens;

    enum Quarter {

        First = 1,
        Second,
        Third,
        Fourth

    };

    /// Четверть
    Quarter quarter;

    /// Если точки одинаковы или вторая только правее первой
    if (y1 == y2 && (x1 == x2 || x1 < x2)) {

        /// Угол равен 0 градусов
        angle = 0;

      /// Если вторая точка ниже и правее первой
    } else if (x1 < x2 && y1 < y2) {

        /// Она в 1 четверти
        quarter = First;

        /// Вычисление тангенса
        tangens = (y2 - y1) / (x2 - x1);

      /// Если вторая точка только ниже правой
    } else if (x1 == x2 && y1 < y2) {

        /// Угол равен 90 градусов
        return 90;

      /// Если вторая точка ниже и левее первой
    } else if (x1 > x2 && y1 < y2) {

        /// Она во 2 четверти
        quarter = Second;

        /// Вычисление тангенса
        tangens = (y2 - y1) / (x1 - x2);

      /// Если вторая точка только левее первой
    } else if (x1 > x2 && y1 == y2) {

        /// Угол равен 180 градусов
        return 180;

      /// Если вторая точка выше и левее первой
    } else if (x1 > x2 && y1 > y2) {

        /// Она в 3 четверти
        quarter = Third;

        /// Вычисление тангенса
        tangens = (y1 - y2) / (x1 - x2);

      /// Если вторая точка только выше первой
    } else if (x1 == x2 && y1 > y2) {

        /// Угол равен 270 градусов
        return 270;

      /// Если вторая точка выше и правее первой
    } else if (x1 < x2 && y1 > y2) {

        /// Она в 4 четверти
        quarter = Fourth;

        /// Вычисление тангенса
        tangens = (y1 - y2) / (x2 - x1);

    }

    /// Нахождение угла
    for (int i = 1; i <= 899; ++i) {

        if (tangens >= tan(0.1 * i * asin(1) / 90) && tangens <= tan((0.1 * i + 0.1) * asin(1) / 90)) {

            switch (quarter) {

                case First:

                    if (tangens < (tan(0.1 * i * asin(1) / 90) + tan((0.1 * i + 0.1) * asin(1) / 90)) / 2)
                        angle = float(i) / 10;
                    else
                        angle = float(i + 1) / 10;

                    break;

                case Second:

                    if (tangens < (tan(0.1 * i * asin(1) / 90) + tan((0.1 * i + 0.1) * asin(1) / 90)) / 2)
                        angle = 180 - float(i) / 10;
                    else
                        angle = 180 - float(i + 1) / 10;

                    break;

                case Third:

                    if (tangens < (tan(0.1 * i * asin(1) / 90) + tan((0.1 * i + 0.1) * asin(1) / 90)) / 2)
                        angle = 180 + float(i) / 10;
                    else
                        angle = 180 + float(i + 1) / 10;

                    break;

                case Fourth:

                    if (tangens < (tan(0.1 * i * asin(1) / 90) + tan((0.1 * i + 0.1) * asin(1) / 90)) / 2)
                        angle = 360 - float(i) / 10;
                    else
                        angle = 360 - float(i + 1) / 10;

                    break;

            }

        }

    }

    return angle;

}

/// Класс карты
class Map {

    /// Поток ввода, слои и функции загрузки
    private:

        ifstream mapFile;

        vector<vector<int>> foreground, interaction, buildings, background, solid;

        void loadForegroundLayer(string& frg) {

            string symBuffer;

            vector <int> tileBuffer;

            mapFile.open(frg);

            while (mapFile.good()) {

                for (int i = 0; i < mapHeight; i++) {

                    for (int j = 0; j < mapWidth; j++) {

                        char sep;

                        if (j != mapWidth - 1)
                            sep = ',';
                        else
                            sep = '\n';

                        if (getline(mapFile, symBuffer, sep))
                            tileBuffer.push_back(stoi(symBuffer));

                    }

                    foreground.push_back(tileBuffer);

                    tileBuffer.clear();

                }

            }

            symBuffer = "";

            mapFile.close();

        }

        void loadInteractionLayer(string& itc) {

            string symBuffer;

            vector <int> tileBuffer;

            mapFile.open(itc);

            while (mapFile.good()) {

                for (int i = 0; i < mapHeight; i++) {

                    for (int j = 0; j < mapWidth; j++) {

                        char sep;

                        if (j != mapWidth - 1)
                            sep = ',';
                        else
                            sep = '\n';

                        if (getline(mapFile, symBuffer, sep))
                            tileBuffer.push_back(stoi(symBuffer));

                    }

                    interaction.push_back(tileBuffer);

                    tileBuffer.clear();

                }

            }

            symBuffer = "";

            mapFile.close();

        }

        void loadBuildingsLayer(string& bdg) {

            string symBuffer;

            vector <int> tileBuffer;

            mapFile.open(bdg);

            while (mapFile.good()) {

                for (int i = 0; i < mapHeight; i++) {

                    for (int j = 0; j < mapWidth; j++) {

                        char sep;

                        if (j != mapWidth - 1)
                            sep = ',';
                        else
                            sep = '\n';

                        if (getline(mapFile, symBuffer, sep))
                            tileBuffer.push_back(stoi(symBuffer));

                    }

                    buildings.push_back(tileBuffer);

                    tileBuffer.clear();

                }

            }

            symBuffer = "";

            mapFile.close();

        }

        void loadBackgroundLayer(string& bcg) {

            string symBuffer;

            vector <int> tileBuffer;

            mapFile.open(bcg);

            while (mapFile.good()) {

                for (int i = 0; i < mapHeight; i++) {

                    for (int j = 0; j < mapWidth; j++) {

                        char sep;

                        if (j != mapWidth - 1)
                            sep = ',';
                        else
                            sep = '\n';

                        if (getline(mapFile, symBuffer, sep))
                            tileBuffer.push_back(stoi(symBuffer));

                    }

                    background.push_back(tileBuffer);

                    tileBuffer.clear();

                }

            }

            symBuffer = "";

            mapFile.close();

        }

        void loadSolidLayer(string& sld) {

            string symBuffer;

            vector <int> tileBuffer;

            mapFile.open(sld);

            while (mapFile.good()) {

                for (int i = 0; i < mapHeight; i++) {

                    for (int j = 0; j < mapWidth; j++) {

                        char sep;

                        if (j != mapWidth - 1)
                            sep = ',';
                        else
                            sep = '\n';

                        if (getline(mapFile, symBuffer, sep))
                            tileBuffer.push_back(stoi(symBuffer));

                    }

                    solid.push_back(tileBuffer);

                    tileBuffer.clear();

                }

            }

            symBuffer = "";

            mapFile.close();

        }

    /// Конструктор с параметрами загрузки, функции возврата и отрисовки
    public:

        /// Конструктор с параметрами (загрузка карты)
        Map(string frg, string itc, string bdg, string bcg, string sld) {

            loadForegroundLayer(frg);

            loadInteractionLayer(itc);

            loadBuildingsLayer(bdg);

            loadBackgroundLayer(bcg);

            loadSolidLayer(sld);

        }

        /// Загрузка карты
        void loadMap(string frg, string itc, string bdg, string bcg, string sld) {

            loadForegroundLayer(frg);

            loadInteractionLayer(itc);

            loadBuildingsLayer(bdg);

            loadBackgroundLayer(bcg);

            loadSolidLayer(sld);

        }

        /// Проверка на твёрдый объект
        inline bool isSolid(int i, int j) {
            return solid[i][j] == 15;
        }

        /// Проверка на трамплин
        inline bool isTrampoline(int i, int j) {
            return buildings[i][j] == 19;
        }

        /// Функции возврата слоёв (векторов)
        inline vector <vector <int>>& getForegroundLayer() {
            return foreground;
        }

        inline vector <vector <int>>& getInteractionLayer() {
            return interaction;
        }

        inline vector <vector <int>>& getBuildingsLayer() {
            return buildings;
        }

        inline vector <vector <int>>& getBackgroundLayer() {
            return background;
        }

        inline vector <vector <int>>&getSolidLayer() {
            return solid;
        }

        /// Отрисовка слоя
        void drawLayer(vector <vector <int>>& layer, RenderWindow& window, string fileName) {

            Image blockImage;
            blockImage.loadFromFile(fileName);
            blockImage.createMaskFromColor(Color(254, 254, 254));

            Texture blockTexture;
            blockTexture.loadFromImage(blockImage);

            Sprite blockSprite;
            blockSprite.setTexture(blockTexture);

            for (int i = (getTempY() - screenHeight / 2) / blockSide; i < (getTempY() + screenHeight / 2) / blockSide; ++i) {

                for (int j = (getTempX() - screenWidth / 2) / blockSide; j < (getTempX() + screenWidth / 2) / blockSide; ++j) {

                        if (layer[i][j] == -1)
                            blockSprite.setTextureRect(IntRect(0, 0, 0, 0));
                        else if (layer[i][j] == 0)
                            blockSprite.setTextureRect(IntRect(0, 0, blockSide, blockSide));
                        else if (layer[i][j] == 1)
                            blockSprite.setTextureRect(IntRect(blockSide, 0, blockSide, blockSide));
                        else if (layer[i][j] == 2)
                            blockSprite.setTextureRect(IntRect(blockSide * 2, 0, blockSide, blockSide));
                        else if (layer[i][j] == 3)
                            blockSprite.setTextureRect(IntRect(blockSide * 3, 0, blockSide, blockSide));
                        else if (layer[i][j] == 4)
                            blockSprite.setTextureRect(IntRect(blockSide * 4, 0, blockSide, blockSide));
                        else if (layer[i][j] == 5)
                            blockSprite.setTextureRect(IntRect(blockSide * 5, 0, blockSide, blockSide));
                        else if (layer[i][j] == 6)
                            blockSprite.setTextureRect(IntRect(blockSide * 6, 0, blockSide, blockSide));
                        else if (layer[i][j] == 7)
                            blockSprite.setTextureRect(IntRect(blockSide * 7, 0, blockSide, blockSide));
                        else if (layer[i][j] == 8)
                            blockSprite.setTextureRect(IntRect(blockSide * 8, 0, blockSide, blockSide));
                        else if (layer[i][j] == 9)
                            blockSprite.setTextureRect(IntRect(blockSide * 9, 0, blockSide, blockSide));
                        else if (layer[i][j] == 10)
                            blockSprite.setTextureRect(IntRect(blockSide * 10, 0, blockSide, blockSide));
                        else if (layer[i][j] == 11)
                            blockSprite.setTextureRect(IntRect(0, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 12)
                            blockSprite.setTextureRect(IntRect(blockSide, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 13)
                            blockSprite.setTextureRect(IntRect(blockSide * 2, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 14)
                            blockSprite.setTextureRect(IntRect(blockSide * 3, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 16)
                            blockSprite.setTextureRect(IntRect(blockSide * 5, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 17)
                            blockSprite.setTextureRect(IntRect(blockSide * 6, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 18)
                            blockSprite.setTextureRect(IntRect(blockSide * 7, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 19)
                            blockSprite.setTextureRect(IntRect(blockSide * 8, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 20)
                            blockSprite.setTextureRect(IntRect(blockSide * 9, blockSide, blockSide, blockSide));
                        else if (layer[i][j] == 21)
                            blockSprite.setTextureRect(IntRect(blockSide * 10, blockSide, blockSide, blockSide));

                        blockSprite.setPosition(j * blockSide, i * blockSide);

                        window.draw(blockSprite);

                }

            }

        }

};

/// Общий класс сущности (от него наследуется класс игрока, заднего фона и снарядв)
class Entity {

    /// То, что есть у всех сущностей и наследуется всеми классами
    protected:

        /// Скорость движения по разным осям и координаты
        float dx, dy, x, y;

        /// Ширина и высота хитбокса
        int w, h;

        /// Изображение, текстура и спрайт сущности
        Image image;
        Texture texture;
        Sprite sprite;

    /// Паблик (тут все функции и конструктор с параметрами)
    public:

        /// Конструктор с параметрами
        Entity(float x, float y, int w, int h) {

            setValues(x, y, w, h);

        }

        void setValues(float x, float y, int w, int h) {

            /// Задание переданных величин
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;

            /// Значения по умолчанию
            dx = 0;
            dy = 0;

        }

        /// Функции возврата
        inline int getW() {
            return w;
        }

        inline int getH() {
            return h;
        }

        inline int getX() {
            return x;
        }

        inline int getY() {
            return y;
        }

        inline float& getDx() {
            return dx;
        }

        inline float& getDy() {
            return dy;
        }

        inline Sprite& getSprite() {
            return sprite;
        }

        void setX(float x) {
            this->x = x;
        }

        void setY(float y) {
            this->y = y;
        }


        void setDx(float dx) {
            this->dx = dx;
        }

        void setDy(float dy) {
            this->dy = dy;
        }

};

/// Класс снаряда
class Shell: public Entity {

    /// То, что есть только у снаряда
    private:

        /// Угол наклона, какой персонаж выстрелил и ульта ли это
        float angle;
        Type type;
        bool isBasic;

        Time disappearTime;
        Clock disappearClock;

    public:

        /// Конструктор с параметрами
        Shell(float x, float y, int w, int h, float angle, Type type, bool isBasic, float disappearTime): Entity (x, y, w, h) {

            setValues(x, y, w, h, angle, type, isBasic, disappearTime);

        }

        void setValues(float x, float y, int w, int h, float angle, Type type, bool isBasic, float disappearTime) {

            /// Задание переданных величин
            this->x = x;
            this->y = y;
            this->w = 0;
            this->h = 0;
            this->angle = angle;
            this->type = type;
            this->isBasic = isBasic;
            this->disappearTime = seconds(disappearTime);

            /// Значения по умолчанию
            dx = 0;
            dy = 0;

            /// Задание хитбоксов и текстуры в зависимости от персонажа
            switch (type) {

                case Brics:

                    if (isBasic) {

                        w = 35;
                        h = 15;

                        sprite.setOrigin(w / 2, h / 2);
                        sprite.setRotation(angle);
                        sprite.setPosition(x, y);

                    }

                    break;

            }

        }

        /// Возвращает угол наклона
        inline float& getAngle() {
            return angle;
        }

        inline Sprite& getSprite() {
            return sprite;
        }

        inline Time& getDisappearTime() {
            return disappearTime;
        }

        inline Clock& getDisappearClock() {
            return disappearClock;
        }

        void setSprite(string fileName) {

            image.loadFromFile(fileName);
            image.createMaskFromColor(Color(254, 254, 254));

            texture.loadFromImage(image);

            sprite.setTexture(texture);

        }

};

/// Класс игрока
class Player: public Entity {

    /// То, что есть только у игрока
    private:

        /// Направление движения, здоровье и очки
        Direction dir;
        int health;
        int playerScore;

        /// Время перезарядки
        Time reloading;
        Clock reloadingTime;

        /// Персонаж игрока
        Character character;

        /// Кадр, который я реализую иначе
        float frame;

        /// Шрифт никнейма
        Font commonFont;

        /// Никнейм персонажа
        String nickname;

        /// Надпись с никнеймом
        Text nicknameText[2];
        Text healthText[2];

        /// Жив ли игрок, движется ли он, на земле ли и на трамплине ли
        bool isAlive, isMove, onGround, onTrampoline;

        /// Снаряды игрока
        list <Shell> basicShells;
        list <Shell> superShells;

        /// Звук прыжка
        SoundBuffer jumpBuffer;
        Sound jump;

        /// Звук основной атаки
        SoundBuffer basicAttackBuffer;
        Sound basicAttack;

    /// Конструктор с параметрами и все функции
    public:

        /// Конструктор с параметрами (задание переданных величин)
        Player(float x, float y, int w, int h, Type type, Direction dir, string nickname): Entity(x, y, w, h) {

            /// Выбор персонажа
            switch (type) {

                case Brics:
                    character.setValues(cBrics.getSkin(), cBrics.getMaxHealth(), cBrics.getSpeed(), cBrics.getDamage(), cBrics.getRarity(), cBrics.getType());
                    image.loadFromFile(character.getSkin());
                    basicAttackBuffer.loadFromFile("resources/sounds/characters/brics/basicattack.wav");
                    reloading = seconds(1);
                    break;

                case Fastquake:
                    character.setValues(cFastquake.getSkin(), cFastquake.getMaxHealth(), cFastquake.getSpeed(), cFastquake.getDamage(), cFastquake.getRarity(), cFastquake.getType());
                    image.loadFromFile(character.getSkin());
                    basicAttackBuffer.loadFromFile("resources/sounds/characters/fastquake/basicattack.wav");
                    reloading = seconds(1.5);
                    break;

                case Epsilon:
                    character.setValues(cEpsilon.getSkin(), cEpsilon.getMaxHealth(), cEpsilon.getSpeed(), cEpsilon.getDamage(), cEpsilon.getRarity(), cEpsilon.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Vird:
                    character.setValues(cVird.getSkin(), cVird.getMaxHealth(), cVird.getSpeed(), cVird.getDamage(), cVird.getRarity(), cVird.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Vacks:
                    character.setValues(cVacks.getSkin(), cVacks.getMaxHealth(), cVacks.getSpeed(), cVacks.getDamage(), cVacks.getRarity(), cVacks.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Swap:
                    character.setValues(cSwap.getSkin(), cSwap.getMaxHealth(), cSwap.getSpeed(), cSwap.getDamage(), cSwap.getRarity(), cSwap.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Fox:
                    character.setValues(cFox.getSkin(), cFox.getMaxHealth(), cFox.getSpeed(), cFox.getDamage(), cFox.getRarity(), cFox.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Spinn:
                    character.setValues(cSpinn.getSkin(), cSpinn.getMaxHealth(), cSpinn.getSpeed(), cSpinn.getDamage(), cSpinn.getRarity(), cSpinn.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Tobi:
                    character.setValues(cTobi.getSkin(), cTobi.getMaxHealth(), cTobi.getSpeed(), cTobi.getDamage(), cTobi.getRarity(), cTobi.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Dixon:
                    character.setValues(cDixon.getSkin(), cDixon.getMaxHealth(), cDixon.getSpeed(), cDixon.getDamage(), cDixon.getRarity(), cDixon.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Chucky:
                    character.setValues(cChucky.getSkin(), cChucky.getMaxHealth(), cChucky.getSpeed(), cChucky.getDamage(), cChucky.getRarity(), cChucky.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Arbyte:
                    character.setValues(cArbyte.getSkin(), cArbyte.getMaxHealth(), cArbyte.getSpeed(), cArbyte.getDamage(), cArbyte.getRarity(), cArbyte.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Yerbek:
                    character.setValues(cYerbek.getSkin(), cYerbek.getMaxHealth(), cYerbek.getSpeed(), cYerbek.getDamage(), cYerbek.getRarity(), cYerbek.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Zinaida:
                    character.setValues(cZinaida.getSkin(), cZinaida.getMaxHealth(), cZinaida.getSpeed(), cZinaida.getDamage(), cZinaida.getRarity(), cZinaida.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Skrypak:
                    character.setValues(cSkrypak.getSkin(), cSkrypak.getMaxHealth(), cSkrypak.getSpeed(), cSkrypak.getDamage(), cSkrypak.getRarity(), cSkrypak.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Goliath:
                    character.setValues(cGoliath.getSkin(), cGoliath.getMaxHealth(), cGoliath.getSpeed(), cGoliath.getDamage(), cGoliath.getRarity(), cGoliath.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case David:
                    character.setValues(cDavid.getSkin(), cDavid.getMaxHealth(), cDavid.getSpeed(), cDavid.getDamage(), cDavid.getRarity(), cDavid.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Ranger:
                    character.setValues(cRanger.getSkin(), cRanger.getMaxHealth(), cRanger.getSpeed(), cRanger.getDamage(), cRanger.getRarity(), cRanger.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Handy:
                    character.setValues(cHandy.getSkin(), cHandy.getMaxHealth(), cHandy.getSpeed(), cHandy.getDamage(), cHandy.getRarity(), cHandy.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Trueman:
                    character.setValues(cTrueman.getSkin(), cTrueman.getMaxHealth(), cTrueman.getSpeed(), cTrueman.getDamage(), cTrueman.getRarity(), cTrueman.getType());
                    image.loadFromFile(character.getSkin());
                    break;

                case Crash:
                    character.setValues(cCrash.getSkin(), cCrash.getMaxHealth(), cCrash.getSpeed(), cCrash.getDamage(), cCrash.getRarity(), cCrash.getType());
                    image.loadFromFile(character.getSkin());
                    break;

            }

            /// Значения по умолчанию
            health = character.getMaxHealth();
            playerScore = 0;
            frame = 0;

            /// Никнейм
            this->nickname = nickname;

            /// И это тоже
            isAlive = true;
            isMove = false;
            onGround = false;
            onTrampoline = false;

            /// Прозрачность фона
            image.createMaskFromColor(Color(254, 254, 254));

            /// Загрузка текстуры и спрайта персонажа и его спаун
            texture.loadFromImage(image);

            sprite.setTexture(texture);
            sprite.setPosition(x, y);

            /// Установка шрифта ника
            commonFont.loadFromFile("resources/fonts/Comic Sans MS.ttf");

            /// Текст никнейма
            nicknameText[0].setFont(commonFont);
            nicknameText[0].setString(nickname);
            nicknameText[0].setCharacterSize(20);
            nicknameText[0].setOrigin(nicknameText[0].getLocalBounds().width / 2, nicknameText[0].getLocalBounds().height / 2);
            nicknameText[0].setFillColor(Color::Green);
            nicknameText[0].setPosition(x + w / 2, y - 40);

            /// Обводка никнейма
            nicknameText[1].setFont(commonFont);
            nicknameText[1].setString(nickname);
            nicknameText[1].setCharacterSize(20);
            nicknameText[1].setOrigin(nicknameText[1].getLocalBounds().width / 2, nicknameText[1].getLocalBounds().height / 2);
            nicknameText[1].setFillColor(Color::Black);
            nicknameText[1].setPosition(nicknameText[0].getPosition().x + 2, nicknameText[0].getPosition().y + 2);

            /// Текст здоровья
            healthText[0].setFont(commonFont);
            healthText[0].setString(to_string(health) + " / " + to_string(character.getMaxHealth()));
            healthText[0].setCharacterSize(20);
            healthText[0].setOrigin(healthText[0].getLocalBounds().width / 2, healthText[0].getLocalBounds().height / 2);
            healthText[0].setFillColor(Color::White);
            healthText[0].setPosition(x + w / 2, y - 20);

            /// Обводка здоровья
            healthText[1].setFont(commonFont);
            healthText[1].setString(to_string(health) + " / " + to_string(character.getMaxHealth()));
            healthText[1].setCharacterSize(20);
            healthText[1].setOrigin(healthText[1].getLocalBounds().width / 2, healthText[1].getLocalBounds().height / 2);
            healthText[1].setFillColor(Color::Black);
            healthText[1].setPosition(healthText[0].getPosition().x + 2, healthText[0].getPosition().y + 2);

            jumpBuffer.loadFromFile("resources/sounds/jump.wav");
            jump.setBuffer(jumpBuffer);

            basicAttack.setBuffer(basicAttackBuffer);

        }

        /// Возвращает снаряды основной атаки
        inline list <Shell>& getBasicShellsList() {
            return basicShells;
        }

        /// Возвращает снаряды ульты
        inline list <Shell>& getSuperShellsList() {
            return superShells;
        }

        inline Text& getNicknameText() {
            return nicknameText[0];
        }

        inline Text& getNicknameBorder() {
            return nicknameText[1];
        }

        inline Text& getHealthText() {
            return healthText[0];
        }

        inline Text& getHealthBorder() {
            return healthText[1];
        }

        /// Функция управления персонажем
        void control(float& time, RenderWindow& window) {

            /// Переключение кадра
            if (isMove) {

                frame += 0.0075 * time;
                if (frame > 2)
                    frame -= 2;

            } else {

                if (dir == Left)
                    sprite.setTextureRect(IntRect(w, 0, -w, h));
                else
                    sprite.setTextureRect(IntRect(0, 0, w, h));

            }

            /// Проверка нажатой клавиши, задание направление движения и анимации
            if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) { /// Если нажата клавиша A и не нажата клавиша D

                /// Персонаж движется
                isMove = true;

                /// Налево со скоростью персонажа
                dx = -character.getSpeed();
                dir = Left;

                /// Задание текстурки в зависимости от кадра
                if (onGround)
                    sprite.setTextureRect(IntRect(w * 3 - int(frame) * w, 0, -w, h));
                else
                    sprite.setTextureRect(IntRect(w * 3, 0, -w, h));

            } else if (!Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::D)) { /// Если нажата клавиша D и не нажата клавиша A

                /// Персонаж движется
                isMove = true;

                /// Направо со скоростью персонажа
                dx = character.getSpeed();
                dir = Right;

                /// Задание текстурки в зависимости от кадра
                if (onGround)
                    sprite.setTextureRect(IntRect(w * int(frame) + w, 0, w, h));
                else
                    sprite.setTextureRect(IntRect(w * 2, 0, w, h));

            } else { /// Если ничего не нажато или нажаты обе

                /// Персонаж не движется
                isMove = false;

                /// У него нет скорости
                dx = 0;

            }

            /// Отдельно от общего условия для многопоточности (мы же можем прыгать в движении, не так ли?)
            if (Keyboard::isKeyPressed(Keyboard::Space) && onGround) {

                /// Проверка на трамплин
                if (!onTrampoline)
                    dy = -0.6;
                else
                    dy = -1.2;

                /// Персонаж не на земле и издаётся звук
                onGround = false;
                if (setting[2])
                    jump.play();

            }

            /// Основная атака, самое сложное начинается >;)
            if (Mouse::isButtonPressed(Mouse::Left)) {

                switch (character.getType()) {

                    case Brics:

                        if (reloadingTime.getElapsedTime().asSeconds() >= reloading.asSeconds()) {

                            reloadingTime.restart();

                            Shell thisS(x + w / 2, y + h / 2, 0, 0, getAngle(x + w / 2, y + h / 2, view.getCenter().x - screenWidth / 2 + Mouse::getPosition(window).x, view.getCenter().y - screenHeight / 2 +  Mouse::getPosition(window).y), Brics, true, 0.5);
                            basicShells.push_back(thisS);

                            if (setting[2])
                                basicAttack.play();

                        }

                        break;

                }

            }

            /// Слежка за персонажем
            setPlayerCoordinateForView(x, y, w, h);

        }

        /// Функция обновления
        void update(float& time, Map& tMap, RenderWindow &window) {

            /// Управление персонажем
            control(time, window);

            /// Передвижение и проверка на столкновение по оси X
            x += dx * time;
            checkCollisionWithMapX(dx, tMap);

            /// Передвижение и проверка на столкновнеие по оси Y
            y += dy * time;
            checkCollisionWithMapY(dy, tMap);

            /// Задание позиции персонажа
            sprite.setPosition(x, y);

            /// Притяжение к земле
            if (!onGround)
                dy += 0.0015 * time;
            else
                dy = 0;

            /// Контроль пули
            for (auto k = basicShells.begin(); k != basicShells.end(); k++) {

                if (k->getDisappearClock().getElapsedTime().asSeconds() >= k->getDisappearTime().asSeconds())
                    basicShells.erase(k);
                else {

                    k->setSprite("resources/images/characters/brics/basicshell.png");

                    k->setDx(2);
                    k->setDy(2);

                    if (k->getAngle() == 0) {

                        k->setX(k->getX() + k->getDx() * time);
                        k->setDy(0);

                    } else if (k->getAngle() >= 0.1 && k->getAngle() <= 89.9) {

                        k->setX(k->getX() + (1 - k->getAngle() / 90) * k->getDx() * time);
                        k->setY(k->getY() + (k->getAngle() / 90) * k->getDx() * time);

                    } else if (k->getAngle() == 90) {

                        k->setDx(0);
                        k->setY(k->getY() + k->getDy() * time);

                    } else if (k->getAngle() >= 90.1 && k->getAngle() <= 179.9) {

                        k->setX(k->getX() - ((k->getAngle() - 90) / 90) * k->getDx() * time);
                        k->setY(k->getY() + (1 - (k->getAngle() - 90) / 90) * k->getDx() * time);

                    } else if (k->getAngle() == 180) {

                        k->setX(k->getX() - k->getDx() * time);
                        k->setDy(0);

                    } else if (k->getAngle() >= 180.1 && k->getAngle() <= 269.9) {

                        k->setX(k->getX() - (1 - (k->getAngle() - 180) / 90) * k->getDx() * time);
                        k->setY(k->getY() - ((k->getAngle() - 180) / 90) * k->getDx() * time);

                    } else if (k->getAngle() == 270) {

                        k->setDx(0);
                        k->setY(k->getY() - k->getDy() * time);

                    } else if (k->getAngle() >= 270.1 && k->getAngle() <= 359.9) {

                        k->setX(k->getX() + ((k->getAngle() - 270) / 90) * k->getDx() * time);
                        k->setY(k->getY() - (1 - (k->getAngle() - 270) / 90) * k->getDx() * time);

                    }

                    k->getSprite().setPosition(k->getX(), k->getY());

                }

            }

            nicknameText[0].setPosition(x + w / 2, y - 40);
            nicknameText[1].setPosition(nicknameText[0].getPosition().x + 2, nicknameText[0].getPosition().y + 2);
            healthText[0].setPosition(x + w / 2, y - 20);
            healthText[1].setPosition(healthText[0].getPosition().x + 2, healthText[0].getPosition().y + 2);

        }

        /// Функция проверки на столкновение по оси X
        void checkCollisionWithMapX(float& dx, Map& tMap) {

            if (dx > 0) {

                int wallX = (x + w) / blockSide;

                for (int i = y / blockSide; i < (y + h) / blockSide; i++) {

                    bool canGo = true;

                    if (tMap.isSolid(i, wallX))
                        canGo = false;

                    if (!canGo) {

                        x = (wallX - 1) * blockSide - w + blockSide;
                        dx = 0;

                    }

                }

            }

            if (dx < 0) {

                int wallX = x / blockSide;

                for (int i = y / blockSide; i < (y + h) / blockSide; i++) {

                    bool canGo = true;

                    if (tMap.isSolid(i, wallX))
                        canGo = false;

                    if (!canGo) {

                        x = (wallX + 1) * blockSide;
                        dx = 0;

                    }

                }

            }

            if (x < 0) {

                x = 0;
                dx = 0;

            }

            if (x > mapTileWidth - w) {

                x = mapTileWidth - w;
                dx = 0;

            }

        }

        /// Функция проверки на столкновение по оси Y
        void checkCollisionWithMapY(float& dy, Map& tMap) {

            if (dy > 0) {

                int wallY = (y + h) / blockSide;

                for (int i = x / blockSide; i < (x + w) / blockSide; i++) {

                    if (tMap.isSolid(wallY, i)) {

                        y = wallY * blockSide - h;
                        dy = 0;
                        onGround = true;

                        onTrampoline = tMap.isTrampoline(wallY, i);

                    }

                }

            }

            if (dy == 0) {

                int wallY = (y + h) / blockSide;

                bool canGo = true;

                for (int i = x / blockSide; i < (x + w) / blockSide; i++)

                if (tMap.isSolid(wallY, i))
                    canGo = false;

                if (canGo)
                    onGround = false;

            }

            if (dy < 0) {

                int wallY = y / blockSide;

                for (int i = x / blockSide; i < (x + w) / blockSide; i++) {

                    if (tMap.isSolid(wallY, i)) {

                        y = wallY * blockSide + blockSide;
                        dy = 0;

                    }

                }

            }

            if (y < 0) {

                y = 0;
                dy = 0;

            }

            if (y > mapTileHeight - h) {

                y = mapTileHeight - h;
                dy = 0;

            }

        }

};

/// Класс заднего фона
class Background: public Entity {

    /// Конструктор с параметрами и функции
    public:

        /// Конструктор с параметрами
        Background(float x, float y, Image& image): Entity(x, y, 0, 0) {

            setValues(x, y, image);

        }

        void setValues(float x, float y, Image& image) {

            this->x = x;
            this->y = y;
            this->image = image;

            /// Загрузка текстуры и спрайта заднего фона и его спаун
            texture.loadFromImage(image);

            sprite.setTexture(texture);
            sprite.setPosition(x, y);

            this->w = sprite.getTextureRect().width;
            this->h = sprite.getTextureRect().height;

        }

        /// Обновление заднего фона
        void update() {

            x = getTempX() - screenWidth / 2;
            y = getTempY() - screenHeight / 2;

            sprite.setPosition(x, y);

        }

        /// Получение спрайта
        inline Sprite& getSprite() {
            return sprite;
        }

};

/// Класс кнопки
class Button: public Entity {

    protected:

        Text text;

    private:

        bool isButtonPressed = false;

    public:

        Button(string filename, float x, float y): Entity(x, y, 0, 0) {

            setValues(filename, x, y);

        }

        void setValues(string filename, float x, float y) {

            this->x = x;
            this->y = y;
            dx = 0;
            dy = 0;

            image.loadFromFile(filename);
            image.createMaskFromColor(Color(254, 254, 254));

            texture.loadFromImage(image);

            sprite.setTexture(texture);
            sprite.setPosition(x, y);

            w = sprite.getTextureRect().width;
            h = sprite.getTextureRect().height;

        }

        bool isCursorPlacedOn(RenderWindow& window) {

            IntRect rect(int(sprite.getPosition().x * float(window.getSize().x / screenWidth)), int(sprite.getPosition().y * float(window.getSize().y / screenHeight)), int(sprite.getTextureRect().width * float(window.getSize().x / screenWidth)), int(sprite.getTextureRect().height * float(window.getSize().y / screenHeight)));

            Vector2i pos;
            pos.x = (float)Mouse::getPosition(window).x * float(window.getSize().x / screenWidth);
            pos.y = (float)Mouse::getPosition(window).y * float(window.getSize().y / screenHeight);

            return rect.contains(pos);

        }

        inline bool& isPressed() {
            return isButtonPressed;
        }

        void setText(string Text, Font& font, unsigned int characterSize) {

            text.setString(Text);
            text.setFont(font);
            text.setCharacterSize(characterSize);
            text.setStyle(Text::Italic);
            text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
            text.setPosition(x + w / 2, y + h / 2 - 5);

        }

        inline Text& getText() {
            return text;
        }

};

/// Класс чекбокса
class Checkbox: public Button {

    private:

        Texture selTexture;
        bool isCheckboxPressed = false;
        Text border;

    public:

        Checkbox(float x, float y, bool isCheckboxEnabled): Button("resources/images/buttons/checkbox.png", x, y) {

            setValues(x, y, isCheckboxEnabled);

        }

        void setValues(float x, float y, bool isCheckboxEnabled) {

            this->x = x;
            this->y = y;
            dx = 0;
            dy = 0;

            texture.loadFromFile("resources/images/buttons/checkbox.png");
            selTexture.loadFromFile("resources/images/buttons/checkboxSel.png");

            if (!isCheckboxEnabled)
                sprite.setTexture(texture);
            else
                sprite.setTexture(selTexture);

            this->w = sprite.getTextureRect().width;
            this->h = sprite.getTextureRect().height;

            sprite.setPosition(x, y);

        }

        void setText(string Text, Font& font, unsigned int characterSize) {

            text.setString(Text);
            text.setFont(font);
            text.setCharacterSize(characterSize);
            text.setStyle(Text::Italic);
            text.setFillColor(Color::Black);
            text.setOrigin(text.getPosition().x, text.getLocalBounds().height / 2);
            text.setPosition(x + w + 20, y + h / 2 - 5);

            border.setString(Text);
            border.setFont(font);
            border.setCharacterSize(characterSize);
            border.setStyle(Text::Italic);
            border.setFillColor(Color::White);
            border.setOrigin(border.getPosition().x, border.getLocalBounds().height / 2);
            border.setPosition(text.getPosition().x + 2, text.getPosition().y + 2);

        }

        inline bool& isPressed() {
            return isCheckboxPressed;
        }

        inline Texture& getTexture() {
            return texture;
        }

        inline Texture& getSelTexture() {
            return selTexture;
        }

        inline Text& getTextBorder() {
            return border;
        }

};

/// Класс выбора
class Choice: public Button {

    private:

        bool isChoicePressed = false;
        bool isChoiceEnabled;
        Texture charTexture;
        Sprite charSprite;
        Text border;

    public:

        Choice(): Button("", 0, 0) {

        }

        Choice(string filename, float x, float y, bool isChoiceEnabled, float zoom, bool smooth): Button(filename, x, y) {

            setValues(filename, x, y, isChoiceEnabled, zoom, smooth);

        }

        void setValues(string filename, float x, float y, bool isChoiceEnabled, float zoom, bool smooth) {

            this->x = x;
            this->y = y;
            this->isChoiceEnabled = isChoiceEnabled;
            dx = 0;
            dy = 0;

            image.loadFromFile(filename);
            image.createMaskFromColor(Color(254, 254, 254));

            charTexture.loadFromImage(image);
            charTexture.setSmooth(smooth);

            charSprite.setTexture(charTexture);
            charSprite.setScale(zoom, zoom);
            charSprite.setTextureRect(IntRect(32, 0, 64, 48));

            w = charSprite.getLocalBounds().width;
            h = charSprite.getLocalBounds().height;

            charSprite.setOrigin(w / 2, h / 2);
            charSprite.setPosition(x - zoom, y - zoom);

            texture.loadFromFile("resources/images/buttons/border.png");
            sprite.setTexture(texture, true);
            sprite.setScale(zoom, zoom);

            sprite.setOrigin(w / 2, h / 2);
            sprite.setPosition(x, y);

        }

        inline Sprite& getCharSprite() {
            return charSprite;
        }

        void setText(string Text, Font& font, unsigned int characterSize) {

            text.setString(Text);
            text.setFont(font);
            text.setCharacterSize(characterSize);
            text.setStyle(Text::Bold);
            text.setFillColor(Color::Black);
            text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
            text.setPosition(x, y + h * 3.3);

            border.setString(Text);
            border.setFont(font);
            border.setCharacterSize(characterSize);
            border.setStyle(Text::Bold);
            border.setFillColor(Color::White);
            border.setOrigin(border.getLocalBounds().width / 2, border.getLocalBounds().height / 2);
            border.setPosition(text.getPosition().x + 2, text.getPosition().y + 2);

        }

        inline bool& isPressed() {
            return isChoicePressed;
        }

        inline bool& isEnabled() {
            return isChoiceEnabled;
        }

        inline Text& getTextBorder() {
            return border;
        }

};

/// Главное меню
void menu(RenderWindow& window, Clock& clock) {

    /// Установка статуса
    status = Menu;

    ///    discordActivity.application_id = 782989077825454092;

    /// Картинка заднего фона и логотипа
    Image backgroundImage, logotypeImage;
    backgroundImage.loadFromFile("resources/images/background.png");
    logotypeImage.loadFromFile("resources/images/logotypes/Logotype.png");
    logotypeImage.createMaskFromColor(Color(254, 254, 254));

    /// Установка заднего фона и логотипа
    Background background(0, 0, backgroundImage);
    Background logotype(screenWidth / 2 - 508 / 2, 15, logotypeImage);

    /// Кнопки и установка
    Button startButton("resources/images/buttons/button1.png", 10, 400);
    Button settingsButton("resources/images/buttons/button1.png", 10, 520);
    Button charButton("resources/images/buttons/button1.png", 10, 640);
    Button exitButton("resources/images/buttons/button1.png", 10, 1080 - 100 - 20);

    /// Шрифт
    Font font;
    font.loadFromFile("resources/fonts/Comic Sans MS.ttf");

    /// Установка текста

    switch (selLang) {

        case English:

            startButton.setText("Play", font, 48);
            settingsButton.setText("Settings", font, 48);
            charButton.setText("Characters", font, 48);
            exitButton.setText("Exit", font, 48);

            break;

        case Russian:

            startButton.setText("Играть", font, 48);
            settingsButton.setText("Настройки", font, 48);
            charButton.setText("Персонаж", font, 48);
            exitButton.setText("Выйти", font, 48);

            break;

        case German:

            startButton.setText("Spielen", font, 48);
            settingsButton.setText("Einstellungen", font, 48);
            charButton.setText("Figuren", font, 48);
            exitButton.setText("Beenden", font, 48);

            break;

    }

    Choice langChoice;

    switch (selLang) {

        case English:
            langChoice.setValues("resources/images/languages/english.png", screenWidth - 32 - 20, 24 + 20, false, 1, true);
            break;

        case Russian:
            langChoice.setValues("resources/images/languages/russian.png", screenWidth - 32 - 20, 24 + 20, false, 1, true);
            break;

        case German:
            langChoice.setValues("resources/images/languages/german.png", screenWidth - 32 - 20, 24 + 20, false, 1, true);
            break;

    }

    Music music;
    music.openFromFile("resources/music/menuLoop.wav");
    music.setLoop(true);
    music.play();

    while (window.isOpen()) {

        /// Задание скорости игры и обновление времени
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        /// Проверка на закрытие окна
        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

        }

        /// Проверка на нажатие кнопки "Играть"
        if (startButton.isCursorPlacedOn(window)) {

            startButton.getSprite().setColor(Color(128, 128, 255));
            startButton.getText().setFillColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                startButton.getSprite().setColor(Color(64, 64, 255));
                startButton.getText().setFillColor(Color(64, 64, 255));

                startButton.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && startButton.isPressed())
                status = Game;

        } else {

            startButton.isPressed() = false;
            startButton.getSprite().setColor(Color(255, 255, 255));
            startButton.getText().setFillColor(Color(255, 255, 255));

        }

        /// Проверка на нажатие кнопки "Настройки"
        if (settingsButton.isCursorPlacedOn(window)) {

            settingsButton.getSprite().setColor(Color(128, 128, 255));
            settingsButton.getText().setFillColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                settingsButton.getSprite().setColor(Color(64, 64, 255));
                settingsButton.getText().setFillColor(Color(64, 64, 255));

                settingsButton.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && settingsButton.isPressed())
                status = Settings;

        } else {

            settingsButton.isPressed() = false;
            settingsButton.getSprite().setColor(Color(255, 255, 255));
            settingsButton.getText().setFillColor(Color(255, 255, 255));

        }

        /// Проверка на нажатие кнопки "Персонаж"
        if (charButton.isCursorPlacedOn(window)) {

            charButton.getSprite().setColor(Color(128, 128, 255));
            charButton.getText().setFillColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                charButton.getSprite().setColor(Color(64, 64, 255));
                charButton.getText().setFillColor(Color(64, 64, 255));

                charButton.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && charButton.isPressed())
                status = Characters;

        } else {

            charButton.isPressed() = false;
            charButton.getSprite().setColor(Color(255, 255, 255));
            charButton.getText().setFillColor(Color(255, 255, 255));

        }

        /// Проверка на нажате кнопки "Выйти"
        if (exitButton.isCursorPlacedOn(window)) {

            exitButton.getSprite().setColor(Color(128, 128, 255));
            exitButton.getText().setFillColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                exitButton.getSprite().setColor(Color(64, 64, 255));
                exitButton.getText().setFillColor(Color(64, 64, 255));

                exitButton.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && exitButton.isPressed())
                window.close();

        } else {

            exitButton.isPressed() = false;
            exitButton.getSprite().setColor(Color(255, 255, 255));
            exitButton.getText().setFillColor(Color(255, 255, 255));

        }

        langChoice.getCharSprite().setTextureRect(IntRect(0, 0, 64 * 6 - 12, 48 * 6 - 12));
        langChoice.getCharSprite().setOrigin(64 * 3 - 6, 48 * 3 - 6);
        langChoice.getCharSprite().setPosition(langChoice.getSprite().getPosition().x, langChoice.getSprite().getPosition().y);

        /// Проверка на нажатие кнопки "Язык"
        if (langChoice.isCursorPlacedOn(window)) {

            langChoice.getSprite().setScale(1.1, 1.1);
            langChoice.getCharSprite().setScale(1.1 / 6, 1.1 / 6);

            if (Mouse::isButtonPressed(Mouse::Left)) {

                langChoice.getSprite().setScale(0.9, 0.9);
                langChoice.getCharSprite().setScale(0.9 / 6, 0.9 / 6);

                langChoice.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && langChoice.isPressed())
                status = Languages;

        } else {

            langChoice.isPressed() = false;
            langChoice.getSprite().setScale(1, 1);
            langChoice.getCharSprite().setScale(1.001 / 6, 1.001 / 6);

        }

        /// Очистка экрана
        window.clear();

        /// Вывод главного меню
        window.draw(background.getSprite());
        window.draw(logotype.getSprite());
        window.draw(startButton.getSprite());
        window.draw(startButton.getText());
        window.draw(settingsButton.getSprite());
        window.draw(settingsButton.getText());
        window.draw(charButton.getSprite());
        window.draw(charButton.getText());
        window.draw(exitButton.getSprite());
        window.draw(exitButton.getText());
        window.draw(langChoice.getSprite());
        window.draw(langChoice.getCharSprite());

        /// Отображение окна
        window.display();

        /// Сброс функции
        if (status != Menu)
            break;

    }

}

/// Меню настроек
void settings(RenderWindow& window, Clock& clock) {

    /// Установка статуса
    status = Settings;

    /// Картинка заднего фона
    Image backgroundImage, upborderImage;
    backgroundImage.loadFromFile("resources/images/background.png");
    upborderImage.loadFromFile("resources/images/buttons/upborder.png");

    /// Установка заднего фона
    Background background(0, 0, backgroundImage);
    Background upborder(0, 0, upborderImage);

    /// Щрифты
    Font back;
    back.loadFromFile("resources/fonts/Bauhaus.ttf");

    Font font;
    font.loadFromFile("resources/fonts/Comic Sans MS.ttf");

    /// Кнопка "Назад"
    Button backButton("resources/images/buttons/Button2.png", 20, 20);
    backButton.setText("<<<", back, 25);

    Checkbox vsCheckbox(20, 95, setting[0]);
    Checkbox musicCheckbox(20, 200, setting[1]);
    Checkbox soundCheckbox(20, 305, setting[2]);

    Text upborderText("", font, 48);

    switch (selLang) {

        case English:

            vsCheckbox.setText("Vertical sync", font, 36);
            musicCheckbox.setText("Music", font, 36);
            soundCheckbox.setText("Sound effects", font, 36);
            upborderText.setString("Settings");

            break;

        case Russian:

            vsCheckbox.setText("Вертикальная синхронизация", font, 36);
            musicCheckbox.setText("Музыка", font, 36);
            soundCheckbox.setText("Звуковые эффекты", font, 36);
            upborderText.setString("Настройки");

            break;

        case German:

            vsCheckbox.setText("Vertikale Synchronisation", font, 36);
            musicCheckbox.setText("Musik", font, 36);
            soundCheckbox.setText("Soundeffekte", font, 36);
            upborderText.setString("Einstellungen");

            break;

    }

    upborderText.setStyle(Text::Bold);
    upborderText.setFillColor(Color::Black);
    upborderText.setPosition(screenWidth / 2 - upborderText.getLocalBounds().width / 2, 10);

    while (window.isOpen()) {

        /// Задание скорости игры и обновление времени
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        /// Проверка на закрытие окна
        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

        }

        /// Проверка на нажатие кнопки "Назад"
        if (backButton.isCursorPlacedOn(window)) {

            backButton.getSprite().setColor(Color(128, 128, 255));
            backButton.getText().setFillColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                backButton.getSprite().setColor(Color(64, 64, 255));
                backButton.getText().setFillColor(Color(64, 64, 255));

                backButton.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && backButton.isPressed())
                status = Menu;

        } else {

            backButton.isPressed() = false;
            backButton.getSprite().setColor(Color(255, 255, 255));
            backButton.getText().setFillColor(Color(255, 255, 255));

        }

        /// Проверка на нажатие чекбокса "Вертикальная синхронизация"
        if (vsCheckbox.isCursorPlacedOn(window)) {

            vsCheckbox.getSprite().setColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                vsCheckbox.getSprite().setColor(Color(64, 64, 255));
                vsCheckbox.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && vsCheckbox.isPressed()) {

                if (setting[0]) {

                    setting[0] = false;
                    window.setVerticalSyncEnabled(false);
                    vsCheckbox.getSprite().setTexture(vsCheckbox.getTexture());

                } else {

                    setting[0] = true;
                    window.setVerticalSyncEnabled(true);
                    vsCheckbox.getSprite().setTexture(vsCheckbox.getSelTexture());

                }

                vsCheckbox.isPressed() = false;

            }

        } else {

            vsCheckbox.isPressed() = false;
            vsCheckbox.getSprite().setColor(Color(255, 255, 255));

        }

        /// Проверка на нажатие чекбокса "Музыка"
        if (musicCheckbox.isCursorPlacedOn(window)) {

            musicCheckbox.getSprite().setColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                musicCheckbox.getSprite().setColor(Color(64, 64, 255));
                musicCheckbox.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && musicCheckbox.isPressed()) {

                if (setting[1]) {

                    setting[1] = false;
                    musicCheckbox.getSprite().setTexture(musicCheckbox.getTexture());

                } else {

                    setting[1] = true;
                    musicCheckbox.getSprite().setTexture(musicCheckbox.getSelTexture());

                }

                musicCheckbox.isPressed() = false;

            }

        } else {

            musicCheckbox.isPressed() = false;
            musicCheckbox.getSprite().setColor(Color(255, 255, 255));

        }

        /// Проверка на нажатие чекбокса "Звуковые эффекты"
        if (soundCheckbox.isCursorPlacedOn(window)) {

            soundCheckbox.getSprite().setColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                soundCheckbox.getSprite().setColor(Color(64, 64, 255));
                soundCheckbox.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && soundCheckbox.isPressed()) {

                if (setting[2]) {

                    setting[2] = false;
                    soundCheckbox.getSprite().setTexture(soundCheckbox.getTexture());

                } else {

                    setting[2] = true;
                    soundCheckbox.getSprite().setTexture(soundCheckbox.getSelTexture());

                }

                soundCheckbox.isPressed() = false;

            }

        } else {

            soundCheckbox.isPressed() = false;
            soundCheckbox.getSprite().setColor(Color(255, 255, 255));

        }

        /// Очистка экрана
        window.clear();

        /// Вывод меню настроек
        window.draw(background.getSprite());

        window.draw(upborder.getSprite());
        window.draw(upborderText);

        window.draw(backButton.getSprite());
        window.draw(backButton.getText());

        window.draw(vsCheckbox.getSprite());
        window.draw(vsCheckbox.getTextBorder());
        window.draw(vsCheckbox.getText());

        window.draw(musicCheckbox.getSprite());
        window.draw(musicCheckbox.getTextBorder());
        window.draw(musicCheckbox.getText());

        window.draw(soundCheckbox.getSprite());
        window.draw(soundCheckbox.getTextBorder());
        window.draw(soundCheckbox.getText());

        /// Отображение окна
        window.display();

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            status = Menu;

        if (status != Settings)
            break;

    }

}

/// Меню выбора персонажа
void characters(RenderWindow& window, Clock& clock) {

    /// Установка статуса
    status = Characters;

    /// Картинка заднего фона
    Image backgroundImage, upborderImage;
    backgroundImage.loadFromFile("resources/images/background.png");
    upborderImage.loadFromFile("resources/images/buttons/upborder.png");

    /// Установка заднего фона
    Background background(0, 0, backgroundImage);
    Background upborder(0, 0, upborderImage);

    /// Щрифты
    Font back;
    back.loadFromFile("resources/fonts/Bauhaus.ttf");

    Font font;
    font.loadFromFile("resources/fonts/Comic Sans MS.ttf");

    /// Кнопка "Назад"
    Button backButton("resources/images/buttons/Button2.png", 20, 20);
    backButton.setText("<<<", back, 25);

    /// Кнопки выбора
    Choice charChoice[2] = {

        Choice(cBrics.getSkin(), screenWidth / 4, 400, selChar == Brics, 6, false),
        Choice(cFastquake.getSkin(), screenWidth / 2, 400, selChar == Fastquake, 6, false)

    };

    Text upborderText("", font, 48);

    switch (selLang) {

        case English:

            charChoice[0].setText("Brics", font, 36);
            charChoice[1].setText("Fastquake", font, 36);
            upborderText.setString("Characters");

            break;

        case Russian:

            charChoice[0].setText("Брикс", font, 36);
            charChoice[1].setText("Фастквейк", font, 36);
            upborderText.setString("Персонаж");

            break;

        case German:

            charChoice[0].setText("Briechs", font, 36);
            charChoice[1].setText("Fastquaehk", font, 36);
            upborderText.setString("Figuren");

            break;

    }

    upborderText.setStyle(Text::Bold);
    upborderText.setFillColor(Color::Black);
    upborderText.setPosition(screenWidth / 2 - upborderText.getLocalBounds().width / 2, 10);

    Image isSelImage;
    isSelImage.loadFromFile("resources/images/buttons/isSelected.png");
    isSelImage.createMaskFromColor(Color(254, 254, 254));

    Texture isSelTexture;
    isSelTexture.loadFromImage(isSelImage);

    Sprite isSelSprite;
    isSelSprite.setTexture(isSelTexture);
    isSelSprite.setOrigin(isSelSprite.getLocalBounds().width / 2, isSelSprite.getGlobalBounds().height / 2);

    while (window.isOpen()) {

        /// Задание скорости игры и обновление времени
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        /// Проверка на закрытие окна
        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

        }

        /// Проверка на нажатие кнопки "Назад"
        if (backButton.isCursorPlacedOn(window)) {

            backButton.getSprite().setColor(Color(128, 128, 255));
            backButton.getText().setFillColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                backButton.getSprite().setColor(Color(64, 64, 255));
                backButton.getText().setFillColor(Color(64, 64, 255));

                backButton.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && backButton.isPressed())
                status = Menu;

        } else {

            backButton.isPressed() = false;
            backButton.getSprite().setColor(Color(255, 255, 255));
            backButton.getText().setFillColor(Color(255, 255, 255));

        }

        for (int i = 0; i < 2; ++i) {

            charChoice[i].isEnabled() = i == selChar;

            if (charChoice[i].isEnabled())
                isSelSprite.setPosition(charChoice[i].getSprite().getPosition().x, charChoice[i].getSprite().getPosition().y);

            if (charChoice[i].isCursorPlacedOn(window)) {

                    charChoice[i].getCharSprite().setScale(6.1, 6.1);
                    charChoice[i].getSprite().setScale(6.1, 6.1);

                    if (charChoice[i].isEnabled())
                        isSelSprite.setScale(6.1 / 6, 6.1 / 6);

                    if (i == Brics || i == Fastquake)
                        charChoice[i].getSprite().setColor(Color(75, 150, 150));

                if (Mouse::isButtonPressed(Mouse::Left)) {

                    charChoice[i].getCharSprite().setScale(5.9, 5.9);
                    charChoice[i].getSprite().setScale(5.9, 5.9);

                    if (charChoice[i].isEnabled())
                        isSelSprite.setScale(5.9 / 6, 5.9 / 6);

                    if (i == Brics || i == Fastquake)
                        charChoice[i].getSprite().setColor(Color(75 / 2, 150 / 2, 150 / 2));

                    charChoice[i].isPressed() = true;

                }

                if (!Mouse::isButtonPressed(Mouse::Left) && charChoice[i].isPressed()) {

                    switch (i) {

                        case Brics:
                            selChar = Brics;
                            break;

                        case Fastquake:
                            selChar = Fastquake;
                            break;

                    }

                }

            } else {

                charChoice[i].isPressed() = false;

                charChoice[i].getCharSprite().setScale(6, 6);
                charChoice[i].getSprite().setScale(6, 6);

                if (charChoice[i].isEnabled())
                    isSelSprite.setScale(1, 1);

                if (i == Brics || i == Fastquake)
                    charChoice[i].getSprite().setColor(Color(75, 150, 150));

            }

        }

        /// Очистка экрана
        window.clear();

        window.draw(background.getSprite());
        window.draw(upborder.getSprite());
        window.draw(upborderText);
        window.draw(backButton.getSprite());
        window.draw(backButton.getText());
        window.draw(isSelSprite);
        for (int i = 0; i < 2; ++i)
            window.draw(charChoice[i].getSprite());
        for (int i = 0; i < 2; ++i)
            window.draw(charChoice[i].getCharSprite());
        for (int i = 0; i < 2; ++i)
            window.draw(charChoice[i].getTextBorder());
        for (int i = 0; i < 2; ++i)
            window.draw(charChoice[i].getText());

        /// Отображение окна
        window.display();

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            status = Menu;

        if (status != Characters)
            break;

    }

}

/// Меню выбра языка
void language(RenderWindow& window, Clock& clock) {

    /// Установка статуса
    status = Languages;

    /// Картинка заднего фона
    Image backgroundImage, upborderImage;
    backgroundImage.loadFromFile("resources/images/background.png");
    upborderImage.loadFromFile("resources/images/buttons/upborder.png");

    /// Установка заднего фона
    Background background(0, 0, backgroundImage);
    Background upborder(0, 0, upborderImage);

    /// Щрифты
    Font back;
    back.loadFromFile("resources/fonts/Bauhaus.ttf");

    Font font;
    font.loadFromFile("resources/fonts/Comic Sans MS.ttf");

    /// Кнопка "Назад"
    Button backButton("resources/images/buttons/Button2.png", 20, 20);
    backButton.setText("<<<", back, 25);

    Choice langChoice[3] = {

        Choice("resources/images/languages/english.png", screenWidth / 4 + 0, 400, selLang == English, 6, true),
        Choice("resources/images/languages/russian.png", screenWidth / 2 + 0, 400, selLang == Russian, 6, true),
        Choice("resources/images/languages/german.png", screenWidth / 2 + screenWidth / 4, 400, selLang == German, 6, true)

    };

    langChoice[0].setText("English", font, 36);
    langChoice[1].setText("Русский", font, 36);
    langChoice[2].setText("Deutsch", font, 36);

    Text upborderText("", font, 48);

    switch (selLang) {

        case English:
            upborderText.setString("Language");
            break;

        case Russian:
            upborderText.setString("Язык");
            break;

        case German:
            upborderText.setString("Sprache");
            break;

    }

    upborderText.setStyle(Text::Bold);
    upborderText.setFillColor(Color::Black);

    Image isSelImage;
    isSelImage.loadFromFile("resources/images/buttons/isSelected.png");
    isSelImage.createMaskFromColor(Color(254, 254, 254));

    Texture isSelTexture;
    isSelTexture.loadFromImage(isSelImage);

    Sprite isSelSprite;
    isSelSprite.setTexture(isSelTexture);
    isSelSprite.setOrigin(isSelSprite.getLocalBounds().width / 2, isSelSprite.getGlobalBounds().height / 2);

    while (window.isOpen()) {

        /// Задание скорости игры и обновление времени
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        /// Проверка на закрытие окна
        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

        }

        /// Проверка на нажатие кнопки "Назад"
        if (backButton.isCursorPlacedOn(window)) {

            backButton.getSprite().setColor(Color(128, 128, 255));
            backButton.getText().setFillColor(Color(128, 128, 255));

            if (Mouse::isButtonPressed(Mouse::Left)) {

                backButton.getSprite().setColor(Color(64, 64, 255));
                backButton.getText().setFillColor(Color(64, 64, 255));

                backButton.isPressed() = true;

            }

            if (!Mouse::isButtonPressed(Mouse::Left) && backButton.isPressed())
                status = Menu;

        } else {

            backButton.isPressed() = false;
            backButton.getSprite().setColor(Color(255, 255, 255));
            backButton.getText().setFillColor(Color(255, 255, 255));

        }

        for (int i = 0; i < 3; ++i) {

            langChoice[i].getCharSprite().setTextureRect(IntRect(0, 0, 64 * 6 - 12, 48 * 6 - 12));
            langChoice[i].getCharSprite().setOrigin(64 * 3 - 6, 48 * 3 - 6);
            langChoice[i].getCharSprite().setPosition(langChoice[i].getSprite().getPosition().x, langChoice[i].getSprite().getPosition().y);

            langChoice[i].isEnabled() = i == selLang;

            if (langChoice[i].isEnabled())
                isSelSprite.setPosition(langChoice[i].getSprite().getPosition().x, langChoice[i].getSprite().getPosition().y);

            if (langChoice[i].isCursorPlacedOn(window)) {

                    langChoice[i].getCharSprite().setScale(6.1 / 6, 6.1 / 6);
                    langChoice[i].getSprite().setScale(6.1, 6.1);

                    if (langChoice[i].isEnabled())
                        isSelSprite.setScale(6.1 / 6, 6.1 / 6);

                if (Mouse::isButtonPressed(Mouse::Left)) {

                    langChoice[i].getCharSprite().setScale(5.9 / 6, 5.9 / 6);
                    langChoice[i].getSprite().setScale(5.9, 5.9);

                    if (langChoice[i].isEnabled())
                        isSelSprite.setScale(5.9 / 6, 5.9 / 6);

                    langChoice[i].isPressed() = true;

                }

                if (!Mouse::isButtonPressed(Mouse::Left) && langChoice[i].isPressed()) {

                    switch (i) {

                        case (int)English:
                            selLang = English;
                            upborderText.setString("Language");
                            break;

                        case (int)Russian:
                            selLang = Russian;
                            upborderText.setString("Язык");
                            break;

                        case (int)German:
                            selLang = German;
                            upborderText.setString("Sprache");
                            break;

                    }

                }

            } else {

                langChoice[i].isPressed() = false;

                langChoice[i].getCharSprite().setScale(1, 1);
                langChoice[i].getSprite().setScale(6, 6);

                if (langChoice[i].isEnabled())
                    isSelSprite.setScale(1, 1);

            }

        }

        upborderText.setOrigin(upborderText.getLocalBounds().width / 2, 0);
        upborderText.setPosition(screenWidth / 2, 10);

        /// Очистка экрана
        window.clear();

        window.draw(background.getSprite());
        window.draw(upborder.getSprite());
        window.draw(upborderText);
        window.draw(backButton.getSprite());
        window.draw(backButton.getText());
        window.draw(isSelSprite);
        for (int i = 0; i < 3; ++i)
            window.draw(langChoice[i].getSprite());
        for (int i = 0; i < 3; ++i)
            window.draw(langChoice[i].getCharSprite());
        for (int i = 0; i < 3; ++i)
            window.draw(langChoice[i].getTextBorder());
        for (int i = 0; i < 3; ++i)
            window.draw(langChoice[i].getText());

        /// Отображение окна
        window.display();

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            status = Menu;

        if (status != Languages)
            break;

    }

}

/// Игровой процесс
void game(RenderWindow& window, Clock& clock) {

    status = Game;

    /// Адреса файлов слоёв
    const string frg = "resources/maps/flood/_foreground.csv";
    const string itc = "resources/maps/flood/_interaction.csv";
    const string bdg = "resources/maps/flood/_buildings.csv";
    const string bcg = "resources/maps/flood/_background.csv";
    const string sld = "resources/maps/flood/_solid.csv";

    /// Адрес изображения тайлсета
    const string tileSet = "resources/images/tileset.png";

    /// Создание карты
    Map tMap(frg, itc, bdg, bcg, sld);

    /// Создание объекта игрока
    Player player(0, 0, 128, 192, selChar, Right, "Коронавирус");

    Image bgImage;
    bgImage.loadFromFile("resources/images/background.png");
    Background bg(0, 0, bgImage);

    /// Шрифт
    Font font;
    font.loadFromFile("resources/fonts/Comic Sans MS.ttf");

    Clock timer;

    Text timerText[2] = {
        Text(to_string(int(timer.getElapsedTime().asSeconds()) / 60) + ":" + to_string(int(timer.getElapsedTime().asSeconds()) % 60), font, 36),
        Text(to_string(int(timer.getElapsedTime().asSeconds()) / 60) + ":" + to_string(int(timer.getElapsedTime().asSeconds()) % 60), font, 36)
    };

    timerText[1].setFillColor(Color::Black);

    /// Пока окно открыто
    while (window.isOpen()) {

        /// Задание скорости игры и обновление времени
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        /// Проверка на закрытие окна
        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

        }

        /// Обновление игрока и заднего фона
        player.update(time, tMap, window);
        bg.update();
        timerText[0].setString(to_string(int(timer.getElapsedTime().asSeconds()) / 60) + ":" + to_string(int(timer.getElapsedTime().asSeconds()) / 10 % 6) + to_string(int(timer.getElapsedTime().asSeconds()) % 10));
        timerText[0].setOrigin(timerText[0].getLocalBounds().width / 2, timerText[0].getLocalBounds().height / 2);
        timerText[0].setPosition(tempX, tempY - screenHeight / 2 + timerText[0].getLocalBounds().height / 2 + 20);
        timerText[1].setString(to_string(int(timer.getElapsedTime().asSeconds()) / 60) + ":" + to_string(int(timer.getElapsedTime().asSeconds()) / 10 % 6) + to_string(int(timer.getElapsedTime().asSeconds()) % 10));
        timerText[1].setOrigin(timerText[1].getLocalBounds().width / 2, timerText[1].getLocalBounds().height / 2);
        timerText[1].setPosition(timerText[0].getPosition().x + 2, timerText[0].getPosition().y + 2);

        /// Задание обзора
        window.setView(view);

        /// Очистка экрана
        window.clear();

        auto basicShells = player.getBasicShellsList();

        /// Вывод слоёв по порядку и игрока
        window.draw(bg.getSprite());
        tMap.drawLayer(tMap.getBackgroundLayer(), window, tileSet);
        tMap.drawLayer(tMap.getBuildingsLayer(), window, tileSet);
        tMap.drawLayer(tMap.getInteractionLayer(), window, tileSet);

        for (auto k = basicShells.begin(); k != basicShells.end(); k++) {
            window.draw(k->getSprite());
        }

        window.draw(player.getSprite());
        window.draw(player.getNicknameBorder());
        window.draw(player.getNicknameText());
        window.draw(player.getHealthBorder());
        window.draw(player.getHealthText());
        tMap.drawLayer(tMap.getForegroundLayer(), window, tileSet);
        window.draw(timerText[1]);
        window.draw(timerText[0]);

        /// Отображение окна
        window.display();

        if (status != Game) {

            view.setCenter(screenWidth / 2, screenHeight / 2);
            window.setView(view);
            break;

        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            status = Menu;

    }

}

#endif
