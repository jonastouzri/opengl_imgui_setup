

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
//#include "imgui_internal.h"


#include "implot.h"



#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}





int main() {


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// ??


	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");


	

		//ImGui::ImPlotFlags p_flgs = ImPlotFlags_Legend | ImPlotFlags_AntiAliased;
		//ImAxisFlags x_flgs = ImAxisFlags_GridLines | ImAxisFlags_LogScale;
		//ImAxisFlags y_flgs = ImAxisFlags_GridLines | ImAxisFlags_TickLabels;

	ImPlot::CreateContext();


	while (!glfwWindowShouldClose(window)){


		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		ImGui::NewFrame();
		ImGui::Begin("window");
		ImGui::Text("hello");

		const float my_values[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
		ImGui::PlotLines("Frame Times", my_values, IM_ARRAYSIZE(my_values));

		//--------------------------------------------------------------------

		
		int   bar_data[3] = {0,1,2};
		float x_data[3] = {2,3,5};
		float y_data[3] = {7,4,5};

		ImGui::Begin("Plot");
		if (ImPlot::BeginPlot("My Plot")) {
			ImPlot::PlotBars("My Bar Plot", bar_data, 3);
			ImPlot::PlotLine("My Line Plot", x_data, y_data, 3);

		

				ImPlot::EndPlot();
		}
		ImGui::End();

		







		//----------------------------------------------------------


		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		


		glfwSwapBuffers(window);
		glfwPollEvents();




	}




	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();


	ImPlot::DestroyContext();
	ImGui::DestroyContext();

	glfwTerminate();






	//IMGUI_CHECKVERSION();
	//ImGui::CreateContext();
	//ImGuiIO& io = ImGui::GetIO();




	//(void)io;








	return 0;
}