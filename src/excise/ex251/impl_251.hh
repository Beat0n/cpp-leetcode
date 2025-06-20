// 请设计并实现一个能够展开二维向量的迭代器。该迭代器需要支持 next 和 hasNext
// 两种操作。

// 实现 Vector2D 类：

// Vector2D(int[][] vec) 使用二维向量 vec 初始化对象
// next() 从二维向量返回下一个元素并将指针移动到下一个位置。你可以假设对 next
// 的所有调用都是合法的。 hasNext() 当向量中还有元素返回 true，否则返回 false。

#include "../common.hh"

class Vector2D {
private:
  vector<vector<int>> vec_;
  vector<vector<int>>::iterator row_iter;
  vector<int>::iterator col_iter;

public:
  Vector2D(vector<vector<int>> &vec) {
    this->vec_.clear();
    for (const auto &v : vec) {
      if (!v.empty()) {
        this->vec_.push_back(v);
      }
    }
    this->row_iter = this->vec_.begin();
    if (!this->vec_.empty()) {
      this->col_iter = this->vec_.begin()->begin();
    }
  }

  int next() {
    int ret = *this->col_iter;
    this->col_iter++;
    if (this->col_iter == this->row_iter->end()) {
      this->row_iter++;
      if (row_iter != this->vec_.end()) {
        this->col_iter = this->row_iter->begin();
      }
    }
    return ret;
  }

  bool hasNext() const {
    if (this->row_iter == this->vec_.end()) {
      return false;
    }
    if (this->col_iter == this->row_iter->end()) {
      auto row_iter = this->row_iter;
      row_iter++;
      return row_iter != this->vec_.end();
    } else {
      return true;
    }
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */