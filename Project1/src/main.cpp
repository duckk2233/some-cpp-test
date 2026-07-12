#include <iostream>//输入输出流
#include <mutex>
#include <ostream>//输出流
#include <random>
#include <string>//string类
#include <cstdlib>//malloc等
#include <memory>//智能指针
#include <cstring>//c风格字符串工具
#include <cstddef>//size_t，nullptr等数据与数据类型
#include <vector>//vector数组
#include <functional>//函数指针
#include <thread>//线程
//#include <chrono>//计时器
#include <algorithm>//一些小众算法（？
#include <tuple>//元组，处理多返回值
#include <optional>//可选返回值
#include <variant>//多类型变量
#include <any>//任意类型变量
#include <fstream>//文件输入流
#include <future>//并行处理
#include "include/DTools.h"
#include "include/Timer.h"
#include "include/Log.h"
#include "../../external/glfw/include/GLFW/glfw3.h"

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    Entity()
        : x(10), y(10)
    {}
    Entity(int x, int y)
        : x(x), y(y)
    {}
    ~Entity()
    {}
public:
    std::string GetClassName() override 
    {
        return "Entity";
    }

    int GetX() const
    {
        return x;
    }
    int GetY() const
    {
        return y;
    }

private:
    int x, y;
};

class Player : public Entity
{
public:
    explicit Player(const char* name, int x, int y)
        :x(x), y(y), name(name)
    {}
public:
    std::string GetClassName() override
    {
        return name;
    }
private:

    std::string name;
    int x, y;
};

class Test
{
public:
    Test(int x, int y, int z)
        :x(x), y(y), z(z)
    {
        testLog.InfoOff();
        testLog.Info("Test construct");
    }
    ~Test()
    {
        testLog.Info("Test destruct");
    }
    Test(const Test& other)
        :x(other.x), y(other.y), z(other.z)
    {
        testLog.Info("Test copy construct");
    }
public:
    friend std::ostream& operator<<(std::ostream& os, const Test& other)
    {
        return os << other.x << " " << other.y << " " << other.z;
    }
public:
    void Said() const
    {
        std::cout << "sb" << std::endl;
    }
public:
    int x, y, z;
    Log testLog;
};

void PrintName(Printable* print)
{
    std::cout << print->GetClassName() << std::endl;
}

static std::mutex printFuncLock;
void SearchChar(const std::string& word = "duckkk", char needSearch = 'd')
{
    std::lock_guard<std::mutex> lock(printFuncLock);
    if(word.find(needSearch) != std::string::npos)
    {
        std::cout << "the position of '" << needSearch << "' in '" << word << "' is on the position " << word.find(needSearch) << std::endl;
    }
    else
    {
        std::cout << "can't find '" << needSearch << "' in '" << word << "'" << std::endl;
    }
}


void ForEach(std::vector<int>& vec, std::function<void(int&)> func)
{
    for(int& mem : vec)
    func(mem);
}

std::tuple<int, std::string> CreatPerson()
{
    return { 114, "duckk" };
}

std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
    std::ifstream fstream(filepath);
    if(fstream)
    {
        std::string result;
        std::getline(fstream, result);
        fstream.close();
        return result;
    }
    else
        return {};
}

static bool finished = 0;
void work1()
{
    using namespace std::literals::chrono_literals;
    while(!finished)
    {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    Timerm* mainTimer = new Timerm("mainTimer");
    Log mainLog;
    mainLog.ErrOff();
    mainLog.Info("i dont know what to write so i write this");
    mainLog.Err("i dont know what to write so i write this");
    mainLog.SwitchState();

    {
        Vector3 position(1, 2, 3);
        Vector3 speed(2, 5, 7);
        Vector3 result = position + speed;
        std::cout << result << "\n";
        Vector3 powerUp(1.1, 1.1, 1.1);
        Vector3 result2 = position + speed * powerUp;
        std::cout << result2 << "\n";
        Vector3 test(1.1, 1.1, 1.1);
        std::cout << (position == speed) << " " << (position != speed) << "\n";
        std::cout << (test == powerUp) << "\n";
    }//vector3类使用例&常规运算符重载

    std::cout << "sb1" << "sb2" << std::endl;
    std::endl(std::operator<<(operator<<(std::cout, "sb1"), "sb2"));//运算符实质（函数）

    std::cout << glfwInit() << std::endl;

    mainTimer->Stop();

    {
        std::unique_ptr<Test> i = std::make_unique<Test>(10, 10, 10);
        i->Said();
        std::shared_ptr<Test> i1 = std::make_shared<Test>(10, 10, 10);
        {
            std::shared_ptr<Test>i2 = i1;
        }
    }//智能指针使用例

    {
        String name = "duckkk";
        String name2 = name;
        std::cout << name << std::endl;
        std::cout << name2 << std::endl;
        name2[3] = 'a';
        std::cout << name2 << std::endl;
    }//string类使用例&下标运算符，赋值运算符重载

    {
    ScopedPtr<Test> test1(new Test(2, 2, 2)); // < cpp17,or
    ScopedPtr test2(new Test(2, 2, 2)); // >= cpp17
    test2->Said();
    const ScopedPtr<Test> test3(new Test(25, 25, 25));
    test3->Said();
    }//scoped_ptr模板类使用例

    {
        std::vector<Test> test4;
        test4.reserve(3);
        test4.emplace_back(1, 2, 3);
        test4.emplace_back(4, 5, 6);
        for(size_t i{}; i < test4.size(); ++i) { std::cout << test4[i] << std::endl; }
        test4.emplace_back(7, 8, 9);
        for(Test& t : test4) { std::cout << t << std::endl; }
        test4.erase(test4.begin() + 2);
    }//std::vector类示例，优化方式

    {
        std::vector<int> intVec1 = {1, 2, 3, 5};
        ForEach(intVec1, [](int& mem) { std::cout << mem << " "; });
        std::cout << "\n";
        ForEach(intVec1, [](int& mem) { mem++; });
        ForEach(intVec1, [](int& mem) { std::cout << mem << " "; });
        std::cout << "\n";
    }//函数指针&lumbda语句示例

    std::cout << "<(°O°)>" << std::endl;

    {
        std::vector<int> vec1 = {7, 4, 1, 2, 1, 8,4};
        std::sort(vec1.begin(), vec1.end(), [](int& a, int& b)
        {
            if(a == 1)
                return 1;
            else
                return 0;
        });
        for(int i : vec1)
            std::cout << i << " ";
        std::cout << "\n";
    }//使用std::sort进行自定义vector数组排序方法

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dice(1, 100);
    dice(rng);//随机数

    std::cout << "<(°O°)>" << std::endl;

    auto[age, name] = CreatPerson();//结构化绑定

    {
    std::optional<std::string> data = ReadFileAsString("data.txt");
    std::cout << data.value_or("read unsuccessful") << std::endl;//optional可选返回值示例&fstream使用例

    std::variant<std::string, int> var;
    var = "hyz";
    if(auto data1 = std::get_if<std::string>(&var); data)
        std::cout << *data1 << std::endl;//variant多类型变量示例

    std::any data3;
    data3 = 20;
    data3 = "sb";
    data3 = std::string("sb");
    std::cout << any_cast<std::string>(data3) << std::endl;//any任意变量示例
    }//多类型数据三部曲

    delete mainTimer;

    {
        std::thread worker1(work1);
        std::cin.get();
        finished = 1;
        worker1.join();
    }//线程创建示例

    {
        Timerm scopeTimer("scopeTimer");

        std::ifstream fstream("strings.txt");
        std::string line;
        std::vector<std::string> strings;
        std::vector<std::future<void>> vecSearchChar;
        size_t failReturn = 114514;
        if(fstream)
        {
            while(std::getline(fstream, line))
                strings.emplace_back(line);
#if 1
            for(std::string str : strings)
                vecSearchChar.emplace_back(std::async(std::launch::async, SearchChar, str, 'g'));
#else
            for(std::string str : strings)
            {
                SearchChar(str, 'g');
            }
#endif
        }
        else
            std::cout << "\"strings.txt\" open failly" << std::endl;
        fstream.close();
    }//并行处理示例
}