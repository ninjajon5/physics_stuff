#include "rectangle.h"

void rectangle_apply_gravity( struct rectangle *rectangle, float gravity ) {
    rectangle->y += gravity ;
}
