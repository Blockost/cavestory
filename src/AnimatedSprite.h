//
// Created by blockost on 1/27/19.
//

#ifndef CAVESTORY_ANIMATEDSPRITE_H
#define CAVESTORY_ANIMATEDSPRITE_H


#include <SDL2/SDL_rect.h>
#include <vector>
#include <string>
#include "Graphics.h"
#include "BoundingBox.h"

class AnimatedSprite {
public:

    /**
     * Default constructor.
     */
    AnimatedSprite() = default;

    /**
     * Constructor.
     */
    AnimatedSprite(SDL_Texture *texture, float maxFrameLifetime);

    /**
     * Destructor.
     */
    ~AnimatedSprite();

    /**
     * Retrieves sprite's bounding box.
     */
    const BoundingBox &getBoundingBox() const;

    /**
     * Adds a animation to the list of this sprite's animation.
     */
    void addAnimations(const std::string &animationName, int numberOfFrames, int x, int y);

    /**
     * Resets the list of animations for this sprite.
     */
    void resetAnimations();

    /**
     * Sets the given animation as the one to be played.
     */
    void setAnimation(const std::string &animationName);

    /**
     * Moves the sprite's bounding box to the given x and y.
     */
    void moveBoundingBox(int x, int y);

    /**
     * Draws (copies) the current frame of the sprite to the renderer at position x and y.
     */
    void draw(Graphics &graphics, int x, int y);

    /**
     * Updates the sprite animation based on the elapsed time since last update. Basically, it
     * updates the index of the frame that will be drawn afterwards.
     */
    void update(int elapsedTime);

private:
    SDL_Texture *texture{};
    // Index of the current frame in the current animation
    int frameIndex = 0;
    // Max number of milliseconds to wait before changing the frame
    float maxFrameLifetime = 0;
    // Number of milliseconds since the last frame update
    float elapsedTime = 0;
    // String identifier for the current animation being played
    std::string currentAnimation;
    // List of all animations
    std::map<std::string, std::vector<SDL_Rect>> animations{};
    // The bounding box around the sprite (for collisions detection)
    BoundingBox boundingBox;
};


#endif //CAVESTORY_ANIMATEDSPRITE_H
