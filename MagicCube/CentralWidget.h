#pragma once

class CentralWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    CentralWidget(QWidget *parent = Q_NULLPTR);
    ~CentralWidget();

protected:
    virtual void initializeGL()override;
    virtual void resizeGL(int w, int h)override;
    virtual void paintGL()override;

    virtual void mousePressEvent(QMouseEvent *e)override;
    virtual void mouseMoveEvent(QMouseEvent *e)override;
    virtual void mouseReleaseEvent(QMouseEvent *e)override;
    virtual void wheelEvent(QWheelEvent *e)override;

public:
    void setAlignView(const QMatrix4x4& alignView, const QString& dir);

public slots:
    void setCoord(const QVector3D& coord);

signals:
    void sendCmd(QSharedPointer<Cmd> pCmd);
    void setMsg(const QString& msg);

private:
    DECL_PRI(CentralWidget);
};
