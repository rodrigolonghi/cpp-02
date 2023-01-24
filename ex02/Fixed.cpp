#include "Fixed.hpp"

Fixed::Fixed() : _bits(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::Fixed(const int nbr) {
	this->_bits = nbr * pow(2.0f, (float)this->_fractional);
}

Fixed::Fixed(const float nbr) {
	this->_bits = nbr * pow(2.0f, (float)this->_fractional) + (nbr >= 0 ? 0.5 : -0.5);
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_bits = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const &rhs) {
	Fixed	result(this->toFloat() + rhs.toFloat());
	return result;
}

Fixed Fixed::operator-(Fixed const &rhs) {
	Fixed	result(this->toFloat() - rhs.toFloat());
	return result;
}

Fixed Fixed::operator*(Fixed const &rhs) {
	Fixed	result(this->toFloat() * rhs.toFloat());
	return result;
}

Fixed Fixed::operator/(Fixed const &rhs) {
	Fixed	result(this->toFloat() / rhs.toFloat());
	return result;
}

Fixed &Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed newFixed = *this;
	this->setRawBits(this->getRawBits() + 1);
	return newFixed;
}

Fixed &Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed newFixed = *this;
	this->setRawBits(this->getRawBits() - 1);
	return newFixed;
}

bool Fixed::operator<(Fixed const &rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(Fixed const &rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

int		Fixed::getRawBits( void ) const {
	return this->_bits;
}

void 	Fixed::setRawBits( int const raw ) {
	this->_bits = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_bits) / pow(2.0f, (float)this->_fractional);
}

int	Fixed::toInt( void ) const {
	return this->_bits / pow(2.0f, (float)this->_fractional);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

Fixed &Fixed::min(Fixed &first_nbr,Fixed &second_nbr) {
	if (first_nbr < second_nbr)
		return first_nbr;
	return second_nbr;
}

Fixed const &Fixed::min(Fixed const &first_nbr, Fixed const &second_nbr) {
	if (first_nbr < second_nbr)
		return first_nbr;
	return second_nbr;
}

Fixed &Fixed::max(Fixed &first_nbr,Fixed &second_nbr) {
	if (first_nbr > second_nbr)
		return first_nbr;
	return second_nbr;
}

Fixed const &Fixed::max(Fixed const &first_nbr, Fixed const &second_nbr) {
	if (first_nbr > second_nbr)
		return first_nbr;
	return second_nbr;
}
