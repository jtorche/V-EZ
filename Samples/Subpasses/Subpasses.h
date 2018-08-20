//
// Copyright (c) 2018 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#pragma once

#include <array>
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../Common/AppBase.h"
#include "../Common/Model.h"

typedef struct PipelineDesc
{
    VezPipeline pipeline = VK_NULL_HANDLE;
    std::vector<VkShaderModule> shaderModules;
} PipelineDesc;

class Subpasses : public AppBase
{
public:
    Subpasses();

protected:
    void Initialize() final;
    void Cleanup() final;
    void Draw() final;
    void OnResize(int width, int height) final;
    void Update(float timeElapsed) final;

private:    
    void CreateQuad();
    void CreateTexture();
    void CreateSampler();
    void CreateUniformBuffer();
    void CreateFramebuffer();
    void CreatePipeline();
    void CreateCommandBuffer();

    VkQueue m_graphicsQueue = VK_NULL_HANDLE;
    VkBuffer m_vertexBuffer = VK_NULL_HANDLE;
    VkBuffer m_indexBuffer = VK_NULL_HANDLE;
    VkImage m_image = VK_NULL_HANDLE;
    VkImageView m_imageView = VK_NULL_HANDLE;
    VkSampler m_sampler = VK_NULL_HANDLE;
    VkBuffer m_uniformBuffer = VK_NULL_HANDLE;
    PipelineDesc m_subPass0Pipeline;
    PipelineDesc m_subPass1Pipeline;
    VezCommandBuffer m_commandBuffer = VK_NULL_HANDLE;

    struct FramebufferAttachment {
        VkImage image;
        VkImageView imageView;
    };
    
    struct {
        std::array<FramebufferAttachment, 5> attachments;
        VezFramebuffer handle = VK_NULL_HANDLE;
    } m_framebuffer;
};