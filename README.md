# CPP_CellularAutomata_pt2_AxialRiver
  Using the part one file dump of my cellular automata as a framework, I built a hexagonal grid in which simulates the game of life of cells with added rulesets. This one is quite buggy and still am building it currently but it was at a cool buggy state where it's giving some interesting patterns from a unintentional bug in finding neighbors of offsetted grid columns. It gives off waves as well as shooting cells which glide across the screen with a sin wave function giving some flow to the movements. I will be only uploading the .cpp and .h files used and not frameworks as that can be found in https://github.com/Kingerthanu/CPP_CellularAutomata_stage1.
  This quick little gizmo has taught me a lot about unique ways of drawing meshes without just triangles like GL_TRIANGLE_FAN. It also made me realize how I can optimize buffer handles in order to not need to use "cost benefits" like GL_TRIANGLE_FAN if I internionally add indexes and vertices in a correct way.
