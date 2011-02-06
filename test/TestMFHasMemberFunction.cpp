#include "TestMFHasMemberFunction.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((tti::mf_has_member_function
                <
                tti::has_member_function_VoidFunction<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<void>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_function
                <
                tti::FunctionReturningInt<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_function
                <
                tti::FunctionReturningInt<_,_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<double>,
                boost::mpl::vector<boost::mpl::identity<int> >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_function
                <
                tti::has_member_function_aFunction<_,_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<AType>,
                boost::mpl::vector<boost::mpl::identity<int> >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_function
                <
                tti::AnotherIntFunction<_,_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<int>,
                boost::mpl::vector<boost::mpl::identity<AType> >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_function
                <
                tti::has_member_function_sFunction<_,_,_>,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AnIntType<AType>,
                boost::mpl::vector
                  <
                  boost::mpl::identity<int>,
                  boost::mpl::identity<long>,
                  boost::mpl::identity<double> 
                  >
                >
              ::value
            ));
  
  return boost::report_errors();

  }
