#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

int MainTwo();

enum building_type
{
    Дом,
    Гараж,
    Сарай,
    Баня
};

enum room_type
{
    спальня,
    кухня,
    ванная,
    детская,
    гостиная
};


class sectionClass
{

    friend void Start(sectionClass* value);
    friend void UpdateSection(vector<sectionClass>& section, int& generalSquare);

protected:

    int squareSection;
    int quantityBuildings;
    vector<building_type> buildingsOnSection;

public:

    class houseClass
    {
        friend sectionClass;


        vector<vector<room_type> > rooms;
        vector<int> heightRoof;
        vector<int> squareRooms;
        bool oven;
        int squareHouse;
        int quantityFloors;
        int quantityRooms;

    public:
        houseClass StartHouse(sectionClass* value);

        void PrintHouse();

        int GetSquare()
        {
            return this->squareHouse;
        }

        void operator = (const houseClass& other)
        {
            this->heightRoof = other.heightRoof;
            this->oven = other.oven;
            this->quantityFloors = other.quantityFloors;
            this->quantityRooms = other.quantityRooms;
            this->rooms = other.rooms;
            this->squareHouse = other.squareHouse;
            this->squareRooms = other.squareRooms;
        }

    };

    class garageClass
    {
        int squareGarage;

    public:
        garageClass StartGarage(sectionClass* value);



        void PrintGarage();

        int GetSquare()
        {
            return this->squareGarage;
        }

        void operator = (const garageClass& other)
        {
            this->squareGarage = other.squareGarage;
        }
    };

    class shedClass
    {
        int squareShed;

    public:
        shedClass StartShed(sectionClass* value);

        void PrintShed();

        int GetSquare()
        {
            return this->squareShed;
        }

        void operator = (const shedClass& other)
        { 
            this->squareShed = other.squareShed;
        }
    };

    class bathhouseClass
    {
        int squareBathhouse;
        bool oven_bathhouse;

    public:

        bathhouseClass StartBathhouse(sectionClass* value);
        void PrintBathhouse();
        int GetSquare()
        {
            return this->squareBathhouse;
        }
        void operator = (const bathhouseClass& other)
        {
            this->squareBathhouse = other.squareBathhouse;
            this->oven_bathhouse = other.oven_bathhouse;
        }
    };

    void Print(int& generalSquare)
    {
        int quantityHouse{ 0 };
        int quantityGarage{ 0 };
        int quantityBathhouse{ 0 };
        int quantityShed{ 0 };
        cout << "Площадь участка: " << squareSection << "м^2" << endl;
        generalSquare += squareSection;
        for (int i = 0; i < quantityBuildings; i++)
        {
            cout << endl;
            if (buildingsOnSection[i] == building_type::Дом)
            {
                cout << "-------- Дом " << i + 1 << " --------" << endl;

                houses[quantityHouse].PrintHouse();
                quantityHouse++;

            }
            else if (buildingsOnSection[i] == building_type::Гараж)
            {
                cout << "------- Гараж " << i + 1 << " -------" << endl;

                garages[quantityGarage].PrintGarage();
                quantityGarage += 1;
            }
            else if (buildingsOnSection[i] == building_type::Баня)
            {
                cout << "------- Баня " << i + 1 << " -------" << endl;

                bathhouses[quantityBathhouse].PrintBathhouse();
                quantityBathhouse += 1;
            }
            else if (buildingsOnSection[i] == building_type::Сарай)
            {
                cout << "------- Сарай " << i + 1 << " -------" << endl;
                 
                sheds[quantityShed].PrintShed();
                quantityShed += 1;
            }
        }


    }


public:
    sectionClass::houseClass* temp_house;
    sectionClass::garageClass* temp_garage;
    sectionClass::bathhouseClass* temp_bathhouse;
    sectionClass::shedClass* temp_shed;
    vector<houseClass> houses;
    vector<garageClass> garages;
    vector<bathhouseClass> bathhouses;
    vector<shedClass> sheds;
    friend houseClass;

};




void Start(sectionClass* value)
{

    cout << "Постройки кол-во: ";
    cin >> value->quantityBuildings;
    string build;
    for (int i = 0; i < value->quantityBuildings; i++)
    {
        while (true)
        {
            cout << endl << "Постройка " << i + 1 << ": ";
            cin >> build;
            if (build == "Дом" || build == "дом")
            {
                value->houses.push_back(value->temp_house->StartHouse(value));
                value->buildingsOnSection.push_back(building_type::Дом);
                break;
            }
            else if (build == "Гараж" || build == "гараж")
            {
                value->garages.push_back(value->temp_garage->StartGarage(value));
                value->buildingsOnSection.push_back(building_type::Гараж);
                break;
            }
            else if (build == "Баня" || build == "баня")
            {
                value->bathhouses.push_back(value->temp_bathhouse->StartBathhouse(value));
                value->buildingsOnSection.push_back(building_type::Баня);
                break;
            }
            else if (build == "Сарай" || build == "сарай")
            {
                value->sheds.push_back(value->temp_shed->StartShed(value));
                value->buildingsOnSection.push_back(building_type::Сарай);
                break;
            }
            else
            {
                cout << "Неверный ввод !!! Введите верную постройку: " << endl;
                continue;
            }

        }

    }
}

void StartSection(int& quantitySections, int generalSquare, vector<sectionClass>& section)
{
    for (int i = 0; i < quantitySections; i++)
    {
        sectionClass* sectioni = new sectionClass;
        cout << endl << "======== УЧАСТОК " << i + 1 << " ========" << endl;
        Start(sectioni);
        section.push_back(*sectioni);
        delete sectioni;
    }

    cout << endl << endl << "========Вывод========" << endl << endl;

    for (int i = 0; i < size(section); i++)
    {

        cout << endl << endl << "======== УЧАСТОК " << i + 1 << " ========" << endl;
        section[i].Print(generalSquare);
    }
    cout << endl << endl << endl << "======== Общая площадь ========" << endl;
    cout << generalSquare << "м^2" << endl << endl;
}

void UpdateSection(vector<sectionClass>& section, int& generalSquare)
{
    cout << "Что вы хотите обновить? (введите цифру)" << endl << "1. Все данные посёлка" << endl << "2. Все данные определённого участка" << endl << "3. Данные определённой постройки на определённом участке" << endl;
    char chooseUpdate{};
    int chooseUpdateSection;
    while (true)
    {
        cout << "Ответ: ";
        cin >> chooseUpdate;
        if (chooseUpdate == '1')
        {
            MainTwo();
        }
        else if (chooseUpdate == '2')
        {
            cout << "Какой участок из " << size(section) << " вы хотите обновить? ";
            cin >> chooseUpdateSection;
            section[chooseUpdateSection - 1].buildingsOnSection.clear();
            section[chooseUpdateSection - 1].houses.clear();
            section[chooseUpdateSection - 1].garages.clear();
            section[chooseUpdateSection - 1].bathhouses.clear();
            section[chooseUpdateSection - 1].sheds.clear();
            //Баг
            section[chooseUpdateSection - 1].squareSection = 0;
            Start(&section[chooseUpdateSection - 1]);
            return;
        }
        else if (chooseUpdate == '3')
        {
            string chooseUpdateBuilding;
            int quantityHouses{ 0 };
            int quantityGarages{ 0 };
            int quantityBathhouses{ 0 };
            int quantitySheds{ 0 };
            while (true)
            {
                if (size(section) == 1)
                {
                    chooseUpdateSection = 1;
                }
                else
                {
                    cout << "На каком участке из " << size(section) << " вы хотите обновить данные постройки?";
                    cin >> chooseUpdateSection;
                    if (chooseUpdateSection < 1 || chooseUpdateSection > size(section))
                    {
                        cout << "Неверный номер участка" << endl;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                
            }

            cout << "На вашем участке имеется: " << ": " << endl;
            for (int i = 0; i < section[chooseUpdateSection - 1].quantityBuildings; i++)
            {
                if (section[chooseUpdateSection - 1].buildingsOnSection[i] == building_type::Дом && quantityHouses == 0)
                {
                    cout << "Дом " << "(" << size(section[chooseUpdateSection - 1].houses) << ")" << endl;
                    quantityHouses++;
                }
                else if (section[chooseUpdateSection - 1].buildingsOnSection[i] == building_type::Гараж && quantityGarages == 0)
                {
                    cout << "Гараж " << "(" << size(section[chooseUpdateSection - 1].garages) << ")" << endl;
                    quantityGarages++;
                }
                else if (section[chooseUpdateSection - 1].buildingsOnSection[i] == building_type::Баня && quantityBathhouses == 0)
                {
                    cout << "Баня " << "(" << size(section[chooseUpdateSection - 1].bathhouses) << ")" << endl;
                    quantityBathhouses++;
                }
                else if (section[chooseUpdateSection - 1].buildingsOnSection[i] == building_type::Сарай && quantitySheds == 0)
                {
                    cout << "Сарай " << "(" << size(section[chooseUpdateSection - 1].sheds) << ")" << endl;
                    quantitySheds++;
                }
            }
            cout << "Введите название постройки (Дом, гараж и тд.): ";
            cin >> chooseUpdateBuilding;
            if (chooseUpdateBuilding == "Дом" || chooseUpdateBuilding == "дом")
            {
                int chooseUpdateHouses{ 0 };
                if (size(section[chooseUpdateSection - 1].houses) > 1)
                {
                    for (int i = 0; i < size(section[chooseUpdateSection - 1].houses); i++)
                    {
                        cout << "Какой из " << size(section[chooseUpdateSection - 1].houses) << " домов вы хотите изменить? (Введите цифру): ";
                        cin >> chooseUpdateHouses;
                        section[chooseUpdateSection - 1].squareSection -= section[chooseUpdateSection - 1].houses[chooseUpdateHouses - 1].GetSquare();
                        section[chooseUpdateSection - 1].houses[chooseUpdateHouses - 1] = section[chooseUpdateSection - 1].temp_house->StartHouse(&section[chooseUpdateSection - 1]);
                        return;
                    }
                }
                else
                {
                    section[chooseUpdateSection - 1].squareSection -= section[chooseUpdateSection - 1].houses[0].GetSquare();
                    section[chooseUpdateSection - 1].houses[0] = section[chooseUpdateSection - 1].temp_house->StartHouse(&section[chooseUpdateSection - 1]);
                    return;
                }
            }
            else if (chooseUpdateBuilding == "Гараж" || chooseUpdateBuilding == "гараж")
            {
                int chooseUpdateGarages{ 0 };
                if (size(section[chooseUpdateSection - 1].garages) > 1)
                {
                    for (int i = 0; i < size(section[chooseUpdateSection - 1].garages); i++)
                    {
                        cout << "Какой из " << size(section[chooseUpdateSection - 1].garages) << " гаражей вы хотите изменить? (Введите цифру): ";
                        cin >> chooseUpdateGarages;
                        section[chooseUpdateSection - 1].squareSection -= section[chooseUpdateSection - 1].garages[chooseUpdateGarages - 1].GetSquare();
                        section[chooseUpdateSection - 1].garages[chooseUpdateGarages - 1] = section[chooseUpdateSection - 1].temp_garage->StartGarage(&section[chooseUpdateSection - 1]);
                        return;
                    }
                }
                else
                {
                    section[chooseUpdateSection - 1].squareSection -= section[chooseUpdateSection - 1].garages[0].GetSquare();
                    section[chooseUpdateSection - 1].garages[0] = section[chooseUpdateSection - 1].temp_garage->StartGarage(&section[chooseUpdateSection - 1]);
                    return;
                }
            }
            else if (chooseUpdateBuilding == "Баня" || chooseUpdateBuilding == "баня")
            {
                int chooseUpdateBathhouse{ 0 };
                if (size(section[chooseUpdateSection - 1].bathhouses) > 1)
                {
                    for (int i = 0; i < size(section[chooseUpdateSection - 1].bathhouses); i++)
                    {
                        cout << "Какую из " << size(section[chooseUpdateSection - 1].bathhouses) << " бань вы хотите изменить? (Введите цифру): ";
                        cin >> chooseUpdateBathhouse;
                        section[chooseUpdateSection - 1].squareSection -= section[chooseUpdateSection - 1].bathhouses[chooseUpdateBathhouse - 1].GetSquare();
                        section[chooseUpdateSection - 1].bathhouses[chooseUpdateBathhouse - 1] = section[chooseUpdateSection - 1].temp_bathhouse->StartBathhouse(&section[chooseUpdateSection - 1]);
                        return;
                    }
                }
                else
                {
                    section[chooseUpdateSection - 1].squareSection -= section[chooseUpdateSection - 1].bathhouses[0].GetSquare();
                    section[chooseUpdateSection - 1].bathhouses[0] = section[chooseUpdateSection - 1].temp_bathhouse->StartBathhouse(&section[chooseUpdateSection - 1]);
                    return;
                }
            }
            else if (chooseUpdateBuilding == "Сарай" || chooseUpdateBuilding == "сарай")
            {
                int chooseUpdateShed{ 0 };
                if (size(section[chooseUpdateSection - 1].sheds) > 1)
                {
                    for (int i = 0; i < size(section[chooseUpdateSection - 1].sheds); i++)
                    {
                        cout << "Какой из " << size(section[chooseUpdateSection - 1].sheds) << " сараев вы хотите изменить? (Введите цифру): ";
                        cin >> chooseUpdateShed;
                        section[chooseUpdateSection - 1].squareSection -= section[chooseUpdateSection - 1].sheds[chooseUpdateShed - 1].GetSquare();
                        section[chooseUpdateSection - 1].sheds[chooseUpdateShed - 1] = section[chooseUpdateSection - 1].temp_shed->StartShed(&section[chooseUpdateSection - 1]);
                        return;
                    }
                }
                else
                {
                    section[chooseUpdateSection - 1].squareSection -= section[chooseUpdateSection - 1].sheds[0].GetSquare();
                    section[chooseUpdateSection - 1].sheds[0] = section[chooseUpdateSection - 1].temp_shed->StartShed(&section[chooseUpdateSection - 1]);
                    return;
                }
            }

            else
            {
                cout << "Я не знаю такой постройки" << endl;
            }
        }
        else
        {
            cout << "Я не знаю такой команды" << endl;
        }
    }
}

void AddSection(vector<sectionClass>& section, int &quantitySectios)
{
    quantitySectios++;
    sectionClass* sectioni = new sectionClass;
    cout << endl << "======== УЧАСТОК " << quantitySectios << " ========" << endl;
    Start(sectioni);
    section.push_back(*sectioni);
    delete sectioni;
}

int MainTwo()
{
    vector<sectionClass> section;
    int quantitySectios{ 0 };
    int generalSquare{ 0 };
    cout << "Кол-во учатсков: ";
    cin >> quantitySectios;
    cin.ignore();

    StartSection(quantitySectios, generalSquare, section);

    char choose;
    while (true)
    {
        cout << endl << "---------------------" << endl << "Что вы хотите сделать? (Введите цифру)" << endl << "1. Изменить данные" << endl << "2. Удалить определённый участок" << endl << "3. Добавить участок" << endl << "4. Показать данные" << endl << "5. Завершить работу" << endl << "---------------------" << endl;
        cout << "Ответ: ";
        cin >> choose;
        cout << endl;
        if (choose == '1')
        {
            UpdateSection(section, generalSquare);
        }
        else if (choose == '2')
        {
            int chooseDeleteSection{0};
            cout << "Какой участок вы хотите удалить из " << size(section) << "? (Введите цифру: )";
            cin >> chooseDeleteSection;
            section.erase(section.begin() + (chooseDeleteSection-1));
        
        }
        else if (choose == '3')
        {
            AddSection(section, quantitySectios);
            

        }
        else if (choose == '4')
        {
            generalSquare = 0;
            for (int i = 0; i < size(section); i++)
            {

                cout << endl << endl << endl << endl << "======== УЧАСТОК " << i + 1 << " ========" << endl;
                section[i].Print(generalSquare);
            }
            cout << endl << endl << endl << "======== Общая площадь ========" << endl;
            cout << generalSquare << "м^2" << endl << endl;
        }
        else if (choose == '5')
        {
            return 0;
        }
        else
        {
            cout << endl << "Я не знаю такой команды" << endl;
            continue;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MainTwo();
    

}



sectionClass::houseClass sectionClass::houseClass::StartHouse(sectionClass* value)
{
    houseClass User_house;
    
    
    while (true)
    {
        cout << "Площадь дома: ";
        cin >> User_house.squareHouse;
        if (User_house.squareHouse < 1)
        {
            cout << "Неверное значение" << endl;
            continue;
        }
        else
        {
            break;
        }
    }
    

    string ovenInHouse_element;
    while (true)
    {
        cout << "Имеется ли у вас печь с трубой в доме? (да/нет): ";
        cin >> ovenInHouse_element;
        if (ovenInHouse_element == "да")
        {
            User_house.oven = true;
            break;
        }
        else if (ovenInHouse_element == "нет")
        {
            User_house.oven = false;
            break;
        }
        else
        {
            cout << "Я не знаю такого ответа" << endl;
            continue;
        }
    }
    while (true)
    {
        cout << "Количестко этажей: ";
        cin >> User_house.quantityFloors;
        if (User_house.quantityFloors < 1 || User_house.quantityFloors > 3)
        {
            cout << "Неверное значение" << endl;
            continue;
        }
        else
        {
            break;
        }
    }
    User_house.rooms.resize(User_house.quantityFloors);

    int heightRoof_element;
    for (int i = 0; i < User_house.quantityFloors; i++)
    {
        cout << "Высота " << i + 1 << " этажа: ";
        cin >> heightRoof_element;
        User_house.heightRoof.push_back(heightRoof_element);
    }
    for (int i = 0; i < User_house.quantityFloors; i++)
    {
        int sumSquareRooms{ 0 };
        while (true)
        {
            cout << "Сколько комнат на " << i + 1 << " этаже? ";
            cin >> User_house.quantityRooms;
            if (User_house.quantityRooms < 2 || User_house.quantityRooms > 4)
            {
                cout << "Неверное значение" << endl;
                continue;
            }
            else
            {
                break;
            }
        }

        string room;
        int squareRoom_element;
        User_house.rooms[i].resize(User_house.quantityRooms);
        for (int j = 0; j < User_house.quantityRooms; j++)
        {
            while (true)
            {
                cout << "Комната " << j + 1 << ": ";
                cin >> room;
                if (room == "Спальня" || room == "спальня")
                {
                    User_house.rooms[i][j] = room_type::спальня;
                }
                else if (room == "Ванная" || room == "ванная")
                {
                    User_house.rooms[i][j] = room_type::ванная;
                }
                else if (room == "Гостинная" || room == "гостиная")
                {
                    User_house.rooms[i][j] = room_type::гостиная;
                }
                else if (room == "Детская" || room == "детская")
                {
                    User_house.rooms[i][j] = room_type::детская;
                }
                else if (room == "Кухня" || room == "кухня")
                {
                    User_house.rooms[i][j] = room_type::кухня;
                }
                else
                {
                    cout << "Я не знаю такой комнаты" << endl;
                    continue;
                }

                cout << "Площадь комнаты: ";
                cin >> squareRoom_element;
                if (squareRoom_element < 1 || squareRoom_element > User_house.squareHouse || sumSquareRooms + squareRoom_element > User_house.squareHouse || (j == User_house.quantityRooms - 2 && sumSquareRooms + squareRoom_element == User_house.squareHouse))
                {
                    cout << "Неверное значение" << endl;
                    continue;
                }
                else
                {
                    sumSquareRooms += squareRoom_element;
                    User_house.squareRooms.push_back(squareRoom_element);
                    break;
                }

            }
        }
    }
    value->squareSection += User_house.squareHouse;
    return User_house;
}

void sectionClass::houseClass::PrintHouse()
{

    int fromSquareVector{ 0 };
    cout << "Площадь дома: " << this->squareHouse << "м^2" << endl;
    if (this->oven)
    {
        cout << "В доме имеется печь с трубой" << endl;
    }
    cout << "Этажей в доме: " << this->quantityFloors << endl;
    for (int i = 0; i < size(this->heightRoof); i++)
    {
        cout << "Высота " << i + 1 << " этажа: " << heightRoof[i] << endl;
    }
    for (int i = 0; i < this->quantityFloors; i++)
    {
        cout << "Комнаты на " << i + 1 << " этаже: ";
        for (int j = 0; j < size(this->rooms[i]); j++)
        {
            if (this->rooms[i][j] == room_type::спальня)
            {
                cout << "спальня";
            }
            else if (this->rooms[i][j] == room_type::ванная)
            {
                cout << "ванная";
            }
            else if (this->rooms[i][j] == room_type::гостиная)
            {
                cout << "гостиная";
            }
            else if (this->rooms[i][j] == room_type::детская)
            {
                cout << "детская";
            }
            else if (this->rooms[i][j] == room_type::кухня)
            {
                cout << "кухня";
            }

            if (size(this->rooms[i]) - 1 == j)
            {
                cout << "(" << this->squareRooms[fromSquareVector] << "м^2)";
            }
            else
            {
                cout << "(" << this->squareRooms[fromSquareVector] << "м^2), ";
            }
            fromSquareVector++;
        }
        cout << endl;
    }
}

sectionClass::garageClass sectionClass::garageClass::StartGarage(sectionClass* value)
{
    garageClass User_garage;
    while (true)
    {
        cout << "Площадь гаража: ";
        cin >> User_garage.squareGarage;
        if (User_garage.squareGarage < 1)
        {
            cout << "Неверное значение" << endl;
            continue;
        }
        else
        {
            break;
        }
    }
    
    value->squareSection += User_garage.squareGarage;
    return User_garage;
}

void sectionClass::garageClass::PrintGarage()
{
    cout << "Площадь гаража: " << this->squareGarage << "м^2" << endl;
}

sectionClass::bathhouseClass sectionClass::bathhouseClass::StartBathhouse(sectionClass* value)
{

    bathhouseClass User_Bathhouse;
    
    while (true)
    {
        cout << "Площадь бани: ";
        cin >> User_Bathhouse.squareBathhouse;
        if (User_Bathhouse.squareBathhouse < 1)
        {
            cout << "Неверное значение" << endl;
            continue;
        }
        else
        {
            break;
        }
    }

    string ovenInBathhouse_element;
    while (true)
    {
        cout << "Имеется ли у вас печь с трубой в бане? (да/нет): ";
        cin >> ovenInBathhouse_element;
        if (ovenInBathhouse_element == "Да" || ovenInBathhouse_element == "да")
        {
            User_Bathhouse.oven_bathhouse = true;
            break;
        }
        else if (ovenInBathhouse_element == "Нет" || ovenInBathhouse_element == "нет")
        {
            User_Bathhouse.oven_bathhouse = false;
            break;
        }
        else
        {
            cout << "Я не знаю такого ответа" << endl;
            continue;
        }
    }
    
    value->squareSection += User_Bathhouse.squareBathhouse;
    return User_Bathhouse;
}

void sectionClass::bathhouseClass::PrintBathhouse()
{
    cout << "Площадь бани: " << this->squareBathhouse << "м^2" << endl;
    if (this->oven_bathhouse)
    {
        cout << "В бане имеется печь с трубой" << endl;
    }
}

sectionClass::shedClass sectionClass::shedClass::StartShed(sectionClass* value)
{
    shedClass User_shed;

    while (true)
    {
        cout << "Площадь сарая: ";
        cin >> User_shed.squareShed;
        if (User_shed.squareShed < 1)
        {
            cout << "Неверное значение" << endl;
            continue;
        }
        else
        {
            break;
        }
    }
    
    value->squareSection += User_shed.squareShed;
    return User_shed;
}

void sectionClass::shedClass::PrintShed()
{
    cout << "Площадь сарая: " << this->squareShed << "м^2" << endl;
}