class Solution:
    def simplifyPath(self, path: str) -> str:
        path += "/"
        arr = path.split("/")
        st = []
        for x in arr:
            if x == "" or x == ".":
                continue
            elif x == "..":
                if len(st) != 0:
                    st.pop()
            else:
                st.append(x)
        
        ans = ""
        
        for x in st:
            ans += "/" + x
        if ans == "":
            ans = "/"
        return ans
