#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <cstdio>

int main(int argc, const char** argv)
{
	if (!glfwInit()) {
		printf("Failed to initialize glfw.r\r\n");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "PGJ1303", NULL, NULL);
	if (!window) {
		printf("Failed to create window.\r\n");
		return -1;
	}

	glfwMakeContextCurrent(window);

	int version = gladLoadGL(glfwGetProcAddress);
	if (version == 0) {
		printf("Failed to initialize OpenGL context\n");
		return -1;
	}

	// MAIN LOOP -----
	while (!glfwWindowShouldClose(window))
	{
		int width, height; glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
