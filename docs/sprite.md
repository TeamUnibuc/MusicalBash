# Sprite

### Class able to render stuff on the terminal, base class for all displayable classes.

## List of methods:

```c++
Sprite();
/// creates a sprite

virtual void Render(int delta_x, int delta_y, bool forced=false);
/** renders the sprite, in a recursive mode. forced specifies if the 
 * sprite is forced to render even if it detected no updates (e.g. 
 * another sprite overwrote it) */

void AddElement(Sprite* elem, int delta_x, int delta_y);
/** Adds an element to the sprite, at relative position
 * (delta_x, delta_y) */

void RenderUpdate();
// detects a render update and propagates it upward
