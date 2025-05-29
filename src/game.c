#include "game.h"
#include "particle.h"

void events(Game *game);
void draw(Game *game);

Game *create_game()
{
    Game *game = (Game *)calloc(1, sizeof(struct Game));
    if (!game)
    {
        return NULL;
    }

    if (!SDL_Init(SDL_FLAGS))
    {
        fprintf(stderr, "SDL Initialization failed: %s\n", SDL_GetError());
        free(game);
        return NULL;
    }

    game->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!game->window)
    {
        fprintf(stderr, "SDL Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    game->renderer = SDL_CreateRenderer(game->window, NULL);
    if (!game->renderer)
    {
        fprintf(stderr, "SDL Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(game->window);
        SDL_Quit();
        free(game);
        return NULL;
    }

    game->is_running = true;

    srand((unsigned int)time(NULL));

    return game;
}

void destroy_game(Game *game)
{
    if (game)
    {

        if (game->renderer)
        {
            SDL_DestroyRenderer(game->renderer);
            game->renderer = NULL;
        }

        if (game->window)
        {
            SDL_DestroyWindow(game->window);
            game->window = NULL;
        }

        SDL_Quit();
        free(game);
    }
}

void events(Game *game)
{
    while (SDL_PollEvent(&game->event))
    {
        switch (game->event.type)
        {
        case SDL_EVENT_QUIT:
            game->is_running = false;
            break;
        case SDL_EVENT_KEY_DOWN:
            switch (game->event.key.scancode) {
            case SDL_SCANCODE_ESCAPE:
                game->is_running = false;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void draw(Game *game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 0);

    Particle seed = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};

    Particle curr = seed;

    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        Particle next = walk(&curr);
        SDL_RenderPoint(game->renderer, next.x, next.y);

        curr = next;

        if (curr.x < 0 || curr.x >= WINDOW_WIDTH || curr.y < 0 || curr.y >= WINDOW_HEIGHT) {
            curr = seed;
        }
    }

    SDL_RenderPresent(game->renderer);
    
}

void run_game(Game *game)
{
    while (game->is_running)
    {
        events(game);

        draw(game);
        
        SDL_Delay(5000);
    }
}