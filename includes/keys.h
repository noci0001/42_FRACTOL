/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:12:36 by snocita           #+#    #+#             */
/*   Updated: 2023/04/09 11:12:46 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  define K_ESC 		65307
#  define K_NUM_MULT	65450
#  define K_NUM_DIV		65455
#  define K_NUM_PLUS	65451
#  define K_NUM_MINUS	65453
#  define K_NUM_ENTER	65421
#  define K_NUM_0		65438
#  define K_UP			65362
#  define K_DOWN		65364
#  define K_LEFT		65361
#  define K_RIGHT		65363
#  define K_DIGIT_1		49
#  define K_L			108
# else
/** define the parameter for keymaps **/

#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_ENTER 36
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_Y 16
#  define KEY_E	14
#  define KEY_Q	12
#  define KEY_C 8
#  define KEY_G 5
#  define KEY_H 4
#  define KEY_SPACE 49
#  define KEY_ONE 18
#  define KEY_TWO 19
#  define KEY_THREE 20
#  define KEY_FOUR 21
#  define KEY_FIVE 23
#  define KEY_SIX 22
#  define KEY_SEVEN 26
#  define KEY_EIGHT 28
#  define INF_C 0x36454f
#  define PSY_C 0x654321
#  define RED_C 0x0A0505
#  define GREEN_C 0x050A05
#  define BLUE_C 0x05050A
#  define GREY_C 0x666666
#  define NEWT_C 0x050A0F
#  define THORN_C 0x08ED55

# endif
#endif