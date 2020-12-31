from queue import Queue


class BinaryTreeNode:
    def __init__(self, data=0, left=None, right=None, nextSibling=None):
        self.data = data
        self.left = left
        self.right = right
        self.nextSibling = nextSibling
# input methods


def inputTreeLevelWiseUsingList(dataList):
    q = Queue()
    # rootData=int(input("Enter root data:"))
    index = 0
    root = BinaryTreeNode(dataList[index])
    index += 1
    q.put(root)
    while(q.empty() == False):
        front = q.get()
        left = dataList[index]
        index += 1
        if(left != -1):
            front.left = BinaryTreeNode(left)
            q.put(front.left)
        right = dataList[index]
        index += 1
        if(right != -1):
            front.right = BinaryTreeNode(right)
            q.put(front.right)
    return root


def inputTreeLevelWise():
    q = Queue()
    rootData = int(input("Enter root data:"))
    root = BinaryTreeNode(rootData)
    q.put(root)
    while(q.empty() == False):
        front = q.get()
        left = int(input("Enter the left child of {}:".format(front.data)))
        if(left != -1):
            front.left = BinaryTreeNode(left)
            q.put(front.left)
        right = int(input("Enter the right child of {}:".format(front.data)))
        if(right != -1):
            front.right = BinaryTreeNode(right)
            q.put(front.right)
    return root


def helper(data):
    root = BinaryTreeNode(data)
    leftData = int(input("Enter data of left child of {}".format(root.data)))
    if(leftData != -1):
        root.left = helper(leftData)
    rightData = int(input("Enter data of right child of {}".format(root.data)))
    if(rightData != -1):
        root.right = helper(rightData)
    return root


def inputRec():
    data = int(input("Enter data"))
    return helper(data)

# traversal methods


def preOrderRec(root, result=[]):
    if(root is None):
        return root
    result.append(root.data)
    preOrderRec(root.left, result)
    preOrderRec(root.right, result)


def preOrderIter(root, result):
    if not root:
        return
    stack = []
    stack.append(root)
    while stack:
        node = stack.pop()
        result.append(node.data)
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)


def inOrderRec(root, result=[]):
    if(root is None):
        return root
    inOrderRec(root.left, result)
    result.append(root.data)
    inOrderRec(root.right, result)


def inOrderIter(root, result):
    stack = []
    while root is not None:
        stack.append(root)
        root = root.left
    while stack:
        node = stack.pop()
        result.append(node.data)
        temp = node.right
        while temp is not None:
            stack.append(temp)
            temp = temp.left


def postOrderRec(root, result=[]):
    if(root is None):
        return root
    postOrderRec(root.left, result)
    postOrderRec(root.right, result)
    result.append(root.data)


def postOrderIter(root, result):
    # using two stacks
    # if root is None:
    #     return
    # s1=[]
    # s2=[]
    # s1.append(root)
    # while s1:
    #     temp=s1.pop()
    #     s2.append(temp)
    #     if temp.left:
    #         s1.append(temp.left)
    #     if temp.right:
    #         s1.append(temp.right)
    # while s2:
    #     result.append(s2.pop().data)

    # using single stack
    stk = []
    temp = root
    while True:
        # step 1
        while temp:
            if temp.right:
                stk.append(temp.right)
            stk.append(temp)
            temp = temp.left
        # step 2
        temp = stk.pop()
        if len(stk) > 0 and temp.right and stk[-1] == temp.right:
            stk.pop()
            stk.append(temp)
            temp = temp.right
        else:
            result.append(temp.data)
            temp = None

        if len(stk) <= 0:
            break


def levelOrder(root, result):
    q = Queue()
    q.put(root)
    while q.empty() == False:
        front = q.get()
        result.append(front.data)
        if front.left:
            q.put(front.left)
        if front.right:
            q.put(front.right)

# Common Problems


def maxEle(root):
    if root is None:
        return root
    maxi = root
    left = maxEle(root.left)
    right = maxEle(root.right)
    if left and left.data > maxi.data:
        maxi = left
    if right and right.data > maxi.data:
        maxi = right
    return maxi


def searchBT(root, target):
    if not root:
        return root
    if root.data == target:
        return root
    left = searchBT(root.left, target)
    right = searchBT(root.right, target)
    if left:
        return left
    if right:
        return right
    return None


def height(root):
    if root is None:
        return 0
    return max(height(root.left), height(root.right))+1


def heightLevelOrder(root):
    ht = 0
    q = []
    q.append(root)
    q.append(None)
    while q:
        front = q.pop(0)
        # print(q.)
        if front is not None:
            if front.left:
                q.append(front.left)
            if front.right:
                q.append(front.right)
        else:
            ht += 1
            print(ht)
            if not q:
                break
            else:
                q.append(None)
    return ht


def deepestNode(root):
    q = Queue()
    q.put(root)
    front = root
    while q.empty() == False:
        front = q.get()
        if front.left:
            q.put(front.left)
        if front.right:
            q.put(front.right)
    return front


def deleteHelper(root, targetNode):
    if not root:
        return root
    if root == targetNode:
        return None
    root.left = deleteHelper(root.left, targetNode)
    root.right = deleteHelper(root.right, targetNode)
    return root


def deleteEleBT(root, ele):
    if not root:
        return root
    targetNode = searchBT(root, ele)
    deepNode = deepestNode(root)
    targetNode.data, deepNode.data = deepNode.data, targetNode.data
    return deleteHelper(root, deepNode)


def diameterHelper(root):
    if root is None:
        return 0, 0
    ld, lh = diameterHelper(root.left)
    rd, rh = diameterHelper(root.right)
    ht = max(lh, rh)+1
    dia = max(max(lh+rh, ld), rd)
    return dia, ht


def diameter(root):
    dia, _ = diameterHelper(root)
    return dia


def allRootToLeafPaths(root):
    if root is None:
        return []
    elif root.left == None and root.right == None:
        return [str(root.data)]
    left = allRootToLeafPaths(root.left)
    right = allRootToLeafPaths(root.right)
    # print(root.data,root.left,root.right)
    # print(left)
    # print(right)
    res = []
    for item in left+right:
        item = str(root.data)+"->"+item
        res.append(item)
    return res


def sumAllRootToLeafPaths(root):
    if root is None:
        return []
    elif root.left == None and root.right == None:
        return [root.data]
    left = sumAllRootToLeafPaths(root.left)
    right = sumAllRootToLeafPaths(root.right)
    # print(root.data,root.left,root.right)
    # print(left)
    # print(right)
    res = []
    for item in left+right:
        res.append(item+root.data)
    return res


def maxPathSumHelper(root):
    if root is None:
        return 0, float("-infinity")
    l, lRes = maxPathSumHelper(root.left)
    r, rRes = maxPathSumHelper(root.right)
    res = max(lRes, rRes)
    maxSingle = max(max(l, r)+root.data, root.data)
    maxTop = max(maxSingle, l+r+root.data)
    res = max(res, maxTop)
    return maxSingle, res


def maxPathSum(root):
    _, res = maxPathSumHelper(root)
    return res
# def maxSumPath(root):


def pathFinder(root, val):
    if root and val == root.data:
        return True, [[root.data]]
    if root == None:
        return False, []
    left, lPaths = pathFinder(root.left, val-root.data)
    right, rPaths = pathFinder(root.right, val-root.data)
    res = []
    if left:
        for item in lPaths:
            item.append(root.data)
            res.append(item)
    if right:
        for item in rPaths:
            item.append(root.data)
            res.append(item)
    return left or right, res


def printLevelOrderNewLine(root):
    q = Queue()
    q.put(root)
    q.put(None)
    while q.empty() == False:
        front = q.get()
        if front:
            print(front.data, end=" ")
            if front.left:
                q.put(front.left)
            if front.right:
                q.put(front.right)
        else:
            print("")
            if q.empty():
                break
            q.put(None)


def mirror(root):
    if root is None:
        return root
    temp = mirror(root.right)
    root.right = mirror(root.left)
    root.left = temp
    return root


def detectMirrors(root1, root2):
    if root1 == None and root2 == None:
        return True
    elif root1 == None or root2 == None:
        return False
    left = detectMirrors(root1.left, root2.right)
    right = detectMirrors(root1.right, root2.left)
    return (left and right) and root1.data == root2.data


def lcaHelper(root, data1, data2):
    if root is None:
        return False, False, root
    leftData1, leftData2, left = lcaHelper(root.left, data1, data2)
    rightData1, rightData2, right = lcaHelper(root.right, data1, data2)
    if left != None:
        return leftData1, leftData2, left
    elif right != None:
        return rightData1, rightData2, right
    d1 = leftData1 if leftData1 != False else rightData1
    d2 = leftData2 if leftData2 != False else rightData2
    d1 = root.data if root.data == data1 else d1
    d2 = root.data if root.data == data2 else d2
    if d1 != False and d2 != False:
        return d1, d2, root
    return d1, d2, None


def lca(root, data1, data2):
    data1, data2, root = lcaHelper(root, data1, data2)
    # print(data1,data2,root)
    return data1, data2, root.data


def lcaEasy(root, data1, data2):
    if root is None:
        return None
    if root.data == data1 or root.data == data2:
        return root.data

    left_lca = lcaEasy(root.left, data1, data2)
    right_lca = lcaEasy(root.right, data1, data2)

    if left_lca and right_lca:
        return root.data

    return left_lca if left_lca is not None else right_lca


def binaryTreeUsingPreorderInorder(preOrder, inOrder):
    if len(preOrder) <= 0:
        return None
    root = BinaryTreeNode(preOrder[0])
    index = inOrder.index(preOrder[0])
    root.left = binaryTreeUsingPreorderInorder(
        preOrder[1:index+1], inOrder[:index])
    root.right = binaryTreeUsingPreorderInorder(
        preOrder[index+1:], inOrder[index+1:])
    return root


def zigZagOrder(root):
    s1 = []
    s2 = []
    s1.append(root)
    while s1 or s2:
        while s1:
            temp = s1.pop()
            print(temp.data, end=" ")
            if temp.left:
                s2.append(temp.left)
            if temp.right:
                s2.append(temp.right)
        if s2:
            print("")
        while s2:
            temp = s2.pop()
            print(temp.data, end=" ")
            if temp.right:
                s1.append(temp.right)
            if temp.left:
                s1.append(temp.left)
        if s1:
            print("")
    print("")


def verticalSum(root, col=0, hashTable={}):
    if root == None:
        return {}
    verticalSum(root.left, col-1, hashTable)
    if not col in hashTable:
        hashTable[col] = root.data
    else:
        hashTable[col] += root.data
    verticalSum(root.right, col+1, hashTable)
    return list(hashTable.values())


def countBinaryTreePossible(n):
    if n == 0 or n == 1:
        return 1
    if n == 2:
        return 2
    sum = 0
    ump = {}
    for item in range(n):
        temp1 = 0
        if item in ump:
            temp1 = ump[item]
        else:
            ump[item] = countBinaryTreePossible(item)
            temp1 = ump[item]
        temp2 = 0
        if n-1-item in ump:
            temp2 = ump[n-1-item]
        else:
            ump[n-1-item] = countBinaryTreePossible(n-1-item)
            temp2 = ump[n-1-item]
        sum += (temp1*temp2)
    return sum


def specialPreorderTree(preorder):
    if len(preorder) <= 0:
        return None
    root = BinaryTreeNode(preorder[0])
    if root.data == 'L':
        return root
    root.left = specialPreorderTree(preorder[1:])
    root.right = specialPreorderTree(preorder[2:])
    return root
