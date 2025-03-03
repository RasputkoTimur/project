#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовый класс пользователя
class User {
protected:
    string fullName;
public:
    User(string name) : fullName(name) {}
    string getName() { return fullName; }
};

// Класс студента
class Student : public User {
private:
    vector<string> completedTests;
    vector<string> pendingTests;
public:
    Student(string name) : User(name) {
        pendingTests = { "Математика", "Физика", "Информатика" };
    }

    void showProfile() {
        cout << "Личный кабинет студента: " << fullName << endl;
    }

    void showCompletedTests() {
        cout << "Пройденные тесты:\n";
        if (completedTests.empty()) cout << "Нет пройденных тестов.\n";
        else for (const auto& test : completedTests) cout << "- " << test << endl;
    }

    void showPendingTests() {
        cout << "Непройденные тесты:\n";
        if (pendingTests.empty()) cout << "Все тесты пройдены!\n";
        else for (const auto& test : pendingTests) cout << "- " << test << endl;
    }

    void takeTest() {
        if (pendingTests.empty()) {
            cout << "Нет тестов для прохождения.\n";
            return;
        }

        cout << "Выберите тест для прохождения:\n";
        for (size_t i = 0; i < pendingTests.size(); i++) {
            cout << i + 1 << ". " << pendingTests[i] << endl;
        }

        int choice;
        cin >> choice;
        if (choice < 1 || choice > pendingTests.size()) {
            cout << "Неверный выбор!\n";
            return;
        }

        cout << "Вы прошли тест: " << pendingTests[choice - 1] << "!\n";
        completedTests.push_back(pendingTests[choice - 1]);
        pendingTests.erase(pendingTests.begin() + (choice - 1));
    }
};

// Класс тестов (пока что просто хранит тесты)
class Test {
public:
    static vector<string> testList;

    static void addTest(string test) {
        testList.push_back(test);
        cout << "Тест '" << test << "' добавлен.\n";
    }

    static void removeTest(int index) {
        if (index < 0 || index >= testList.size()) {
            cout << "Неверный индекс.\n";
            return;
        }
        cout << "Тест '" << testList[index] << "' удалён.\n";
        testList.erase(testList.begin() + index);
    }

    static void showTests() {
        cout << "Список тестов:\n";
        if (testList.empty()) cout << "Нет доступных тестов.\n";
        else for (size_t i = 0; i < testList.size(); i++) {
            cout << i + 1 << ". " << testList[i] << endl;
        }
    }
};

vector<string> Test::testList = { "Математика", "Физика", "Информатика" };

// Класс администратора
class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void getProfile() {
        cout << "Личный кабинет администратора: " << fullName << endl;
    }

    void manageStudent() {
        cout << "Управление студентами (пока без реализации).\n";
    }

    void manageTests() {
        int choice;
        do {
            cout << "Управление тестами:\n";
            cout << "1. Просмотреть тесты\n";
            cout << "2. Добавить тест\n";
            cout << "3. Удалить тест\n";
            cout << "4. Выйти\n";
            cout << "Ваш выбор: ";
            cin >> choice;

            switch (choice) {
            case 1:
                Test::showTests();
                break;
            case 2: {
                cout << "Введите название нового теста: ";
                string testName;
                cin.ignore();
                getline(cin, testName);
                Test::addTest(testName);
                break;
            }
            case 3: {
                Test::showTests();
                cout << "Введите номер теста для удаления: ";
                int index;
                cin >> index;
                Test::removeTest(index - 1);
                break;
            }
            case 4:
                return;
            default:
                cout << "Неверный выбор!\n";
            }
        } while (choice != 4);
    }
};

// Функция меню студента
void studentMenu(Student& student) {
    int choice;
    while (choice != 5) {
        cout << "Меню. Студент: " << student.getName() << endl;
        cout << "1. Личный кабинет" << endl;
        cout << "2. Пройденные тесты" << endl;
        cout << "3. Непройденные тесты" << endl;
        cout << "4. Пройти тест" << endl;
        cout << "5. Выйти" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            student.showProfile();
            break;
        case 2:
            student.showCompletedTests();
            break;
        case 3:
            student.showPendingTests();
            break;
        case 4:
            student.takeTest();
            break;
        case 5:
            return;
        default:
            cout << "Неверный выбор!\n";
        }
    }
}

// Функция меню администратора
void adminMenu(Admin& admin) {
    int choice;
    while(choice!=4){
        cout << "Меню. Админ: " << admin.getName() << endl;
        cout << "1. Личный кабинет" << endl;
        cout << "2. Управление студентами" << endl;
        cout << "3. Управление тестами" << endl;
        cout << "4. Выйти" << endl;
        cout << "Ваш выбор: " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            admin.getProfile(); break;
        case 2:
            admin.manageStudent(); break;
        case 3:
            admin.manageTests(); break;
        case 4: return;
        default: cout << "ОШИБКА" << endl;
        }
    }
}
// Главное меню
int main() {
    Student s1("1231231 123");
        studentMenu(student);
    }
    else if (test == 2) {
        Admin admin("1231 123");
        adminMenu(admin);
    }
    else {
        cout << "ОШИБКА" << endl;
    }
}
