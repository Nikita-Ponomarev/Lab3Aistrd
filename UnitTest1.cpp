#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../LAB3Aistrd2.0/Header.h"
#include "\Users\Никита\source\repos\LAB3Aistrd2.0\LAB3Aistrd2.0\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(insert)
		{
			Tree* tree = new Tree();
			Tree* tree2 = new Tree();
			tree->get_root(10);
			tree->insert(5);
			tree->insert(15);
			tree->insert(100);
			tree->insert(20);

			tree2->get_root(10);
			tree2->insert(5);
			tree2->insert(15);
			tree2->insert(100);
			tree2->insert(20);

			tree->create_queue();
			tree2->create_queue();
			Iterator* iter;
			iter = tree->create_bft_iterator();
			Iterator* iter2;
			iter2 = tree2->create_bft_iterator();
			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(iter2->next(), iter->next());
			}
			tree->deleting_tree();
			tree2->deleting_tree();
		}

		TEST_METHOD(remove)
		{
			Tree* tree = new Tree();
			Tree* tree2 = new Tree();
			tree->get_root(10);
			tree->insert(5);
			tree->insert(15);
			tree->insert(100);
			tree->insert(20);
			tree->remove(20);

			tree2->get_root(10);
			tree2->insert(5);
			tree2->insert(15);
			tree2->insert(100);

			tree->create_queue();
			tree2->create_queue();
			Iterator* iter;
			iter = tree->create_bft_iterator();
			Iterator* iter2;
			iter2 = tree2->create_bft_iterator();
			for (int i = 0; i < 3; i++)
			{
				Assert::AreEqual(iter2->next(), iter->next());
			}
			tree->deleting_tree();
			tree2->deleting_tree();
		}

		TEST_METHOD(contains)
		{
			Tree* tree = new Tree();
			tree->get_root(10);
			tree->insert(5);
			tree->insert(15);
			tree->insert(100);
			tree->insert(20);

			Assert::AreEqual(true, tree->contains(15));
		}
	};
}
