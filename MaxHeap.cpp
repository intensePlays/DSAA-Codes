#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Student {
    string name;
    float grade;
};

void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

void heapify(Student arr[], int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left].grade > arr[largest].grade)
        largest = left;

    if (right < n && arr[right].grade > arr[largest].grade)
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(Student arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(Student arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void displayStudents(Student arr[], int n) {
    cout << "\nStudent List:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " - " << arr[i].grade << endl;
    }
}

int main() {
    int n;
    Student students[MAX];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student name and grade (0.0 to 10.0):\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ":\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Grade: ";
        cin >> students[i].grade;
    }


    buildMaxHeap(students, n);
    cout << "\nTopper eligible for internship:\n";
    cout << students[0].name << " - " << students[0].grade << endl;

    heapSort(students, n);

    cout << "\nStudents sorted in ascending order of grades:\n";
    displayStudents(students, n);

    return 0;
}
