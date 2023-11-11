#version 420 core
uniform sampler2D TheTexture;
layout(binding = 1)uniform sampler2D gTexture;

layout(location = 0) out vec4 finalPixel;

void main()
{
	vec2 uv = vec2(gl_FragCoord.x/800,  gl_FragCoord.y/600);
	float sm = texture(gTexture, uv).x;
	
	if(sm > 0.5){
		finalPixel = vec4(0, 0, 0, 0);
	}
	else{
		finalPixel = vec4(0,0,0,1);
	}
}