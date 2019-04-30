/*
 * 题目描述：
 *     定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数
 *     (时间复杂度应为O(1))。
 * 
 * 解题思路：
 *     使用两个栈，一个栈用作正常的pop和push操作，另一个栈来根据压栈或出栈的数据
 *     来更新其中记录的当前栈最小值。
 * 
 */

class Solution {
public:
    void push(int value) {
        if (stack1.size() == 0) {
            stack1.push(value);
            stack2.push(value);
        } else {
            stack1.push(value);
            int min = stack2.top();
            if (min>=value)
                stack2.push(value);
        }
    }
    void pop() {
        assert(stack1.size()>0 && stack2.size()>0);
        int pop = stack1.top();
        stack1.pop();
        if (pop == stack2.top())
            stack2.pop();
    }
    int top() {
        assert(stack1.size()>0);
        return stack1.top();
    }
    int min() {
        assert(stack2.size()>0);
        return stack2.top();
    }
    stack<int> stack1;
    stack<int> stack2;
};