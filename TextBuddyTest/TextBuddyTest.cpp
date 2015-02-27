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
		}
		TEST_METHOD(AnotherTest) {
			
		}
	};
}