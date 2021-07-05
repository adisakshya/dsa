"""
You are playing a video game where you are defending your city from a group of n monsters. You are given a 0-indexed integer array dist of size n, where dist[i] is the initial distance in meters of the ith monster from the city.
The monsters walk toward the city at a constant speed. The speed of each monster is given to you in an integer array speed of size n, where speed[i] is the speed of the ith monster in meters per minute.
The monsters start moving at minute 0. You have a weapon that you can choose to use at the start of every minute, including minute 0. You cannot use the weapon in the middle of a minute. The weapon can eliminate any monster that is still alive. You lose when any monster reaches your city. If a monster reaches the city exactly at the start of a minute, it counts as a loss, and the game ends before you can use your weapon in that minute.
Return the maximum number of monsters that you can eliminate before you lose, or n if you can eliminate all the monsters before they reach the city.

Source - https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
"""

"""
Time Complexity - O(nLogn)
    - computing time vector in O(n)
    - sorting in O(nLogn)
Space Complexity - O(n)
    - size of time vector is n
"""

class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        # Find order in which Monsters will arrive
        n = len(dist)
        times = [dist[i]/speed[i] for i in range(n)]
        times.sort()
        # Simulating the situation
        i = 0                                   # i-th minute
        while i < n:                            # every minute we kill one monster in order
            if times[i] <= i:                   # while currentTime < it's arival time
                # i monsters can be killed
                return i
            i += 1
        # All monsters can be killed
        return n

