package HomeWork_Algorithm;

import java.util.*;

public class Project_6 {

    // Defiene the tree node
    static class Tree {

        private Node root;

        public Node getRoot() {
            return root;
        }

        public void setRoot(Node root) {
            this.root = root;
        }

    }

    // 制造node
    static class Node implements Comparable<Node> {

        private String chars = "";
        private int frequence = 0;

        private Node parent;

        private Node leftNode;
        private Node rightNode;

        @Override
        public int compareTo(Node n) {
            return frequence - n.frequence;
        }

        public boolean isLeaf() {
            return chars.length() == 1;
        }

        public boolean isRoot() {
            return parent == null;
        }

        public boolean isLeftChild() {
            return parent != null && this == parent.leftNode;
        }

        public int getFrequence() {
            return frequence;
        }

        public void setFrequence(int frequence) {
            this.frequence = frequence;
        }

        public String getChars() {
            return chars;
        }

        public void setChars(String chars) {
            this.chars = chars;
        }

        public Node getParent() {
            return parent;
        }

        public void setParent(Node parent) {
            this.parent = parent;
        }

        public Node getLeftNode() {
            return leftNode;
        }

        public void setLeftNode(Node leftNode) {
            this.leftNode = leftNode;
        }

        public Node getRightNode() {
            return rightNode;
        }

        public void setRightNode(Node rightNode) {
            this.rightNode = rightNode;
        }
    }

    // 统计
    public static Map<Character, Integer> statistics(char[] charArray) {

        Map<Character, Integer> map = new HashMap<Character, Integer>();

        for (char character : charArray) {

            if (map.containsKey(character)) {
                map.put(character, map.get(character) + 1);
            } else {
                map.put(character, 1);
            }

        }

        return map;
    }

    // 构造树
    private static Tree buildTree(Map<Character, Integer> statistics, List<Node> leafs) {

        Character[] keys = statistics.keySet().toArray(new Character[0]);

        PriorityQueue<Node> priorityQueue = new PriorityQueue<Node>(); // using heap

        for (Character character : keys) {

            Node node = new Node();

            node.chars = character.toString();

            node.frequence = statistics.get(character);

            priorityQueue.add(node);

            leafs.add(node);
        }

        int size = priorityQueue.size();

        for (int i = 1; i <= size - 1; i++) {

            Node node1 = priorityQueue.poll();
            Node node2 = priorityQueue.poll();

            Node sumNode = new Node();

            sumNode.chars = node1.chars + node2.chars;

            sumNode.frequence = node1.frequence + node2.frequence;

            sumNode.leftNode = node1;
            sumNode.rightNode = node2;

            node1.parent = sumNode;
            node2.parent = sumNode;

            priorityQueue.add(sumNode);
        }

        Tree tree = new Tree();

        tree.root = priorityQueue.poll();

        return tree;
    }

    // encoding
    public static String encode(String originalStr, Map<Character, Integer> statistics) {

        if (originalStr == null || originalStr.equals("")) {
            return "";
        }

        char[] charArray = originalStr.toCharArray();

        List<Node> leafNodes = new ArrayList<Node>();

        buildTree(statistics, leafNodes);

        Map<Character, String> encodInfo = buildEncodingInfo(leafNodes);

        StringBuffer buffer = new StringBuffer();

        for (char character : charArray) {

            buffer.append(encodInfo.get(character));
        }

        return buffer.toString();
    }


    // Variable-Length --> buildEncodingInfo --> here is to build mapping for character -->  codeword
    private static Map<Character, String> buildEncodingInfo(List<Node> leafNodes) {

        Map<Character, String> codewords = new HashMap<Character, String>();

        for (Node leafNode : leafNodes) {

            Character character = leafNode.chars.charAt(0);
            String codeword = "";
            Node currentNode = leafNode;

            do {
                if (currentNode.isLeftChild()) {
                    codeword = "0" + codeword;
                } else {
                    codeword = "1" + codeword;
                }

                currentNode = currentNode.parent;
            } while (currentNode.parent != null);

            codewords.put(character, codeword);
        }

        return codewords;
    }



    // decode - variable 
    public static String decode(String binaryStr, Map<Character, Integer> statistics) {

        if (binaryStr == null || binaryStr.equals("")) {
            return "";
        }

        char[] binaryCharArray = binaryStr.toCharArray();
        LinkedList<Character> binaryList = new LinkedList<Character>();

        int size = binaryCharArray.length;

        for (int i = 0; i < size; i++) {
            binaryList.addLast(new Character(binaryCharArray[i]));
        }

        List<Node> leafNodes = new ArrayList<Node>();
        Tree tree = buildTree(statistics, leafNodes);

        StringBuffer buffer = new StringBuffer();

        while (binaryList.size() > 0) {

            Node node = tree.root;

            do {
                Character c = binaryList.removeFirst();
                if (c.charValue() == '0') {
                    node = node.leftNode;
                } else {
                    node = node.rightNode;
                }
            } while (!node.isLeaf());

            buffer.append(node.chars);
        }

        return buffer.toString();
    }



    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************
    // ********************* encoding_fixed *********************

    public static String encode_fixed(String originalStr, Map<Character, Integer> statistics) {

        if (originalStr == null || originalStr.equals("")) {
            return "";
        }

        char[] charArray = originalStr.toCharArray();

        List<Node> leafNodes = new ArrayList<Node>();

        buildTree(statistics, leafNodes);

        Map<Character, String> encodInfo_fixed = buildEncodingInfo_fixed(leafNodes);


        StringBuffer buffer = new StringBuffer();

        for (char character : charArray) {

            buffer.append(encodInfo_fixed.get(character));
        }

        return buffer.toString();
    }

    // Fixed - Length --> buildEncodingInfo_fixed --> here is to build mapping for character -->  codeword
    private static Map<Character, String> buildEncodingInfo_fixed(List<Node> leafNodes) {

        Map<Character, String> codewords = new HashMap<Character, String>();

        int n = leafNodes.size();

//        Integer.toBinaryString(11)
        int K = 0;

        String codeword = "";

        for (Node leafNode : leafNodes) {

            Character c = leafNode.chars.charAt(0);

            codeword = Integer.toBinaryString(K++);

            int i = 0;

            while(i < 8 - codeword.length()){  // --> make it to 8-bit!!!
                //  System.out.println(codeword);
                codeword = "0" + codeword;
            }

           // System.out.println(codeword + " -- " + codeword.length());

            codewords.put(c, codeword);
        }

        return codewords;
    }


    // ********************* decode_fixed *********************
    public static String decode_fixed(String binaryStr, Map<Character, Integer> statistics) {

        // 1. Corner case
        if (binaryStr == null || binaryStr.equals("")) {
            return "";
        }

        // 2. make char array --> then char list
        char[] binaryCharArray = binaryStr.toCharArray();

        LinkedList<Character> binaryList = new LinkedList<Character>();

        int size = binaryCharArray.length;

        for (int i = 0; i < size; i++) {
            binaryList.addLast(new Character(binaryCharArray[i]));
        }

        List<Node> leafNodes = new ArrayList<Node>();

        Tree tree = buildTree(statistics, leafNodes);

        StringBuffer buffer = new StringBuffer();

        // 根据 加密后的input
        while (binaryList.size() > 0) {

            Node node = tree.root;

            do {
                Character c = binaryList.removeFirst();
                if (c.charValue() == '0') {
                    node = node.leftNode;
                } else {
                    node = node.rightNode;
                }
            } while (!node.isLeaf());

            buffer.append(node.chars);
        }

        return buffer.toString();
    }

    /** *******************************************************************************************************************************************************/

    public static void main(String[] args) {

        String A = "qwertyu.iopas.dfghuuuuuuujkxz xcvb.nmdfghjkoiuytrewqsx.azxcfghjkertyu ioqwe.rtyuiopzxcvbnm,sdfghjkzxcvbjsjsjsjsjswuwuwuwusisisisiakakakakwkwocicuduuuuuuuuunzxcvbn.kdhstqu.xgztaisdzia  sdhsajz jahqoxhhinw.ertyuios.dfghj.poiuytrlkj.hgfdsnbvzxcqazws.xedcrfvtgb.yhnujmikol,.vb";

        String B = "Huffman Coding is an entropy encoding algorithm used for lossless data compression. It refers to the use of a variable-length code table for encoding a source symbol (such as a character in a file) where the variable-length code table has been derived in a particular way based on the estimated probability of occurrence for each possible value of the source symbol.;";

        String C = "Mr. Trump appeared to be particularly angry at the W.H.O. for issuing a statement saying it did not support his decision on Jan. 31 to restrict some travel from China because of the virus. At the time, the group issued a statement saying that “restricting the movement of people and goods during public health emergencies is ineffective in most situations and may divert resources from other interventions. Don’t close your borders to China, don’t do this,” Mr. Trump said, paraphrasing the group and accusing the organization of “not seeing” the outbreak when it started in Wuhan, China. “They didn’t see it, how do you not see it? They didn’t see it. They didn’t report it. If they did see it, they must have seen it, but they didn’t report. In fact, the W.H.O. repeatedly issued statements about the emergence of the virus in China and its movement around the world.";


        String[] M = {A,B,C};

        for(String LLL:M) {

                Map<Character, Integer> statistics = statistics(LLL.toCharArray());

                // ************************ variable
                String encodedBinariStr = encode(LLL, statistics);
                String decodedStr = decode(encodedBinariStr, statistics);

                // ************************ fixed
                String encodedBinariStr_fixed = encode_fixed(LLL, statistics);
                String decodedStr_fixed = decode_fixed(encodedBinariStr, statistics);

                // ************************ Orignal String
                System.out.println("\n\n\n\n***********-->  Original sstring: \n" + LLL);

                // ************************ Encode
                System.out.println("\n***********-->  Huffman encoed (variable) binary string: \n" + encodedBinariStr);      // Variable
                System.out.println("\n***********-->  Huffman encoed (fixed) binary string: \n" + encodedBinariStr_fixed);   // Fixed

                // ************************ Decode
                System.out.println("\n***********-->  decoded string (variable) from binariy string: \n" + decodedStr);      // Variable
                System.out.println("\n***********-->  decoded string (fixed) from binariy string: \n" + decodedStr_fixed);   // Fixed

                // System.out.println("binary string of US-ASCII: " +    getStringOfByte(oriStr, Charset.forName("US-ASCII")));

        }

    }

}
