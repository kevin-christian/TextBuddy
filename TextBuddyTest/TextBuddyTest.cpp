#include "stdafx.h"
#include "CppUnitTest.h"
#include "TextBuddy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest
{		
	TEST_CLASS(TextBuddyTest)
	{
	public:
		
		TEST_METHOD(SearchTest)
		{
			TextBuddy tb("mytextfile.txt");
			tb.addText("Little Brown Fox");
			tb.addText("jumped over the lazy dog");
			tb.addText("white fox");
			tb.addText("played with firefox");
			tb.addText("on top of the tree");
			Assert::AreEqual("played with firefox", tb.searchText("fox")[1].c_str());
			Assert::AreEqual("white fox", tb.searchText("fox")[0].c_str());
			Assert::AreEqual("on top of the tree", tb.searchText("the")[1].c_str());
			Assert::AreEqual("jumped over the lazy dog", tb.searchText("the")[0].c_str());
		}
		
		TEST_METHOD(SearchNotFound)
		{
			TextBuddy tb("mytextfile.txt");
			tb.addText("Little Brown Fox");
			tb.addText("jumped over the lazy dog");
			tb.addText("white fox");
			tb.addText("played with firefox");
			tb.addText("on top of the tree");
			Assert::AreEqual(0U, tb.searchText("cat").size());
		}
		
		TEST_METHOD(SearchEmpty)
		{
			TextBuddy tb("mytextfile.txt");
			Assert::AreEqual(0U, tb.searchText("something").size());
		}

		TEST_METHOD(SortTest) {
			TextBuddy tb("mytextfile.txt");
			tb.addText("Mango");
			tb.addText("Apple");
			tb.addText("Banana");
			tb.addText("Cherry");
			tb.addText("apple");
			tb.addText("banana split");
			tb.addText("cherish");
			tb.sortText();
			Assert::AreEqual("Apple", tb.getTextVector()[0].c_str());
			Assert::AreEqual("apple", tb.getTextVector()[1].c_str());
			Assert::AreEqual("Banana", tb.getTextVector()[2].c_str());
			Assert::AreEqual("banana split", tb.getTextVector()[3].c_str());
			Assert::AreEqual("cherish", tb.getTextVector()[4].c_str());
			Assert::AreEqual("Cherry", tb.getTextVector()[5].c_str());
			Assert::AreEqual("Mango", tb.getTextVector()[6].c_str());
		}
	};
}