/******************************************************************************
 * Copyright (c) 2024 [Jason Parkinson-Brooke Pacheco]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 *****************************************************************************/

#include "../AppMainGui.h"

AppMainGui::AppMainGui(int width, int height, const std::string& title)
    : screenWidth(width), screenHeight(height), windowTitle(title), window(nullptr) {}

AppMainGui::~AppMainGui() {
    cleanup();
}

// Initialize the application
bool AppMainGui::initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    window = glfwCreateWindow(screenWidth, screenHeight, windowTitle.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    return true;
}

// Main loop
void AppMainGui::run() {
    if (!window) {
        std::cerr << "Window is not initialized. Call initialize() first." << std::endl;
        return;
    }

    while (!glfwWindowShouldClose(window)) {
        processInput();
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

// Handle input
void AppMainGui::processInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

// Render the scene
void AppMainGui::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Set background color
}

// Clean up resources
void AppMainGui::cleanup() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}
