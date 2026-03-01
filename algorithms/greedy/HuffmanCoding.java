import java.util.*;

class Node {
  char ch;
  int freq;
  Node left;
  Node right;

  Node(char ch, int freq) {
    this.ch = ch;
    this.freq = freq;
    this.left = null;
    this.right = null;
  }

  Node(char ch, int freq, Node left, Node right) {
    this.ch = ch;
    this.freq = freq;
    this.left = left;
    this.right = right;
  }
}

public class HuffmanCoding {
  public static void printCodes(
      Node root, String str, Map<Character, String> huffmanCode) {
    if (root == null)
      return;

    if (root.left == null && root.right == null) {
      huffmanCode.put(root.ch, str);
    }

    printCodes(root.left, str + "0", huffmanCode);
    printCodes(root.right, str + "1", huffmanCode);
  }

  public static void buildHuffmanTree(String text) {
    Map<Character, Integer> freq = new HashMap<>();
    for (char ch : text.toCharArray()) {
      freq.put(ch, freq.getOrDefault(ch, 0) + 1);
    }

    PriorityQueue<Node> pq = new PriorityQueue<>((l, r) -> l.freq - r.freq);

    for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
      pq.add(new Node(entry.getKey(), entry.getValue()));
    }

    while (pq.size() != 1) {
      Node left = pq.poll();
      Node right = pq.poll();

      int sum = left.freq + right.freq;

      pq.add(new Node('\0', sum, left, right));
    }

    Node root = pq.peek();

    Map<Character, String> huffmanCode = new HashMap<>();
    printCodes(root, "", huffmanCode);

    System.out.println("Huffman Codes:");
    for (Map.Entry<Character, String> entry : huffmanCode.entrySet()) {
      System.out.println(entry.getKey() + " " + entry.getValue());
    }

    System.out.println("\nOriginal string:");
    System.out.println(text);

    StringBuilder encodedStr = new StringBuilder();
    for (char ch : text.toCharArray()) {
      encodedStr.append(huffmanCode.get(ch));
    }

    System.out.println("\nEncoded string:");
    System.out.println(encodedStr);

    System.out.println("\nDecoded string:");
    Node curr = root;

    for (char bit : encodedStr.toString().toCharArray()) {
      if (bit == '0') {
        curr = curr.left;
      } else {
        curr = curr.right;
      }

      if (curr.left == null && curr.right == null) {
        System.out.print(curr.ch);
        curr = root;
      }
    }

    System.out.println();
  }
}
