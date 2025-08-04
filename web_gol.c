#include <raylib.h>
#include <math.h>
// Window dimentions
#define HEIGHT 900
#define WIDTH 1600
// Game of life grid dimentions
#define GRID_HEIGHT 500
#define GRID_WIDTH 500
// World borders color rgbw
#define BORDER_COLOR 1.f, 0.0f, 0.0f, 1.0f
// two grids to contains cells stats in the current and next generation
int grid[GRID_HEIGHT][GRID_WIDTH] ={0};
int grid2[GRID_HEIGHT][GRID_WIDTH]={0};
// live cells locations, buffer's data for redering
float live[GRID_HEIGHT*GRID_WIDTH][2];
/*
 * @activeGrid : actual generation grid
 * @swapGrid : the next generation grid
 */
int (*activeGrid)[GRID_HEIGHT][GRID_WIDTH] = &grid;
int (*swapGrid)[GRID_HEIGHT][GRID_WIDTH]= &grid2;
unsigned int liveCounter =0; // actual population
// initialze the grid with random stat
void generateRandomGrid(int grid[GRID_HEIGHT][GRID_WIDTH]);
// calculate the next generation and put the value in @swapGrid and new population in @liveCountNew (old without multi-thread)
void nextGeneration(int grid[GRID_HEIGHT][GRID_WIDTH]);
// Reset the @activeGrid to all dead cells
void resetGrid(int grid[GRID_HEIGHT][GRID_WIDTH]);
//
int emod(int a, int b);
//
void RenderGrid(int grid[GRID_HEIGHT][GRID_WIDTH]);
//
const Color CELL_COLOR = RAYWHITE;
int main(){
    InitWindow(WIDTH,HEIGHT,"Game Of Life");
    SetRandomSeed(GetTime()*__INT_FAST32_MAX__);
    SetRandomSeed(GetRandomValue(0,__INT_FAST32_MAX__));
    SetTargetFPS(60);
    generateRandomGrid(*activeGrid);
    Camera2D camera={0} ;
    camera.zoom = 10;
    camera.offset =(Vector2) {(float)WIDTH/2,(float)HEIGHT/2};
    camera.target =(Vector2) {(float)(GRID_WIDTH/2),(float)(GRID_HEIGHT/2)};
    float cameraVelocity = GRID_WIDTH / 100;
    float updateTimer = 0.0f;
    while(!WindowShouldClose()){
        updateTimer+=GetFrameTime();
        if (IsKeyPressed(KEY_R)) {
            resetGrid(*activeGrid);
            generateRandomGrid(*activeGrid);
        }
        if (updateTimer>=0.1f){
            updateTimer=0;
            nextGeneration(*activeGrid);
        }
        // camera Movement controls
        if (IsKeyDown(KEY_A)) camera.target.x -=cameraVelocity;
        if (IsKeyDown(KEY_D)) camera.target.x+=cameraVelocity;
        if (camera.target.x > GRID_WIDTH) camera.target.x = GRID_WIDTH;
        if (camera.target.x < 0) camera.target.x =0;
        
        if (IsKeyDown(KEY_W)) camera.target.y -=cameraVelocity;
        if (IsKeyDown(KEY_S)) camera.target.y+=cameraVelocity;
        if (camera.target.y > GRID_HEIGHT) camera.target.y = GRID_HEIGHT;
        if (camera.target.y < 0) camera.target.y =0;
        // Camera zoom controls
        // Uses log scaling to provide consistent zoom speed
        camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove()*0.1f));
    
        if (camera.zoom > 10.0f) camera.zoom = 10.0f;
        else if (camera.zoom < 0.5f) camera.zoom = 0.5f;

        BeginDrawing();
        ClearBackground(BLACK);
            BeginMode2D(camera);
            RenderGrid(*activeGrid);
            DrawRectangleLines( 0, 0, GRID_WIDTH, GRID_HEIGHT, BLUE);
            EndMode2D();

            DrawRectangle(0, 0, WIDTH, 5, RED);
            DrawRectangle(0, 5, 5, HEIGHT - 10, RED);
            DrawRectangle(WIDTH - 5, 5, 5, HEIGHT - 10, RED);
            DrawRectangle(0, HEIGHT - 5, WIDTH, 5, RED);

            DrawRectangle( 10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines( 10, 10, 250, 113, BLUE);

            DrawText("Game controls:", 20, 20, 10, BLACK);
            DrawText("- WASD to move Camera", 40, 40, 10, CELL_COLOR);
            DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, CELL_COLOR);
            DrawText("- R to rest the grid", 40, 80, 10, CELL_COLOR);
        EndDrawing();
    }

    CloseWindow();
    return 0x10;
}


void generateRandomGrid(int grid[GRID_HEIGHT][GRID_WIDTH])
{

    int factor=2;
    int startX = (GRID_WIDTH / factor) - (GRID_WIDTH /(factor*2));
    int starty = (GRID_HEIGHT / factor) - (GRID_HEIGHT /(factor*2));

    for (int i=starty; i <starty+ GRID_HEIGHT/factor; i++)
    {
        for (int j=startX; j <startX + GRID_WIDTH/factor; j++)
        {
            int k = GetRandomValue(0,1);
            grid[i][j] = k;
            if (k) liveCounter++;
        }
    }
}
void nextGeneration(int grid[GRID_HEIGHT][GRID_WIDTH])
{
    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            int liveNeighbours = 0;
            for (int k = i-1; k <= i+1; k++)
            {
                for (int l = j-1; l <= j+1; l++)
                {
                    int ck = emod(k,GRID_HEIGHT);
                    int cl = emod(l,GRID_WIDTH);
                    if (k==i && l==j) continue;
                    if (grid[ck][cl]==1) liveNeighbours++;
                }
            }
            if (grid[i][j] && (liveNeighbours<2 || liveNeighbours>3)){
                (*swapGrid)[i][j] = 0;
                liveCounter--;
            }
            else if (!grid[i][j] && liveNeighbours==3){
                (*swapGrid)[i][j] = 1;
                liveCounter++;
            }
            else (*swapGrid)[i][j] = grid[i][j];
        }

    }
    int (*tem)[GRID_HEIGHT][GRID_WIDTH] = swapGrid;
    swapGrid = activeGrid;
    activeGrid = tem;

}
void resetGrid(int grid[GRID_HEIGHT][GRID_WIDTH])
{
    liveCounter =0;
    for (int i=0; i < GRID_HEIGHT; i++)
    {
        for (int j=0; j < GRID_WIDTH; j++)
        {
            grid[i][j] = 0;
        }
    }
}
int emod(int a, int b)
{
    return ((a%b)+b)%b;
}

void RenderGrid(int grid[GRID_HEIGHT][GRID_WIDTH])
{
    int count =0;
    int stop=0;
    for(int i=0;i<GRID_HEIGHT && !stop;i++){
        for (int j=0;j<GRID_WIDTH && !stop;j++){
            if (grid[i][j]){
                DrawRectangle(j,i,1,1,CELL_COLOR);
            }
            if (count==liveCounter) stop=1;
        }
    }
}