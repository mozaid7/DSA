def solve():
    n, m = map(int, input().split())
    grid = [input().strip() for _ in range(n)]

    # Find all rods and cables
    rods = []
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'R':
                rods.append((i, j))

    # Determine if rod is horizontal or vertical
    # (Since rods span full row or full column)
    r_rows = set([r for r, c in rods])
    r_cols = set([c for r, c in rods])

    switches = 0

    # Case 1: Vertical rod
    if len(r_cols) == 1:
        col = list(r_cols)[0]
        pattern = []
        for i in range(n):
            if grid[i][col] in ['C', 'R']:
                pattern.append(grid[i][col])
        # Count alternations between C and R
        for i in range(1, len(pattern)):
            if pattern[i] != pattern[i - 1]:
                switches += 1

    # Case 2: Horizontal rod
    elif len(r_rows) == 1:
        row = list(r_rows)[0]
        pattern = []
        for j in range(m):
            if grid[row][j] in ['C', 'R']:
                pattern.append(grid[row][j])
        # Count alternations between C and R
        for i in range(1, len(pattern)):
            if pattern[i] != pattern[i - 1]:
                switches += 1

    # Divide by 2 because each wrap has two transitions (C→R→C)
    print(switches // 2)


if __name__ == "__main__":
    solve()
