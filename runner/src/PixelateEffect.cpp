#include "../header/PixelateEffect.h"

using namespace std;


/********************************************
    Default Constructor
*********************************************
    @author Arthur  @date 28/04
*********************************************/
Pixelate::Pixelate() : m_isLoaded(false)
{ }


/********************************************
    Destructor
*********************************************
    @author Arthur  @date 28/04
*********************************************/
Pixelate::~Pixelate()
{ }


/********************************************
   Load if shader available
*********************************************
    @author Arthur  @date 28/04
*********************************************/
void Pixelate::load(string image)
{
    m_isLoaded = sf::Shader::isAvailable() && onLoad(image);
}


/********************************************
    action linked to load
*********************************************
    @author Arthur  @date 28/04
*********************************************/
bool Pixelate::onLoad(std::string image)
{
    if (!m_texture.loadFromFile(image))
        return false;
    m_sprite.setTexture(m_texture);

    // Load the shader
    if (!m_shader.loadFromFile("Resources/pixelate.frag", sf::Shader::Fragment))
        return false;
    m_shader.setParameter("texture", sf::Shader::CurrentTexture);

    return true;
}


/********************************************
   Effect update
*********************************************
    @author Arthur  @date 28/04
*********************************************/
void Pixelate::update(float time, float x, float y)
{
    if (m_isLoaded)
        m_shader.setParameter("pixel_threshold", (x + y) / 30);
}


/********************************************
    Draw function
*********************************************
    @author Arthur  @date 28/04
*********************************************/
void Pixelate::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_isLoaded)
    {
        states.shader = &m_shader;
        target.draw(m_sprite, states);
    }
}
