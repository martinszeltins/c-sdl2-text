#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 500

void setTextTextureAndRect(SDL_Renderer *renderer, int x, int y, char *text, TTF_Font *font, SDL_Texture **textTexture, SDL_Rect *textRect);


/**
 * A program to demonstrate text rendering
 * using the SDL2 library.
 */
int main()
{
    TTF_Font * font;
    SDL_Event event;
    SDL_Rect textRect;
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Rect anotherTextRect;
    SDL_Texture * textTexture;
    SDL_Texture * anotherTextTexture;

    char * fontPath = "DaysLater.ttf";
    int quit = 0;

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
 
    font = TTF_OpenFont(fontPath, 50);
    setTextTextureAndRect(renderer, 150, 100, "hello wooorld 123", font, &textTexture, &textRect);

    font = TTF_OpenFont(fontPath, 30);
    setTextTextureAndRect(renderer, 225, 200, "Why I need subtitle", font, &anotherTextTexture, &anotherTextRect);

    while (!quit)
    {
        while (SDL_PollEvent(&event) == 1) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 100, 50, 50, 0);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_RenderCopy(renderer, anotherTextTexture, NULL, &anotherTextRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(anotherTextTexture);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * Set the text's texture and rectangle
 */
void setTextTextureAndRect(SDL_Renderer *renderer, int x, int y, char *text, TTF_Font *font, SDL_Texture **textTexture, SDL_Rect *textRect)
{
    int textWidth;
    int textHeight;

    SDL_Surface * surface;
    SDL_Color textColor = { 255, 255, 255, 0 };

    surface = TTF_RenderText_Solid(font, text, textColor);
    *textTexture = SDL_CreateTextureFromSurface(renderer, surface);

    textWidth = surface->w;
    textHeight = surface->h;

    SDL_FreeSurface(surface);

    textRect->x = x;
    textRect->y = y;
    textRect->w = textWidth;
    textRect->h = textHeight;
}