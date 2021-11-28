#pragma once
#include "pch.h"

namespace Nade {

	enum class EventType {
		WindowClose, WindowResize, WindowMove,
		KeyPress, KeyRelease,
		MouseButtonPress, MouseButtonRelease, MouseScroll
	};

	class Event {
	public:
		virtual EventType GetEventType() const = 0;
		virtual std::string GetEventName() const = 0;
		virtual std::string ToString() = 0;
	};

	class WindowCloseEvent : public Event {
	public:
		EventType GetEventType() const override { return GetStaticType(); }
		static EventType GetStaticType() { return EventType::WindowClose; }
		std::string GetEventName() const { return "Window Close Event"; }
		std::string ToString() override { return GetEventName(); }
	};
	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(int x, int y):xSize(x) ,ySize(y){}
		EventType GetEventType() const override { return GetStaticType(); }
		static EventType GetStaticType() { return EventType::WindowResize; }
		std::string GetEventName() const { return "Window Resize Event"; }
		std::string ToString() override { 
			std::stringstream ss;
			ss << GetEventName() << " " << GetX() << "," << GetY();
			return ss.str();
		}
		int GetX() const { return xSize; }
		int GetY() const { return ySize; }
	private:
		int xSize, ySize;
	};

	class WindowMoveEvent : public Event {
	public:
		WindowMoveEvent(int x, int y) :xSize(x), ySize(y) {}
		EventType GetEventType() const override { return GetStaticType(); }
		static EventType GetStaticType() { return EventType::WindowMove; }
		std::string GetEventName() const { return "Window Move Event"; }
		std::string ToString() override {
			std::stringstream ss;
			ss << GetEventName() << " " << GetX() << "," << GetY();
			return ss.str();
		}
		int GetX() const { return xSize; }
		int GetY() const { return ySize; }
	private:
		int xSize, ySize;
	};
	class KeyPressEvent : public Event {
	public:
		KeyPressEvent(int keyCode, int repeatCount):mKeyCode(keyCode), mRepeatCount(repeatCount) {}
		EventType GetEventType() const { return GetStaticType(); };
		static EventType GetStaticType() { return EventType::KeyPress; }
		std::string GetEventName() const { return "Key Press Event"; }
		std::string ToString() {
			std::stringstream ss;
			ss << GetEventName() << " " << mKeyCode << "(" << mRepeatCount << ")";
			return ss.str();
		}
	private:
		int mKeyCode;
		int mRepeatCount;
	};
	class KeyReleaseEvent : public Event {
	public:
		KeyReleaseEvent(int keyCode) :mKeyCode(keyCode){}
		EventType GetEventType() const { return GetStaticType(); };
		static EventType GetStaticType() { return EventType::KeyRelease; }
		std::string GetEventName() const { return "Key Release Event"; }
		std::string ToString() {
			std::stringstream ss;
			ss << GetEventName() << " " << mKeyCode;
			return ss.str();
		}
	private:
		int mKeyCode;
	};
	class MouseButtonPressEvent : public Event {
	public:
		MouseButtonPressEvent(int button) :mButton(button) {}
		EventType GetEventType() const { return GetStaticType(); };
		static EventType GetStaticType() { return EventType::MouseButtonPress; }
		std::string GetEventName() const { return "Mouse Button Press Event"; }
		std::string ToString() {
			std::stringstream ss;
			ss << GetEventName() << " " << mButton;
			return ss.str();
		}
	private:
		int mButton;
	};
	class MouseButtonReleaseEvent : public Event {
	public:
		MouseButtonReleaseEvent(int button) :mButton(button) {}
		EventType GetEventType() const { return GetStaticType(); };
		static EventType GetStaticType() { return EventType::MouseButtonRelease; }
		std::string GetEventName() const { return "Mouse Button Release Event"; }
		std::string ToString() {
			std::stringstream ss;
			ss << GetEventName() << " " << mButton;
			return ss.str();
		}
	private:
		int mButton;
	};
	class MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(double xPos, double yPos) :mXpos(xPos), mYpos(yPos) {}
		EventType GetEventType() const { return GetStaticType(); };
		static EventType GetStaticType() { return EventType::MouseScroll; }
		std::string GetEventName() const { return "Mouse Scroll Event"; }
		std::string ToString() {
			std::stringstream ss;
			ss << GetEventName() << " " << mXpos << "," << mYpos;
			return ss.str();
		}
	private:
		double mXpos, mYpos;
	};
}