#version 120

void main()
{
    gl_FragDepth = (log(gl_FragCoord.z/gl_FragCoord.w + 1.0) / log(1000000000.0 + 1.0));
}
