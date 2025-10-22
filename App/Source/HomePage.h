//
// Created by Johnny Gonzales on 10/22/25.
//

#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QFrame>

namespace App {
    class HomePage : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit HomePage(QWidget *parent = nullptr);
        ~HomePage() = default;

    private slots:
        void toggleMenu();
        void navigateToPage(const QString &pageName);

    private:
        void setupUI();
        void setupMenuBar();
        void setupContentArea();
        QWidget *createPlaceholderPage(const QString &title, const QString &color);

        // UI Components
        QWidget *centralWidget_;
        QHBoxLayout *mainLayout_;

        // Menu
        QFrame *menuFrame_;
        QVBoxLayout *menuLayout_;
        QPushButton *hamburgerButton_;
        bool menuVisible_;
        QPropertyAnimation *menuAnimation_;

        // Content
        QWidget *contentWidget_;
        QVBoxLayout *contentLayout_;
        QLabel *titleLabel_;
        QStackedWidget *stackedWidget_;
    };
}
