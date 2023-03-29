//Ввести деяку послідовність дійсних чисел і створити динамічний масив лише з чисел, модуль яких не попадає в проміжок (20, 40]. За допомогою функції обчислити кількість елементів, що перевищують середнє арифметичне всіх елементів


#include <iostream>
#include <cmath>
using namespace std;

// функція для обчислення середнього арифметичного масиву
double calc_serar(double arr[], int size) {
    double sum = 0.0;          
    for (int i = 0; i < size; i++) {  
        sum += arr[i];         
    }
    return sum / size;         
}

int main() {
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    // виділення пам'яті для масиву
    double* arr = new double[n];

    // зчитання вхідної послідовності дійсних чисел
    for (int i = 0; i < n; i++) {
        cout << "Введіть дійсне число: ";
        cin >> arr[i];
       if (arr[i] < 0) {      // перевіряємо, чи число від'ємне
            arr[i] = -arr[i];  // перетворюємо в додатнє значення
      }
    }

    // створення нового масиву тільки з чисел, модуль яких не потрапляє в діапазон (20, 40]
  
    int new_size = 0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] >= -40 && arr[i] <= -20) || (arr[i] <= 20 || arr[i] > 40)) {  // перевірка, чи елемент не знаходиться в діапазоні (20, 40])
            new_size++;      // збільшення розміру нового масиву
        }
    }
    double* new_arr = new double[new_size];  // виділення пам'яті для нового масиву
    int j = 0;
    for (int i = 0; i < n; i++) {
      if ((arr[i] >= -40 && arr[i] <= -20) || (arr[i] <= 20 || arr[i] > 40)) {  //перевірка, чи елемент не знаходиться в діапазоні (20, 40])
        
    new_arr[j] = arr[i];  // додання елемента до нового масиву
    j++;          // збільшення індекса нового масиву
        }
    }

   // виведення початкового масиву та його середнє арифметичне
    double serar = calc_serar(arr, n);     //  обчислення середнього арифметичного
    cout << "\nПочатковий масив: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\nСереднє арифметичне початкового масиву: \n" << serar << endl;

    // Виведення нового масиву 
    cout << "\nНовий масив (тільки з чисел, модуль яких не потрапляє в діапазон (20, 40]): \n";
    for (int i = 0; i < new_size; i++) {
        cout << new_arr[i] << " ";
    }
    cout << endl;

    // підрахування кількості елементів, які перевищують середнє арифметичне всіх елементів
    int count = 0;
    for (int i = 0; i < new_size; i++) {
        if (new_arr[i] > serar) {   // перевірка, чи елемент більший за середнє арифметичне
            count++;          // збільшення кількості на одиницю
        }
    }

    // Виведення результату
    cout << "\nКількість елементів, які перевищують середнє арифметичне всіх елементів, дорівнює : \n" << count << endl;

    // звільнення пам'яті 
    delete[] arr;
    delete[] new_arr;

    return 0;
}
