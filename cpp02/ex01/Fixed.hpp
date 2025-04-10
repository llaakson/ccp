/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:20 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/10 13:57:18 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	private:
		int fixed;
		static const int fractional_bits = 8;
	public:
		int getRawBits( void );
		void setRawBits( int const raw );
		Fixed(const Fixed &previousFixed);
		Fixed& operator=(const Fixed& previousFixed);
		Fixed();
		~Fixed();

		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed (const int n);
		Fixed (const float n);
};
std::ostream &operator<<(std::ostream &stream, const Fixed& previousFixed);

#endif
