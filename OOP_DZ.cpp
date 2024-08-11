#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <tuple>

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
    struct MyStruct;
    friend void Start(sectionClass* value);

protected:
    int square;
    building_type buildType;
    int quantityBuildings;
    vector<building_type> buildingsOnSection;
    
public:
    
   

    class houseClass
    { 
        friend sectionClass;
        vector<vector<string> > rooms;
        int square;
        int quantityFloors;
        int quantityRooms;

    public:
        houseClass StartHouse()
        {
            
            houseClass User_house;
            
            cout << "Площадь: ";
            cin >> User_house.square;
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
            string room;
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

                User_house.rooms[i].resize(User_house.quantityRooms);
                for (int j = 0; j < User_house.quantityRooms; j++)
                {
                    cout << "Комната " << j + 1 << ": ";
                    cin >> room;
                    User_house.rooms[i][j] = room;
                }
            }
            return User_house;
        }
        
        void PrintHouse()
        {
           
            cout << "Площадь дома: " << this->square << "м^2" << endl;
            cout << "Этажей в доме: " << this->quantityFloors << endl;
            for (int i = 0; i < this->quantityFloors; i++)
            {
                cout << "Комнаты на " << i + 1 << " этаже: ";
                for (int j = 0; j < size(this->rooms[i]); j++)
                {
                    if (size(this->rooms[i]) - 1 == j)
                    {
                        cout << this->rooms[i][j];
                    }
                    else
                    {
                        cout << this->rooms[i][j] << ", ";
                    }
                }
                cout << endl;
            }
            
           
        }

        int GetSquare()
        {
            return this->square;
        }

    };

    class garageClass
    {
        int square;
    };

    void Print()
    {
        for (int i = 0; i < quantityBuildings; i++)
        {
            if (buildingsOnSection[i] == building_type::Дом)
            {
                cout << "--------Дом--------" << endl;
                
                houses[i].PrintHouse();
            }
        }
    }

    
public:
    sectionClass::houseClass* temp = new sectionClass::houseClass;
    garageClass User_garage;
    vector<houseClass> houses;
    friend houseClass;

};



class shedClass
{
    int square;
};

class saunaClass
{
    int square;
};




void Start(sectionClass *value)
{

    cout << "Постройки кол-во: ";
    cin >> value->quantityBuildings;
    cin.ignore();
    string build;
    for (int i = 0; i < value->quantityBuildings; i++)
    {
        while (true)
        {
            cout << "Постройка" << i + 1 << ": ";
            cin >> build;
            if (build == "Дом")
            {
                value->buildType = building_type::Дом;
                value->houses.push_back(value->temp->StartHouse()); 
                value->buildingsOnSection.push_back(building_type::Дом);
                break;
            }
            else
            {
                cout << "Неверный ввод !!! Введите верную постройку: ";
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
    int sum{0};
    cout << "Кол-во учатсков: ";
    cin >> quantitySectios;
    cin.ignore();

    for (int i = 0; i < quantitySectios; i++)
    {
        sectionClass *sectioni = new sectionClass;
        cout << "========УЧАСТОК" << i + 1 << "========" << endl;
        Start(sectioni);
        section.push_back(*sectioni);
        delete sectioni;
    }
    
    cout << sum << endl;
    cout << endl << endl << endl << "========Вывод========" << endl << endl << endl;

    for (int i = 0; i < size(section); i++)
    {
        
        cout << "========УЧАСТОК" << i+1 << "========" << endl;
        section[i].Print();

        cout << endl << endl << endl << "========Площадь========" << endl << endl << endl;
       
        for (int j = 0; j < size(section[i].houses); j++)
        {
            sum += section[i].houses[j].GetSquare();
        }
        cout << sum << endl;
    }
}

