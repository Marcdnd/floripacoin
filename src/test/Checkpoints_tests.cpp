//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
<<<<<<< HEAD
    uint256 p1500 = uint256("0x841a2965955dd288cfa707a755d05a54e45f8bd476835ec9af4402a2b59a2967");
    uint256 p120000 = uint256("0xbd9d26924f05f6daa7f0155f32828ec89e8e29cee9e7121b026a7a3552ac6131");
    BOOST_CHECK(Checkpoints::CheckBlock(1500, p1500));
    BOOST_CHECK(Checkpoints::CheckBlock(120000, p120000));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(1500, p120000));
    BOOST_CHECK(!Checkpoints::CheckBlock(120000, p1500));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(1500+1, p120000));
    BOOST_CHECK(Checkpoints::CheckBlock(120000+1, p1500));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 120000);
=======
    uint256 p11111 = uint256("0x0000000069e244f73d78e8fd29ba2fd2ed618bd6fa2ee92559f542fdb26e7c1d");
    uint256 p134444 = uint256("0x00000000000005b12ffd4cd315cd34ffd4a594f430ac814c91184a0d42d2b0fe");
    BOOST_CHECK(Checkpoints::CheckBlock(11111, p11111));
    BOOST_CHECK(Checkpoints::CheckBlock(134444, p134444));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(11111, p134444));
    BOOST_CHECK(!Checkpoints::CheckBlock(134444, p11111));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(11111+1, p134444));
    BOOST_CHECK(Checkpoints::CheckBlock(134444+1, p11111));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 134444);
>>>>>>> upstream/master
}    

BOOST_AUTO_TEST_SUITE_END()
