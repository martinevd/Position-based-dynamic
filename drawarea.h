#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QOpenGLWidget>
#include "context.h"

/**
 * @brief A widget for rendering and interacting with the simulation.
 *
 * The `DrawArea` class is a custom widget that renders the simulation
 * context and allows user interactions such as adding particles via mouse events.
 * It inherits from `QOpenGLWidget` to support OpenGL-based rendering.
 */
class DrawArea : public QOpenGLWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructs a new `DrawArea` widget.
     *
     * Initializes the rendering area and sets up the simulation context.
     *
     * @param parent The parent widget (optional).
     */
    explicit DrawArea(QOpenGLWidget *parent = nullptr);

    /**
     * @brief Destroys the `DrawArea` widget.
     *
     * Automatically cleans up the resources used by the context.
     */
    ~DrawArea() = default;

    /**
     * @brief Paints the simulation on the widget.
     *
     * Called whenever the widget needs to be repainted. Renders the current
     * state of the simulation context.
     *
     * @param e The paint event triggering the repaint.
     */
    void paintEvent(QPaintEvent *e) override;

    /**
     * @brief Animates the simulation by updating its state.
     *
     * Advances the simulation by a small time step and triggers a repaint.
     */
    void animate();

    /**
     * @brief Handles double-click mouse events.
     *
     * Adds a new particle to the simulation at the position of the double-click.
     *
     * @param event The mouse event containing the click position.
     */
    void mouseDoubleClickEvent(QMouseEvent *event) override;

public slots:
    /**
     * @brief Resets the simulation context.
     *
     * Clears and reinitializes the simulation context to its default state.
     */
    void resetContext();

private:
    /// Pointer to the simulation context being rendered and managed.
    std::unique_ptr<Context> context;
};

#endif // DRAWAREA_H
