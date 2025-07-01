#pragma once

#include <oapch.h>

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;
typedef glm::vec4 Vector4;
typedef glm::mat4 Matrix4x4;

struct Color {
	float R, G, B, A;

	Color(float r = 255.0f, float g = 255.0f, float b = 255.0f, float a = 255.0f)
		: R(r / 255.0f), G(g / 255.0f), B(b / 255.0f), A(a / 255.0f) {
	}

	Vector4 Value() {
		return Vector4(R, G, B, A);
	}
};
