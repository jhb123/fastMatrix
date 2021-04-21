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

				std::vector< std::vector<int> > matIdata{
					{1,0},
					{0,1},
				};

				matrix<int> A(matAdata);
				matrix<int> B(matBdata);
				matrix<int> C(matCdata);
				matrix<int> I(matCdata);

				EXPECT_EQ(A, A);
				EXPECT_EQ(A, B);
				//EXPECT_EQ(C, D);
			}

			TEST(matrixTest, identityMulitplication) {

				std::vector< std::vector<int> > A22_data{
					{1,2},
					{3,4},
				};

				std::vector< std::vector<int> > I22_data{
					{1,0},
					{0,1},
				};

				std::vector< std::vector<int> > A23_data{
					{1,2,3},
					{4,5,6},
				};

				std::vector< std::vector<int> > A33_data{
					{1,2,3},
					{4,5,6},
					{7,8,9},
				};

				std::vector< std::vector<int> > I33_data{
					{1,0,0},
					{0,1,0},
					{0,0,1},
				};



				matrix<int> A22(A22_data);
				matrix<int> A23(A23_data);
				matrix<int> A33(A33_data);
				matrix<int> I22(I22_data);
				matrix<int> I33(I33_data);

				matrix<int> B22_1 = A22 * I22;
				matrix<int> B22_2 = I22 * A22;

				matrix<int> B23_1 = I22 * A23;
				matrix<int> B23_2 = A23 * I33;
				
				matrix<int> B33_1 = A33 * I33;
				matrix<int> B33_2 = I33 * A33;

				EXPECT_EQ(A22, B22_1);
				EXPECT_EQ(A22, B22_2);

				EXPECT_EQ(A23, B23_1);
				EXPECT_EQ(A23, B23_2);

				EXPECT_EQ(A33, B33_1);
				EXPECT_EQ(A33, B33_2);
	
			}
		}
	}
}