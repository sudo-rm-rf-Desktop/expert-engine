# There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

# The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

# The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

# Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix:
            return []
        
        p_visited = set()
        a_visited = set()
        m,n = len(matrix), len(matrix[0])
        directions = ((0,1),(1,0),(0,-1),(-1,0))
        
        def traverse(i,j,visited):
            if (i,j) in visited:
                return
            visited.add((i,j))
            
            for direction in directions:
                next_i, next_j = i+direction[0], j+direction[1]
                if 0<=next_i<m and 0<=next_j<n:
                    if matrix[next_i][next_j]>=matrix[i][j]:
                        traverse(next_i,next_j,visited)
                    
        for row in range(m):
            traverse(row,0,p_visited)
            traverse(row,n-1,a_visited)
            
        for col in range(n):
            traverse(0,col,p_visited)
            traverse(m-1,col,a_visited)
        
        ans = set()
        for item in p_visited:
            if item in a_visited:
                ans.add(item)
            
        return list(ans)