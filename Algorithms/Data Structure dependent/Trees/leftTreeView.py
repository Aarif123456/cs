import math
# Add any extra import statements you may need here


class TreeNode: 
  def __init__(self,key): 
    self.left = None
    self.right = None
    self.val = key 

# Add any helper functions you may need here

def helper(root, out, depth=0):
  if root is None: return
  if len(out) <= depth:
    out.append(root.val)
  helper(root.left, out, depth+1)
  helper(root.right, out, depth+1)

def visible_nodes(root):
    out = []
    helper(root, out)
    return len(out)










# These are the tests we use to determine if the solution is correct.
# You can add your own at the bottom.

def printInteger(n):
  print('[', n, ']', sep='', end='')

test_case_number = 1

def check(expected, output):
  global test_case_number
  result = False
  if expected == output:
    result = True
  rightTick = '\u2713'
  wrongTick = '\u2717'
  if result:
    print(rightTick, 'Test #', test_case_number, sep='')
  else:
    print(wrongTick, 'Test #', test_case_number, ': Expected ', sep='', end='')
    printInteger(expected)
    print(' Your output: ', end='')
    printInteger(output)
    print()
  test_case_number += 1

if __name__ == "__main__":
  root_1 = TreeNode(8)
  root_1.left = TreeNode(3)
  root_1.right = TreeNode(10)
  root_1.left.left = TreeNode(1)
  root_1.left.right = TreeNode(6)
  root_1.left.right.left = TreeNode(4)
  root_1.left.right.right = TreeNode(7)
  root_1.right.right = TreeNode(14)
  root_1.right.right.left = TreeNode(13)
  expected_1 = 4
  output_1 = visible_nodes(root_1)
  check(expected_1, output_1)

  root_2 = TreeNode(10)
  root_2.left = TreeNode(8)
  root_2.right = TreeNode(15)
  root_2.left.left = TreeNode(4)
  root_2.left.left.right = TreeNode(5)
  root_2.left.left.right.right = TreeNode(6)
  root_2.right.left =TreeNode(14)
  root_2.right.right = TreeNode(16)

  expected_2 = 5
  output_2 = visible_nodes(root_2)
  check(expected_2, output_2)

  # Add your own test cases here
  