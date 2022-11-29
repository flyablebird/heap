// heap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <type_traits>

#include "MaxHeap.hpp"

template <template <typename T> class C,typename T>
void print(const C<T> &c)
{
	for (auto x : c)
	{
		std::cout << x << "\t";
	}
	std::cout << std::endl;
}

template <typename T,typename Cmp = std::greater<T>>
void test(std::vector<T>& c)
{
	auto hp = BaseHeap<typename std::remove_reference_t<decltype(c)>::iterator,Cmp>(c.begin(), c.end());
	hp.Sort();
	print<std::vector,int>(c);
}

template <typename T,typename Cmp = std::greater<T>>
void test(std::initializer_list<T> l)
{
	std::vector<T> c(l);
	test<T,Cmp>(c);
}

int main()
{

	//test({8,1,2,3,4,5});
	//test({300,10,40,50,8,4,55});
	//test({100,101,300,305});
	//test({8,7,6,5,4,3,2,1});



	test<int,std::less<int>>({9,5,3,7,10});
	test<int,std::less<int>>({100,300,105,7,20,30,40,10});
	test({100,5,200,3,105,7});

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
