//including the header file.
#include "bigint.hh"

//constructor1
bigint :: bigint(void){
	minus = false;
}

//constructor2
bigint :: bigint(string s){
	for(int i=0;i<s.size();i++){
		if(i == 0){
			if(s[i] == '-')
				minus = true;
			else if(s[i] >= '1' && s[i] <= '9'){
				minus = false;
				array.push_back(s[i]-'0');
			}
			else{
				cout << "Invalid input" << endl;
				exit(0);
			}
		}
		else{
			if(s[i] >= '0' && s[i] <= '9'){
				array.push_back(s[i]-'0');
			}
			else{
				cout << "Invalid input" << endl;
				exit(0);
			}	
		}
	}
}

//Prints output to standard output/console.
void bigint :: printint(){
	if(minus)
		cout << "-";
	for(int i=0;i<this->array.size();i++)
		cout << this->array[i] ;
	cout << endl;
	return ;
}


//removes insignificant zeroes from number.
void bigint :: removeinsignificantzero(void){
	int ctr = 0;
	while(true){
		if(this->array[ctr] != 0)
			break;
		if(ctr >= this->array.size())
			break;
		ctr++;
	}
	bigint tmp;
	for(int i=ctr;i<this->array.size();i++)
		tmp.array.push_back(this->array[i]);
	*this = tmp;
}


//reads number from standard input/console.
void bigint :: getint(void){
	char c;
	c = getchar();
	int flag = 0;
	if( c == '-')
		minus = true ;
	else{
		if(c >= '0' && c <= '9'){
			if(c != '0'){
				flag = 1;
				array.push_back(c-'0'); 
			}
		}
		else{
			std::cin.clear();
			cout << "Invalid input" << endl;
			exit(0);
		}
	}

	while(true && !flag){
		c = getchar();
		if(c >= '0' && c <= '9'){
			array.push_back(c-'0');
			break;
		}
		else if(c == '0')
			continue;
		else if(c != 0){
			std::cin.clear();
			cout << "Invalid input" << endl;
			exit(0);
			break;
		}
	}

	while(true){
		c = getchar();
		if(c == '\n' || c ==' ')
			break;
		else if(c >= '0' && c <= '9')
			array.push_back(c-'0');
		else{
			std::cin.clear();
			cout << "Invalid input" << endl;
			exit(0);
		}
	}
	return ; 
}

//helper function.
bigint bigint :: revert(void){
	int len = this->array.size();
	bigint a;
	for(int i=0;i<len;i++)
		a.array.push_back(0);
	for(int i=0;i<len;i++)
		a.array[i] = this->array[len-i-1];
	return a;
}

//if a == b return true else false
bool bigint :: isequal(bigint a){
	a.removeinsignificantzero();
	this->removeinsignificantzero();
	if(this->array.size() == a.array.size() && this->minus == a.minus){
		for(int i=0;i<a.array.size();i++){
			if(a.array[i] != this->array[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

//if a < 0 return true else false.
bool bigint :: isnegative(){
	return this->minus;
}

bool bigint :: iszero(){
	bigint a = *this;
	for(int i=0;i<a.array.size();i++){
		if(a.array[i] != 0)
			return false;
	}
	return true;
}


//if a > b returns true else false.
bool bigint :: isgreater(bigint b){
	this->removeinsignificantzero();
	b.removeinsignificantzero();
	if(this->minus == b.minus){
		if(b.minus){
			if(b.array.size() > this->array.size())
				return true;
			else if(b.array.size() < this->array.size())
				return false;
			else{
				for(int i=0;i<b.array.size();i++){
					if(this->array[i] > b.array[i])
						return false;
					else if(this->array[i] < b.array[i])
						return true;
					else
						continue;
				}
				return false;
			}
		}
		else{
			if(b.array.size() > this->array.size())
				return false;
			else if(b.array.size() < this->array.size())
				return true;
			else{
				for(int i=0;i<b.array.size();i++){
					if(this->array[i] > b.array[i])
						return true;
					else if(this->array[i] < b.array[i])
						return false;
					else
						continue;
				}
				return false;
			}
		}
	}
	else{
		if(this->minus && !b.minus)
			return false;
		else if(!this->minus && b.minus)
			return true;
	}
}


//addition
void bigint :: add(bigint a){
	bigint b = *this;
	int alen = a.array.size();
	int blen = b.array.size();
	bigint m = a.revert();
	bigint n = b.revert();
	bigint sum;
	int x,carry = 0;
	bool minusflag = false;
	if(alen >= blen && (a.minus == b.minus)){
		if(a.minus)
			minusflag = true;
		for(int i=0;i<blen;i++){
			x = m.array[i] + n.array[i] + carry;
			sum.array.push_back(x%10);
			carry = x/10;
		}
		for(int i=blen;i<alen;i++){
			x = m.array[i] + carry;
			sum.array.push_back(x%10);
			carry = x/10;
		}
		while(carry!=0){
			sum.array.push_back(carry);
			carry = carry/10;
		}
	}
	else if(alen < blen && (a.minus==b.minus)){
		if(a.minus)
			minusflag = true;
		for(int i=0;i<alen;i++){
			x = m.array[i] + n.array[i] + carry;
			sum.array.push_back(x%10);
			carry = x/10;
		}
		for(int i=alen;i<blen;i++){
			x = n.array[i] + carry;
			sum.array.push_back(x%10);
			carry = x/10;
		}
		while(carry!=0){
			sum.array.push_back(carry);
			carry = carry/10;
		}	
	}
	else if(a.minus && !b.minus){
		bigint n1,n2;
		n1 = a;
		n2 = b;
		n1.minus = n2.minus = false ;
		n2.subtract(n1);
		*this = n2;
		return ;
	}
	else if(!a.minus && b.minus){
		bigint n1,n2;
		n1 = a;
		n2 = b;
		n1.minus = n2.minus = false ;
		n1.subtract(n2);
		*this = n1;
		return ;
	}
	if(minusflag){
		*this = sum.revert();
		this->minus = true;
	}
	else
		*this = sum.revert();
	return ;
}


//Subtraction.
void bigint :: subtract(bigint a){
	bigint b = *this;
	int alen = a.array.size();
	int blen = b.array.size();
	bigint m = a.revert();
	bigint n = b.revert();
	bigint diff;
	int x=0;
	bool minusflag = false;
	if(b.isequal(a)){
		diff.array.push_back(0);
		*this = diff;
		return ;
	}
	else if(!a.minus && !b.minus && b.isgreater(a)){
		for(int i=0;i<alen;i++){
			x = n.array[i] - m.array[i];
			if(x < 0){
				x = x + 10;
				n.array[i+1]--;
			}
			diff.array.push_back(x);
		}
		for(int i=alen;i<blen;i++){
			x = n.array[i];
			if( x < 0){
				x = x + 10;
				n.array[i+1]--;
			}
			diff.array.push_back(x);
		}
	}
	else if(!a.minus && !b.minus && !b.isgreater(a)){
		minusflag = true;
		for(int i=0;i<blen;i++){
			x = m.array[i] - n.array[i];
			if(x < 0){
				x = x + 10;
				m.array[i+1]--;
			}
			diff.array.push_back(x);
		}
		for(int i=blen;i<alen;i++){
			x = m.array[i];
			if( x < 0){
				x = x + 10;
				m.array[i+1]--;
			}
			diff.array.push_back(x);
		}
	}
	else if(a.minus && !b.minus){
		bigint n1,n2;
		n1 = a;
		n2 = b;
		n1.minus = n2.minus = false;
		n1.add(n2);
		*this = n1;
		return ;
	}
	else if(!a.minus && b.minus){
		bigint n1,n2;
		n1 = a;
		n2 = b;
		n1.minus = n2.minus = true;
		n1.add(n2);
		*this = n1;
		return ;
	}
	else if(a.minus && b.minus){
		bigint n1,n2;
		n1 = a;
		n2 = b;
		n1.minus = n2.minus = false;
		n1.subtract(n2);
		*this = n1;
		return ;
	}
	if(minusflag){
		*this = diff.revert();
		this->removeinsignificantzero();
		this->minus = true;
		return ;
	}
	else{
		*this = diff.revert();
		this->removeinsignificantzero();
		return ;
	}
} 


//Multiplication.
void bigint :: multiply(bigint a){
	bigint b = *this ;
	bigint m = a.revert();
	bigint n = b.revert();
	bigint product;
	product.array.push_back(0);
	for(int i=0;i<a.array.size();i++){
		bigint tmp;
		for(int k=0;k<i;k++)
			tmp.array.push_back(0);
		int x,carry=0;
		for(int j=0;j<b.array.size();j++){
			x = m.array[i]*n.array[j] + carry;
			tmp.array.push_back(x%10);
			carry = x/10;
		}
		while(carry!=0){
			tmp.array.push_back(carry%10);
			carry = carry/10;
		}
		tmp = tmp.revert();
		product.add(tmp);
	}
	*this = product;
	if(a.minus == b.minus)
		this->minus = false;
	else
		this->minus = true;
}


//Integer Division
void bigint :: divide(bigint a){
	bigint b = *this;
	bigint m = a;
	bigint n = b;
	m.minus = false;
	n.minus = false;
	bigint zero;
	zero.array.push_back(0);
	bigint one;
	one.array.push_back(1);
	bigint quotient;
	if(n.isequal(zero)){
		cout << "Division by ZERO!!!" << endl;
		exit(0);
	}
	else if(m.isequal(zero)){
		*this = zero;
	}
	else if(!m.isequal(zero) && !n.isequal(zero) && m.isequal(n)){
		*this = one;
	}
	else if(!m.isequal(zero) && !n.isequal(zero) && n.isequal(one)){
		*this = m;
	}
	else if(!m.isequal(zero) && !n.isequal(zero) && !m.isequal(n)){
		if(n.isgreater(m)){
			*this = zero;
			return ;
		}
		else{
			bigint tmp;
			int flag = 0;
			int k = n.array.size();
			for(int i=0;i<n.array.size();i++)
				tmp.array.push_back(m.array[i]);
			
			if(!tmp.isgreater(n) && !tmp.isequal(n)){
				tmp.array.push_back(m.array[k]);
				k++;
			}

			while(tmp.isgreater(n) || tmp.isequal(n)){
				bigint swap,prectr,ctr,q;
				prectr = ctr = one;
				while(true){
					ctr.multiply(n);
					q = ctr;
					ctr = ++prectr;
					if(q.isgreater(tmp)){
						ctr--;
						ctr--;
						q.subtract(n);
						break;
					}
					else{
						if(q.isequal(tmp)){
							ctr--;
							break;
						}
					}
				}
				tmp.removeinsignificantzero();
				quotient.array.push_back(ctr.array[0]);
				tmp.subtract(q);
				tmp.removeinsignificantzero();
				if(k < m.array.size())
					tmp.array.push_back(m.array[k++]);
				else
					break;
				if(tmp.iszero()){
					tmp.array.clear();
				}
				while(tmp < n){
					if(k == m.array.size()){
						quotient.array.push_back(0);
						flag = 1;
						break;
					}
					tmp.array.push_back(m.array[k]);
					quotient.array.push_back(0);
					k++;
				}
				if(flag)
					break;
			}
			*this = quotient;
		}
	}
	if(a.minus == b.minus)
		this->minus = false;
	else
		this->minus = true;
	return ;
}

//Overloaded Operators

//Addition
bigint bigint :: operator+(bigint a){
	bigint b = *this;
	bigint c;
	c.array.push_back(0);
	c.add(a);
	c.add(b);
	return c;
}

//Subtraction
bigint bigint :: operator-(bigint a){
	bigint b = *this;
	b.subtract(a);
	return b;
}

//Multiplication
bigint bigint :: operator*(bigint a){
	bigint b = *this;
	b.multiply(a);
	return b;
}

//Integer Division
bigint bigint :: operator/(bigint a){
	bigint b = *this;
	a.divide(b);
	return a;
}

//Addition assignment
bigint bigint :: operator+=(bigint a){
	bigint b = *this;
	b = b + a;
	*this = b;
	return b;
}

//Subtraction assignment
bigint bigint :: operator-=(bigint a){
	bigint b = *this;
	b = b-a;
	*this = b;
	return b;
}

//Multiplication assignment
bigint bigint :: operator*=(bigint a){
	bigint b = *this;
	b = b*a;
	*this = b;
	return b;
}

//Division assignment
bigint bigint :: operator/=(bigint a){
	bigint b = *this;
	b = b/a;
	*this = b;
	return b;
}

bigint bigint :: operator ++(){
	bigint one;
	one.array.push_back(1);
	this->add(one);
	return *this;
}

bigint bigint :: operator ++(int){
	bigint tmp,one;
	tmp = *this;
	one.array.push_back(1);
	this->add(one);
	return tmp;
}

bigint bigint :: operator --(){
	bigint one;
	one.array.push_back(1);
	this->subtract(one);
	return *this;
}

bigint bigint :: operator --(int){
	bigint tmp,one;
	tmp = *this;
	one.array.push_back(1);
	this->subtract(one);
	return tmp;
}

//Factorial.
void bigint :: factorial(void){
	if(this->minus){
		cout << "Negative numbers not allowed" << endl;
		exit(0);
	}
	else{
		bigint zero,tmp,product;
		tmp = *this;
		product.array.push_back(1);
		zero.array.push_back(0);
		while(!tmp.isequal(zero)){
			product.multiply(tmp);
			tmp--;
		}
		*this = product;
		return ;
	}
}


//Calculates x^y. 
//It is done in O(y) time not in O(lg y).
void bigint :: power(bigint p){
	if(p.minus){
		cout << "Negative Power not allowed" << endl;
		exit(0);
	}
	else{
		bigint product,ctr,zero;
		ctr = p;
		zero.array.push_back(0);
		product.array.push_back(1);
		while(!ctr.isequal(zero)){
			product.multiply(*this);
			ctr--;
		}
		*this = product;
		return ;
	}
}

//Calculates greatest common divisor of two numbers and returns the result in the form of bigint.
bigint bigint :: gcd(bigint a,bigint b){
	if(a.minus || b.minus){
		cout << "Negative numbers not allowed" << endl;
		exit(0);
	}
	else{
		if(!b.iszero())
			return gcd(b,a%b);
		else
			return a;
	}
}

//Overloaded Modulo 
bigint bigint :: operator%(bigint a){
	bigint b = *this;
	bigint tmp = a;
	a.divide(b);
	a.multiply(tmp);
	if(a.iszero()){
		a.array.clear();
		a.array.push_back(0);
	}
	b.subtract(a);
	return b;	
}


//Overloaded Logical Operators.
bool bigint :: operator>(bigint a){
	bigint b = *this;
	if(b.isgreater(a))
		return true;
	else
		return false;
}

bool bigint :: operator<(bigint a){
	bigint b = *this;
	if(b.isgreater(a) or b.isequal(a))
		return false;
	else
		return true;
}

bool bigint :: operator==(bigint a){
	bigint b = *this;
	if(a.isequal(b))
		return true; 
	else
		return false;
}

bool bigint :: operator>=(bigint a){
	bigint b = *this;
	if(b.isgreater(a) or b.isequal(a))
		return true;
	else
		return false;
}

bool bigint :: operator<=(bigint a){
	bigint b = *this;
	if(b.isgreater(a))
		return false;
	else
		return true;
}

//Converts a given number in decimal form into it's binary form.
//Returns the result in the form of bigint.
bigint bigint :: ConvertToBinary(){
	bigint a = *this;
	bigint binary,r;
	binary.minus = a.minus;
	bigint two("2");
	while(!a.iszero()){
		r = a%two;
		binary.array.push_back(r.array[0]);
		a /= two;
	}
	bigint tmp = binary.revert();
	return tmp;
}

//Converts an integer to bigint.
bigint ConvertToBigint(int n){
	bigint tmp;
	if(n < 0){
		n = -n;
		tmp.minus = true;
	}
	if(n == 0)
		tmp.array.push_back(0);
	while(n > 0){
		tmp.array.push_back(n%10);
		n = n/10;
	}
	tmp = tmp.revert();
	return tmp;
}

//Converts a given number in binary form into it's decimal form.
//Returns the result in the form of a bigint.
bigint bigint :: ConvertToDecimal(){
	int len = this->array.size();
	bigint decimal,tmp,number;
	decimal.array.push_back(0);
	for(int i=0;i<len;i++){
		bigint two;
		two.array.push_back(2);
		if(array[i] == 1 || array[i] == 0)
			number = ConvertToBigint(this->array[i]);
		else{
			cout << "Input not binary" << endl;
			exit(0);
		}
		tmp = ConvertToBigint(len-i-1);
		two.power(tmp);
		decimal += (two*number);
	}
	return decimal;
}

//Overloaded Bitwise operators

//Unary "not" 
bigint bigint :: operator~(void){
	bigint a = this->ConvertToBinary();
	bigint b;
	for(int i=0;i<a.array.size();i++){
		b.array.push_back(!a.array[i]);
	}
	b = b.ConvertToDecimal();
	if(!b.iszero())
		b.removeinsignificantzero();
	return b;
}

//Binary "and"
bigint bigint :: operator&(bigint a){
	bigint b = *this;
	b = b.ConvertToBinary();
	a = a.ConvertToBinary();
	bigint c;
	for(int i=0;i<min(a.array.size(),b.array.size());i++){
		c.array.push_back(a.array[i]&b.array[i]);
	}
	c = c.ConvertToDecimal();
	return c;
}

//Binary "or"
bigint bigint :: operator|(bigint a){
	bigint b = *this;
	a = a.ConvertToBinary();
	b = b.ConvertToBinary();
	bigint c;
	if(a.array.size() > b.array.size()){
		int ll = b.array.size();
		for(int i=ll;i<a.array.size();i++)
			c.array.push_back(a.array[i]);
		for(int i=0;i<ll;i++)
			c.array.push_back(a.array[i]|b.array[i]);
	}
	else{
		int ll = a.array.size();
		for(int i=ll;i<b.array.size();i++)
			c.array.push_back(b.array[i]);	
		for(int i=0;i<ll;i++)
			c.array.push_back(a.array[i]|b.array[i]);
	}
	c = c.ConvertToDecimal();
	return c;
}

//Binary "xor"
bigint bigint :: operator^(bigint a){
	bigint b = *this;
	a = a.ConvertToBinary();
	b = b.ConvertToBinary();
	bigint c;
	if(a.array.size() > b.array.size()){
		int ll = b.array.size();
		for(int i=ll;i<a.array.size();i++)
			c.array.push_back(a.array[i]^0);
		for(int i=0;i<ll;i++)
			c.array.push_back(a.array[i]^b.array[i]);
	}
	else{
		int ll = a.array.size();
		for(int i=ll;i<b.array.size();i++)
			c.array.push_back(b.array[i]^0);	
		for(int i=0;i<ll;i++)
			c.array.push_back(a.array[i]^b.array[i]);
	}
	c = c.ConvertToDecimal();
	return c;
}

//Overloaded output stream to write output to console
std::ostream &operator <<(std::ostream &outstream,bigint a){
	if(a.minus)
		outstream << "-";
	for(int i=0;i<a.array.size();i++)
		outstream << a.array[i];
	outstream << std::endl;
}

