#ifndef CELL_2_H
#define CELL_2_H

#include "Vertex.h"
#include <glad/glad.h>

class Cell_Gen2
{

private:
	bool state = false;
	int offset;
	char NEIGHBORS_SIZE = 0;

public:
	Cell_Gen2** NEIGHBORS = new Cell_Gen2*[0];


	Cell_Gen2(const int& blockOffset)
	{

		this->offset = blockOffset;

	};

	void addNeighbor(Cell_Gen2& newNeighbor)
	{

		Cell_Gen2** tmp = new Cell_Gen2 * [NEIGHBORS_SIZE + 1];

		for (int index = 0; index < this->NEIGHBORS_SIZE; index++) {

			tmp[index] = this->NEIGHBORS[index];

		}

		tmp[this->NEIGHBORS_SIZE++] = &newNeighbor;

		delete[] this->NEIGHBORS;

		this->NEIGHBORS = tmp;


	};

	

	void think()
	{

		char amntAlive = 0;

		std::time_t val = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

		for (char i = 0; i < this->NEIGHBORS_SIZE; i++) {

			if (this->NEIGHBORS[i]->state) {

				amntAlive++;

			}

		}

		// Use sine wave to modulate the probability of turning on
		float sineWave = std::sin(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() * 0.000001f);
		float probability = (sineWave + 1.0) * 0.25;  // Map sine wave [-1, 1] to [0, 1]

		if (!this->state && (amntAlive < 4 && amntAlive >= 2) && probability > 0.005) {
			this->state = true;
		}
		else {
			this->state = false;
		}

		this->turnOn();

	};

	void grabNeighbors(Cell_Gen2***& cells, const int& maxRow, const int& maxCol,  const int& row, const int& col)
	{

		if ((int)(row - 1) > -1) {

			if (col + 1 < maxCol) {

				this->addNeighbor(*cells[row - 1][col + 1]);

			}
			this->addNeighbor(*cells[row - 1][col]);

		}
		if (row + 1 <= maxRow) {

			if ((int)(col - 1) > -1) {

				this->addNeighbor(*cells[row + 1][col - 1]);

			}

			this->addNeighbor(*cells[row + 1][col]);

		}

		if (col + 1 <= maxCol) {

			this->addNeighbor(*cells[row][col + 1]);
		}
		if ((int)(col - 1) > -1) {

			this->addNeighbor(*cells[row][col - 1]);
		}

	};

	void spark()
	{

		this->state = true;

	};

	void turnOn()
	{

		Vertex* bufferData = static_cast<Vertex*>(glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE));

		if (this->state) {

			// Check if the mapping was successful
			if (bufferData != nullptr) {
				std::random_device rd;
				std::mt19937 gen(rd());

				std::uniform_real_distribution<float> indexColor = std::uniform_real_distribution<float>(0.00f, 1.00f);
				// Update all vertices in the buffer
				for (int i = this->offset, newOffset = this->offset + 6; i < newOffset; i++) {
					bufferData[i].color = glm::vec3(std::sin(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() * 0.0001f), indexColor(gen), std::sin(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() * 0.0000001f));
				}

				// Unmap the buffer to apply the changes
				glUnmapBuffer(GL_ARRAY_BUFFER);
			}
		}
		else {

			// Check if the mapping was successful
			if (bufferData != nullptr) {

				// Update all vertices in the buffer
				for (int i = this->offset, newOffset = this->offset + 6; i < newOffset; i++) {
					bufferData[i].color = glm::vec3(0.0f, 0.0f, 0.0f);
				}

				// Unmap the buffer to apply the changes
				glUnmapBuffer(GL_ARRAY_BUFFER);
			}

		}

	};

};

#endif
