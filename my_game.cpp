#include <bits/stdc++.h>
using namespace std;
int score = 0;
void moveup(vector<vector<int>>& grid) {
    for(int col=0;col<4;col++){
        for(int row = 0;row<4;row++){
            if(grid[row][col] == 0){
                for(int k = row+1;k<4;k++){
                    if(grid[k][col] >0){
                        grid[row][col] = grid[k][col];
                        grid[k][col] =0;
                        break;
                    }
                }
            }
        }
    }
}

void moveleft(vector<vector<int>>& grid) {
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            if(grid[row][col] == 0){
                for(int k=col+1;k<4;k++){
                    if(grid[row][k] > 0){
                        grid[row][col] = grid[row][k];
                        grid[row][k] =0;
                        break;
                    }
                }
            }
        }
    }
}

void movedown(vector<vector<int>>& grid) {
    for(int col=0;col<4;col++){
        for(int row = 3;row>0;row--){
            if(grid[row][col] == 0){
                for(int k=row-1;k>=0;k--){
                    if(grid[k][col] > 0){
                        grid[row][col] = grid[k][col];
                        grid[k][col]  =0;
                        break;
                    }
                }
            }
        }
    }
}

void moveright(vector<vector<int>>& grid) {
    for(int row=0;row<4;row++){
        for(int col=3;col>0;col--){
            if(grid[row][col] == 0){
                for(int k=col-1;k>=0;k--){
                    if(grid[row][k] > 0){
                        grid[row][col] = grid[row][k];
                        grid[row][k] =0;
                        break;
                    }
                }
            }
        }
    }
}
void sumup(vector<vector<int>>& grid) {
    for(int col=0;col<4;col++){
        for(int row =0;row<3;row++){
            if(grid[row][col] && grid[row][col] == grid[row+1][col]){
                grid[row][col] +=grid[row+1][col];
                grid[row+1][col] =0;
                score+=grid[row][col];
            }
        }
    }
}
void sumdown(vector<vector<int>>& grid){
    for(int col =0;col<4;col++){
        for(int row=3;row>0;row--){
            if(grid[row][col] && grid[row][col] == grid[row-1][col]){
                grid[row][col] +=grid[row-1][col];
                grid[row-1][col] = 0;
                score+=grid[row][col]; 
            }
        }
    }
}
void sumleft(vector<vector<int>>& grid){
    for(int row=0;row<4;row++){
        for(int col =0;col<3;col++){
            if(grid[row][col] && grid[row][col] == grid[row][col+1]){
                grid[row][col]+=grid[row][col+1];
                grid[row][col+1] =0;
                score+=grid[row][col];
            }
        }
    }
}
void sumright(vector<vector<int>>& grid){
    for(int row=0;row<4;row++){
        for(int col=3;col>0;col--){
            if(grid[row][col] && grid[row][col] == grid[row][col-1]){
                grid[row][col] += grid[row][col-1];
                grid[row][col-1] =0;
                score+=grid[row][col]; 
            }
        }
    }
}
int generaterandom2(int nofzeros,vector<vector<int>> &grid)
{
    srand(time(NULL));
    int randomIndex = rand() % nofzeros + 1;
    int randomnum = rand() % 2 + 1;
    int count = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (grid[i][j] == 0)
            {
                count++;
                if (count == randomIndex)
                {
                    if(randomnum == 1){
                        grid[i][j] = 2; // Place the 2 at the chosen zero position
                        break;
                    }
                    else{
                        grid[i][j] = 4; // Place the 4 at the chosen zero position
                        break;
                    }
                }
            }
        }
        if (count == randomIndex)
        {
            break; // Exit once the 2 is placed
        }
    }
}
void printgrid(const vector<vector<int>>& grid) {
    cout << "score: " << score << endl;
    cout << "__________________________" << endl;

    for (const auto& row : grid) {
        cout << "|";
        for (int num : row) {
            // Print each number with padding for alignment
            cout << "  " << num << "  |";
        }
        cout << endl;
        cout << "__________________________" << endl;
    }
}
int countnoofzeros(vector<vector<int>> &grid){
    int cnt =0;
    for(int i =0;i<=3;i++){
        for(int j=0;j<=3;j++){
            if(grid[i][j] == 0){
                cnt++;
            }
        }
    }
    return cnt;
}
int search2048(vector<vector<int>> &grid){
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            if(grid[i][j] == 2048){
                return 1;
            }
        }
    }
    return 0;
}
int game_ends(vector<vector<int>> &grid){
    int flag=1;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j] == grid[i][j+1]){
                flag =0;
                break;
            }
        }
    }
    if(flag == 1){
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                if(grid[i][j] == grid[i+1][j]){
                    flag = 0;
                    break;
                }
            }
        }
    }
    return flag;
}
void lose_display(){
	cout<<"\t\t\tGAME OVER\n\n";
	cout<<"Your final score is "<<score<<"\n\n";
	cout<<"Good try!!!\n\n";
}
int main() {
    cout << "\n\t\t\t\t\t\t\t 2048 GAME started\n\n";
    bool running = true;
    vector<vector<int>> grid(4, vector<int>(4, 0));
    bool quit = false;
    while (running) {
        // cout << "score: " << score << endl;

        if (search2048(grid)) {
            cout << "2048 found! You won the game!" << endl;
            running = false;
            continue;  // Exit the loop as the game is won
        }
        if(quit){
            cout<<"you quitted the game "<<endl;
            break;
        }

        if (countnoofzeros(grid) > 0) {
            generaterandom2(countnoofzeros(grid), grid);
            printgrid(grid);
            char movement;
            bool validMove = false;
            while (!validMove) {
                cout << "Select 'a' for left, 'w' for up, 'd' for right, 's' for down" << endl;
                cin >> movement;
                switch (movement) {
                    case 'w':
                        moveup(grid);
                        sumup(grid);
                        moveup(grid);
                        validMove = true;
                        break;
                    case 'a':
                        moveleft(grid);
                        sumleft(grid);
                        moveleft(grid);
                        validMove = true;
                        break;
                    case 's':
                        movedown(grid);
                        sumdown(grid);
                        movedown(grid);
                        validMove = true;
                        break;
                    case 'd':
                        moveright(grid);
                        sumright(grid);
                        moveright(grid);
                        validMove = true;
                        break;
                    case 'q':
                        quit = true;
                        validMove = true;
                        break;
                    default:
                        cout << "Invalid movement! Please select 'a', 'w', 'd', or 's'." << endl;
                        break;
                }
            }
        } else {
            if (game_ends(grid)) {
                lose_display();
                running = false;
            }
        }
    }
    return 0;
}