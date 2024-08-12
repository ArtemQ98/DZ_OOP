#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;


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
    };

    class shedClass
    {
        int square;

    public:
        garageClass StartShed();

        void PrintShed();

        int GetSquare()
        {
            return this->square;
        }
    };

    class saunaClass
    {
        int square;
    };

    void Print()
    {
        int quantityHouse{ 0 };
        int quantityGarage{ 0 };
        cout << "Площадь участка: " << squareSection << "м^2" << endl;
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
                quantityGarage+=1;

            }
            
        }
    }

    

    
public:
    sectionClass::houseClass* temp_house;
    sectionClass::garageClass* temp_garage;
    vector<houseClass> houses;
    vector<garageClass> garages; 
    friend houseClass; 
     
};




void Start(sectionClass *value)
{

    bool okStep{ true };
    int sizeCin;
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
            else
            {
                cout << "Неверный ввод !!! Введите верную постройку: " << endl;
                continue;
            }
            
        }
        
    }
}



int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    vector<sectionClass> section;
    int quantitySectios;
    int generalSquare{0};
    cout << "Кол-во учатсков: ";
    cin >> quantitySectios;
    cin.ignore();

    for (int i = 0; i < quantitySectios; i++)
    {
        sectionClass *sectioni = new sectionClass;
        cout << endl << "======== УЧАСТОК " << i + 1 << " ========" << endl;
        Start(sectioni);
        section.push_back(*sectioni);
        delete sectioni;
    }

    cout << endl << endl << "========Вывод========" << endl << endl;

    for (int i = 0; i < size(section); i++)
    {
        
        cout << endl << endl << "======== УЧАСТОК " << i+1 << " ========" << endl;
        section[i].Print();

    }

    cout << endl << endl << endl << "======== Общая площадь ========" << endl;
    for (int i = 0; i < size(section); i++)
    {
        for (int j = 0; j < size(section[i].houses); j++)
        {
            generalSquare += section[i].houses[j].GetSquare();
        }
        for (int j = 0; j < size(section[i].garages); j++)
        {
            generalSquare += section[i].garages[j].GetSquare();
        }
    }
    cout << generalSquare << "м^2" << endl;

}



sectionClass::houseClass sectionClass::houseClass::StartHouse(sectionClass* value)
{
    houseClass User_house;

    cout << "Площадь: ";
    cin >> User_house.squareHouse;
    
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
        User_house.rooms[i].resize(User_house.quantityRooms);
        for (int j = 0; j < User_house.quantityRooms; j++)
        {  
            while (true)
            {
                cout << "Комната " << j + 1 << ": ";
                cin >> room;
                if (room == "спальня")
                {
                    User_house.rooms[i][j] = room_type::спальня;
                    break;
                }
                else if (room == "ванная")
                {
                    User_house.rooms[i][j] = room_type::ванная;
                    break;
                }
                else if (room == "гостиная")
                {
                    User_house.rooms[i][j] = room_type::гостиная;
                    break;
                }
                else if (room == "детская")
                {
                    User_house.rooms[i][j] = room_type::детская;
                    break;
                }
                else if (room == "кухня")
                {
                    User_house.rooms[i][j] = room_type::кухня;
                    break;
                }
                else
                {
                    cout << "Я не знаю такой комнаты" << endl;
                    continue;
                }
            }   
        }
    }
    value->squareSection += User_house.squareHouse;
    return User_house;
}

void sectionClass::houseClass::PrintHouse()
{
    
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
            if (size(this->rooms[i]) - 1 == j)
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
            }
            else
            {
                if (this->rooms[i][j] == room_type::спальня)
                {
                    cout << "спальня, ";
                }
                else if (this->rooms[i][j] == room_type::ванная)
                {
                    cout << "ванная, ";
                }
                else if (this->rooms[i][j] == room_type::гостиная)
                {
                    cout << "гостиная, ";
                }
                else if (this->rooms[i][j] == room_type::детская)
                {
                    cout << "детская, ";
                }
                else if (this->rooms[i][j] == room_type::кухня)
                {
                    cout << "кухня, ";
                }
            }
        }
        cout << endl;
    }
}

sectionClass::garageClass sectionClass::garageClass::StartGarage(sectionClass* value)
{
    garageClass User_garage;
    cout << "Площадь: ";
    cin >> User_garage.squareGarage;
    value->squareSection += User_garage.squareGarage;
    return User_garage; 
}

void sectionClass::garageClass::PrintGarage()
{
    cout << "Площадь гаража: " << this->squareGarage << endl;
}