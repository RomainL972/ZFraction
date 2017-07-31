#include "ZFraction.h"
using namespace std;

ZFraction::ZFraction(double numerateur, double denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
	ameliorer();
}

ZFraction::~ZFraction()
{
}

bool ZFraction::estEgal(ZFraction const &fraction) const
{
	return m_numerateur==fraction.m_numerateur && m_denominateur==fraction.m_denominateur;
}

bool ZFraction::estPlusGrandQue(ZFraction const &fraction) const
{
	return m_numerateur/m_denominateur > fraction.m_numerateur/fraction.m_denominateur;
}

ZFraction& ZFraction::operator+=(ZFraction const &fraction)
{
	int ppcm1(ppcm(m_denominateur, fraction.m_denominateur));

	m_numerateur*=ppcm1/m_denominateur;
	int nominateur2 = fraction.m_numerateur * ppcm1/fraction.m_denominateur;

	m_numerateur+=nominateur2;
	m_denominateur=ppcm1;

	ameliorer();
	return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const &fraction)
{
	int ppcm1(ppcm(m_denominateur, fraction.m_denominateur));

	m_numerateur*=ppcm1/m_denominateur;
	int nominateur2 = fraction.m_numerateur * ppcm1/fraction.m_denominateur;

	m_numerateur-=nominateur2;
	m_denominateur=ppcm1;

	ameliorer();
	return *this;
}

void ZFraction::afficher(ostream &flux) const
{
	if (m_denominateur == 1)
	{
		flux << m_numerateur;
	}
	else {
		flux << m_numerateur << "/" << m_denominateur;
	}
}

ZFraction& ZFraction::operator*=(ZFraction const &fraction)
{
	m_numerateur*=fraction.m_numerateur;
	m_denominateur*=fraction.m_denominateur;
	ameliorer();
	return *this;
}

ZFraction& ZFraction::operator/=(ZFraction const &fraction)
{
	m_numerateur*=fraction.m_denominateur;
	m_denominateur*=fraction.m_numerateur;
	ameliorer();
	return *this;
}

void ZFraction::simplifier()
{
	int pgcd1(pgcd(m_numerateur, m_denominateur));
	m_numerateur/=pgcd1;
	m_denominateur/=pgcd1;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
	return a.estEgal(b);
}

bool operator!=(ZFraction const& a, ZFraction const& b)
{
	return !(a==b);
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
	return a.estPlusGrandQue(b);
}

bool operator<(ZFraction const& a, ZFraction const& b)
{
	return !(a>b) && a!=b;
}

bool operator>=(ZFraction const& a, ZFraction const& b)
{
	return a>b || a==b;
}

bool operator<=(ZFraction const& a, ZFraction const& b)
{
	return a<b || a==b;
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);

	copie+=b;
	return copie;
}

ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);

	copie-=b;
	return copie;
}

ostream &operator<<( ostream &flux, ZFraction const& fraction)
{
    fraction.afficher(flux) ;
    return flux;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie*=b;
	return copie;
}

ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie/=b;
	return copie;
}

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

int ppcm(int a, int b)
{
	int x=a;
	int y=b;
	while(x!=y)
	{
		while(x>y) y=y+b;
		while(y>x) x=x+a;
	}
	return x;
}

int ZFraction::numerateur() const
{
	return m_numerateur;
}

int ZFraction::denominateur() const
{
	return m_denominateur;
}

double ZFraction::decimal() const
{
	return (double)m_numerateur / (double)m_denominateur;
}

void ZFraction::placerSigne()
{
	if (m_numerateur < 0 && m_denominateur < 0)
	{
		m_numerateur = std::abs(m_numerateur);
		m_denominateur = std::abs(m_denominateur);
	}
	else if (m_denominateur < 0)
	{
		m_denominateur = std::abs(m_denominateur);
		m_numerateur = -m_numerateur;
	}
}

ZFraction abs(ZFraction const &fraction)
{
	ZFraction copie(fraction);
	copie.abs();
	return copie;
}

void ZFraction::abs()
{
	m_numerateur = std::abs(m_numerateur);
	ameliorer();
}

ZFraction pow(ZFraction const &fraction, int puissance)
{
	ZFraction copie(fraction);
	copie.pow(puissance);
	return copie;
}

void ZFraction::pow(int puissance)
{
	m_numerateur = std::pow(m_numerateur, puissance);
	m_denominateur = std::pow(m_denominateur, puissance);
	ameliorer();
}

ZFraction sqrt(ZFraction const &fraction)
{
	ZFraction copie(fraction);
	copie.sqrt();
	return copie;
}

void ZFraction::sqrt()
{
	m_numerateur = std::sqrt(m_numerateur);
	m_denominateur = std::sqrt(m_denominateur);
	ameliorer();
}

ZFraction& ZFraction::operator-(ZFraction const &fraction)
{
	m_numerateur-=m_numerateur*2;
}

void ZFraction::ameliorer()
{
	simplifier();
	placerSigne();
}