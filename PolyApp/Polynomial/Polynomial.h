#pragma once
#include "../Containers/List.h"
#include "Monom.h"
#include <regex>

class Polynomial : protected ad::List<Monom>
{
public:
	using List::List;
	Polynomial();
	Polynomial(const Polynomial& other);
	Polynomial(const Monom& _monom);
	using List::operator=;
	//Polynomial& operator=(const Polynomial& other);
	Polynomial operator+(const Polynomial& other);
	Polynomial operator-(const Polynomial& other);
	Polynomial operator*(const Polynomial& other);
	Polynomial operator/(const Polynomial& other);

	Polynomial derivative(size_t indexOfVariable);
	Polynomial power(const Polynomial& base, unsigned indicator);
	void eraseZeros();
	static Polynomial parsePolynomial(const std::string& input);
};

inline Polynomial::Polynomial()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

inline Polynomial::Polynomial(const Polynomial& other)
{
	Node* temp = other.head;
	while (temp != nullptr)
	{
		push_back(temp->value);
		temp = temp->nextNode;
	}
}

inline Polynomial::Polynomial(const Monom& _monom)
{
	head = new Node(_monom);
	tail = head;
	size = 1;
}

inline Polynomial Polynomial::operator+(const Polynomial& other)
{
	Polynomial result;
	for (auto thisIter = begin(); thisIter != end(); ++thisIter)
	{
		bool added = false;
		for (auto otherIter = other.begin(); otherIter != other.end(); ++otherIter)
		{
			if ((*thisIter).similiar(*otherIter))
			{
				result.push_back(*thisIter + *otherIter);
				added = true;
			}
		}
		if (!added)
			result.push_back(*thisIter);
	}
	//MergeSort(&result.head);
	result.eraseZeros();
	return result;
}

inline Polynomial Polynomial::operator-(const Polynomial& other)
{
	Polynomial result;
	for (auto thisIter = begin(); thisIter != end(); ++thisIter)
	{
		bool added = false;
		for (auto otherIter = other.begin(); otherIter != other.end(); ++otherIter)
		{
			if ((*thisIter).similiar(*otherIter))
			{
				result.push_back(*thisIter - *otherIter);
				added = true;
			}
		}
		if (!added)
			result.push_back(*thisIter);
	}
	//MergeSort(&result.head);
	result.eraseZeros();
	return result;
}

inline Polynomial Polynomial::operator*(const Polynomial& other)
{
	Polynomial result;
	for (auto thisIter = begin(); thisIter != end(); ++thisIter)
		for (auto otherIter = other.begin(); otherIter != other.end(); ++otherIter)
			result.push_back(*thisIter * *otherIter);
	for (auto iterI = result.begin(); iterI != result.end() - 1; ++iterI)
		for (auto iterJ = iterI + 1; iterJ != result.end();)
			if ((*iterI).similiar(*iterJ))
			{
				*iterI = *iterI + *iterJ;
				iterJ = result.erase(iterJ);
			}
			else
				++iterJ;
	//MergeSort(&result.head);
	result.eraseZeros();
	return result;
}

inline Polynomial Polynomial::operator/(const Polynomial& other)
{
	Polynomial result;
	for (auto thisIter = begin(); thisIter != end(); ++thisIter)
		for (auto otherIter = other.begin(); otherIter != other.end(); ++otherIter)
			if ((*thisIter).getDegrees() < (*otherIter).getDegrees())
				;
			else
				result.push_back(*thisIter / *otherIter);
	//MergeSort(&result.head);
	result.eraseZeros();
	return result;
}

inline Polynomial Polynomial::derivative(size_t indexOfVariable)
{
	Polynomial result;
	for (auto& elem : *this)
	{
		result.push_back(elem.derivative(indexOfVariable));
	}
	//MergeSort(&result.head);
	result.eraseZeros();
	return result;
}

inline Polynomial Polynomial::power(const Polynomial& base, unsigned indicator)
{
	if (indicator == 0)
		return Polynomial(Monom(1));
	else if (indicator == 1)
		return base;
	else
	{
		Polynomial result = power(base, indicator / 2);
		result = result * result;
		if (indicator % 2 == 1)
			result = result * base;
		return result;
	}
}

inline void Polynomial::eraseZeros()
{
	Node* current = head;
	for (auto iter = begin(); iter != end();)
		if ((*iter).getCoefficient() == 0)
			iter = erase(iter);
		else
			++iter;
}

inline Polynomial Polynomial::parsePolynomial(const std::string& input)
{
	std::regex monomRegex(R"(([-+]?\d*\.?\d*)x_(\d+)(\^(\d+))?)");
	std::smatch match;
	std::string remaining = input;
	Polynomial polynomial;

	while (std::regex_search(remaining, match, monomRegex)) {
		double coeff = match[1].str().empty() ? 1.0 : std::stod(match[1]);
		unsigned var = std::stoul(match[2]);
		unsigned degree = match[4].str().empty() ? 1 : std::stoul(match[4]);

		ad::Vector<unsigned> degrees(var + 1, 0);
		degrees[var] = degree;

		polynomial.push_back(Monom(coeff, degrees));

		remaining = match.suffix();
	}

	return polynomial;
}

