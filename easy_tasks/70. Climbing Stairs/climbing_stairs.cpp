#include <iostream>
#include <vector>
#include <memory>

struct Branch
{
    //TREBAJU IMAT PARENTA
    //DA SE IMAJU KAKO VRACATI PO STABLU
    int m_left_steps;
    std::unique_ptr<Branch> m_children[2];
    Branch(){}
    Branch(int left_steps)
    {
        m_left_steps = left_steps;
        generate_children(left_steps);
    }
    void generate_children(int left_steps)
    {
        if (left_steps > 1)
        {
            m_children[0] = std::make_unique<Branch>(left_steps- 1);
            m_children[1] = std::make_unique<Branch>(left_steps - 2);
        }
        else if (left_steps == 1)
        {
            m_children[0] = std::make_unique<Branch>(left_steps - 1);
            m_children[1] = nullptr;
        }
    }
};

struct Tree
{
    int m_steps;
    int m_steps_combinations = 0;
    std::vector<std::unique_ptr<Branch>> m_nodesToVisit;
    //only 2 branches needed since there are only 2 possible steps
    std::unique_ptr<Branch> root;
    Tree(int steps)
    {
        m_steps = steps;
    }
    void generate_tree() 
    {
        root = std::make_unique<Branch>(m_steps);
    }
    int count_steps_combinations()
    {
        m_nodesToVisit.push_back(std::move(root));
        Branch* currentNode = m_nodesToVisit.back().get();
        //when you reach node, increment for 1 and hop back to parent
        while(m_nodesToVisit.size() > 0)
        {
            currentNode = m_nodesToVisit.back().get();
            if (!currentNode->m_children[0] && !currentNode->m_children[1])
            {
                if (currentNode->m_left_steps == 0) m_steps_combinations++;
                m_nodesToVisit.back() = nullptr;
                m_nodesToVisit.pop_back();
            }
            else
            {
                if (currentNode->m_children[0].get()) m_nodesToVisit.push_back(std::move(currentNode->m_children[0]));
                if (currentNode->m_children[1].get()) m_nodesToVisit.push_back(std::move(currentNode->m_children[1]));
            }
        }
        return m_steps_combinations;
    }
};

int climbStairs(int n) 
{
    return 1;        
}

int main()
{
    // int n = 3;
    Tree t{35};
    std::cout << "Sucessful build\n";
    t.generate_tree();
    std::cout << "Result: " << t.count_steps_combinations();
    return 0;
}