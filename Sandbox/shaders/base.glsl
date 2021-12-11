#type vertex
#version 410 core

layout(location = 0) in vec4 VertexPosition;
layout(location = 1) in vec2 VertexTexCoord;

out vec2 TexCoord;

void main(){
	TexCoord = VertexTexCoord;
	gl_Position = VertexPosition;
}

#type fragment
#version 410 core

out vec4 color;
in vec2 TexCoord;

uniform sampler2D u_Texture;

void main(){
	vec4 tex = texture(u_Texture, TexCoord);
	// color = vec4(1.0, 0.5, 0.9, 1.0);
	color = tex;
}