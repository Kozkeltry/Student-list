#include <iostream>
#include <vector>
#include <string>

class Baassqa {
private:
    std::vector<std::string> names;
public:
    Baassqa() = default;

    void add() {
        std::string new_name;

        std::cout << "Введите имя ученика: ";
        std::getline(std::cin >> std::ws, new_name);
        names.push_back(new_name);

        std::cout << "Вы добавили ученика: " << new_name << " в список!" << std::endl;
    }

    void show() const {
        if (names.empty()) {
            std::cout << "Список пуст.\n";
            return;
        }
        std::cout << "\n--- Список учеников ---\n";
        for (size_t i = 0; i < names.size(); ++i) {
            std::cout << i + 1 << ". " << names[i] << "\n";
        }
        std::cout << "-----------------------\n";
    }

    void remove() {
        if (names.empty()) {
            std::cout << "Некого удалять, список пуст!\n";
            return;
        }

        show();

        int num;
        std::cout << "Введите номер ученика для удаления: ";
        std::cin >> num;

        if (num < 1 || num > static_cast<int>(names.size())) {
            std::cout << "Ошибка: неверный номер ученика!\n";
            return;
        }

        std::string deleted_name = names[num - 1];
        names.erase(names.begin() + (num - 1));

        std::cout << "Ученик " << deleted_name << " удален из списка.\n";
    }
};

int main() {
    int opc = 0;
    Baassqa basedann;
    
    while (opc != 4)
    {
        std::cout << "\n";
        std::cout << "1. Добавить ученика\n";
        std::cout << "2. Удалить ученика\n";
        std::cout << "3. Список учеников\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите опцию: ";
        std::cin >> opc;

       switch (opc)
       {
       case 1:
            basedann.add();
            break;
        case 2:
            basedann.remove();
            break;
        case 3:
            basedann.show();
            break;
        default:
            return 0;
        }
    }

    return 0;
}
