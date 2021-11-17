#pragma once
#include <string>
#include <sstream>

namespace Nade {

	enum class EventType {
		WindowClose
	};

	class Event {
	public:
		virtual EventType GetEventType() const = 0;
		virtual std::string GetEventName() const = 0;
	};

	class WindowCloseEvent : public Event {
	public:
		EventType GetEventType() const override { return GetStaticType(); }
		static EventType GetStaticType() { return EventType::WindowClose; }
		std::string GetEventName() const { return "Window Close Event"; }
		std::string ToString() const { return GetEventName(); }
	};
}