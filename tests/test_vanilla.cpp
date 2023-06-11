#include "test_log.h"

#include <gtest/gtest.h>


namespace {


class TestSPMCQueue: public ::testing::Test
{
protected:
    void SetUp() override
    {
        LOG_INFO("Hello World!\n");
        m_inited = true;
    }

protected:
    bool m_inited = false;
};


// Tests goes here
TEST_F(TestSPMCQueue, TestSetup) { GTEST_ASSERT_TRUE(this->m_inited); }


}   // GTest's anonymous namespace


// int main(int argc, char const *argv[])
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
