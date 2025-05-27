#pragma once

#include <vector>
#include <memory>

#include <volk.h>

namespace VulkanRenderer
{
	class VulkanDevice;
	class VulkanSwapChain;
	class VulkanRenderPass;
	class Mesh;
	class Camera;
	class VulkanImGuiOverlay;

	class VulkanPipeline
	{
	public:
		VulkanPipeline(VulkanDevice* device, VulkanSwapChain* swapChain, VulkanRenderPass* renderPass);
		~VulkanPipeline();

		void SetImGuiOverlay(VulkanImGuiOverlay* overlay);

		void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex, uint32_t currentFrame, const std::vector<std::unique_ptr<Mesh>>& meshes, Camera* camera);

		VkDescriptorSetLayout GetCameraDescriptorSetLayout() const;
		VkDescriptorSetLayout GetMeshDescriptorSetLayout() const;

	private:
		void CreateCameraDescriptorSetLayout();
		void CreateMeshDescriptorSetLayout();
		void CreateGraphicsPipeline();

		VkPipeline pipeline;
		VkPipelineLayout pipelineLayout;

		VkDescriptorSetLayout cameraDescriptorSetLayout;
		VkDescriptorSetLayout meshDescriptorSetLayout;

		VulkanSwapChain* swapChain;
		VulkanRenderPass* renderPass;

		VulkanImGuiOverlay* imGuiOverlay;

		VulkanDevice* device;
	};
}