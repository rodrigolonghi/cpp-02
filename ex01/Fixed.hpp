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
		Fixed &operator=(Fixed const &rhs);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
