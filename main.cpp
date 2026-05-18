#include <iostream>  
#include <vector>  

using namespace std;  

//Lop bieu dien toan hoc tren GF(2)
class Bit {  
private:  
    bool val;  
public:  
    //Khoi tao tu dong lay mod 2
    Bit(int v = 0) : val(v % 2 != 0) {}
    
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

//Lop vector nhi phan co so
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
    
    void printBits() const {
        for (int i = 0; i < size(); ++i) {
            cout << bits[i] << (i == size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    // Bonus: ham in da thuc duoi dang toan hoc P(x)
    void printPolynomial() const {
        bool first = true;
        bool isZero = true;
        for (int i = 0; i < size(); ++i) {
            if (bits[i].get()) {
                isZero = false;
                if (!first) cout << " + ";
                if (i == 0) cout << "1";
                else if (i == 1) cout << "x";
                else cout << "x^" << i;
                first = false;
            }
        }
        if (isZero) cout << "0";
        cout << "\n";
    }
};

// Lop da thuc tren GF(2) ke thua vector nhi phan
// Chi so cua mang tuong ung voi bac cua x
class GF2Polynomial : public BinaryVector {
public:
    GF2Polynomial(int degree = 0) : BinaryVector(degree + 1) {}
};

// Lop ma vong tuyen tinh C(n, k)
class CyclicCode {
private:
    int n, k;
    GF2Polynomial h; // Da thuc kiem tra h(x)
public:
    CyclicCode(int n, int k, const GF2Polynomial& h) : n(n), k(k), h(h) {}

    // Thuat toan nhan xac dinh tu ma he thong
    GF2Polynomial encodeSystematic(const GF2Polynomial& m, bool verbose = false) {
        GF2Polynomial c(n - 1); // Tu ma c(x) có bac cao nhat la n - 1
        
        if (verbose) {
            cout << "\n[BONUS] --- GIAI THICH CHI TIET THUAT TOAN NHAN ---\n";
            cout << "* Thong so: Ma vong C(n=" << n << ", k=" << k << ")\n";
            cout << "* Da thuc kiem tra h(x) = "; h.printPolynomial();
            cout << "* Da thuc ban tin m(x)  = "; m.printPolynomial();
            cout << "--------------------------------------------------\n";
            cout << "BUOC 1: Xay dung phan ban tin cho tu ma he thong.\n";
            cout << "- Trong ma he thong, ban tin m(x) duoc giu nguyen va dat vao k vi tri bac cao nhat.\n";
            cout << "- Tuong duong viec tinh x^(n-k) * m(x).\n";
        }

        // Buoc 1: Gan ban tin m(x) vao k bit cao nhat cua tu ma (tu c_{n-k} den c_{n-1})
        for (int i = 0; i < k; ++i) {
            c[n - k + i] = m[i];
            if (verbose) {
                cout << "  -> Gan c_" << (n - k + i) << " = m_" << i << " = " << m[i] << "\n";
            }
        }
        
        if (verbose) {
            cout << "\nBUOC 2: Tinh (n-k) bit kiem tra (parity bits).\n";
            cout << "- Su dung he thuc truy hoi tu da thuc kiem tra h(x):\n";
            cout << "  c_p = SUM(h_j * c_{p + k - j}) voi j chay tu 0 den k-1\n";
            cout << "- Tinh tuong tu viec dich bit qua thanh ghi lfsr:\n";
        }
        
        // Buoc 2: Dung thuat toan nhan voi da thuc kiem tra h(x) de tim cac bit kiem tra
        for (int p = n - k - 1; p >= 0; --p) {
            Bit sum = 0;
            if (verbose) cout << "  => Tinh c_" << p << ":\n     c_" << p << " = ";
            
            bool first = true;
            for (int j = 0; j < k; ++j) {
                // Chi lay cac gia tri c_{p+k-j} cong don vao neu he so h_j = 1
                if (h[j].get()) {
                    sum = sum + c[p + k - j];
                    
                    if (verbose) {
                        if (!first) cout << " + ";
                        cout << "c_" << (p + k - j) << "(=" << c[p + k - j] << ")";
                        first = false;
                    }
                }
            }
            c[p] = sum;
            if (verbose) cout << " = " << sum << "\n";
        }
        
        if (verbose) {
            cout << "--------------------------------------------------\n";
            cout << "[KET QUA] Da thuc tu ma hoan chinh c(x) = ";
            c.printPolynomial();
            cout << "\n";
        }
        
        return c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    
    // verbose = true => xem giai thich chi tiet, bonus = false => in theo ICPC
    bool isVerbose = true; 

    while (T--) {
        int n, k;
        cin >> n >> k;

        //Nhap he so h(x) tu bac 0 den bac k - 1
        GF2Polynomial h(k - 1);
        for (int i = 0; i < k; ++i) {
            cin >> h[i];
        }

        // Nhap ban tin m(x) tu bac 0 den bac k - 1
        GF2Polynomial m(k - 1);
        for (int i = 0; i < k; ++i) {
            cin >> m[i];
        }

        if (isVerbose) {
            cout << "==================================================\n";
            cout << "XU LY BO TEST MOI\n";
        }

        CyclicCode code(n, k, h);
        GF2Polynomial c = code.encodeSystematic(m, isVerbose);

        if (!isVerbose) {
            c.printBits();
        } else {                            
            cout << "=> Vector tu ma: ";
            c.printBits();
        }
    }
    return 0;                    
}
