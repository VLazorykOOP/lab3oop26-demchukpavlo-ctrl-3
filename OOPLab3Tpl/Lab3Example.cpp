#include <iostream>
using namespace std;

class Parallelogram {
    double base, height, side;
    int color;

public:
    Parallelogram() {
        base = height = side = 1;
        color = 0;
    }

    Parallelogram(double b, double h, double s, int c) {
        setBase(b);
        setHeight(h);
        setSide(s);
        setColor(c);
    }

    void setBase(double b) {
        if (b > 0) base = b;
        else cout << "Error base\n";
    }

    void setHeight(double h) {
        if (h > 0) height = h;
        else cout << "Error height\n";
    }

    void setSide(double s) {
        if (s > 0) side = s;
        else cout << "Error side\n";
    }

    void setColor(int c) {
        if (c >= 0) color = c;
        else cout << "Error color\n";
    }

    double area() {
        return base * height;
    }

    double perimeter() {
        return 2 * (base + side);
    }

    void print() {
        cout << "\nBase: " << base
            << "\nHeight: " << height
            << "\nSide: " << side
            << "\nColor: " << color
            << "\nArea: " << area()
            << "\nPerimeter: " << perimeter() << endl;
    }
};

class VectorShort {
    short* arr;
    int size;
    int state;
    static int count;

public:

    VectorShort() {
        size = 1;
        arr = new short[size] {0};
        state = 0;
        count++;
    }

    VectorShort(int n) {
        if (n <= 0) {
            size = 0;
            arr = nullptr;
            state = -1;
        }
        else {
            size = n;
            arr = new short[size] {0};
            state = 0;
        }
        count++;
    }

    VectorShort(int n, short value) {
        if (n <= 0) {
            size = 0;
            arr = nullptr;
            state = -1;
        }
        else {
            size = n;
            arr = new short[size];
            for (int i = 0; i < size; i++)
                arr[i] = value;
            state = 0;
        }
        count++;
    }

    VectorShort(const VectorShort& other) {
        size = other.size;
        state = other.state;

        if (size > 0) {
            arr = new short[size];
            for (int i = 0; i < size; i++)
                arr[i] = other.arr[i];
        }
        else {
            arr = nullptr;
        }

        count++;
    }

    VectorShort& operator=(const VectorShort& other) {
        if (this == &other) return *this;

        delete[] arr;

        size = other.size;
        state = other.state;

        if (size > 0) {
            arr = new short[size];
            for (int i = 0; i < size; i++)
                arr[i] = other.arr[i];
        }
        else {
            arr = nullptr;
        }

        return *this;
    }

    ~VectorShort() {
        delete[] arr;
        count--;
    }

    void set(int i, short val = 0) {
        if (i >= 0 && i < size && arr != nullptr)
            arr[i] = val;
        else
            state = -1;
    }

    short get(int i) {
        if (i >= 0 && i < size && arr != nullptr)
            return arr[i];
        state = -1;
        return 0;
    }

    VectorShort add(VectorShort& b) {
        int n = (size < b.size) ? size : b.size;
        VectorShort temp(n);

        for (int i = 0; i < n; i++)
            temp.arr[i] = arr[i] + b.arr[i];

        return temp;
    }

    VectorShort sub(VectorShort& b) {
        int n = (size < b.size) ? size : b.size;
        VectorShort temp(n);

        for (int i = 0; i < n; i++)
            temp.arr[i] = arr[i] - b.arr[i];

        return temp;
    }

    VectorShort mul(unsigned char k) {
        VectorShort temp(size);

        for (int i = 0; i < size; i++)
            temp.arr[i] = arr[i] * k;

        return temp;
    }

    bool isEqual(VectorShort& b) {
        if (size != b.size) return false;

        for (int i = 0; i < size; i++)
            if (arr[i] != b.arr[i]) return false;

        return true;
    }

    void print() {
        if (arr == nullptr) {
            cout << "Empty vector\n";
            return;
        }for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    static int getCount() {
        return count;
    }
};

int VectorShort::count = 0;

void task1_parallelogram() {
    double b, h, s;
    int c;

    cout << "Enter base, height, side, color: ";
    cin >> b >> h >> s >> c;

    Parallelogram p(b, h, s, c);
    p.print();
}

void task2_vector() {
    int n;

    cout << "Enter size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Wrong size!\n";
        return;
    }

    VectorShort v1(n), v2(n);

    cout << "Enter v1:\n";
    for (int i = 0; i < n; i++) {
        short x;
        cin >> x;
        v1.set(i, x);
    }

    cout << "Enter v2:\n";
    for (int i = 0; i < n; i++) {
        short x;
        cin >> x;
        v2.set(i, x);
    }

    VectorShort sum = v1.add(v2);
    VectorShort diff = v1.sub(v2);

    cout << "Sum: ";
    sum.print();

    cout << "Diff: ";
    diff.print();
}

int main()
{
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Parallelogram\n";
        cout << "2 - Vector (short)\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            task1_parallelogram();
            break;

        case 2:
            task2_vector();
            break;

        case 0:
            cout << "Bye!" << endl;
            break;

        default:
            cout << "Wrong choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}