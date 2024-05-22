#version 330 core
out vec4 fragColor;

uniform int 		numberObjects;
uniform vec2 		resolution;
uniform float 		uTime;
uniform int 		uRand;

uniform int			uFrameCount;
uniform sampler2D	currentFrame;

struct Sphere {
    vec4 	origin;
    vec4 	color;
	vec4	mat;
};

struct Camera
{
	vec4	origin;
	vec4	direction;
	mat4	rotation_matrix_x;
	mat4	rotation_matrix_y;
};


struct hit_info {
	vec3 	position;
	vec3 	normal;
	float	dist;
	Sphere	obj;
};

struct t_ray {
	vec3 origin;
	vec3 dir;
};


struct Scene
{
	Sphere	obj[1000];
	Camera	camera;
	int		frameCount;
};

layout(std140) uniform SceneBlock {
    Scene scene;
};


bool raySphereIntersect(t_ray ray, Sphere sphere, out hit_info hit)
{
	vec3 oc = ray.origin - sphere.origin.xyz;
	float a = dot(ray.dir, ray.dir);
	float b = 2.0 * dot(oc, ray.dir);
	float c = dot(oc, oc) - sphere.origin.w * sphere.origin.w;
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0) return false;
	float t = (-b - sqrt(discriminant)) / (2.0 * a);
	hit.position = ray.origin + t * ray.dir;
	hit.normal = normalize(hit.position - sphere.origin.xyz);
	hit.dist = t;
	return true;
}

bool	hit_objects(t_ray ray, out hit_info hit)
{
	hit_info tmp_hit;

	hit.dist = -1.0f;
	for (int i = 0; i < numberObjects; i++) {
		if (scene.obj[i].origin.w <= 0.0f) break;
		if (raySphereIntersect(ray, scene.obj[i], tmp_hit)) {
			if (tmp_hit.dist > 0.0f && (tmp_hit.dist < hit.dist || hit.dist < 0.0f))
			{
				hit.position = tmp_hit.position;
				hit.normal = tmp_hit.normal;
				hit.dist = tmp_hit.dist;
				hit.obj = scene.obj[i];
			}
		}
	}
	return (hit.dist >= 0.0f);
}

int rand_seed = 0;

uint hash( uint x ) {
    x += ( x << 10u );
    x ^= ( x >>  6u );
    x += ( x <<  3u );
    x ^= ( x >> 11u );
    x += ( x << 15u );
    return x;
}

uint hash( uvec2 v ) { return hash( v.x ^ hash(v.y)                         ); }
uint hash( uvec3 v ) { return hash( v.x ^ hash(v.y) ^ hash(v.z)             ); }
uint hash( uvec4 v ) { return hash( v.x ^ hash(v.y) ^ hash(v.z) ^ hash(v.w) ); }

float floatConstruct( uint m ) {
    const uint ieeeMantissa = 0x007FFFFFu; 
    const uint ieeeOne      = 0x3F800000u; 

    m &= ieeeMantissa;
    m |= ieeeOne;

    float  f = uintBitsToFloat( m );       
    return f - 1.0;                        
}


float randombis( float x ) { return floatConstruct(hash(floatBitsToUint(x))); }
float randombis( vec2  v ) { return floatConstruct(hash(floatBitsToUint(v))); }
float randombis( vec3  v ) { return floatConstruct(hash(floatBitsToUint(v))); }
float randombis( vec4  v ) { return floatConstruct(hash(floatBitsToUint(v))); }

float random()
{
	if (rand_seed == 0)
		rand_seed = uRand;
	rand_seed *= 2;
	return randombis(vec3(gl_FragCoord.xy, uTime * rand_seed));
}

void	new_ray(hit_info hit, inout t_ray ray)
{
	vec3	rand;
	vec3	in_unit_sphere;

	in_unit_sphere = normalize(vec3((random() - 0.5) * 2, (random() - 0.5) * 2, (random() - 0.5) * 2));

	if (dot(in_unit_sphere, hit.normal) < 0.0f)
		in_unit_sphere *= -1.0f;
	
	vec3 diffuse_dir = normalize(hit.normal + in_unit_sphere);
	vec3 specular_dir = reflect(ray.dir, hit.normal);
	
	ray.origin = hit.position + hit.normal * 0.001;
	ray.dir = mix(diffuse_dir, specular_dir, hit.obj.mat.r);
}

void	calcul_lc(hit_info hit, out vec3 light)
{
	vec3	light_pos = vec3(0,5,0);
	vec3	light_direction = normalize(light_pos - hit.position);
	float	diffuse_ratio = 0.0;

	// t_ray		shadow_ray = t_ray(hit.position + hit.normal * 0.001, light_direction);
	// hit_info	shadow_hit;

	// hit_objects(shadow_ray, shadow_hit);
	// if (!(shadow_hit.dist > 0.0 && shadow_hit.dist < length(light_pos - hit.position)))
	// {
	// 	diffuse_ratio = max(0.0, dot(hit.normal, light_direction));
	// 	light += diffuse_ratio;
	// }

	if (hit.obj.mat.g > 0.0)
		light += hit.obj.color.rgb * hit.obj.mat.g;

}

vec3	per_pixel(t_ray ray)
{
	hit_info	hit;
	vec3		light = vec3(0.0, 0.0, 0.0);
	vec3		color = vec3(1.0, 1.0, 1.0);

	for (int i = 0; i < 50; i++)
	{
		if (hit_objects(ray, hit))
		{
			new_ray(hit, ray);
			color *= hit.obj.color.rgb;
			calcul_lc(hit, light);
			if (hit.obj.mat.g > 0.0)
				break ;
		}
		else
		{
			// light += vec3(0.5, 0.8, 0.92);
			break ;
		}
	}
	return (color * light);
}


vec4 multiply_matrix_vector(mat4 m, vec4 vector)
{
	vec4 result;

	result.x = m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z;
	result.y = m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z;
	result.z = m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z;
	result.w = 0;

	return (result);
}

t_ray	calculate_ray(vec2 uv)
{
	t_ray	ray;
	float 	fov = tan(100 / 2.0f * 3.14 / 180.0f);
	
	uv.x *= fov;
	uv.y *= fov;

	vec4	direction = vec4(uv.x, uv.y, -1.0f, 0.0f);

	direction = multiply_matrix_vector(scene.camera.rotation_matrix_x, direction);
	direction = multiply_matrix_vector(scene.camera.rotation_matrix_y, direction);
	direction = normalize(direction);

	ray.origin = scene.camera.origin.xyz;
	ray.dir = direction.xyz;
	return (ray);
}

void main()
{
	vec2 antialiasing = gl_FragCoord.xy;
	antialiasing += vec2(random() - 0.5, random() - 0.5);

	vec2 uv = antialiasing / resolution * 2.0 - 1.0;
	uv.x *= resolution.x / resolution.y;

	t_ray ray = calculate_ray(uv);
	hit_info hit;

	vec4 color = vec4(sqrt(per_pixel(ray)), 1.0);
	vec4 currentColor = texture(currentFrame, gl_FragCoord.xy / resolution.xy);
	
	if (uFrameCount == 0)
		fragColor = color;
	else
		fragColor = mix(currentColor, color, 1.0 / float(uFrameCount));
};