# CPP_CellularAutomata_pt2_AxialRiver
  Using the part one file dump of my cellular automata as a framework, I built a hexagonal grid in which simulates the game of life of cells with added rulesets. This one is quite buggy and still am building it currently but it was at a cool buggy state where it's giving some interesting patterns from a unintentional bug in finding neighbors of offsetted grid columns. It gives off waves as well as shooting cells which glide across the screen with a sin wave function giving some flow to the movements. Some instances create in likeness rivers with waterfalls and will show cycles push forward the cycle to give off a sense of movement and transfer of energy between cells. One very interesting pattern that can arise is the "filling bin" in which a cycle will start from one spot, and climb upwards either repeating in a loop, or causing some semblence of a kill switch as all cells break their stable states and die off. Also because we check 2 neighbors for birth, we can get interesting singapating rythms in which cycle from one side to another. The changing color is from a random time check I have in there to swap colors for debug.
  
  <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/06504ebf-457c-4eee-83f4-7d46ca08435d" alt="Cornstarch <3" width="95" height="99">

  I will be only uploading the .cpp and .h files used and not frameworks as that can be found in https://github.com/Kingerthanu/CPP_CellularAutomata_stage1.
  This quick little gizmo has taught me a lot about unique ways of drawing meshes without just triangles like GL_TRIANGLE_FAN. It also made me realize how I can optimize buffer handles in order to not need to use "cost benefits" like GL_TRIANGLE_FAN if I internionally add indexes and vertices in a methodical way.

----------------------------------------------
<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/892d7fb4-c8e9-4d49-995a-8bdd83132522" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/892d7fb4-c8e9-4d49-995a-8bdd83132522" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/892d7fb4-c8e9-4d49-995a-8bdd83132522" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/892d7fb4-c8e9-4d49-995a-8bdd83132522" alt="Cornstarch <3" width="55" height="49">

**The Breakdown:**

  This C++ Program Works With GLSL And OpenGL In Order To Make A Drawable Hexagonally-Formatted Window To Simulate Conways Game Of Life.

  This Program Starts By Dividing Our Screen Space Into Equally Sized Hexagons Specified By The User In A Constant Global Variable In Which Will Represent A Given Cell For Our Game Of Life. All Our Cells Will Be Loaded Into A 2D Array In Which Will Hold Our Current World Map We Are Working With Which Will Help In Simulating The Game Of Life As We Need Neighbors Of Given Cells For Proper Functionality.

  Our Hexagons Of Our Screen Will Be All Loaded Into A Single Buffer, So Instead Of Each Hexagon Holding Its Direct Vertexes, We Will Hold Our Offset In Our Windows Hexagon Buffer And Read Only Four Of These Vertexes As These Should Be Our Associated Cells Vertexes So We Can Swap Its Color/State Without Direct References On Where TO Access.

  Each Cell Instance Will Hold Its Alive State As Well And This Will Be Used In Its Main Loop Called React Function In Which Will Look Around Itself In A Given, Passed 2D Cell Map And Based Upon Its Alive Cell Neighbors Will React Accordingly. In This Iteration, The Current React Function Works With Sine Waves Of Our Given Time Stamp Of The React Check To Check:
  &nbsp;- If We Are Dead and Based Upon A Probability Of 0.5%, If We Have Less Than Or Equal To 2 Amount Of Alive Neighbors Turn On. 
  &nbsp;- Else, Die

  While This Isn't That Visuaully Nuanced, This Project Helped Me Initially Prod Into The Cellular Automata Concept And See Exactly How We Can Simulate Behaivor From These Simple Two States. This Project Also Greatly Helped Me With Buffer Management/Understanding.

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/fe802363-9cce-4df8-80ea-d4f0c7140293" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/fe802363-9cce-4df8-80ea-d4f0c7140293" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/fe802363-9cce-4df8-80ea-d4f0c7140293" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/fe802363-9cce-4df8-80ea-d4f0c7140293" alt="Cornstarch <3" width="55" height="49">


----------------------------------------------

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/9f1db116-a786-4628-9f1d-5193b281e72b" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/9f1db116-a786-4628-9f1d-5193b281e72b" alt="Cornstarch <3" width="55" height="49">
 <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/9f1db116-a786-4628-9f1d-5193b281e72b" alt="Cornstarch <3" width="55" height="49">
 <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/9f1db116-a786-4628-9f1d-5193b281e72b" alt="Cornstarch <3" width="55" height="49">





**Features:**


**Marching Cells and swap cycle:**

![trimmed-ezgif com-optimize](https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/9668057b-d5e3-430d-ba08-994e855125bb)

**Filling Bin Pattern:**

![2024-01-1817-44-18-ezgif com-optimize](https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/2d10834f-9ec3-4bf4-b50b-b609c20bd698)

<img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/57f55e0a-6453-4424-b0a8-c55160963205" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/57f55e0a-6453-4424-b0a8-c55160963205" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/57f55e0a-6453-4424-b0a8-c55160963205" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_CellularAutomata_pt2_AxialRiver/assets/76754592/57f55e0a-6453-4424-b0a8-c55160963205" alt="Cornstarch <3" width="55" height="49">
