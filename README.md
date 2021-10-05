# CTBars

A bar manager for the terminal, written in C. You can use it to display loading bars and stuff like that.

I don't really know if the project is really going to be helpful, but i'm making it to practice my C and programming skills in general.  
I plan to add always more features in the future.

## Todo

- [x] Working simple loading bar
- [ ] Custom bars
- [ ] Examples

## Documentation

Create a simple bar
```c
/// Without using a rectangle
struct CTBar bar = CTBar_Init(x, y, w, h, min, max);

/// Using a rectangle
// Currently, x, y and height doesn't affect the render
struct CTBar_Rect = {
    .x = xpos,
    .y = ypos,
    .w = width,
    .h = height
};

struct CTBar bar = CTBar_InitR(rect, min, max);
```

Change the value of the bar
```c
// Note that if min=0 and value<0, the value is going to be clamped during the render
bar.value = value;
```

Render a bar
```c
// flush defines if we need to call fflush on stdout after the render
CTBar_Render(bar, flush);
```
