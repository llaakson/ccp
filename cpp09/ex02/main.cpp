#include "PmergeMe2.hpp"
#include <sstream>
#include <chrono>

int main (int argc, char **argv){
    try {
    if (argc < 2){
        std::cout << "No argument given" << std::endl;
        return 0;
    }
    std::vector<int> aa;
    std::deque<int> sort_deque;
    for (int i = 1; i < argc; ++i) 
        {
            std::istringstream iss(argv[i]);
            std::string num;
            int numInt;
            while (iss >> num) 
            {
                numInt = stoi(num);
                if (numInt < 0)
                    throw std::runtime_error("negative numbers in input");
                aa.push_back(numInt);
                sort_deque.push_back(numInt);
            }
        }
    std::cout << "Before:  ";
    for (auto it = aa.begin(); it != aa.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    class PmergeMe Pmerge;
    class PmergeMe Pmerge2;
    const auto start_vector{std::chrono::steady_clock::now()};
    Pmerge.start(aa,1);
    const auto finish_vector{std::chrono::steady_clock::now()};
    std::chrono::duration<double> elapsed_seconds{finish_vector - start_vector};
    //std::cout << "Total comparisons: " << Pmerge.getComparison() << std::endl;

    const auto start_deque{std::chrono::steady_clock::now()};
    Pmerge2.start(sort_deque,1);
    const auto finish_deque{std::chrono::steady_clock::now()};
    std::chrono::duration<double> elapsed_seconds_deque{finish_deque - start_deque};
    //std::cout << "Total comparisons: " << Pmerge.getComparison() << std::endl;
    std::cout << "After:   ";
    for (auto it = aa.begin(); it != aa.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    std::cout << "Time to process a rage of: " << aa.size() << " elements with std::vector: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed_seconds) << std::endl;
    std::cout << "Time to process a rage of: " << sort_deque.size() << " elements with std::deque:  "<<std::chrono::duration_cast<std::chrono::microseconds>(elapsed_seconds_deque) << std::endl;
    } 
    catch (...){
        std::cout << "Error!" << std::endl;
    }
    
    return 0;
}

//  int main()
//  {
//       class PmergeMe Pmerge;

// // //     std::vector<int> basic = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};
// // //     Pmerge.start(basic,1);

// // //     std::vector<int> basicp = {4, 26, 11, 27, 18, 57, 48, 96, 65, 77, 43, 88, 9};
// // //     Pmerge.start(basicp,1);

// //     std::vector<int> basic14 = {1, 9, 10, 18, 6, 17, 13, 19, 3, 12, 4, 16, 5, 15, 8, 20, 7, 11, 2, 14 };
// //     Pmerge.start(basic14,1);
           
//     std::vector<int> basic89 = {4, 8, 1, 9, 5, 10, 6, 17, 2, 12, 13, 18, 3, 14, 11, 19, 15, 16, 7, 20};
//     Pmerge.start(basic89,1);


// //     // std::vector<int> basic89 = {5 ,14, 13, 15, 3, 11, 18, 19, 6, 10, 7, 12, 1, 16, 9, 20, 2, 8, 4, 17};
// //     // Pmerge.start(basic89,1);

// //         // std::vector<int> basic33 = {54, 60, 28, 87, 24, 37, 39, 90, 31, 33, 13, 41, 86, 89, 95, 99, 6, 12, 15, 16, 23, 68, 82, 97, 18, 70, 79, 98, 35, 75, 36, 100, 43};
// //         // Pmerge.start(basic33,1);
 

// // //     std::vector<int> basic89 = {10, 48, 52, 86, 28, 59, 38, 88, 7, 20, 12, 31, 80, 97, 24, 100, 56, 74, 8, 184, 45, 78};
// // //     Pmerge.start(basic89,1);

// //     //   std::vector<int> basic1 = {5,4,3,2,1,7,9};
// //     //    Pmerge.start(basic1,1);
// //     // std::vector<int> basic2 = {1,2,3,4,5};
// //     // Pmerge.start(basic2,1);
// //     // std::vector<int> basic33 = {3,2,1,99};
// //     // Pmerge.start(basic33,1);
// //     // std::vector<int> basic3 = {3,2,1};
// //     // Pmerge.start(basic3,1);
// //     // std::vector<int> basic4 = {3,2};
// //     // Pmerge.start(basic4,1);
// //     //  std::vector<int> basic5 = {3};
// //     // Pmerge.start(basic5,1);

// //     // std::vector<int> ultimate = {1112, 1857, 2462, 4066, 1562, 2508, 1370, 2087, 4577, 958, 2661, 4715, 4095, 4044, 1772, 4633, 3180, 933, 1490, 3007, 4356, 4095, 2067, 3299, 3631, 481, 4024, 1842, 4501, 3153, 3615, 65, 2376, 1973, 3741, 3488, 2961, 2322, 4753, 295, 4285, 2307, 4513, 4587, 3005, 304, 491, 2845, 1883, 2194, 1154, 1925, 4395, 2338, 2792, 2075, 2496, 2618, 3137, 4119, 3768, 4179, 2202, 4587, 2826, 1344, 2417, 3635, 4043, 2614, 916, 3779, 2611, 4728, 2667, 4254, 2087, 4619, 3823, 2920, 330, 2117, 1389, 4231, 2820, 2683, 3060, 1070, 2709, 4222, 380, 4260, 1083, 630, 2957, 4872, 916, 2894, 2265, 4951, 1188, 1709, 3623, 816, 2675, 1342, 2563, 1364, 445, 3178, 3311, 2295, 4044, 3407, 3110, 446, 1706, 1111, 2424, 352, 1590, 3336, 318, 813, 164, 474, 2999, 1083, 3837, 4490, 1687, 4295, 3031, 111, 843, 2541, 4071, 3609, 1218, 1994, 2748, 4393, 1538, 3669, 2632, 2476, 4028, 1316, 1177, 3929, 2182, 3396, 3117, 4218, 1687, 3674, 750, 4047, 2629, 3643, 2463, 4367, 2525, 2765, 195, 826, 4978, 661, 3873, 752, 2858, 3812, 557, 2857, 4124, 4422, 2045, 4980, 4197, 3243, 3668, 4805, 187, 4693, 303, 292, 1293, 2250, 2531, 4825, 489, 1917, 3436, 2533, 1100, 1735, 4402, 3825, 3993, 3668, 3955, 4649, 3268, 1028, 2200, 1510, 1891, 1191, 3996, 4424, 968, 1365, 2841, 3305, 4256, 4810, 1058, 3636, 2069, 4790, 556, 2910, 1489, 3307, 1919, 826, 78, 647, 3467, 1061, 3944, 2930, 3166, 957, 456, 2170, 972, 643, 2805, 4172, 1907, 1411, 3315, 4584, 3838, 2056, 1301, 4705, 580, 794, 4356, 3925, 2072, 4384, 2100, 946, 2617, 1508, 1694, 2078, 3517, 3519, 4740, 1647, 4500, 470, 1464, 2442, 2809, 1447, 2844, 3342, 2917, 262, 3899, 3855, 176, 2653, 4979, 4728, 2689, 878, 3446, 4142, 1390, 1514, 2766, 3716, 2746, 3480, 4643, 4433, 1714, 1497, 855, 3850, 1540, 2854, 4651};
// //     // Pmerge.start(ultimate,1);

// // //         std::vector<int> hundre = {3983, 89, 3491, 4056, 3324, 2630, 3287, 3947, 2748, 3860, 2596, 2294, 3428, 4781, 4420, 3135, 4531, 122, 3076, 1701, 2730, 3847, 617, 4411, 4977, 3992, 757, 3304, 4054, 625, 3886, 3965, 822, 728, 3268, 4050, 2123, 2434, 2829, 1480, 4219, 1977, 3960, 2115, 1204, 3692, 3487, 96, 1687, 1969, 1715, 3946, 2013, 654, 573, 4611, 629, 3272, 1656, 24, 27, 1650, 3357, 3259, 4787, 2906, 3120, 3938, 1291, 1067, 596, 3518, 3131, 880, 3993, 4850, 620, 3933, 1081, 4666, 2112, 1342, 2442, 838, 1500, 4378, 63, 495, 4194, 4907, 3848, 3105, 2540, 3079, 3449, 2601, 2209, 256, 3048, 3025};
// // //        Pmerge.start(hundre,1);     
//         std::cout << "Total comparisons: " << Pmerge.getComparison() << std::endl;
//      return 0;
//      }