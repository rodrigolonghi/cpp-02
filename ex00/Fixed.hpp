#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					_fixed;
		static const int	_fractional = 8;

	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &rhs);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
