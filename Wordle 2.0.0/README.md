## 打开方式

请先保证词库和可执行文件在同一文件夹下

### Linux

请先解压到 /home 文件夹下（其他地方也可以，但是你在运行之前必须要先跳到那个文件夹下）

然后打开终端，输入以下命令：

`./wordle`

### Windows

运行 exe 即可

## 读入

运行时你会看到一个读入界面，在这个界面你可以导入已有的词库.

提供的 StandardVocabulary.wordle 可以通过输入一个 `0` 来读取，此外，你还可以通过完整的文件名来读取一个词库. 额外提供的 `name.wordle` 即为一个拓展词库，它存储了一些人的 ID 以供使用.

## 模式选择

1. 1P  单人模式

2. 2P CREATOR  双人模式：出词+猜词

3. 2P BATTLE 双人模式：轮流猜不同的词（每个人的词固定），先猜出来的赢

4. 2P COOPERATION 双人模式：轮流猜同一个词，先猜出来的赢

5. NP 未开发

6. Read File 重新读入一个词库

## 界面

在一开始你可能会看到如下页面：

```katex
There's a string has 6 letters.
Answer : * * * * * * 

You have 5 chance in total to guess.
Guess a word >>
```

第一行提示了您需要猜的单词长度，以后您都需要猜一个相同长度的单词，否则系统会报出 `Wrong Length` 错误.

第二行是这个词，每当您猜出一个字母，对应位置的字母就会显示出来

您一共有五次机会来猜词

## 提示

在您猜了一个单词后，界面会变成如下这样：

```katex
Rule
Yellow means the string has this letter,but it isn't in the correct place.
Green means the string has this letter,and it is in the correct place.
There's a string has 6 letters.
Answer : a * * * * * 

a b c d e f 

Remain Letters
a b c d e f g h i j k l m n o p q r s t u v w x y z
```

第一行再告诉您如何阅读这些提示，黄色说明您猜对了一个字母，它确实在这个单词之中，但并不在正确的位置上. 绿色表示您完全猜对了这个字母以及位置，黑色则说明它不在这个单词中.

您需要通过五次猜词的提示来趋近答案.

下方 Remain Letters 会提示您已经猜了哪些字母

## 新建词库

你可以新建一个词库，词库中每个单词用空格隔开，最后用 $0$ 结尾. 这样形成的词库可以在导入界面被导入，随后您就可以使用自制词库进行游玩了.
