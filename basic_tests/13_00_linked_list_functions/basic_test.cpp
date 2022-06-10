#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/linked_list_functions/linked_list_functions.h"



//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//------------------------------------------------------------------------------

using namespace std;

bool basic_test(bool debug = false)
{
  node<int>* head = nullptr;
  node<int>* marker;
  node<int>* buffer;

  buffer = _insert_after(head, head, 77);
  cout << "_insert_after: " << buffer->_item << endl;

  buffer = _insert_head(head, 99);
  cout << "_insert_head: " << buffer->_item << endl;
  marker = head;
  
  buffer = _insert_after(head, head, 88);
  cout << "_insert_after: " << buffer->_item << endl;
  
  marker = marker->_next->_next; // marker is 77
  buffer = _insert_after(head, marker, 55);
  cout << "_insert_after: " << buffer->_item << endl;

  marker = marker->_next; // marker is 55
  buffer = _insert_before(head, marker, 66);
  cout << "_insert_before: " << buffer->_item << endl;
  _print_list(head);
  cout << endl;

  cout << "_previous_node: " << _previous_node(head, marker)->_item << endl;
  cout << "_delete_node: " << _delete_node(head, marker) << endl;
  _print_list(head);
  cout << endl;

  cout << "_search_list: " << _search_list(head, 77)->_item << endl;
  if (!_search_list(head, 11)) {
    cout << "11 is not in the list\n";
  }
  cout << endl;

  buffer = _copy_list(head);
  cout << "_copy_list:\n";
  cout << "buffer: ";
  _print_list(buffer);
  cout << "head  : ";
  _print_list(head);
  cout << endl;

  marker = head->_next; // marker is 44
  _insert_after(head, marker, 44);
  cout << "modify head linked list, buffer is not changed:\n";
  cout << "buffer: ";
  _print_list(buffer);
  cout << "head  : ";
  _print_list(head);
  cout << endl;

  _clear_list(buffer);
  if(!buffer) {
    cout << "buffer is cleared\n";
  }
  cout << endl;

  cout << "_at 2 is " << _at(head, 2) << endl << endl;

  cout << "last node is " << _last_node(head)->_item << endl;

  cout << "\n\n-------- DONE ---------\n\n" << endl;
  return true;
}


//Lord help me! 
bool debug = false;

TEST(BASIC_TEST, BasicTest)
{
  bool success = basic_test(debug);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv)
{
  if (argc>1){
    debug = argv[1][0]=='t';
  }
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*
13_00_linked_list_functions git:(master)  😊 $> tree includes
includes
├── linked_list_functions
│   └── linked_list_functions.h
└── node
    └── node.h
2 directories, 2 files
13_00_linked_list_functions git:(master)  😊 $> ./build/bin/basic_test
----------running basic_test.cpp---------
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest
_insert_after: 77
_insert_head: 99
_insert_after: 88
_insert_after: 55
_insert_before: 66
[99]->[88]->[77]->[66]->[55]->|||

_previous_node: 66
_delete_node: 55
[99]->[88]->[77]->[66]->|||

_search_list: 77
11 is not in the list

_copy_list:
buffer: [99]->[88]->[77]->[66]->|||
head  : [99]->[88]->[77]->[66]->|||

modify head linked list, buffer is not changed:
buffer: [99]->[88]->[77]->[66]->|||
head  : [99]->[88]->[44]->[77]->[66]->|||

buffer is cleared

_at 2 is 44

last node is 66

-------- DONE ---------


[       OK ] BASIC_TEST.BasicTest (1 ms)
[----------] 1 test from BASIC_TEST (1 ms total)
[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
*/
