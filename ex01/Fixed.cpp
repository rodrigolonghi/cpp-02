#include "Fixed.hpp"

Fixed::Fixed() : _bits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	this->_bits = nbr * pow(2.0f, (float)this->_fractional);
}

Fixed::Fixed(const float nbr) {
	std::cout << "Float constructor called" << std::endl;
	this->_bits = nbr * pow(2.0f, (float)this->_fractional) + (nbr >= 0 ? 0.5 : -0.5);
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_bits = rhs.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
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
