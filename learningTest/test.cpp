#include "pch.h"
#include "../fastMatrix/matrix.h"

namespace {
	namespace matrixTest {
		namespace matrixIsEqual {
			TEST(matrixTest, matrixIsEqual) {

				std::vector< std::vector<int> > matAdata{
					{1,2},
					{3,4},
				};

				std::vector< std::vector<int> > matBdata{
					{1,2},
					{3,4},
				};

				std::vector< std::vector<int> > matCdata{
					{5,6,7},
					{10,8,9},
				};

				matrix A(matAdata);
				matrix B(matBdata);
				matrix C(matCdata);

				EXPECT_EQ(A, A);
				EXPECT_EQ(A, B);
				//EXPECT_EQ(C, D);
			}
		}
	}
}