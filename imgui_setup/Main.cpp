

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>








int main() {


	//GLFWwindow* window = glfwCreateWindow(600, 600, "Test",NULL,NULL);
	//glfwMakeContextCurrent(window);
	//if(glfwInit())



	glfwInit();

	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (window)
		std::cout << "OK" << std::endl;
	else
		std::cout << "FAIL" << std::endl;


	glfwMakeContextCurrent(window);



	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	//ImGui_ImplGlfw_InitForOpenGL(window, true);

	//Imgui_ImplGlfw_InitForOpenGl(window, true);

	//(void)io;








	return 0;
}