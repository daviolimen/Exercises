class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

def inorder(root):
    if root is not None:
        # Traverse left
        inorder(root.left)
        # Traverse root
        print(str(root.data) + "->", end=' ')
        # Traverse right
        inorder(root.right)

def insert(root, data):
    if not root:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    else:
        root.right = insert(root.right, data)
    return root

def minValueNode(root):
    current = root
    while root.left:
        current = current.left
    return current

def deleteNode(root, data):
    if not root:
        return root
    if data  < root.data:
        root.left = deleteNode(root.left, data)
    elif (data > root.data):
        root.right = deleteNode(root.right, data)
    else:
        if not root.left:
            temp = root.right
            root = None
            return temp
        elif not root.right:
            temp = root.left
            root = None
            return temp
        temp = minValueNode(root.right)
        root.data = temp.data
        root.right = deleteNode(root.right, temp.data)
    return root

root = None
root = insert(root, 8)
root = insert(root, 3)
root = insert(root, 1)
root = insert(root, 6)
root = insert(root, 7)
root = insert(root, 10)
root = insert(root, 14)
root = insert(root, 4)

print("Inorder traversal: ", end=' ')
inorder(root)

print("\nDelete 10")
root = deleteNode(root, 10)
print("Inorder traversal: ", end=' ')
inorder(root)