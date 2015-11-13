namespace data {
	template<class T>
	Matrix<T>::Matrix(const Matrix<T>& m){
		this->data = m.data;
		this->n = m.n;
		this->m = m.m;
	}

	template<class T>
	Matrix<T>::Matrix(unsigned int n, unsigned int m, const T& value){
		this->n = n;
		this->m = m;

		for(unsigned int i=0; i<n; i++){
			for(unsigned int j=0; j<m; j++){
				this->data.push_back(value);
			}
		}
	}

	template<class T>
	Matrix<T>::~Matrix(){
	}

	template<class T>
	void Matrix<T>::reset(const T& value){
		for(unsigned int i=0; i < this->n; i++){
			for(unsigned int j=0; j < this->m; j++){
				//std::cout << i << " " << j << std::endl;
				this->set(i,j,value);
			}
		}
	}

	template<class T>
	T Matrix<T>::get(unsigned int i, unsigned int j) const{
		assert( i*m+j < this->data.size() &&  i*m+j >= 0);
		//std::cout << i << "  - " << j << " = " << this->data[i*m+j] << " " << m << " " << n << std::endl;
		return this->data[i*m+j];
	}

	template<class T>
	void Matrix<T>::set(unsigned int i, unsigned int j, const T& value){
		assert( i*m+j < this->data.size() &&  i*m+j >= 0);
		this->data[i*m+j] = value;
	}

	template<class T>
	void Matrix<T>::setLine(unsigned int l, const T& value){
		for(unsigned int i=0; i<m; i++){
			this->set(l, i, value);
		}
	}

	template<class T>
	void Matrix<T>::setColumn(unsigned int c, const T& value){
		for(unsigned int i=0; i<n; i++){
			this->set(i, c, value);
		}
	}

	template<class T>
	T Matrix<T>::getMaximumValue(unsigned int& i, unsigned int& j) const{
	//TODO
	}

	template<class T>
	T Matrix<T>::getMaximumValueOnLine(unsigned int l, unsigned int& pos) const{
	//TODO
	}

	template<class T>
	std::string Matrix<T>::toString() const{
		std::stringstream description;
		description << std::setw(3) << "*" <<  " |";
		for(unsigned int a=0; a<m; a++){
			description << std::setw(4) << a;
		}
		description << std::endl;

		for(unsigned int i=0; i<n; i++){
			description << std::setw(3) << i << " |";
			for(unsigned int j=0; j<m; j++){
				description << std::setw(4) << this->get(i,j);
			}
			description << std::endl;
		}
		return description.str();
	}
}