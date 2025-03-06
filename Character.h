#include <BBOP/Graphics/bbopMathClass.h>
#include <BBOP/Graphics/sceneClass.h>
#include <BBOP/Graphics.h>

enum State{
    rest=1,
    throwing=2,
    pull=3
};

class Character : public Sprite{
private:
    Vector2f position;

public:
    Character();
    std::vector<Texture> texture[2];
    Texture Base;
    Sprite character;
    State state;
    void Animate();
    void Draw(GLint *renderUniforms) const override;
    void SetPosition(Vector2f); // useful?
    Vector2f GetPosition();
};

/*
to do:
- animation
- var etat
- def le sprite?
*/