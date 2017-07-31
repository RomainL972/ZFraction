#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION

#include <iostream>
#include <cmath>

class ZFraction
{
public:
	ZFraction(double numerateur=0, double denominateur=1);
	~ZFraction();

	bool estEgal(ZFraction const& fraction) const;
	bool estPlusGrandQue(ZFraction const& fraction) const;
	ZFraction& operator+=(ZFraction const &fraction);
	ZFraction& operator-=(ZFraction const &fraction);
	void afficher(std::ostream &flux) const;
	ZFraction& operator*=(ZFraction const &fraction);
	ZFraction& operator/=(ZFraction const &fraction);
	int numerateur() const;
	int denominateur() const;
	double decimal() const;
	void abs();
	void pow(int puissance);
	void sqrt();
	ZFraction& operator-(ZFraction const &fraction);
	
private:
	void simplifier();
	void placerSigne();
	void ameliorer();

	double m_numerateur;
	double m_denominateur;
};

bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
std::ostream& operator<<(std::ostream &flux, ZFraction const& fraction);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);
int pgcd(int a, int b);
int ppcm(int a, int b);
ZFraction abs(ZFraction const &fraction);
ZFraction pow(ZFraction const &fraction, int puissance);
ZFraction sqrt(ZFraction const &fraction);

#endif