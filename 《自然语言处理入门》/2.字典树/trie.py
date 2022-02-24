# -*- coding:utf-8 -*-
# Author：HuXiaoming
# Date: 2021-05-07
# 重现trie.py文件
# 参考 https://github.com/hankcs/pyhanlp/blob/master/tests/book/ch02/trie.py

"""
# 与 pyhanlp trie.py的不同之处：
# 1. 用结点存储字，而不是边存储字
"""

class Node(object):

    def __init__(self, word: str) -> None:
        self._children = {}
        self._word = word
        self._isWords = False

    def _add_child(self, word: str, overwirte: bool=False):
        child = self._children.get(word)
        if child is None:
            child = Node(word)
            self._children[word] = child
        if overwirte:
            self._isWords = True
        return child

    # 删除孩子结点
    def _del_child(self, word: str) -> None:
        child = self._children.get(word)
        if not child._children:
            # 已没有孙子结点
            self._children.pop(word)
            del child
        else:
            # 有孙子结点
            # 则儿子不再对应一个单词
            # 但不删除儿子这个字
            child._isWords = False

    def delete(self, words: str) -> None:
        if words:
            word, words = words[0:1], words[1:]
            child = self._children.get(word)
            child.delete(words)
        else:
            # 最后一个
            return
        self._del_child(word)


class Trie(Node):

    def __init__(self) -> None:
        super().__init__(word="Root")

    def append(self, words: str) -> None:
        # state: Node对象
        state = self
        for i, char in enumerate(words):
            # 递归将一个词插入字典树中
            if i < len(words) - 1:
                state = state._add_child(char, False)
            else:
                # 词语words的最后一个字
                state = state._add_child(char, True)

    def delete(self, words: str) -> None:
        if words in self:
            word, words = words[0:1], words[1:]
            child = self._children.get(word)
            child.delete(words)
        else:
            raise IndexError("待删除词不在字典树中")

    def __getitem__(self, words: str):
        state = self
        for i, char in enumerate(words):
            if i < len(words):
                state = state._children.get(char)
                if state is None:
                    return None

        # 词语words的最后一个字
        if state._isWords:
            # 搜索成功
            return state
        else:
            # words的最后一个字在当前字典树中不是结束字
            return None

    def __contains__(self, words):
        return self[words] is not None


if __name__ == "__main__":

    trie = Trie()
    # 增
    trie.append("机器")
    trie.append("机器人")
    trie.append("前进")
    trie.append("机械臂")

    # 查
    assert "机器" in trie
    assert "前面" not in trie

    # 删
    trie.delete("机器")
    assert "机器" not in trie
