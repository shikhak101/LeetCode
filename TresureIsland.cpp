public class Main {
    
    public static int minSteps(char[][] grid) {
        queue<pair<int,int>> q;
        int steps = 0;
        if(grid.size()>0 && grid[0].size()>0) q.push(make_pair(0,0));
        else return -1;
        while(!q.empty()) {

        }
        return steps;
    }
    
    public static void main(String[] args) {
        char[][] grid = {{'O', 'O', 'O', 'O'},
                         {'D', 'O', 'D', 'O'},
                         {'O', 'O', 'O', 'O'},
                         {'X', 'D', 'D', 'O'}};
        cout<<(minSteps(grid));
    }
}

