# CPP_CellularAutomata_pt2_AxialRiver
  Using the part one file dump of my cellular automata as a framework, I built a hexagonal grid in which simulates the game of life of cells with added rulesets. This one is quite buggy and still am building it currently but it was at a cool buggy state where it's giving some interesting patterns from a unintentional bug in finding neighbors of offsetted grid columns. It gives off waves as well as shooting cells which glide across the screen with a sin wave function giving some flow to the movements. Some instances create in likeness rivers with waterfalls and will show cycles push forward the cycle to give off a sense of movement and transfer of energy between cells. One very interesting pattern that can arise is the "filling bin" in which a cycle will start from one spot, and climb upwards either repeating in a loop, or causing some semblence of a kill switch as all cells break their stable states and die off. Also because we check 2 neighbors for birth, we can get interesting singapating rythms in which cycle from one side to another. The changing color is from a random time check I have in there to swap colors for debug.
  
  <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/06504ebf-457c-4eee-83f4-7d46ca08435d" alt="Cornstarch <3" width="95" height="99">

  I will be only uploading the .cpp and .h files used and not frameworks as that can be found in https://github.com/Kingerthanu/CPP_CellularAutomata_stage1.
  This quick little gizmo has taught me a lot about unique ways of drawing meshes without just triangles like GL_TRIANGLE_FAN. It also made me realize how I can optimize buffer handles in order to not need to use "cost benefits" like GL_TRIANGLE_FAN if I internionally add indexes and vertices in a methodical way.

----------------------------------------------
<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/892d7fb4-c8e9-4d49-995a-8bdd83132522" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/892d7fb4-c8e9-4d49-995a-8bdd83132522" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/892d7fb4-c8e9-4d49-995a-8bdd83132522" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/892d7fb4-c8e9-4d49-995a-8bdd83132522" alt="Cornstarch <3" width="55" height="49">

**The Breakdown:**

  ------

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/fe802363-9cce-4df8-80ea-d4f0c7140293" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/fe802363-9cce-4df8-80ea-d4f0c7140293" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/fe802363-9cce-4df8-80ea-d4f0c7140293" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/fe802363-9cce-4df8-80ea-d4f0c7140293" alt="Cornstarch <3" width="55" height="49">


----------------------------------------------

<img src="https://github.com/Kingerthanu/CPP_FallingSand/assets/76754592/bc289d3f-ca9f-4372-a386-925798d5536e" alt="Cornstarch <3" width="55" height="49"><img src="https://github.com/Kingerthanu/CPP_FallingSand/assets/76754592/bc289d3f-ca9f-4372-a386-925798d5536e" alt="Cornstarch <3" width="55" height="49"><img src="https://github.com/Kingerthanu/CPP_FallingSand/assets/76754592/bc289d3f-ca9f-4372-a386-925798d5536e" alt="Cornstarch <3" width="55" height="49"><img src="https://github.com/Kingerthanu/CPP_FallingSand/assets/76754592/bc289d3f-ca9f-4372-a386-925798d5536e" alt="Cornstarch <3" width="55" height="49">



**Features:**


**Marching Cells and swap cycle:**

![trimmed-ezgif com-optimize](https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/9668057b-d5e3-430d-ba08-994e855125bb)

**Filling Bin Pattern:**

![2024-01-1817-44-18-ezgif com-optimize](https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/2d10834f-9ec3-4bf4-b50b-b609c20bd698)

