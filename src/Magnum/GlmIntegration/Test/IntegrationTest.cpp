#include <sstream>
#include <Corrade/TestSuite/Tester.h>

#include <Magnum/Magnum.h>
#include <Magnum/Math/Vector.h>
#include <Magnum/Math/Vector2.h>
#include <Magnum/Math/Vector3.h>
#include <Magnum/Math/Vector4.h>

#include <Magnum/Math/Matrix.h>
#include <Magnum/Math/Matrix3.h>
#include <Magnum/Math/Matrix4.h>

#include "../Integration.h"
//#include "Magnum/BulletIntegration/DebugDraw.h"

namespace Magnum { namespace GlmIntegration { namespace Test {

struct IntegrationTest: TestSuite::Tester {
    explicit IntegrationTest();

    void vector();
    void matrix3();
    void matrix4();
    void quaternion();

    void debugDrawMode();
};

IntegrationTest::IntegrationTest() {
    addTests({&IntegrationTest::vector,
              &IntegrationTest::matrix3,
              &IntegrationTest::matrix4,
              &IntegrationTest::quaternion,
              &IntegrationTest::debugDrawMode});
}

void IntegrationTest::vector() {
	{
		Vector2 a{ 1.0f, 2.0f };
		glm::vec2 b{ 1.0f, 2.0f, };

		CORRADE_COMPARE(Vector2{ b }, a);
		CORRADE_VERIFY(glm::vec2(a) == b);
	}
	{
		Vector3 a{ 1.0f, 2.0f, 3.0f };
		glm::vec3 b{ 1.0f, 2.0f, 3.0f };

		CORRADE_COMPARE(Vector3{ b }, a);
		CORRADE_VERIFY(glm::vec3(a) == b);
	}
	{
		Vector4 a{ 1.0f, 2.0f, 3.0f, 4.0f };
		glm::vec4 b{ 1.0f, 2.0f, 3.0f, 4.0f };

		CORRADE_COMPARE(Vector4{ b }, a);
		CORRADE_VERIFY(glm::vec4(a) == b);
	}
	{
		Vector2i a{ 1, 2 };
		glm::ivec2 b{ 1, 2, };

		CORRADE_COMPARE(Vector2i{ b }, a);
		CORRADE_VERIFY(glm::ivec2(a) == b);
	}
	{
		Vector3i a{ 1, 2, 3 };
		glm::ivec3 b{ 1, 2, 3 };

		CORRADE_COMPARE(Vector3i{ b }, a);
		CORRADE_VERIFY(glm::ivec3(a) == b);
	}
	{
		Vector4i a{ 1, 2, 3, 4 };
		glm::ivec4 b{ 1, 2, 3, 4 };

		CORRADE_COMPARE(Vector4i{ b }, a);
		CORRADE_VERIFY(glm::ivec4(a) == b);
	}
}

void IntegrationTest::matrix3() {

    constexpr Matrix3 a{Vector3{3.0f,  5.0f, 8.0f},
                        Vector3{4.5f,  4.0f, 7.0f},
                        Vector3{7.9f, -1.0f, 8.0f}};
	const glm::mat3 b{ 3.0f,  5.0f, 8.0f,
                        4.5f,  4.0f, 7.0f,
                        7.9f, -1.0f, 8.0f};

    CORRADE_COMPARE(Matrix3{b}, a);

    const glm::mat3 btA = glm::mat3(a);
    const float* pa = &btA[0][0];
    const float* pb = &b[0][0];
    
	for(std::size_t i = 0; i < 9; ++i, ++pb, ++pa)
        CORRADE_COMPARE(*pa, *pb);

}

void IntegrationTest::matrix4() {
	{
		constexpr Matrix4 a{ Vector4{ 3.0f,  5.0f, 8.0f, 10.0f },
			Vector4{ 4.5f,  4.0f, 7.0f, 11.0f },
			Vector4{ 7.9f, -1.0f, 8.0f, 12.0f },
			Vector4{ 8.1f, 0.1f, 0.5f, 13.0f}  };
		const glm::mat4 b{ 3.0f,  5.0f, 8.0f, 10.0f,
			4.5f,  4.0f, 7.0f, 11.0f,
			7.9f, -1.0f, 8.0f, 12.0f,
			8.1f, 0.1f, 0.5f, 13.0f };

		CORRADE_COMPARE(Matrix4{ b }, a);

		const glm::mat4 btA = glm::mat4(a);
		const float* pa = &btA[0][0];
		const float* pb = &b[0][0];

		for (std::size_t i = 0; i < 16; ++i, ++pb, ++pa)
			CORRADE_COMPARE(*pa, *pb);
	}
	/*
    const Quaternion rotation = Quaternion{{1.0f, 2.0f, 3.0f}, 4.0f}.normalized();
    constexpr Vector3 translation{1.0f, 2.0f, 3.0f};

    const Matrix4 a = Matrix4::from(rotation.toMatrix(), translation);
    const btTransform b{btQuaternion{rotation}, btVector3{translation}};

    CORRADE_COMPARE(Matrix4{b}, a);

    const btTransform btA = btTransform(a);
    CORRADE_COMPARE(Quaternion{btA.getRotation()}, rotation);
    CORRADE_COMPARE(Vector3{btA.getOrigin()}, translation);
*/
}

void IntegrationTest::quaternion() {

    Quaternion a{{1.0f, 2.0f, 3.0f}, 4.0f};
    glm::quat b{4.0f, 1.0f, 2.0f, 3.0f};

    CORRADE_COMPARE(Quaternion{b}, a);
    CORRADE_VERIFY(glm::quat{a} == b);

}

void IntegrationTest::debugDrawMode() {
/*
    std::ostringstream out;

    Debug(&out) << DebugDraw::DebugMode::DrawAabb << DebugDraw::DebugMode(0xbaadcafe);
    CORRADE_COMPARE(out.str(), "BulletIntegration::DebugDraw::DebugMode::DrawAabb BulletIntegration::DebugDraw::DebugMode(0xbaadcafe)\n");
*/
	CORRADE_VERIFY(true);
}

}}}

CORRADE_TEST_MAIN(Magnum::GlmIntegration::Test::IntegrationTest)