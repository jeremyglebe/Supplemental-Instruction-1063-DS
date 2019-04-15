template <class T>
class Stack
{
  private:
    T *items;
    int top_index;
    int max_size;

  public:
    Stack(int size)
    {
        items = new T[size];
        top_index = -1;
        max_size = size;
    }
    void push(T item)
    {
        try
        {
            if (top_index < max_size - 1)
            {
                items[++top_index] = item;
            }
            else
            {
                throw std::invalid_argument("pushed to a full stack");
            }
        }
        catch (std::exception &e)
        {
            std::cerr << "\nexception: " << e.what() << std::endl;
        }
    }
    T pop()
    {
        try
        {
            if (top_index >= 0)
            {
                T result = items[top_index--];
                return result;
            }
            else
            {
                throw std::invalid_argument("popped from an empty stack");
            }
        }
        catch (std::exception &e)
        {
            std::cerr << "\nexception: " << e.what() << std::endl;
            return T();
        }
    }
};