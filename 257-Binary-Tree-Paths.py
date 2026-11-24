class Solution:
    def binaryTreePaths(self, root):
        ans = []

        def f(root, path):
            if not root:
                return

            path.append(str(root.val))

            if not root.left and not root.right:
                ans.append("->".join(path))
            else:
                f(root.left, path)
                f(root.right, path)

            path.pop()

        f(root, [])
        return ans