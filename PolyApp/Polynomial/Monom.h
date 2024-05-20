#pragma once
#include "../Containers/Vector.h"

class Monom {
private:
	ad::Vector<unsigned> degrees;
	double coefficient;

public:
	Monom();
	Monom(const Monom& other);
	Monom(const double _coefficient, const ad::Vector<unsigned> _degrees = ad::Vector<unsigned>(1, 0.0));

	ad::Vector<unsigned> getDegrees() const;
	double getCoefficient() const;
	void setDegrees(ad::Vector<unsigned> _degrees);
	void setCoefficient(double _coefficient);

	Monom& operator=(const Monom& other);
	Monom operator+(const Monom& other) const;
	Monom operator-(const Monom& other) const;
	Monom operator*(const Monom& other) const;
	Monom operator*(const double _const) const;
	Monom operator/(const Monom& other) const;
	Monom operator/(const double _const) const;
	bool operator>(const Monom& other) const;
	bool operator>=(const Monom& other) const;
	bool operator<(const Monom& other) const;
	bool operator<=(const Monom& other) const;
	bool operator==(const Monom& other) const;
	bool operator!=(const Monom& other) const;
	Monom derivative(const size_t indexOfVariable) const;
	bool similiar(const Monom& other) const;
};

inline Monom::Monom()
{
	coefficient = 0.0;
	degrees = ad::Vector<unsigned>(1, 0);
}

inline Monom::Monom(const Monom& other)
{
	coefficient = other.coefficient;
	degrees = other.degrees;
}

inline Monom::Monom(const double _coefficient, const ad::Vector<unsigned> _degrees)
{
	coefficient = _coefficient;
	degrees = _degrees;
}

inline ad::Vector<unsigned> Monom::getDegrees() const
{
	return degrees;
}

inline double Monom::getCoefficient() const
{
	return coefficient;
}

inline void Monom::setDegrees(ad::Vector<unsigned> _degrees)
{
	degrees = _degrees;
}

inline void Monom::setCoefficient(double _coefficient)
{
	coefficient = _coefficient;
}

inline Monom& Monom::operator=(const Monom& other)
{
	if (this != &other)
	{
		degrees = other.degrees;
		coefficient = other.coefficient;
	}
	return *this;
}

inline Monom Monom::operator+(const Monom& other) const
{
	return Monom(coefficient + other.coefficient, degrees);
}

inline Monom Monom::operator-(const Monom& other) const
{
	return Monom(coefficient - other.coefficient, degrees);
}

inline Monom Monom::operator*(const Monom& other) const
{
	bool biggerThanRight = degrees.size() > other.degrees.size();
	ad::Vector<unsigned> newDegrees(biggerThanRight ? other.degrees.size() : degrees.size());
	for (size_t i = 0; i < newDegrees.size(); i++)
		newDegrees[i] = degrees[i] + other.degrees[i];
	if (biggerThanRight)
		while (newDegrees.size() != degrees.size())
			newDegrees.push_back(degrees[newDegrees.size()]);
	else
		while (newDegrees.size() != other.degrees.size())
			newDegrees.push_back(other.degrees[newDegrees.size()]);
	return Monom(coefficient * other.coefficient, newDegrees);
}

inline Monom Monom::operator*(const double _const) const
{
	return Monom(coefficient * _const, degrees);
}

inline Monom Monom::operator/(const Monom& other) const
{
	ad::Vector<unsigned> newDegrees(other.degrees.size());
	for (size_t i = 0; i < newDegrees.size(); i++)
		newDegrees[i] = degrees[i] - other.degrees[i];
	return Monom(coefficient / other.coefficient, newDegrees);
}

inline Monom Monom::operator/(const double _const) const
{
	return Monom(coefficient / _const, degrees);
}

inline bool Monom::operator>(const Monom& other) const
{
	if (coefficient == 0 && other.coefficient != 0)
		return false;
	else
		if (coefficient != 0 && other.coefficient == 0)
			return true;
	int posOfDifferent = -1;
	for (size_t i = 0; i < degrees.size(); i++)
		if (degrees[i] != other.degrees[i])
		{
			posOfDifferent = i;
			break;
		}
	if (posOfDifferent > -1)
		return degrees[posOfDifferent] > other.degrees[posOfDifferent];
	else
		return coefficient > other.coefficient;
}

inline bool Monom::operator>=(const Monom& other) const
{
	if (coefficient == 0 && other.coefficient != 0)
		return false;
	else
		if (coefficient != 0 && other.coefficient == 0)
			return true;
	int posOfDifferent = -1;
	for (size_t i = 0; i < degrees.size(); i++)
		if (degrees[i] != other.degrees[i])
		{
			posOfDifferent = i;
			break;
		}
	if (posOfDifferent > -1)
		return degrees[posOfDifferent] >= other.degrees[posOfDifferent];
	else
		return coefficient >= other.coefficient;
}

inline bool Monom::operator<(const Monom& other) const
{
	if (coefficient == 0 && other.coefficient != 0)
		return true;
	else
		if (coefficient != 0 && other.coefficient == 0)
			return false;
	int posOfDifferent = -1;
	for (size_t i = 0; i < degrees.size(); i++)
		if (degrees[i] != other.degrees[i])
		{
			posOfDifferent = i;
			break;
		}
	if (posOfDifferent > -1)
		return degrees[posOfDifferent] < other.degrees[posOfDifferent];
	else
		return coefficient < other.coefficient;
}

inline bool Monom::operator<=(const Monom& other) const
{
	if (coefficient == 0 && other.coefficient != 0)
		return true;
	else
		if (coefficient != 0 && other.coefficient == 0)
			return false;
	int posOfDifferent = -1;
	for (size_t i = 0; i < degrees.size(); i++)
		if (degrees[i] != other.degrees[i])
		{
			posOfDifferent = i;
			break;
		}
	if (posOfDifferent > -1)
		return degrees[posOfDifferent] <= other.degrees[posOfDifferent];
	else
		return coefficient <= other.coefficient;
}

inline bool Monom::operator==(const Monom& other) const
{
	for (size_t i = 0; i < degrees.size(); i++)
		if (degrees[i] != other.degrees[i])
			return false;
	return coefficient == other.coefficient;
}

inline bool Monom::operator!=(const Monom& other) const
{
	int posOfDifferent = -1;
	for (size_t i = 0; i < degrees.size(); i++)
		if (degrees[i] != other.degrees[i])
			return true;
	return coefficient != other.coefficient;
}

inline Monom Monom::derivative(const size_t indexOfVariable) const
{
	if (degrees[indexOfVariable] == 0)
		if (coefficient == 0)
			return Monom();
		else
			return Monom(1);
	else
	{
		ad::Vector<unsigned> newDegrees(degrees);
		newDegrees[indexOfVariable] -= 1.0;
		return Monom(coefficient * degrees[indexOfVariable], newDegrees);
	}
}

inline bool Monom::similiar(const Monom& other) const
{
	for (size_t i = 0; i < degrees.size(); i++)
		if (degrees[i] != other.degrees[i])
			return false;
	return true;
}
