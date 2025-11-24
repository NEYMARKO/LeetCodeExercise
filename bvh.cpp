#include <iostream>
#include <array>
#include <memory>
#include <ostream>
#include <vector>

struct Position
{
    float x;
    float y;
    float z;
    Position operator-(const Position& pos)
    {
        return Position{x - pos.x, y - pos.y, z - pos.z};
    }
    Position operator+(const Position& pos)
    {
        return Position{x + pos.x, y + pos.y, z + pos.z};
    }
    Position operator*(float s)
    {
        return Position{x * s, y * s, z * s};
    }
    
};

inline std::ostream& operator<<(std::ostream& os, const Position& p)
{
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")\n"; 
    return os;
}
class Quadrant
{
public:
    Position m_center_position;
    float m_dimension{-1.0f};
    int m_level{-1};
    std::array<std::unique_ptr<Quadrant>, 8> m_children;
    Quadrant() :  m_center_position{Position{0,0,0}}, m_dimension {-1.0f}, m_level{-1}
    {}
    Quadrant(int level, int max_depth, float dimension, Position center_pos) : 
    m_dimension {dimension}, m_level {level}, m_center_position{center_pos}
    {
        if (level != max_depth)
        {
            make_children(m_center_position, m_dimension, max_depth);
        }
    }    
    void make_children(Position center_pos, float dimension, int max_depth)
    {
        float child_dim = dimension / 2;
        m_children[0] = std::make_unique<Quadrant>(m_level + 1, max_depth, child_dim, m_center_position + Position{- child_dim / 2, - child_dim / 2, child_dim / 2});
        m_children[1] = std::make_unique<Quadrant>(m_level + 1, max_depth, child_dim, m_center_position + Position{child_dim / 2, - child_dim / 2, child_dim / 2});
        m_children[2] = std::make_unique<Quadrant>(m_level + 1, max_depth, child_dim, m_center_position + Position{- child_dim / 2, child_dim / 2, child_dim / 2});
        m_children[3] = std::make_unique<Quadrant>(m_level + 1, max_depth, child_dim, m_center_position + Position{child_dim / 2, child_dim / 2, child_dim / 2});
        m_children[4] = std::make_unique<Quadrant>(m_level + 1, max_depth, child_dim, m_center_position + Position{- child_dim / 2, - child_dim / 2, - child_dim / 2});
        m_children[5] = std::make_unique<Quadrant>(m_level + 1, max_depth, child_dim, m_center_position + Position{child_dim / 2, - child_dim / 2, - child_dim / 2});
        m_children[6] = std::make_unique<Quadrant>(m_level + 1, max_depth, child_dim, m_center_position + Position{- child_dim / 2, child_dim / 2, - child_dim / 2});
        m_children[7] = std::make_unique<Quadrant>(m_level + 1, max_depth, child_dim, m_center_position + Position{child_dim / 2, child_dim / 2, - child_dim / 2});
    }
};

class BVH
{
    int m_depth {2};
    float m_quadrant_size{2.0f};
public:
    std::unique_ptr<Quadrant> m_root = std::make_unique<Quadrant>(0, m_depth, m_quadrant_size, Position{0,0,0});
    BVH() = default;
};

int main()
{
    BVH bvh;

    std::vector<Quadrant*> queue;
    queue.push_back(bvh.m_root.get());

    while (queue.size() > 0)
    {
        Quadrant* temp_var = queue.back();
        queue.pop_back();
        std::cout << "Quadrant level: " << temp_var->m_level << "\n";
        std::cout << "Position:" << temp_var->m_center_position << "\n";
        for (const std::unique_ptr<Quadrant>& q : temp_var->m_children)
        {
            if (q.get() != nullptr)
            {
                queue.push_back(q.get());
            }
        }
        // queue.pop_back();
    } 
    // for (const std::unique_ptr<Quadrant>& q : bvh.m_root.m_children)
    // {
    //     std::cout << "Quadrant level: " << q.get()->m_level << "\n";
    //     std::cout << "Position:" << q.get()->m_center_position << "\n";
    // }
    return 0;
}