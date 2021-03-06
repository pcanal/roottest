# File: roottest/python/cpp11/PyROOT_cpptests.py
# Author: Wim Lavrijsen (LBNL, WLavrijsen@lbl.gov)
# Created: 11/25/13
# Last: 11/26/13

"""C++11 language interface unit tests for PyROOT package."""

import sys, os, unittest
sys.path.append(os.path.dirname(os.path.dirname(__file__)))

import ROOT
from ROOT import TGraphErrors, gROOT
from common import *

__all__ = [
   'Cpp1Cpp11StandardClassesTestCase',
   'Cpp2Cpp11LanguageConstructsTestCase'
]

gROOT.LoadMacro( "Cpp11Features.C+" )

MyCounterClass = ROOT.MyCounterClass
CreateMyCounterClass = ROOT.CreateMyCounterClass

### C++11 standard library classes ===========================================
class Cpp1Cpp11StandardClassesTestCase( MyTestCase ):
   def test01SharedPtr( self ):
      """Test usage and access of std::shared_ptr<>"""

    # proper memory accounting
      self.assertEqual( MyCounterClass.counter, 0 )

      ptr1 = CreateMyCounterClass()
      self.assert_( not not ptr1 )
      self.assertEqual( MyCounterClass.counter, 1 )

      ptr2 = CreateMyCounterClass()
      self.assert_( not not ptr2 )
      self.assertEqual( MyCounterClass.counter, 2 )

      del ptr2, ptr1
      import gc; gc.collect()
      self.assertEqual( MyCounterClass.counter, 0 )


### C++11 language constructs test cases =====================================
class Cpp2Cpp11LanguageConstructsTestCase( MyTestCase ):
   def test01StaticEnum( self ):
      """Test usage and access of a const static enum defined in header"""

      # TODO: this will fail
      # self.assert_( hasattr( PyTest, '_Lock_policy' ) )
      if not FIXCLING:
         self.assert_( hasattr( PyTest, '_S_single' ) )
         self.assert_( hasattr( PyTest, '__default_lock_policy' ) )

   def test02NULLPtrPassing( self ):
      """Allow the programmer to pass NULL in certain cases"""
      
      nullptr = ROOT.nullptr

      self.assertNotEqual( nullptr, 0 )
      if os.environ.get('EXP_PYROOT') == 'False':
         # In new Cppyy, TGraphErrors(0,0,0) is accepted.
         # I.e. it is allowed to pass 0 when the argument is of pointer type.
         self.assertRaises( TypeError, TGraphErrors, 0, 0, 0 )

      g = TGraphErrors( 0, nullptr, nullptr )
      self.assertEqual( round( g.GetMean(), 8 ), 0.0 )

 
## actual test run
if __name__ == '__main__':
   from MyTextTestRunner import MyTextTestRunner

   loader = unittest.TestLoader()
   testSuite = loader.loadTestsFromModule( sys.modules[ __name__ ] )

   runner = MyTextTestRunner( verbosity = 2 )
   result = not runner.run( testSuite ).wasSuccessful()

   sys.exit( result )
