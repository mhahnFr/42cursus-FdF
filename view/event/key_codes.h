#ifndef KEY_CODES_H
# define KEY_CODES_H

/*
 * This enumeration contains some collected key codes on macOS 10.15. For
 * different implementations one can simply exchange this header.
 */
typedef enum e_key_codes {
	ESC	= 53, A = 0, B = 11, C = 8, D = 2, E = 14, F = 3, G = 5, H = 4, I = 34,
	J = 38, K = 40, L = 37, M = 46, N = 45, O = 31, P = 35, Q = 12, R = 15,
	S = 1, T = 17, U = 32, V = 9, W = 13, X = 7, Y = 16, Z = 6, F1 = 122,
	F2 = 120, F3 = 99, F4 = 118, F5 = 96, F6 = 97, F7 = 98, F8 = 100, F9 = 101,
	F10 = 109, F11 = 103, F12 = 111, F13 = 105, F14 = 107, F15 = 113,
	F16 = 106, F17 = 64, F18 = 79, ONE = 18, TWO = 19, THREE = 20, FOUR = 21,
	FIVE = 23, SIX = 22, SEVEN = 26, EIGHT = 28, NINE = 25, ZERO = 29,
	NUM_0 = 82, NUM_1 = 83, NUM_2 = 84, NUM_3 = 85, NUM_4 = 86, NUM_5 = 87,
	NUM_6 = 88, NUM_7 = 89, NUM_8 = 91, NUM_9 = 92, LEFT = 123, RIGHT = 124,
	UP = 126, DOWN = 125, RETURN = 36, ENTER = 76, DELETE = 117, BACKSPACE = 51,
	L_SHIFT = 257, R_SHIFT = 258, L_CTRL = 256, R_CTRL = 269, L_ALT = 261,
	R_ALT = 262, L_CMD = 259, R_CMD = 260, COMMA = 43, DOT = 47, SPACE = 49,
	NUM_PLUS = 69, NUM_MINUS = 78
}	t_key_codes;

#endif
