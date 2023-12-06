typedef enum
{
    UP,
    RIGHT,
    DOWN,
    LEFT
} Direction;

typedef struct
{
    int x;
    int y;
    Direction dir;
} Snake;
