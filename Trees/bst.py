class bstNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
class BST:
    def __init__(self):
        self.root=None
        self.numNodes=0

    def printTreeHelper(self, root):
        if root == None:
            return
        print(root.data, end = ":")
        if root.left != None:
            print("L:",end='')
            print(root.left.data,end=',')
        if root.right != None:
            print("R:",end='')
            print(root.right.data,end='')
        print()
        self.printTreeHelper(root.left)
        self.printTreeHelper(root.right)
    
    def printTree(self):
        self.printTreeHelper(self.root)

    def insertHelper(self,root,data):
        if root==None:
            root=bstNode(data)
        elif root.data>data:
            root.left=self.insertHelper(root.left,data)
        else:
            root.right=self.insertHelper(root.right,data)
        return root

    def insert(self,data):
        self.root=self.insertHelper(self.root,data)
    
    def searchHelper(self,root,data):
        if root == None:
            return False
        if root.data==data:
            return True
        elif root.data>data:
            return self.searchHelper(root.left,data)
        else:
            return self.searchHelper(root.right,data)
    def search(self,data):
        return self.searchHelper(self.root,data)
    
    def getMax(self,root):
        if root==None:
            return root
        temp=root
        while temp.right!=None:
            temp=temp.right
        return temp
    
    def getMin(self,root):
        if root==None:
            return root
        temp=root
        while temp.left!=None:
            temp=temp.left
        return temp
    
    def deleteHelper(self,root,data):
        if root==None:
            return root
        if root.data==data:
            if root.left==None and root.right==None:
                del root
                return None
            elif root.left and root.right:
                temp=self.getMin(root.right)
                root.data=temp.data
                root.right=self.deleteHelper(root.right,root.data)
                return root
            elif root.left:
                temp=root.left
                del root
                return temp
            elif root.right:
                temp=root.right
                del root
                return temp
        elif root.data>data:
            root.left=self.deleteHelper(root.left,data)
            return root
        else:
            root.right=self.deleteHelper(root.right,data)
            return root
    
    def delete(self,data):
        self.root=self.deleteHelper(self.root,data)
    
    def createTreeFromListHelper(self,dataList):
        if len(dataList)<=0:
            return None
        index=len(dataList)//2
        root=bstNode(dataList[index])
        root.left=self.createTreeFromListHelper(dataList[:index])
        root.right=self.createTreeFromListHelper(dataList[index+1:])
        return root
    def createTreeFromList(self,dataList):
        dataList=sorted(dataList)
        self.root=self.createTreeFromListHelper(dataList)
    def lcaHelper(self,root,data1,data2):
        if root==None:
            return None
        elif root.data>data1 and root.data>data2:
            return self.lcaHelper(root.left,data1,data2)
        elif root.data<data1 and root.data<data2:
            return self.lcaHelper(root.left,data1,data2)
        return root.data
    def lca(self,data1,data2):
        return self.lcaHelper(self.root,data1,data2)
    def helper(self,root,left,right):
        if root is None:
            return True
        # common elements should be in right subtree 
        elif root.data>left and root.data<=right:
            l=self.helper(root.left,left,root.data)
            r=self.helper(root.right,root.data,right)
            return l and r
    
    def isBST(self):
        left=float("-infinity")
        right=float("infinity")
        return self.helper(self.root,left,right)