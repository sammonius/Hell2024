#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Types/vk_allocation.hpp"
#include "Types/vk_frameData.hpp"
#include "../../Common.h"
#include "../../Types/Mesh.hpp"
#include "../../Renderer/RendererCommon.h"

namespace VulkanBackEnd {
    
    void CreateVulkanInstance();

    void InitMinimum();
    bool StillLoading();
    void LoadNextItem();
    void ImmediateSubmit(std::function<void(VkCommandBuffer cmd)>&& function);
    void MarkFrameBufferAsResized();
    void HandleFrameBufferResized();

    void SetGLFWSurface();
    void SelectPhysicalDevice();
    void CreateSwapchain();
    void CreateCommandBuffers();
    void CreateSyncStructures();
    void CreateSampler();

    void UploadVertexData(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);

    void AddDebugName(VkBuffer buffer, const char* name);
    void AddDebugName(VkDescriptorSetLayout descriptorSetLayout, const char* name);

    void PrepareSwapchainForPresent(VkCommandBuffer commandBuffer, uint32_t swapchainImageIndex);
    void RecreateDynamicSwapchain();
    bool FrameBufferWasResized();

    VkDevice GetDevice();
    VkSurfaceKHR GetSurface();
    VkSwapchainKHR GetSwapchain();
    int32_t GetFrameIndex();
    VkQueue GetGraphicsQueue();
    FrameData& GetCurrentFrame(); 
    VmaAllocator GetAllocator();
    VkDescriptorPool GetDescriptorPool();
    VkSampler GetSampler(); 
    std::vector<VkImage>& GetSwapchainImages();

    inline AllocatedBuffer _mainVertexBuffer;
    inline AllocatedBuffer _mainIndexBuffer;

    // Raytracing
    void InitRayTracing();
    void CreateAccelerationStructureBuffer(AccelerationStructure& accelerationStructure, VkAccelerationStructureBuildSizesInfoKHR buildSizeInfo);
    uint64_t GetBufferDeviceAddress(VkBuffer buffer);
    AccelerationStructure CreateBottomLevelAccelerationStructure(Mesh& mesh);
    void CreateTopLevelAccelerationStructure(std::vector<VkAccelerationStructureInstanceKHR> instances, AccelerationStructure& outTLAS);
    std::vector<VkAccelerationStructureInstanceKHR> CreateTLASInstancesFromRenderItems(std::vector<RenderItem3D>& renderItems);

};
