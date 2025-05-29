// https://leetcode.com/problems/happy-number/description/

private:
    int sumOfSquare(int n){
        int sum = 0;
        while(n > 0){
            int x = n% 10;
            n = n/10;
            sum += x*x;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = 0;
        int fast = 0;

        if(n == 1){
            return true;
        }

        // 7 -> 49 -> 106 -> 37 -> 90 -> 81 -> 67 -> 

        slow = sumOfSquare(n);
        fast = sumOfSquare(sumOfSquare(n));

        while(fast != 1 && slow != fast){
            slow = sumOfSquare(slow);
            fast = sumOfSquare(sumOfSquare(fast));
            if(slow == fast){
                return false;
            }
        }

        return fast == 1;
    }