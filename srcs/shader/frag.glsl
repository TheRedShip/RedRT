#version 330 core
out vec4 fragColor;
uniform vec2 resolution;

struct Sphere {
	vec3 center;
	float radius;
	vec3 color;
};

layout(std140) uniform Spheres {
	Sphere spheres[1];
};

bool raySphereIntersect(vec3 rayOrigin, vec3 rayDir, vec3 center, float radius, out vec3 hitPoint) {
	vec3 oc = rayOrigin - center;
	float a = dot(rayDir, rayDir);
	float b = 2.0 * dot(oc, rayDir);
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0) return false;
	float t = (-b - sqrt(discriminant)) / (2.0 * a);
	hitPoint = rayOrigin + t * rayDir;
	return true;
}

void main() {
	vec2 uv = gl_FragCoord.xy / resolution * 2.0 - 1.0;
	uv.x *= resolution.x / resolution.y;
	vec3 rayOrigin = vec3(0.0, 0.0, 0.0);
	vec3 rayDir = normalize(vec3(uv, -1.0));
	vec3 hitPoint;
	if (raySphereIntersect(rayOrigin, rayDir, spheres[0].center, spheres[0].radius, hitPoint)) {
		vec3 light_direction = normalize(vec3(0., -10., 15.) - hitPoint);
		vec3 normal = normalize(hitPoint - spheres[0].center);
		float diffuse_light = max(0.0, dot(normal, light_direction));
		fragColor = vec4(diffuse_light * spheres[0].color, 1.0);
	} else {
		fragColor = vec4(0.0, 0.0, 0.0, 1.0);
	}
};