//###########################################################################
// This file is part of LImA, a Library for Image Acquisition
//
// Copyright (C) : 2009-2012
// European Synchrotron Radiation Facility
// BP 220, Grenoble 38043
// FRANCE
//
// This is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//###########################################################################
#include "AndorInterface.h"
#include <algorithm>

using namespace lima;
using namespace lima::Andor;
using namespace std;

/*******************************************************************
 * \brief DetInfoCtrlObj constructor
 *******************************************************************/
DetInfoCtrlObj::DetInfoCtrlObj(Camera& cam)   :m_cam(cam)
{
    DEB_CONSTRUCTOR();
}

//-----------------------------------------------------
//
//-----------------------------------------------------
DetInfoCtrlObj::~DetInfoCtrlObj()
{
    DEB_DESTRUCTOR();
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::getMaxImageSize(Size& size)
{
    DEB_MEMBER_FUNCT();
    m_cam.getDetectorImageSize(size);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::getDetectorImageSize(Size& size)
{
    DEB_MEMBER_FUNCT();
    m_cam.getDetectorImageSize(size);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::getDefImageType(ImageType& image_type)
{
    DEB_MEMBER_FUNCT();
    m_cam.getImageType(image_type);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::getCurrImageType(ImageType& image_type)
{
    DEB_MEMBER_FUNCT();
    m_cam.getImageType(image_type);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::setCurrImageType(ImageType image_type)
{
    DEB_MEMBER_FUNCT();
    m_cam.setImageType(image_type);

}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::getPixelSize(double& size)
{
    DEB_MEMBER_FUNCT();
    m_cam.getPixelSize(size);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::getDetectorType(std::string& type)
{
    DEB_MEMBER_FUNCT();
    m_cam.getDetectorType(type);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::getDetectorModel(std::string& model)
{
    DEB_MEMBER_FUNCT();
    m_cam.getDetectorModel(model);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::registerMaxImageSizeCallback(HwMaxImageSizeCallback& cb)
{
    DEB_MEMBER_FUNCT();
    //m_cam.registerMaxImageSizeCallback(cb);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void DetInfoCtrlObj::unregisterMaxImageSizeCallback(HwMaxImageSizeCallback& cb)
{
    DEB_MEMBER_FUNCT();
    //m_cam.unregisterMaxImageSizeCallback(cb);
}

/*******************************************************************
 * \brief SyncCtrlObj constructor
 *******************************************************************/
SyncCtrlObj::SyncCtrlObj(Camera& cam)
    : HwSyncCtrlObj(), m_cam(cam)
{
}

//-----------------------------------------------------
//
//-----------------------------------------------------
SyncCtrlObj::~SyncCtrlObj()
{
}

//-----------------------------------------------------
//
//-----------------------------------------------------
bool SyncCtrlObj::checkTrigMode(TrigMode trig_mode)
{
    bool valid_mode = false;
    
    return m_cam.checkTrigMode(trig_mode);   
 }

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::setTrigMode(TrigMode trig_mode)
{
    DEB_MEMBER_FUNCT();    
    if (!checkTrigMode(trig_mode))
        THROW_HW_ERROR(InvalidValue) << "Invalid " << DEB_VAR1(trig_mode);
    m_cam.setTrigMode(trig_mode);
    
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::getTrigMode(TrigMode& trig_mode)
{
    m_cam.getTrigMode(trig_mode);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::setExpTime(double exp_time)
{
    m_cam.setExpTime(exp_time);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::getExpTime(double& exp_time)
{
    m_cam.getExpTime(exp_time);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::setLatTime(double lat_time)
{
    m_cam.setLatTime(lat_time);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::getLatTime(double& lat_time)
{
    m_cam.getLatTime(lat_time);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::setNbHwFrames(int nb_frames)
{
    m_cam.setNbFrames(nb_frames);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::getNbHwFrames(int& nb_frames)
{
    m_cam.getNbFrames(nb_frames);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void SyncCtrlObj::getValidRanges(ValidRangesType& valid_ranges)
{
    double min_time = 10e-9;
    double max_time = 1e6;
    valid_ranges.min_exp_time = min_time;
    valid_ranges.max_exp_time = max_time;
    valid_ranges.min_lat_time = min_time;
    valid_ranges.max_lat_time = max_time;
}



/*******************************************************************
 * \brief RoiCtrlObj constructor
 *******************************************************************/

RoiCtrlObj::RoiCtrlObj(Camera& cam)
    : m_cam(cam)
{
    DEB_CONSTRUCTOR();
    
}

//-----------------------------------------------------
//
//-----------------------------------------------------
RoiCtrlObj::~RoiCtrlObj()
{
    DEB_DESTRUCTOR();
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void RoiCtrlObj::checkRoi(const Roi& set_roi, Roi& hw_roi)
{
    DEB_MEMBER_FUNCT();
    m_cam.checkRoi(set_roi, hw_roi);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void RoiCtrlObj::setRoi(const Roi& roi)
{
    DEB_MEMBER_FUNCT();
    Roi real_roi;
    checkRoi(roi,real_roi);
    m_cam.setRoi(real_roi);

}

//-----------------------------------------------------
//
//-----------------------------------------------------
void RoiCtrlObj::getRoi(Roi& roi)
{
    DEB_MEMBER_FUNCT();
    m_cam.getRoi(roi);
}

/*******************************************************************
 * \brief BinCtrlObj constructor
 *******************************************************************/
BinCtrlObj::BinCtrlObj(Camera &cam) : m_cam(cam) {}

void BinCtrlObj::setBin(const Bin& aBin)
{
  m_cam.setBin(aBin);
}

void BinCtrlObj::getBin(Bin &aBin)
{
  m_cam.getBin(aBin);
}

void BinCtrlObj::checkBin(Bin &aBin)
{
  m_cam.checkBin(aBin);
}
/*******************************************************************
 * \brief Hw Interface constructor
 *******************************************************************/

Interface::Interface(Camera& cam)
  : m_cam(cam),m_det_info(cam),
    m_sync(cam),m_bin(cam),m_roi(cam)
{
    DEB_CONSTRUCTOR();

    HwDetInfoCtrlObj *det_info = &m_det_info;
    m_cap_list.push_back(HwCap(det_info));

    m_cap_list.push_back(HwCap(cam.getBufferMgr()));
    
    HwSyncCtrlObj *sync = &m_sync;
    m_cap_list.push_back(HwCap(sync));
    
    HwRoiCtrlObj *roi = &m_roi;
    m_cap_list.push_back(HwCap(roi));

	if(m_cam.isBinnigAvailable())
	{
		HwBinCtrlObj *bin = &m_bin;
		m_cap_list.push_back(HwCap(bin));
	}
}

//-----------------------------------------------------
//
//-----------------------------------------------------
Interface::~Interface()
{
    DEB_DESTRUCTOR();
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void Interface::getCapList(HwInterface::CapList &cap_list) const
{
    DEB_MEMBER_FUNCT();
    cap_list = m_cap_list;
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void Interface::reset(ResetLevel reset_level)
{
    DEB_MEMBER_FUNCT();
    DEB_PARAM() << DEB_VAR1(reset_level);

    stopAcq();

    Size image_size;
    m_det_info.getMaxImageSize(image_size);
    m_cam._setStatus(Camera::Ready,true);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void Interface::prepareAcq()
{
    DEB_MEMBER_FUNCT();
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void Interface::startAcq()
{
    DEB_MEMBER_FUNCT();
    m_cam.startAcq();
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void Interface::stopAcq()
{
    DEB_MEMBER_FUNCT();
    m_cam.stopAcq();
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void Interface::getStatus(StatusType& status)
{
		Camera::Status andor_status = Camera::Ready;
    m_cam.getStatus(andor_status);
    switch (andor_status)
    {
        case Camera::Ready:
            status.acq = AcqReady;
            status.det = DetIdle;
            break;
        case Camera::Exposure:
            status.det = DetExposure;
            status.acq = AcqRunning;
            break;
        case Camera::Readout:
            status.det = DetReadout;
            status.acq = AcqRunning;
            break;
        case Camera::Latency:
            status.det = DetLatency;
            status.acq = AcqRunning;
            break;
        case Camera::Fault:
          status.det = DetFault;
          status.acq = AcqFault;
    }
    status.det_mask = DetExposure | DetReadout | DetLatency;
}

//-----------------------------------------------------
//
//-----------------------------------------------------
int Interface::getNbHwAcquiredFrames()
{
    DEB_MEMBER_FUNCT();
    int acq_frames;
    m_cam.getNbHwAcquiredFrames(acq_frames);
    return acq_frames;
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void Interface::getFrameRate(double& frame_rate)
{
    DEB_MEMBER_FUNCT();
    m_cam.getFrameRate(frame_rate);
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void Interface::setTimeout(int TO)
{
    m_cam.setTimeout(TO);
}
//-----------------------------------------------------
//
//-----------------------------------------------------
