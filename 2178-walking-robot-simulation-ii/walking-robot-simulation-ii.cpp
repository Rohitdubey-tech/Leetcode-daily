class Robot {
public:
    int max_x;
    int max_y;
    int x;
    int y;
    string currDir;

    Robot(int width, int height) {
        max_x = width - 1;
        max_y = height - 1;
        x = 0;
        y = 0;
        currDir = "East";
    }

    void step(int num) {
        int perimeter = 2 * (max_x + max_y);
        num = num % perimeter;

        if (num == 0 && (x != 0 || y != 0)) return;
        if (num == 0 && x == 0 && y == 0) {
            currDir = "South";
            return;
        }

        while (num > 0) {
            if (currDir == "East") {
                int canMove = min(num, max_x - x);
                x += canMove;
                num -= canMove;
                if (num > 0) currDir = "North";
            } else if (currDir == "North") {
                int canMove = min(num, max_y - y);
                y += canMove;
                num -= canMove;
                if (num > 0) currDir = "West";
            } else if (currDir == "West") {
                int canMove = min(num, x);
                x -= canMove;
                num -= canMove;
                if (num > 0) currDir = "South";
            } else {
                int canMove = min(num, y);
                y -= canMove;
                num -= canMove;
                if (num > 0) currDir = "East";
            }
        }
    }

    vector<int> getPos() { return {x, y}; }
    string getDir() { return currDir; }
};
/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */