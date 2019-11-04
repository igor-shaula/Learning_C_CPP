// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//

int power(int x, unsigned p) {
    int answer;
    if(p > 1) {
        answer = x;
        for(int i = p; i > 1; i--) {
            answer *= x;
        }
    } else if (p == 1) {
        return answer = x;
    } else if(p == 0) {
        return 1;
    } else return -1;
    return answer;
}