#include <iostream>
#include <vector>

struct Branch
{
    //TREBAJU IMAT PARENTA
    //DA SE IMAJU KAKO VRACATI PO STABLU
    int m_left_steps;
    Branch* m_children[2] = {nullptr, nullptr};
    Branch(int left_steps)
    {
        m_left_steps = left_steps;
        generate_children(left_steps);
    }
    void generate_children(int left_steps)
    {
        if (left_steps > 1)
        {
            m_children[0] = new Branch(left_steps- 1);
            m_children[1] = new Branch(left_steps - 2);
        }
        else if (left_steps == 1)
        {
            m_children[0] = new Branch(left_steps - 1);
            m_children[0] = nullptr;
        }
    }
};

struct Tree
{
    int m_steps;
    int m_steps_combinations = 0;
    //only 2 branches needed since there are only 2 possible steps
    Branch* m_branches[2];
    void generate_tree() 
    {
        m_branches[0] = new Branch{m_steps - 1};
        m_branches[1] = new Branch{m_steps - 2};
    }
    int count_steps_combinations()
    {
        Branch* child1;
        Branch* child2;
        while(child1 || child2)
        {

        }
    }
};

int climbStairs(int n) 
{
    return 1;        
}

int main()
{
    // int n = 3;
    Tree t{3};
    std::cout << "Sucessful build\n";
    t.generate_tree();
    // std::cout << "Result: " << climbStairs(n);
    return 0;
}