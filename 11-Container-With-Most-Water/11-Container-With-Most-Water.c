int maxArea(int* height, int heightSize){
    int head, tail, max, length, width, area;
    
    if (height == NULL)
        return 0;
    
    if (heightSize < 2)
        return 0;
    
    width = heightSize - 1;
    head = 0;
    tail = width;
    max = 0;
    while (tail > head) {
        if (height[head] <= height[tail]) {
            length = height[head];
            while (tail > head && height[++head] <= length);
               
        } else {
            length = height[tail];
            while (tail > head && height[--tail] <= length);
        }

        area = width * length;
        if (area > max)
            max = area;
        
        width = tail - head;
    }
    
    return max;
}