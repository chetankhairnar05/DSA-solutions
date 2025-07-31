class Solution {
    public String reverseWords(String s) {
        String[] w = s.split(" +");
        String ans = "";
        for(int i =w.length-1;i>=0;i--){
            ans+= w[i]+" ";
        }
        return ans.trim();
    }
}