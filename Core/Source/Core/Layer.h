#pragma once

#include "Event.h"
#include <QString>
#include <QEvent>

namespace Core {
#include <QString>
#include <QEvent>

	class Layer {
	public:
		explicit Layer(const QString& name = "Layer");
		virtual ~Layer() = default;

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate(float deltaTime) {}
		virtual bool onEvent(QEvent* event) { return false; }

		const QString& getName() const { return name_; }

		void setEnabled(bool enabled) { enabled_ = enabled; }
		bool isEnabled() const { return enabled_; }

	protected:
		QString name_;
		bool enabled_ = true;
	};

}