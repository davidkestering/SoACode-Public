///
/// PhysicsBlockRenderStage.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 9 Nov 2014
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// This file implements the physics block rendering,
///

#pragma once

#ifndef PhysicsBlockRenderStage_h__
#define PhysicsBlockRenderStage_h__

#include "IRenderStage.h"
#include "GLProgram.h"

class GameRenderParams;
class PhysicsBlockMesh;

class PhysicsBlockRenderStage : public vg::IRenderStage {
public:
    /// Construcst the stage and injects dependencies
    /// @param gameRenderParams: Some shared parameters
    /// @param physicsBlockMeshes: Handle to the list of meshes to render
    /// @param glProgram: The program used to draw physics blocks
    PhysicsBlockRenderStage(GameRenderParams* gameRenderParams, 
                            const std::vector<PhysicsBlockMesh*>& physicsBlockMeshes,
                            vg::GLProgram* glProgram);

    // Draws the render stage
    virtual void draw() override;

private:
    vg::GLProgram* _glProgram; ///< Shader program that renders the voxels
    GameRenderParams* _gameRenderParams; ///< Some shared voxel rendering params
    const std::vector<PhysicsBlockMesh*>& _physicsBlockMeshes; ///< The meshes to render
};


#endif // PhysicsBlockRenderStage_h__