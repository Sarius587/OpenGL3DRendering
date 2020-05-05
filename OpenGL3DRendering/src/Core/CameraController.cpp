#include "oglpch.h"

#include "CameraController.h"
#include "Input/Input.h"

namespace OpenGLRendering {

	void CameraController::OnUpdate(Timestep t)
	{
		float cameraSpeed = 2.5 * t;

		if (Input::IsKeyPressed(OGL_KEY_W))
		{
			m_CameraPosition += cameraSpeed * m_CameraFront;
		}
		if (Input::IsKeyPressed(OGL_KEY_S))
		{
			m_CameraPosition -= cameraSpeed * m_CameraFront;
		}
		if (Input::IsKeyPressed(OGL_KEY_A))
		{
			m_CameraPosition -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
		}
		if (Input::IsKeyPressed(OGL_KEY_D))
		{
			m_CameraPosition += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
		}
		if (Input::IsKeyPressed(OGL_KEY_C))
		{
			m_CameraPosition += m_CameraUp * cameraSpeed;
		}
		if (Input::IsKeyPressed(OGL_KEY_Z))
		{
			m_CameraPosition -= m_CameraUp * cameraSpeed;
		}
		m_Camera.SetCameraPosition(m_CameraPosition);
	}

	void CameraController::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(CameraController::OnMouseMoved));
	}

	bool CameraController::OnMouseMoved(MouseMovedEvent& event)
	{
		static bool firstMouse = true;
		static float lastX = 0;
		static float lastY = 0;

		if (firstMouse)
		{
			lastX = event.GetX();
			lastY = event.GetY();
			firstMouse = false;
		}

		float xOffset = event.GetX() - lastX;
		float yOffset = lastY - event.GetY();

		lastX = event.GetX();
		lastY = event.GetY();

		m_Yaw += xOffset * 0.1f;
		m_Pitch += yOffset * 0.1f;

		if (m_Pitch > 89.0f)
		{ 
			m_Pitch = 89.0f;
		}
		if (m_Pitch < -89.0f)
		{
			m_Pitch = -89.0f;
		}

		glm::vec3 front;
		front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		front.y = sin(glm::radians(m_Pitch));
		front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

		m_CameraFront = glm::normalize(front);
		m_Camera.SetCameraFront(m_CameraFront);

		return true;
	}



}
