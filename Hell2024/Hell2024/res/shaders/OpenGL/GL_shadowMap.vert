#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 5) in ivec4 aBoneID;
layout (location = 6) in vec4 aBoneWeight;

struct RenderItem3D {
    mat4 modelMatrix;
    int meshIndex;
    int baseColorTextureIndex;
    int normalTextureIndex;
    int rmaTextureIndex;
    int vertexOffset;
    int indexOffset;
    int padding0;
    int padding1;
};

layout(std430, binding = 1) readonly buffer renderItems {
    RenderItem3D RenderItems[];
};

uniform bool isAnimated;
uniform mat4 skinningMats[64];

out vec3 FragPos;

void main()
{
	mat4 model = RenderItems[gl_DrawID].modelMatrix;

	vec4 worldPos;
	vec4 totalLocalPos = vec4(0.0);
	
	vec4 vertexPosition =  vec4(aPos, 1.0);

	// Animated
	if (isAnimated)
	{
		for(int i=0;i<4;i++) 
		{
			mat4 jointTransform = skinningMats[int(aBoneID[i])];
			vec4 posePosition =  jointTransform  * vertexPosition * aBoneWeight[i];

			totalLocalPos += posePosition;	
		}
		worldPos = model * totalLocalPos;
				gl_Position = worldPos;
	}
	else // Not animated
	{
		worldPos = model * vec4(aPos, 1.0);
		gl_Position = worldPos;
	}
	

}