//copyright 2015 (c) Marc Groefsema
/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef DNN_CONSTANTS_H
#define DNN_CONSTANTS_H

//dnn settings


#define LAYER_STACK_SIZE 4
#define LAYER_SIZES {28*28,200,20,10}
#define INPUT_LAYER_SIZE 28*28

#define LEARNING_RATE 0.01 //should be 0<=alpha<=1




#endif