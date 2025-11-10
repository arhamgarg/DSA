# **Contributing to the Data Structures and Algorithms Repository**

Hey there! 👋
We’re so glad you’re here and interested in contributing to this project. Below, you'll find guidelines and instructions to help you get started. Let’s dive in! 🚀

⚠️ **Important**: AI-generated code is strongly discouraged in this repository.  
This repo is meant for *your own learning* — writing and debugging code yourself will help you grow as a developer.

## **How to Contribute**

### **1. Fork the Repository**

Start by forking this repository to create a copy under your GitHub account.
- Hit the **Fork** button on the repository page.

Clone your forked version:
```bash
git clone https://github.com/<your-username>/DSA.git
cd DSA
```
*(Replace `<your-username>` with your GitHub username.)*

### **2. Set Upstream**

To keep your fork up-to-date with the original repository:
```bash
git remote add upstream https://github.com/arhamgarg/DSA.git
```

### **3. Create a New Branch**

Before making any changes, create a new branch:
```bash
git checkout -b feat/<branch-name>
```
Examples:
- `feat/add-dijkstra`
- `fix/binary-search-bug`

Now you’re all set to start coding!

## **What Can You Contribute?**

There’s plenty to do! Here are some ways you can help:

1. **New Data Structures and Algorithms**: If you have a data structure or an algorithm we’re missing, bring it in!
2. **Bug Fixes**: Fix those pesky bugs!
3. **Documentation**: Add examples, comments, or improve the README. This helps others understand the code better.
4. **Different approaches and Proposing new problems**: Implement a new approach to solve an existing problem in the repository. If you feel like something could be added as a problem, feel free to open an issue and put your problem request as comments.

## **Submitting Your Changes**

Once your changes are ready:

1. **Commit Your Work**
   Write clear and concise commit messages:
   ```bash
   git commit -m "add: Quick Sort implementation in Python"
   ```

2. **Push Your Branch**
   Send your changes to your fork:
   ```bash
   git push origin feat/<branch-name>
   ```

3. **Open a Pull Request**
   - Head to the original repository.
   - Click **Pull Requests** > **New Pull Request**.
   - Select your branch, add a meaningful title and description, and submit the PR. Let it be short and crisp.

4. **Feedback Time**
   Reviewers might leave comments—don’t worry, it’s all to make your work shine! Update your code and resubmit when needed.

## **Coding Standards**

Great code is readable and consistent. Here are some tips to keep in mind:

- **Document Your Code**: Add comments for tricky parts.
- **Follow Naming Conventions**:
  - Use **camelCase** for variables and functions.
  - Use **PascalCase** for classes and files.
  - Use **kebab-case** for directories.
- **Test Your Code**: Include test cases with inputs and expected outputs.
- **Use Formatters**: Automated formatters help enforce standards and keep your codebase consistent. Here are some common ones:

| Programming Language | Formatter             | Command                       |
|----------------------|-----------------------|-------------------------------|
| C                    | **clang-format**      | `clang-format -i *.c`         |
| C++                  | **clang-format**      | `clang-format -i *.cpp`       |
| Dart                 | **dart format**       | `dart format .`               |
| Go                   | **gofmt**             | `gofmt -s -w .`               |
| Java                 | **google-java-format**| `google-java-format -i *.java`|
| Python               | **ruff**              | `ruff format .`               |
| Rust                 | **rustfmt**           | `cargo fmt`                   |
| TypeScript           | **biome**             | `biome check --write .`       |

## **Community Support**

If you have any questions or suggestions, open a discussion under the **Discussions** tab.

We’re happy to have you onboard. 🚀
