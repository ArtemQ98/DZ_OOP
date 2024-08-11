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
        void StartHouse()
        {
            cout << "Площадь: ";
            cin >> square;
            while (true)
            {
                cout << "Количестко этажей: ";
                cin >> quantityFloors;
                if (quantityFloors < 1 || quantityFloors > 3)
                {
                    cout << "Неверное значение" << endl;
                    continue;
                }
                else
                {
                    break;
                }
            }
            
            rooms.resize(quantityFloors);
            string room;
            for (int i = 0; i < quantityFloors; i++)
            {
                while (true)
                {
                    cout << "Сколько комнат на " << i + 1 << " этаже? ";
                    cin >> quantityRooms;
                    if (quantityRooms < 2 || quantityRooms > 4)
                    {
                        cout << "Неверное значение" << endl;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                
                rooms[i].resize(quantityRooms);
                for (int j = 0; j < quantityRooms; j++)
                {
                    cout << "Комната " << j + 1 << ": ";
                    cin >> room;
                    rooms[i][j] = room;
                }
            }
        }
        void PrintHouse()
        {
            cout << "Площадь дома: " << quantityRooms << endl;
            cout << "Этажей: " << quantityFloors<< endl;
            for (int i = 0; i < quantityFloors; i++)
            {
                cout << "Комнаты на " << i+1 << " этаже: ";
                for (int j = 0; j < size(rooms[i]); j++)
                {
                    if (size(rooms[i]) - 1 == j)
                    {
                        cout << rooms[i][j];
                    }
                    else
                    {
                        cout << rooms[i][j] << ", ";
                    }
                }
                cout << endl;
            }
        }
    };

    void Print()
    {
        for (int i = 0; i < quantityBuildings; i++)
        {
            if (buildingsOnSection[i] == building_type::Дом)
            {
                cout << "--------Дом--------" << endl;
                this->User_house.PrintHouse();
            }
        }
    }


public:
    houseClass User_house;
};



class garageClass
{
    int square;
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
                value->User_house.StartHouse();
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
    cout << "Кол-во учатсков: ";
    cin >> quantitySectios;
    cin.ignore();

    for (int i = 0; i < quantitySectios; i++)
    {
        sectionClass *sectioni = new sectionClass;
        cout << "========УЧАСТОК" << i + 1 << "========" << endl;
        Start(sectioni);
        section.push_back(*sectioni);
    }

    cout << endl << endl << endl << "========Вывод========" << endl << endl << endl;

    for (int i = 0; i < size(section); i++)
    {
        
        cout << "========УЧАСТОК" << i+1 << "========" << endl;
        section[i].Print();
    }
}

