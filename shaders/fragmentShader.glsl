uniform sampler2D texture;
uniform int width;
uniform int height;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    if (texture2D(texture, gl_TexCoord[0].xy - vec2(1.0f / (float)width, 0.0f)).x >= 0.5)
    {
        gl_FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    }

    else
    {
        gl_FragColor = pixel;
    }
}
