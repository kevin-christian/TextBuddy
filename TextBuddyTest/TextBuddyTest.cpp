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

		TEST_METHOD(SortAlphabetical) {
			TextBuddy tb("mytextfile.txt");
			tb.addText("mango");
			tb.addText("Apple");
			tb.addText("banana");
			tb.addText("Guava");
			tb.sortText();
			Assert::AreEqual("Apple", tb.getTextVector()[0].c_str());
			Assert::AreEqual("banana", tb.getTextVector()[1].c_str());
			Assert::AreEqual("Guava", tb.getTextVector()[2].c_str());
			Assert::AreEqual("mango", tb.getTextVector()[3].c_str());
		}

		TEST_METHOD(SortCaseInsensitive){
			TextBuddy tb("mytextfile.txt");
			tb.addText("Apple");
			tb.addText("apple");
			tb.addText("android");
			tb.addText("Apple");
			tb.sortText();
			Assert::AreEqual("android", tb.getTextVector()[0].c_str());
			Assert::AreEqual("Apple", tb.getTextVector()[1].c_str());
			Assert::AreEqual("apple", tb.getTextVector()[2].c_str());
			Assert::AreEqual("Apple", tb.getTextVector()[3].c_str());
		}

		TEST_METHOD(SortLongerVsShorterWord){
			TextBuddy tb("mytextfile.txt");
			tb.addText("Apple Pie");
			tb.addText("Apple");
			tb.addText("Applecake");
			tb.sortText();
			Assert::AreEqual("Apple", tb.getTextVector()[0].c_str());
			Assert::AreEqual("Apple Pie", tb.getTextVector()[1].c_str());
			Assert::AreEqual("Applecake", tb.getTextVector()[2].c_str());
		}

		TEST_METHOD(SortEmpty){
			TextBuddy tb("mytextfile.txt");
			Assert::AreEqual(0U, tb.getTextVector().size());
		}
	};
}