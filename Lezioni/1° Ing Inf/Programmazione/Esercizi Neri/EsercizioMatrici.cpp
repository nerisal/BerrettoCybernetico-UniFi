template <typename T>
class Matrix {
private:
  // Qua sto definenendo un vettore di vettori chiamato data che rappresenta appunto una matrice
	std::vector<std::vector<T>> data;
	int rows;
	int cols;
	
public:
  Matrix(int r, int c, T d) : rows(r), cols(c) {
    data = std::vector<std::vector<T>>(rows, std::vector<T>(cols, d));
  } 
  
  Matrix(const Matrix<T>& original) : rows(original.rows), cols(original.cols), data(original.data) {}
  
  Matrix& operator=(const Matrix<T>& &right) {
    if(this != right)
    {
      this.rows = right.rows;
      this.cols = right.cols;
      this.data = right.data;
    }
    
    return *this;
  }
  
  void set(int c, int r, T value) {
    data[r][c] = value;  
  } 
  
  T& get(int c, int r) {
    return data[r][c];
  }

};
