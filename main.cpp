#include <iostream>
#include <vector>

using namespace std;

//Lop bit toan hoc tren GF(2)
class Bit {
private:
    bool val;
public:
    //Khoi tao tu dong modul 2
    Bit(int v = 0) : val(v % 2 != 0) {}
    
    //Nap chong phep cong (XOR) va phep nhan (AND) tren GF(2)
    Bit operator+(const Bit& other) const { return Bit(val ^ other.val); }
    Bit operator*(const Bit& other) const { return Bit(val & other.val); }
    Bit& operator=(const int& v) { val = (v % 2 != 0); return *this; }
    
    bool get() const { return val; }
    
    friend ostream& operator<<(ostream& os, const Bit& b) {
        os << b.val;
        return os;
    }
    friend istream& operator>>(istream& is, Bit& b) {
        int v; is >> v; b = Bit(v);
        return is;
    }
};

//Lop vector Nhi Phan - Tu ma 
class BinaryVector {
protected:
    vector<Bit> bits;
public:
    BinaryVector(int size = 0) { bits.resize(size, Bit(0)); }
    void push_back(Bit b) { bits.push_back(b); }
    Bit& operator[](int index) { return bits[index]; }
    const Bit& operator[](int index) const { return bits[index]; }
    int size() const { return bits.size(); }
    void resize(int n) { bits.resize(n, Bit(0)); }
    
    void print() const {
        for (int i = 0; i < size(); ++i) {
            cout << bits[i] << (i == size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
};

//Lop da thuc trn GF(2)
//Ke thuc vector nhi phan, chi so mang tuong ung voi bac cua x
class GF2Polynomial : public BinaryVector {
public:
    GF2Polynomial(int degree = 0) : BinaryVector(degree + 1) {}
};

//Lop ma vong tuyen tinh C(n, k)
class CyclicCode {
private:
    int n, k;
    GF2Polynomial h; //Da thuc kiem tra h(x)
public:
    CyclicCode(int n, int k, const GF2Polynomial& h) : n(n), k(k), h(h) {}

    //Thuat toan nhan xac dinh tu ma he thong
    GF2Polynomial encodeSystematic(const GF2Polynomial& m, bool verbose = false) {
        GF2Polynomial c(n - 1);
        
        // Buoc 1: Gan ban tin m(x) vao k bit cao nhat cua tu ma (tu c_{n-k} den c_{n-1})
        for (int i = 0; i < k; ++i) {
            c[n - k + i] = m[i];
        }
        
        if (verbose) {
            cout << "--- Chi tiet tinh toan cac bit kiem tra ---\n";
            for (int i = 0; i < k; ++i) {
                cout << "c_" << (n - k + i) << " = m_" << i << " = " << m[i] << "\n";
            }
        }
        
        // Buoc 2: Dung thuat toan nhan voi da thuc kiem tra h(x) de tim cac bit con lai
        // Cong thuc: c_{p} = sum(h_j * c_{p + k - j}) voi j tu 0 den k - 1
        for (int p = n - k - 1; p >= 0; --p) {
            Bit sum = 0;
            if (verbose) cout << "c_" << p << " = ";
            
            bool first = true;
            for (int j = 0; j < k; ++j) {
                if (h[j].get()) {
                    sum = sum + c[p + k - j];
                    if (!first && verbose) cout << " + ";
                    if (verbose) cout << "c_" << (p + k - j);
                    first = false;
                }
            }
            c[p] = sum;
            if (verbose) cout << " = " << sum << "\n";
        }
        return c;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
  
    // isVerbose = true de xem giai thich tu luan, = false thi ra ket qua theo chuan ICPc
    bool isVerbose = false; 

    while (T--) {
        int n, k;
        cin >> n >> k;

        // Nhap k he so cua h(x) tu bac 0 den bac k-1 (h_k luon = 1 nen khong can nhap)
        GF2Polynomial h(k - 1);
        for (int i = 0; i < k; ++i) {
            cin >> h[i];
        }

        // Nhap ban tin m(x) do dai k (tu m_0 den m_{k-1})
        GF2Polynomial m(k - 1);
        for (int i = 0; i < k; ++i) {
            cin >> m[i];
        }

        if (isVerbose) {
            cout << "========================================\n";
            cout << "Ma vong tuyen tinh C(" << n << "," << k << ")\n";
        }

        CyclicCode code(n, k, h);
        GF2Polynomial c = code.encodeSystematic(m, isVerbose);

        if (isVerbose) cout << "=> Tu ma he thong C(x): ";
        c.print();
    }
    return 0;
}