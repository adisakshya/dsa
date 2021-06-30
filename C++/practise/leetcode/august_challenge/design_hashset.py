"""
Problem Name: Design HashSet
Problem Url: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3410/
Problem Statement: 
    Design a HashSet without using any built-in hash table libraries.
        To be specific, your design should include these functions:
            1. add(value): Insert a value into the HashSet. 
            2. contains(value) : Return whether the value exists in the HashSet or not.
            3. remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
"""

class Bucket:
    def __init__(self):
        self.bucket = []
    
    def update(self, key):
        for index, value in enumerate(self.bucket):
            if value == key:
                return
        self.bucket.append(key)

    def get(self, key):
        if key in self.bucket:
            return True
        return False
    
    def remove(self, key):
        if key not in self.bucket:
            return
        self.bucket.remove(key)

class MyHashSet:

    def __init__(self):
        self.keyspace = 1024
        self.hash_table = [Bucket() for i in range(self.keyspace)]

    def add(self, key: int) -> None:
        hash_key = key%self.keyspace
        self.hash_table[hash_key].update(key)

    def remove(self, key: int) -> None:
        hash_key = key%self.keyspace
        self.hash_table[hash_key].remove(key)

    def contains(self, key: int) -> bool:
        hash_key = key%self.keyspace
        return self.hash_table[hash_key].get(key)
