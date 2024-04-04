Convert an infix expression to postfix format. The major rule to remember during the conversion process is that the operations with the highest precedence are converted first 
and that after a portion of an expression has been converted to postfix it is to be treated as a single operand.These operations are denoted by the usual operators, +, –, *, and /, 
respectively. There are two levels of operator precedence. Both * and / have higher precedence than + and –. Furthermore, when un parenthesized operators of the same precedence are 
scanned, the order is assumed to be left to right. Parentheses may be used in infix expressions to override the default precedence. The postfix form requires no parentheses.
For example: 
Infix: ( ( A + B ) * ( C - D ) + E ) / ( F + G ) .
Postfix: A B + C D - * E + F G + /

