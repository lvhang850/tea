#include <QtWidgets>
#include <QtOpenGL>
#include <GL/glut.h>

class GLWidget : public QGLWidget
{
public:
    GLWidget(QWidget *parent = 0) : QGLWidget(parent) { }

protected:
    void initializeGL() {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glEnable(GL_DEPTH_TEST);
    }

    void resizeGL(int w, int h) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1, 1, -1, 1, -1, 1);
        glMatrixMode(GL_MODELVIEW);
    }

    void paintGL() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);

        // 绘制茶壶
        glutSolidTeapot(0.5);
    }
};

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    QMainWindow window;
    GLWidget glWidget;
    window.setCentralWidget(&glWidget);
    window.setGeometry(100, 100, 800, 600);
    window.show();
    return a.exec();
}
