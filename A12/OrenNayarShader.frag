#version 450#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;layout(location = 1) in vec3 fragNorm;layout(location = 2) in vec2 fragUV;

layout(location = 0) out vec4 outColor;layout(binding = 1) uniform sampler2D tex;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec4 lightColor;
	vec3 eyePos;
} gubo;

vec3 BRDF(vec3 V, vec3 N, vec3 L, vec3 Md, float sigma) {	//vec3 V  - direction of the viewer	//vec3 N  - normal vector to the surface	//vec3 L  - light vector (from the light model)	//vec3 Md - main color of the surface	//float sigma - Roughness of the model	float dotLN = dot(L, N);	float dotVN = dot(V, N);	float thetaI = acos(dotLN);	float thetaR = acos(dotVN);	float alpha = max(thetaI, thetaR);	float beta = min(thetaI, thetaR);	float a = 1 - 0.5*(sigma*sigma/(sigma*sigma+0.33));	float b = 0.45*(sigma*sigma/(sigma*sigma+0.09));	vec3 vI = normalize(L-dotLN*N);	vec3 vR = normalize(V-dotVN*N);	float g = max (0, dot(vI, vR));	vec3 elle = Md*clamp(dotLN, 0.0f, 1.0f);	vec3 fDiffuseON = elle*(a+b*g*sin(alpha)*tan(beta));		//return vec3(1,0,0);	return fDiffuseON;}void main() {	vec3 Norm = normalize(fragNorm);	vec3 EyeDir = normalize(gubo.eyePos - fragPos);		vec3 lightDir = gubo.lightDir;	vec3 lightColor = gubo.lightColor.rgb;	vec3 DiffSpec = BRDF(EyeDir, Norm, lightDir, texture(tex, fragUV).rgb, 1.1f);	vec3 Ambient = texture(tex, fragUV).rgb * 0.05f;		outColor = vec4(clamp(0.95 * (DiffSpec) * lightColor.rgb + Ambient,0.0,1.0), 1.0f);}