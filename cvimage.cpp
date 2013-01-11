#include "cvimage.h"
#include "highgui.h"
#include <QMessageBox>
#include "jpegdialog.h"
#include <vector>

CVImage::CVImage(QString fileName) {
    mat = cvLoadImageM(fileName.toStdString().c_str(),CV_LOAD_IMAGE_UNCHANGED);
    int format = mat.type();
    if ( format == CV_8UC3 )
        cvtColor(mat, mat, CV_BGR2RGB);
    else if ( format == CV_8UC1 ) {
        cvtColor(mat,rgb,CV_GRAY2RGB);
    }
    path = fileName;
}

CVImage::CVImage() {}

CVImage::CVImage(const CVImage& cvimage) {
    mat = cvimage.mat.clone();
    observer = NULL;
}

void CVImage::setObserver(DarqImage *img) {
    observer = img;
}

void CVImage::notify() {
    if ( mat.type() == CV_8UC3 )
        observer->repaint(mat,true);
    else {
        cvtColor(mat,rgb,CV_GRAY2RGB);
        observer->repaint(rgb,true);
    }
}

CVImage::~CVImage() {
    for ( std::list<Transformation*>::iterator it = transforms.begin(); it != transforms.end(); it++ ) {
        delete *it;
    }
}

QStringList CVImage::transformStringList() {
    QStringList list;
    for ( std::list<Transformation*>::iterator it = transforms.begin(); it != transforms.end(); it++ ) {
        list.append((*it)->toString());
    }
    return list;
}

Memento* CVImage::createMemento() {
    return new Memento(transforms,mat);
}

int CVImage::save(QString savePath) {
    if ( savePath.isEmpty() )
        savePath = path;
    QString extension;
    for ( int i = 0; i < savePath.size(); i++) {
        if ( savePath.at(i) != '.' )
            continue;
        for ( int j = i + 1; j < savePath.size(); j++)
            extension.append(savePath.at(j));
        break;
    }
    if ( QString::compare(extension,"jpg",Qt::CaseInsensitive) == 0 ) {
        if ( mat.type() == CV_8UC3 ) {
            JPEGDialog dlg;
            if ( dlg.exec() ) {
                std::vector<int> compression_params;
                compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
                compression_params.push_back(dlg.getValue());
                cv::Mat bgr;
                cv::cvtColor(mat,bgr,CV_RGB2BGR);
                cv::imwrite(savePath.toStdString(),bgr,compression_params);
            }
        }
        else if ( mat.type() == CV_8UC1 ) {
            JPEGDialog dlg;
            if ( dlg.exec() ) {
                std::vector<int> compression_params;
                compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
                compression_params.push_back(dlg.getValue());
                cv::imwrite(savePath.toStdString(),mat,compression_params);
            }
        }
    }

    else if ( QString::compare(extension,"png",Qt::CaseInsensitive) == 0 ) {
        if ( mat.type() == CV_8UC3 ) {
            cv::Mat bgr;
            cv::cvtColor(mat,bgr,CV_RGB2BGR);
            cv::imwrite(savePath.toStdString(),bgr);
        }
        else if ( mat.type() == CV_8UC1 ) {
            cv::imwrite(savePath.toStdString(),mat);
        }
    }
    else if ( QString::compare(extension,"bmp",Qt::CaseInsensitive) == 0 ) {
        cv::Mat bgr;
        if ( mat.type() == CV_8UC1 ) {
            cv::cvtColor(mat,bgr,CV_GRAY2BGR);
        }
        else {
            cv::cvtColor(mat,bgr,CV_RGB2BGR);
        }
        cv::imwrite(savePath.toStdString(),bgr);
    }
    else if ( QString::compare(extension,"tiff",Qt::CaseInsensitive) == 0 ) {
        if ( mat.type() == CV_8UC3 ) {
            cv::Mat bgr;
            cv::cvtColor(mat,bgr,CV_RGB2BGR);
            cv::imwrite(savePath.toStdString(),bgr);
        }
        else if ( mat.type() == CV_8UC1 ) {
            cv::imwrite(savePath.toStdString(),mat);
        }
    }
    else {
        QMessageBox::critical(observer, "Format Error",
                                 "Unsupported file format - try again");
        return 1;
    }
    return 0;
}

std::list<Transformation*> CVImage::transformationListClone() {
    std::list<Transformation*> ret;
    for ( std::list<Transformation*>::iterator it = transforms.begin(); it != transforms.end(); it++ ) {
        ret.push_back((*it)->clone());
    }
    return ret;
}
