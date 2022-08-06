uniform sampler2D texture;
uniform int width;
uniform int height;

int GetNeighbourCount()
{
    int total = 0;

    for (int y = -1; y <= 1; y++)
    {
        for (int x = -1; x <= 1; x++)
        {
            if (x != 0 || y != 0)
            {
                if (texture2D(texture, gl_TexCoord[0].xy + vec2(1.0f / (float)width * (float)x, 1.0f / (float)height * (float)y)).x >= 0.5)
                {
                    total += 1;
                }
            }
        }
    }

    return total;
}

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    bool isAlive;

    if (pixel.x >= 0.5)
    {
        isAlive = true;
    }

    else
    {
        isAlive = false;
    }

    int count = GetNeighbourCount();

    if (isAlive)
    {
        if (count == 2 || count == 3)
        {
            gl_FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
        }

        else
        {
            gl_FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }

    else
    {
        if (count == 3)
        {
            gl_FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
        }

        else
        {
            gl_FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }
}
