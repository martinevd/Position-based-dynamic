#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawarea.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The main application window.
 *
 * The `MainWindow` class provides the main graphical interface for the application.
 * It contains a `DrawArea` widget where the simulation is rendered and managed.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructs the main window.
     *
     * Initializes the user interface and sets up the `DrawArea` widget for rendering.
     *
     * @param parent The parent widget (optional).
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the main window.
     *
     * Ensures proper cleanup of the user interface and other dynamically allocated resources.
     */
    ~MainWindow();

private:
    /// Pointer to the user interface generated by Qt Designer.
    Ui::MainWindow *ui;

    /// Unique pointer to the `DrawArea` widget for rendering the simulation.
    std::unique_ptr<DrawArea> draw_area;
};

#endif // MAINWINDOW_H
