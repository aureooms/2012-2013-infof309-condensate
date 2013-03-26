#include "MainWindow.h"

#include <QApplication>
#include "Algorithm_NoProcessing.h"
#include "Algorithm_Tagging.h"
#include "Algorithm_FeaturesTracker.h"
#include "Algorithm_TagAnTrack.h"
#include "Algorithm_BinaryMaskWithOriginalFrame.h"
#include "Algorithm_Watershed.h"
#include "Algorithm_OomsChallenge.h"
#include "Algorithm_CustomCondensationV1.h"
#include "Algorithm_CustomCondensationTemplateV3.h"
#include "Matcher_GreyLevelDistanceMatcher.h"

//===================================================

FrameProcessor* MainWindow::generateProcessor(){
	return new CustomCondensationTemplateV3();
}

MainWindow::MainWindow(QWidget *parent) : BasicWindow(parent){
	this->setWindowTitle("ConDensAte");

	QGridLayout* upperBarLayout = new QGridLayout(this->_upperBar);
	upperBarLayout->addWidget(this->_inputChoice, 0, 0, 1, 3);
	upperBarLayout->addWidget(this->_parameterToggle, 0, 3, 1, 1);
	this->_parameterToggle->setFixedHeight(23);
	this->_parameterToggle->setIcon(QIcon(":parameter_icon"));
	upperBarLayout->setContentsMargins(0,0,0,0);

	QObject::connect(this->_parameterToggle, SIGNAL(clicked()), this, SLOT(toggleParameterControlWidget()));
}

MainWindow::~MainWindow(){}

void MainWindow::toggleParameterControlWidget(){
	if(this->_parameterControlWidget->isVisible()){
		this->_parameterControlWidget->hide();
	}
	else{
		this->_parameterControlWidget->show();
	}
}
