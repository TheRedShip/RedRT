#version 330 core
out vec4 fragColor;
uniform vec2 resolution;
uniform int numberObjects;

struct Sphere {
	vec4 center;
	vec4 color;
};

layout(std140) uniform Spheres {
	Sphere spheres[];
};

bool raySphereIntersect(vec3 rayOrigin, vec3 rayDir, Sphere sphere, out vec3 hitPoint) {
	vec3 oc = rayOrigin - sphere.center.xyz;
	float a = dot(rayDir, rayDir);
	float b = 2.0 * dot(oc, rayDir);
	float c = dot(oc, oc) - sphere.center.w * sphere.center.w;
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0) return false;
	float t = (-b - sqrt(discriminant)) / (2.0 * a);
	hitPoint = rayOrigin + t * rayDir;
	return true;
}

vec3	hit_objects(vec3 rayOrigin, vec3 rayDir)
{
	vec3 hitPoint;
	if (raySphereIntersect(rayOrigin, rayDir, spheres[0], hitPoint)) {
		return hitPoint;
	}
	if (raySphereIntersect(rayOrigin, rayDir, spheres[1], hitPoint)) {
		return hitPoint;
	}
	return vec3(0.0, 0.0, 0.0);
}

void main() {
	vec2 uv = gl_FragCoord.xy / resolution * 2.0 - 1.0;
	uv.x *= resolution.x / resolution.y;
	vec3 rayOrigin = vec3(0.0, 0.0, 0.0);
	vec3 rayDir = normalize(vec3(uv, -1.0));

	vec3 hitPoint = hit_objects(rayOrigin, rayDir);
	
	if (hitPoint != vec3(0.0, 0.0, 0.0)) {
		// vec3 normal = normalize(hitPoint - hit_sphere.center.xyz);
		// float intensity = dot(normal, normalize(vec3(1.0, 1.0, 1.0)));
		fragColor = vec4(1.0);
	}
	else {
		fragColor = vec4(0.0, 0.0, 0.0, 1.0);
	}

	// int i = 1;
	// while (i < 2)
	// {
	// 	fragColor = vec4(i);
	// 	return ;
	// }


};