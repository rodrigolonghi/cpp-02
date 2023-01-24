#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int					_bits;
		static const int	_fractional = 8;

	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed(int const nbr);
		Fixed(float const nbr);
		~Fixed();

		Fixed	&operator=(Fixed const &rhs);
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		Fixed	operator+(Fixed const &rhs);
		Fixed	operator-(Fixed const &rhs);
		Fixed	operator*(Fixed const &rhs);
		Fixed	operator/(Fixed const &rhs);
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	&operator++();
		Fixed	&operator--();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed		&min(Fixed &first_nbr, Fixed &second_nbr);
		static const Fixed	&min(Fixed const &first_nbr, Fixed const &second_nbr);
		static Fixed		&max(Fixed &first_nbr, Fixed &second_nbr);
		static const Fixed	&max(Fixed const &first_nbr, Fixed const &second_nbr);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
