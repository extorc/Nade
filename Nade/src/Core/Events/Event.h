#pragma once
#include "pch.h"

#define EVENT_TYPE(x)  EventType GetEventType() const override { return GetStaticType(); } \
		static EventType GetStaticType() { return x; }

namespace Nade {

	enum class EventType {
		WindowClose, WindowResize, WindowMove,
		KeyPress, KeyRelease,
		MouseButtonPress, MouseButtonRelease, MouseScroll, MouseMove
	};

	class Event {
	public:
		virtual EventType GetEventType() const = 0;
		virtual std::string GetEventName() const = 0;
		virtual std::string ToString() = 0;
	};
	class EventDispatcher{
	public:
		using EventCallback = std::function<void(Event&)>;
		
		void Dispatch(Event& e, EventCallback func, EventType type){
			if(e.GetEventType() == type){
				std::cout<<e.ToString()<<std::endl;
				func(e);
			}
		}
	};
	class WindowCloseEvent : public Event {
	public:
		EVENT_TYPE(EventType::WindowClose);
		std::string GetEventName() const { return "Window Close Event"; }
		std::string ToString() override { return GetEventName(); }
	};
	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(int x, int y):xSize(x) ,ySize(y){}
		EVENT_TYPE(EventType::WindowResize);
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
		EVENT_TYPE(EventType::WindowMove);
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
		EVENT_TYPE(EventType::KeyPress);
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
		EVENT_TYPE(EventType::KeyRelease);
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
		EVENT_TYPE(EventType::MouseButtonPress);
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
		EVENT_TYPE(EventType::MouseButtonRelease);
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
		EVENT_TYPE(EventType::MouseScroll);
		std::string GetEventName() const { return "Mouse Scroll Event"; }
		std::string ToString() {
			std::stringstream ss;
			ss << GetEventName() << " " << mXpos << "," << mYpos;
			return ss.str();
		}
	private:
		double mXpos, mYpos;
	};
	class MouseMoveEvent : public Event {
	public:
		MouseMoveEvent(double xPos, double yPos) :mXpos(xPos), mYpos(yPos) {}
		EVENT_TYPE(EventType::MouseMove);
		std::string GetEventName() const { return "Mouse Move Event"; }
		std::string ToString() {
			std::stringstream ss;
			ss << GetEventName() << " " << mXpos << "," << mYpos;
			return ss.str();
		}
	private:
		double mXpos, mYpos;
	};
}