// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

// 实现 MinStack 类:

// MinStack() 初始化堆栈对象。
// void push(int val) 将元素val推入堆栈。
// void pop() 删除堆栈顶部的元素。
// int top() 获取堆栈顶部的元素。
// int getMin() 获取堆栈中的最小元素。
#include "../common.hh"

class MinStack {
 private:
  vector<int> vec_;
  vector<int> min_list_;

 public:
  void push(int val) {
    vec_.push_back(val);

    if (min_list_.empty())
      min_list_.push_back(val);
    else if (val < min_list_.back())
      min_list_.push_back(val);
    else
      min_list_.push_back(min_list_.back());
  }

  void pop() {
    min_list_.pop_back();
    vec_.pop_back();
  }

  int top() { return vec_.back(); }

  int getMin() { return min_list_.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */