class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    def __repr__(self):
        return 'TreeNode({})'.format(self.val)
    
def deserialize(string, null = 'null'):
    if string == '{}':
        return None
    nodes = [None if val == null else TreeNode(int(val))
             for val in string.strip('[]{}').split(',')]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left  = kids.pop()
            if kids: node.right = kids.pop()
    return root

def drawtree(root):
    def height(root):
        return 1 + max(height(root.left), height(root.right)) if root else -1
    def jumpto(x, y):
        t.penup()
        t.goto(x, y)
        t.pendown()
    def draw(node, x, y, dx):
        if node:
            t.goto(x, y)
            jumpto(x, y-20)
            t.write(node.val, align='center', font=('Arial', 12, 'normal'))
            draw(node.left, x-dx, y-60, dx/2)
            jumpto(x, y-20)
            draw(node.right, x+dx, y-60, dx/2)
    import turtle
    t = turtle.Turtle()
    t.speed(0); turtle.delay(0)
    h = height(root)
    jumpto(0, 30*h)
    draw(root, 0, 30*h, 40*h)
    t.hideturtle()
    turtle.mainloop()
    
if __name__ == '__main__':

    # drawtree(deserialize(''))
    # drawtree(deserialize(''))
    # drawtree(deserialize(''))
    # drawtree(deserialize(''))
    # drawtree(deserialize(''))
    # drawtree(deserialize(''))
    drawtree(deserialize('{6,82,82,#,53,53,#,-58,#,#,-58,#,-85,-85,#,-9,#,#,-9,#,48,48,#,33,#,#,33,81,#,#,81,5,#,#,5,61,#,#,61,#,9,9,#,91,#,#,91,72,7,7,72,89,#,94,#,#,94,#,89,-27,#,-30,36,36,-30,#,-27,50,36,#,-80,34,#,#,34,-80,#,36,50,18,#,#,91,77,#,#,95,95,#,#,77,91,#,#,18,-19,65,#,94,#,-53,#,-29,-29,#,-53,#,94,#,65,-19,-62,-15,-35,#,#,-19,43,#,-21,#,#,-21,#,43,-19,#,#,-35,-15,-62,86,#,#,-70,#,19,#,55,-79,#,#,-96,-96,#,#,-79,55,#,19,#,-70,#,#,86,49,#,25,#,-19,#,#,8,30,#,82,-47,-47,82,#,30,8,#,#,-19,#,25,#,49}', null='#'))
    # drawtree(deserialize('{3,9,8,4,0,1,7,#,#,#,2,5,#,#,#,#,1,#,#,#,60}', null='#'))
    # drawtree(deserialize('{3,9,8,4,0,1,7}', null='#'))]
    # drawtree(deserialize('[5,4,8,11,null,13,4,7,2,null,null,null,1]'))
    # drawtree(deserialize('[1,2,3,2,2,3,null,null,null,2,null,null,null,1,null,1]'))
    # drawtree(deserialize('[0,-3,9,-10,null,5]'))
    # drawtree(deserialize('[5,null,14,10,77,null,null,null,95]'))
    # drawtree(deserialize('[5,null,14,10,77,null,null,null,95,null,null]'))
    # drawtree(deserialize('[0,-3,5,-10,null,0]]'))
    # drawtree(deserialize('[3,1,4,null,2]'))

    # drawtree(deserialize('[1,2,0,4,0,null,null,16,0,null,null,16,0,null,null,32,0]'))
    # drawtree(deserialize('[2,0,2,null,null,0,2,null,null,0,1,null,null,0,1,null,null,0,1]'))

    # drawtree(deserialize('[0,1,9,5,7,7,6,7,3,2,5,6,7,5,7,2,5,0,4,5,6,8,9,6,8,5,2,9,5,5,9,5,5,7,8,5,4,5,7,4,4,8,8,8,9,6,0,6,4,0,6,9,4,6,9,4,4,3,5,1,9,3,1,3,8,1,2,5,4,0,7,7,4,0,8,3,4,8,3,2,6,9,0,7,0,1,8,0,6,2,1,6,6,4,8,8,1,0,1,4,4,3,2,2,0,3,3,2,6,3,2,1,7,7,5,2,0,0,7,5,2,6,5,6,2,5,3,7,9,6,7,0,4,5,0,7,2,5,0,8,3,7,8,3,0,0,7,4,4,2,4,4,0,9,5,3,1,6,7,7,3,5,8,6,5,6,6,1,3,3,4,0,7,2,3,4,0,1,4,2,3,8,5,8,6,1,6,2,5,1,7,6,4,5,2,3,3,1,4,8,7,8,5,1,9,4,1,6,8,2,4,6,4,6,7,4,6,9,0,6,7,4,6,7,5,6,6,8,7,7,5,8,7,9,2,7,1,4,0,4,2,9,9,9,2,0,8,8,9,0,2,6,1,8,4,5,6,6,2,8,2,7,4,7,6,2,null,4,3,0,5,5,7,7,9,3,7,2,0,5,1,4,8,2,4,5,1,5,2,6,2,6,0,6,7,6,6,8,7,9,3,9,5,3,2,3,2,6,0,0,4,4,1,5,2,0,1,9,3,8,0,3,3,0,0,2,4,1,4,6,1,4,3,9,8,5,7,9,2,0,6,8,1,7,0,3,6,0,6,5,0,4,8,0,6,3,6,4,8,9,7,0,3,6,2,2,5,7,9,4,6,1,8,7,8,6,8,6,4,8,7,7,5,5,1,6,8,8,1,7,8,3,0,4,0,9,8,5,5,4,0,6,3,0,1,2,8,1,8,5,2,0,1,1,2,1,1,9,6,1,0,8,1,8,4,3,2,7,8,7,9,2,2,1,9,8,4,6,5,8,3,2,8,6,7,4,4,7,9,4,3,9,1,4,6,2,7,3,3,1,1,5,1,3,6,7,3,4,9,7,2,2,0,3,6,6,0,6,2,9,5,3,0,1,6,7,2,1,1,7,6,7,7,2,8,2,7,6,7,2,9,9,5,3,9,1,2,7,7,3,null,null,null,null,null,4,7,1,1,2,6,7,2,2,null,null,null,6,0,9,2,null,null,0,5,9,0,1,5,1,null,7,null,null,null,3,7,3,6,1,0,0,5,3,4,1,9,0,null,null,null,3,null,7,6,1,0,2,null,0,3,8,0,null,null,null,null,2,0,9,3,4,null,0,null,2,4,7,2,7,1,6,9,7,null,null,null,0,1,7,8,1,9,5,1,1,null,null,null,3,6,5,6,1,5,6,0,5,4,0,null,1,null,null,null,6,3,7,2,2,1,7,5,4,6,2,null,2,3,4,6,3,2,8,9,0,7,8,6,9,8,5,1,4,1,7,9,2,3,4,6,6,6,3,3,9,1,7,4,5,3,2,9,7,1,0,5,3,7,3,5,3,4,7,5,9,8,1,0,2,3,4,null,7,2,1,null,8,2,4,null,5,null,4,null,0,8,4,0,5,4,3,7,9,3,5,0,3,7,0,7,4,5,0,null,1,9,2,null,1,5,3,0,5,4,6,null,6,4,6,null,8,null,null,null,8,3,1,9,7,null,4,null,0,7,0,0,null,null,null,null,9,1,2,4,4,4,3,3,0,null,null,null,9,5,2,1,0,9,9,0,1,null,null,null,3,null,2,7,7,9,9,6,6,2,2,7,6,4,3,0,6,null,null,null,8,3,1,1,0,3,9,9,1,null,null,null,0,4,8,5,5,4,7,null,0,6,9,null,8,3,7,8,0,null,2,null,8,2,0,7,4,null,null,null,1,3,1,null,1,null,7,null,7,null,9,null,2,1,null,null,0,null,3,null,0,0,4,4,9,null,3,null,6,4,9,8,2,9,5,4,5,7,9,3,2,1,8,1,2,null,null,null,9,1,9,2,1,null,null,null,0,null,9,null,3,4,4,7,9,5,5,null,3,6,1,null,9,2,5,8,7,null,5,null,8,7,6,5,6,5,6,6,7,1,0,null,4,6,4,null,4,6,1,null,9,8,1,null,4,6,3,null,7,5,6,null,4,null,7,null,3,9,1,5,8,4,4,7,5,2,5,0,9,6,8,1,5,null,null,null,9,4,9,7,null,null,null,null,1,6,7,1,3,null,5,null,8,null,3,null,2,5,5,0,1,4,9,null,2,9,7,2,0,0,8,8,null,null,7,null,null,null,9,null,null,null,null,null,null,null,6,7,0,9,null,null,9,null,null,null,7,null,null,null,6,null,7,null,3,null,null,null,null,null,null,null,null,null,null,null,6,null,null,null,null,null,null,null,8,null,null,null,null,null,null,null,8,null,null,null,2,null,null,null,null,null,null,null,2,9,4,6,null,null,null,null,null,null,0,null,null,null,null,null,null,null,4,null,null,null,2,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,2,null,8,null,4,null,1,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,8,null,5,null,5,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,9,null,null,null,1,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,6,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,0,null,3,null,3,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,7,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,5,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,5,null,3,null,4,null,null,null,null,null,null,null,null,null,null,null,5,8,2,null,0,null,null,null,null,null,null,null,4,null,null,null,null,null,null,null,null,null,6,null,null,null,null,null,null,null,9,null,null,null,null,null,null,null,null,null,null,null,2,6,5,1,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,9,null,6,null,6,null,2,null,null,null,2,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,3,null,3,null,6,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,3,3,5,null,6,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,4,0,4,5,null,null,null,null,6,null,null,null,null,null,null,null,null,null,null,null,4,null,null,null,null,null,null,null,9,null,6,null,4,null,null,null,1,null,null,null,null,null,null,null,0,null,null,null,null,null,null,null,null,null,7,null,1,null,1,null,7,null,null,null,null,null,null,null,7,null,null,null,9,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,3,1,6,0,7,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,0,null,null,null,null,null,null,null,7,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,8,null,null,null,8,3,7,null,null,null,9,null,6,null,5,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,7,1,6,8,null,null,null,null,null,null,null,null,null,null,1,null,null,null,4,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,1]'))
    # drawtree(deserialize('[1,4,9,2,3,5]'))
    # drawtree(deserialize('[7,2,8,1,6,null,10,null,null,3,null,9,11,null,5,null,null,null,null,4]'))
    # drawtree(deserialize('[1,2,3,null,null,4,null,null,5]'))
    # drawtree(deserialize('[2,1,3,0,7,9,1,2,null,1,0,null,null,8,8,null,null,null,null,7]'))