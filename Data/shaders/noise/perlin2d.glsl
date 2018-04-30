#version 430

//gradient.h
layout(std430, binding = 0) buffer permutationBuffer
{
	int myData[512];
}permute;

layout(std430, binding = 1) buffer gradientPermutationBuffer
{
	int myData[512];
}gradientPermute;

const float GRAD_X[] = 
{
	1.0, -1.0, 1.0, -1.0,
	1.0, -1.0, 1.0, -1.0,
	0.0, 0.0, 0.0, 0.0
};
const float GRAD_Y[] = 
{
	1.0, 1.0, -1.0, -1.0,
	0.0, 0.0, 0.0, 0.0,
	1.0, -1.0, 1.0, -1.0
};
const float GRAD_Z[] = 
{
	0.0, 0.0, 0.0, 0.0,
	1.0, 1.0, -1.0, -1.0,
	1.0, 1.0, -1.0, -1.0
};

float GradCoord2D(int x, int y, float xd, float yd){
	int gradPermute = gradientPermute.myData[(x & 0xff) + permute.myData[(y & 0xff)]];
	return xd*GRAD_X[gradPermute] + yd*GRAD_Y[gradPermute];
}
float interp(float t) { return t*t*t*(t*(t * 6 - 15) + 10); }

float PerlinNoise2D(float x, float y){
	int x0 = int(floor(x));
	int y0 = int(floor(y));
	int x1 = x0 + 1;
	int y1 = y0 + 1;
	float xs = interp(fract(x));
	float ys = interp(fract(y));
	float xd0 = fract(x);
	float yd0 = fract(y);
	float xd1 = xd0 - 1.0;
	float yd1 = yd0 - 1.0;
	float xf0 = mix(GradCoord2D(x0, y0, xd0, yd0), GradCoord2D(x1, y0, xd1, yd0), xs);
	float xf1 = mix(GradCoord2D(x0, y1, xd0, yd1), GradCoord2D(x1, y1, xd1, yd1), xs);
	float perlin = mix(xf0, xf1, ys);
	return perlin;
}
