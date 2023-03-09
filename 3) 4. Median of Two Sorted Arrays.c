//https://leetcode.com/problems/median-of-two-sorted-arrays/

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

//C Solution

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int low = 0, high = nums1Size;
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (nums1Size + nums2Size + 1) / 2 - partitionX;
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
        int minRightX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
        int minRightY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((nums1Size + nums2Size) % 2 == 0) {
                return ((double) fmax(maxLeftX, maxLeftY) + fmin(minRightX, minRightY)) / 2;
            }
            else {
                return (double) fmax(maxLeftX, maxLeftY);
            }
        }
        else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        }
        else {
            low = partitionX + 1;
        }
    }
    return 0;
}
