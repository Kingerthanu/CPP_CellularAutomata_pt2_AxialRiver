#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>

#include "shader.h"
#include "Vertex_Array.h"
#include "Element_Buffer.h"
#include <glm/glm.hpp>
#include <random>
#include "cell_2.h"

const unsigned int WINDOW_WIDTH = 1800;
const unsigned int WINDOW_HEIGHT = 1800;


  

int main()
{

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::vector<Vertex>* vertices = new std::vector<Vertex>;
	std::vector<GLuint>* indices = new std::vector<GLuint>;


	unsigned int MAX_CELLS = 100;

	Cell_Gen2*** CELL_GRID = new Cell_Gen2 **[MAX_CELLS * 2.330f];

	float width = 1.0f;



	float centerX;
	float centerY;
	float hexRadius = 0.01f;

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> indexColor = std::uniform_real_distribution<float>(0.00f, 1.00f);

	
	for (int i = 0; i < MAX_CELLS*2.325f; ++i) {

		CELL_GRID[i] = new Cell_Gen2*[MAX_CELLS / 1.535f];

		for (int j = 0; j < MAX_CELLS/1.535f; ++j) {

			centerX = (3.0f * hexRadius * j + ((i % 2 == 0) ? 0.0f : 1.5f * hexRadius) - (0.9925 - hexRadius)); // Adjust the x-coordinate for column offset
			centerY = (0.995f - hexRadius) - (0.85f * hexRadius * i);  // Adjust the y-coordinate for stacking
			
			float color = indexColor(gen);
			float color2 = indexColor(gen);

			bool flag = false;

			for (int in = 0; in < 6; ++in) {

				float angle = 2.0f * 3.14159265358979323846f * in / 6.0f;
				vertices->push_back(Vertex{ glm::vec3(centerX + hexRadius * std::cos(angle), centerY + hexRadius * std::sin(angle), 1.0f), glm::vec3(0.0f, 0.0f, 0.0f)});
				
			}

			CELL_GRID[i][j] = new Cell_Gen2(vertices->size()+6);

			indices->push_back(vertices->size() - 5);
			indices->push_back(vertices->size() - 6);
			indices->push_back(vertices->size() - 1);

			indices->push_back(vertices->size() - 1);
			indices->push_back(vertices->size() - 2);
			indices->push_back(vertices->size() - 5);

			indices->push_back(vertices->size() - 2);
			indices->push_back(vertices->size() - 3);
			indices->push_back(vertices->size() - 4);

			indices->push_back(vertices->size() - 4);
			indices->push_back(vertices->size() - 5);
			indices->push_back(vertices->size() - 2);



		}
	}




	

	for (unsigned int i = 0; i < MAX_CELLS * 2.325f; i++) {

		for (unsigned int j = 0; j < MAX_CELLS / 1.535f; j++) {

			CELL_GRID[i][j]->grabNeighbors(CELL_GRID, (MAX_CELLS * 2.325f), (MAX_CELLS / 1.55f), i, j);

		}
	}
	

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Cell Division", NULL, NULL);

	if (!window) {

		glfwTerminate();
		return 0;

	}
	
	glfwMakeContextCurrent(window);


	gladLoadGL();

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	
	Shader shaderProg("default.vert", "default.frag");


	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(*vertices);
	EBO EBO1(*indices);

	const unsigned int blockAmount = indices->size();

	delete vertices;
	delete indices;

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));

	VAO1.unBind();
	VBO1.unBind();
	EBO1.unBind();

	VAO1.Bind();
	VBO1.Bind();

	std::uniform_int_distribution<int> indexRandomX = std::uniform_int_distribution<int>(0, 40);
	std::uniform_int_distribution<int> indexRandomY = std::uniform_int_distribution<int>(0, 60);

	for (int i = 0; i < 500; i++) {

			CELL_GRID[indexRandomX(gen)][indexRandomY(gen)]->spark();
			CELL_GRID[indexRandomX(gen)][indexRandomY(gen)]->turnOn();

	}

	shaderProg.Activate();

	std::chrono::duration<double> frameDuration(1.0 / 25);

	while (!glfwWindowShouldClose(window)) {

		auto start = std::chrono::high_resolution_clock::now();


		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

		for (unsigned int i = 0; i < MAX_CELLS * 2.325f; i++) {

			for (unsigned int j = 0; j < MAX_CELLS / 1.535f; j++) {

				CELL_GRID[i][j]->think();

			}
		}

		glDrawElements(GL_TRIANGLES, blockAmount, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();

		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

		// Sleep to maintain the desired frame rate
		std::this_thread::sleep_for(frameDuration - elapsed);

	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProg.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

}


