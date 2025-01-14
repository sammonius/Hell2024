#pragma once
#include "../common.h"
#include "../Physics/Physics.h"
#include "../Renderer/RendererCommon.h"

class Window {

public:

	glm::vec3 position = glm::vec3(0);
	glm::vec3 rotation = glm::vec3(0);

	PxRigidStatic* raycastBody = NULL;
	PxShape* raycastShape = NULL;
	//PxRigidStatic* raycastBodyTop = NULL;
	//PxShape* raycastShapeTop = NULL;

	Window();
	glm::mat4 GetModelMatrix();
	void CleanUp();
	void CreatePhysicsObjects();

	glm::vec3 GetFrontLeftCorner();
	glm::vec3 GetFrontRightCorner();
	glm::vec3 GetBackLeftCorner();
	glm::vec3 GetBackRightCorner();

    glm::vec3 GetWorldSpaceCenter();

    void UpdateRenderItems();
    std::vector<RenderItem3D>& GetRenderItems();
private:
    std::vector<RenderItem3D> renderItems;
};