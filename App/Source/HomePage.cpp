#include "HomePage.h"
#include <QGraphicsDropShadowEffect>

namespace App {
    HomePage::HomePage(QWidget *parent)
        : QMainWindow(parent), menuVisible_(false)
    {
        setupUI();
    }

    void HomePage::setupUI()
    {
        // Main window setup
        setWindowTitle("HavenWMS");
        resize(1920, 1080);

        // Central widget
        centralWidget_ = new QWidget(this);
        setCentralWidget(centralWidget_);

        mainLayout_ = new QHBoxLayout(centralWidget_);
        mainLayout_->setContentsMargins(0, 0, 0, 0);
        mainLayout_->setSpacing(0);

        setupMenuBar();
        setupContentArea();
    }

    void HomePage::setupMenuBar()
    {
        // Menu frame (sidebar)
        menuFrame_ = new QFrame();
        menuFrame_->setStyleSheet(
            "QFrame {"
            "   background-color: #2c3e50;"
            "   border-right: 2px solid #34495e;"
            "}"
            "QPushButton {"
            "   background-color: transparent;"
            "   color: white;"
            "   text-align: left;"
            "   padding: 15px 20px;"
            "   border: none;"
            "   font-size: 14px;"
            "}"
            "QPushButton:hover {"
            "   background-color: #34495e;"
            "}"
        );
        menuFrame_->setFixedWidth(0); // Initially hidden

        menuLayout_ = new QVBoxLayout(menuFrame_);
        menuLayout_->setContentsMargins(0, 60, 0, 0);
        menuLayout_->setSpacing(0);

        // Menu title
        QLabel *menuTitle = new QLabel("Navigation");
        menuTitle->setStyleSheet(
            "color: #ecf0f1;"
            "font-size: 18px;"
            "font-weight: bold;"
            "padding: 20px;"
        );
        menuLayout_->addWidget(menuTitle);

        // Menu buttons
        QStringList menuItems = {"Home", "Dashboard", "Profile", "Settings", "Scripting Module"};

        for (const QString &item: menuItems)
        {
            QPushButton *menuBtn = new QPushButton(item);
            connect(menuBtn, &QPushButton::clicked, this, [this, item]()
            {
                navigateToPage(item);
            });
            menuLayout_->addWidget(menuBtn);
        }

        menuLayout_->addStretch();

        // Add menu to main layout
        mainLayout_->addWidget(menuFrame_);

        // Setup animation
        menuAnimation_ = new QPropertyAnimation(menuFrame_, "minimumWidth");
        menuAnimation_->setDuration(300);
        menuAnimation_->setEasingCurve(QEasingCurve::InOutQuad);
    }

    void HomePage::setupContentArea()
    {
        // Content widget
        contentWidget_ = new QWidget();
        contentWidget_->setStyleSheet("background-color: #ecf0f1;");

        contentLayout_ = new QVBoxLayout(contentWidget_);
        contentLayout_->setContentsMargins(0, 0, 0, 0);
        contentLayout_->setSpacing(0);

        // Header with hamburger button and title
        QWidget *headerWidget = new QWidget();
        headerWidget->setStyleSheet("background-color: #3498db;");
        headerWidget->setFixedHeight(60);

        QHBoxLayout *headerLayout = new QHBoxLayout(headerWidget);
        headerLayout->setContentsMargins(10, 0, 20, 0);

        // Hamburger button
        hamburgerButton_ = new QPushButton("☰");
        hamburgerButton_->setStyleSheet(
            "QPushButton {"
            "   background-color: transparent;"
            "   color: white;"
            "   font-size: 24px;"
            "   border: none;"
            "   padding: 10px;"
            "}"
            "QPushButton:hover {"
            "   background-color: #2980b9;"
            "   border-radius: 5px;"
            "}"
        );
        hamburgerButton_->setFixedSize(50, 50);
        connect(hamburgerButton_, &QPushButton::clicked, this, &HomePage::toggleMenu);

        // Title
        titleLabel_ = new QLabel("Welcome to Haven");
        titleLabel_->setStyleSheet(
            "color: white;"
            "font-size: 24px;"
            "font-weight: bold;"
            "padding-left: 20px;"
        );

        headerLayout->addWidget(hamburgerButton_);
        headerLayout->addWidget(titleLabel_);
        headerLayout->addStretch();

        contentLayout_->addWidget(headerWidget);

        // Stacked widget for different pages
        stackedWidget_ = new QStackedWidget();

        // Create placeholder pages
        stackedWidget_->addWidget(createPlaceholderPage("Home", "#ffffff"));
        stackedWidget_->addWidget(createPlaceholderPage("Dashboard", "#e8f4f8"));
        stackedWidget_->addWidget(createPlaceholderPage("Profile", "#fef5e7"));
        stackedWidget_->addWidget(createPlaceholderPage("Settings", "#f4ecf7"));
        stackedWidget_->addWidget(createPlaceholderPage("Scripting Module", "#e8f8f5"));

        contentLayout_->addWidget(stackedWidget_);

        // Add content to main layout
        mainLayout_->addWidget(contentWidget_);
    }

    QWidget *HomePage::createPlaceholderPage(const QString &title, const QString &color)
    {
        QWidget *page = new QWidget();
        page->setStyleSheet(QString("background-color: %1;").arg(color));

        QVBoxLayout *layout = new QVBoxLayout(page);
        layout->setAlignment(Qt::AlignCenter);

        QLabel *label = new QLabel(title + " Page");
        label->setStyleSheet(
            "font-size: 32px;"
            "font-weight: bold;"
            "color: #2c3e50;"
        );
        label->setAlignment(Qt::AlignCenter);

        QLabel *subtitle = new QLabel("Content goes here...");
        subtitle->setStyleSheet(
            "font-size: 16px;"
            "color: #7f8c8d;"
            "margin-top: 10px;"
        );
        subtitle->setAlignment(Qt::AlignCenter);

        layout->addWidget(label);
        layout->addWidget(subtitle);

        return page;
    }

    void HomePage::toggleMenu()
    {
        if (menuVisible_)
        {
            // Hide menu
            menuAnimation_->setStartValue(250);
            menuAnimation_->setEndValue(0);
            menuVisible_ = false;
        } else
        {
            // Show menu
            menuAnimation_->setStartValue(0);
            menuAnimation_->setEndValue(250);
            menuVisible_ = true;
        }
        menuAnimation_->start();
    }

    void HomePage::navigateToPage(const QString &pageName)
    {
        // Update title
        titleLabel_->setText(pageName);

        // Switch to the corresponding page
        QStringList pages = {"Home", "Dashboard", "Profile", "Settings", "Scripting Module"};
        int index = pages.indexOf(pageName);
        if (index != -1)
        {
            stackedWidget_->setCurrentIndex(index);
        }

        // Optionally close menu after navigation
        if (menuVisible_)
        {
            toggleMenu();
        }
    }
}
