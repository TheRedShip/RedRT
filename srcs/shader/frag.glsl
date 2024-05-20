#version 330 core
out vec4 fragColor;

uniform vec2 resolution;
uniform int numberObjects;

struct Sphere {
    vec4 center;
    vec4 color;
};

struct hit_info {
	vec3 	position;
	vec3 	normal;
	float	distance;
	Sphere obj;
};

layout(std140) uniform SphereBlock {
    Sphere spheres[100];
};

bool raySphereIntersect(vec3 rayOrigin, vec3 rayDir, Sphere sphere, out hit_info hit)
{
	vec3 oc = rayOrigin - sphere.center.xyz;
	float a = dot(rayDir, rayDir);
	float b = 2.0 * dot(oc, rayDir);
	float c = dot(oc, oc) - sphere.center.w * sphere.center.w;
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0) return false;
	float t = (-b - sqrt(discriminant)) / (2.0 * a);
	hit.position = rayOrigin + t * rayDir;
	hit.normal = normalize(hit.position - sphere.center.xyz);
	hit.distance = t;
	return true;
}

bool	hit_objects(vec3 rayOrigin, vec3 rayDir, out hit_info hit)
{
	for (int i = 0; i < numberObjects; i++) {
		if (raySphereIntersect(rayOrigin, rayDir, spheres[i], hit)) {
			hit.obj = spheres[i];
			return true;
		}
	}
	return (false);
}

void main()
{
	vec2 uv = gl_FragCoord.xy / resolution * 2.0 - 1.0;
	uv.x *= resolution.x / resolution.y;
	vec3 rayOrigin = vec3(0.0, 0.0, 0.0);
	vec3 rayDir = normalize(vec3(uv, -1.0));

	hit_info hit;
	if (hit_objects(rayOrigin, rayDir, hit)) {
		float intensity = dot(hit.normal, normalize(vec3(0.0, 1.0, 1.0)));
		fragColor = hit.obj.color * intensity;
	} else {
		fragColor = vec4(0.0, 0.0, 0.0, 1.0);
	}
};