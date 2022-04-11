#include <iostream>
#include <numeric>

int main() {
    int k = INT32_MAX, n = INT32_MAX, count = 0;
    uint32_t res = 0;

    while (n > 31) {
        std::cout << "Enter size (< 32) of multitude: ";
        std::cin >> n;
    }

    while (k > n) {
        std::cout << "Enter size (<= n) of subset: ";
        std::cin >> k;
    }

    for (int i = 0; i < k; i++)
        res |= 1 << i;

    int i;

    while (res < (1 << n)) {
        if (count == 0) {
            std::cout << "{ ";
            for (int j = 0; j < 32; j++)
                if (res & (1 << j))
                    std::cout << j << " ";
            std::cout << "} " << std::endl;

            i = 0;

            while (count == 0) {
                while (res & (1 << i)) {
                    res ^= (1 << i);
                    count++;
                    i++;
                }

                if (count == 0)
                    i++;
            }

            res ^= (1 << i);
            count--;
        } else {
            i = 0;

            while (count != 0) {
                res ^= (1 << i);
                count--;
                i++;
            }
        }
    }

    return 0;
}
