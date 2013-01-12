mat4 ident(){
return mat4(1.0, 0.0, 0.0, 0.0, 
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0);
}

mat4 rotateX(float alpha){
return mat4(1.0, 0.0, 0.0, 0.0, 
			0.0, cos(alpha), -sin(alpha), 0.0,
			0.0, sin(alpha), cos(alpha), 0.0,
			0.0, 0.0, 0.0, 1.0);
}

mat4 rotateY(float alpha){
return mat4(cos(alpha), 0.0, sin(alpha), 0.0, 
			0.0, 1.0, 0.0, 0.0,
			-sin(alpha), 0.0, cos(alpha), 0.0,
			0.0, 0.0, 0.0, 1.0);
}


mat4 rotateZ(float alpha){
return mat4(cos(alpha), -sin(alpha), 0.0, 0.0,
			sin(alpha), cos(alpha), 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0);
}

mat4 translateX(float d){
return mat4(1.0, 0.0, 0.0, d, 
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0);
}

mat4 translateY(float d){
return mat4(1.0, 0.0, 0.0, 0.0, 
			0.0, 1.0, 0.0, d,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0);
}

mat4 translateZ(float d){
return mat4(1.0, 0.0, 0.0, 0.0, 
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, d,
			0.0, 0.0, 0.0, 1.0);
}
