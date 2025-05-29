#include "game.h"

int main(void)
{
    bool exit_status = EXIT_FAILURE;
    Game *game = create_game();

    if (game)
    {
        run_game(game);
        exit_status = EXIT_SUCCESS;
    }

    destroy_game(game);

    return exit_status;
}
