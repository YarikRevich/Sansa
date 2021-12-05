#type vertex
#version core 410

in vec3 Coord;

void main(){
	gl_Position = Coord;
}

#type fragment

#version core 410

#ifdef GL_ES
precision mediump float
#endif

void main(){
	gl_FragColor = vec4(1.0, 1.0, 0.5, 1.0);
}