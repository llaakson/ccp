/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:20 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/09 15:21:58 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int fixed;
		static const int fractional_bits = 8;
	public:
		int getRawBits( void );
		void setRawBits( int const raw );
		Fixed(const Fixed &previousFixed);
		Fixed (int x);
		Fixed();
		~Fixed();
};

#endif
