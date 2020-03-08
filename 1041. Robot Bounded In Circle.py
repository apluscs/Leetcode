class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x, y, dx, dy = 0,0,0,1  # initial pos and direction
        for inst in instructions:
            if inst == 'G':
                x += dx
                y += dy
            elif inst == 'L':
                temp = dx
                dx = -dy
                dy = temp
            else:   # turn to the right
                temp = dx
                dx = dy
                dy = -temp
        return x == 0 and y == 0 or dx != 0 or dy != 1  # position is the same or 
        # direction changed = you will return in 4 cycles
