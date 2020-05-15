/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

/*
  Author(s):  Zihan Chen, Anton Deguet
  Created on: 2015-05-23

  (C) Copyright 2015-2020 Johns Hopkins University (JHU), All Rights Reserved.

--- begin cisst license - do not edit ---

This software is provided "as is" under an open source license, with
no warranty.  The complete license can be found in license.txt and
http://www.cisst.org/cisst/license.txt.

--- end cisst license ---
*/

#ifndef _dvrk_add_topics_functions_h
#define _dvrk_add_topics_functions_h

#include <cisst_ros_bridge/mtsROSBridge.h>

namespace dvrk {

    /*! This methods adds a default set of topics to connect to a dVRK
      console.  Topics are /off, /home, /teleop/start, /teleop/stop,
      /teleop/set_scale and /teleop_scale.
    */
    void add_topics_console(mtsROSBridge & bridge,
                            const std::string & ros_namespace);

    /*! This method connects all the required interfaces for the
      console, it must be used after add_topics_console. */
    void connect_bridge_console(const std::string & bridge_name,
                                const std::string & console_component_name);

    /*! This methods adds a default set of topics to connect to a dVRK
      foot pedal.  It will create one required interface per "button",
      i,e: "Clutch", "Coag", "Camera", Cam+" and "Cam-". */
    void add_topics_footpedals(mtsROSBridge & bridge,
                               const std::string & ros_namespace);

    /*! This method connects all the required interfaces for the foot
      pedals, it must be used after add_topics_footpedals. */
    void connect_bridge_footpedals(const std::string & bridge_name,
                                   const std::string & io_component_name);

    /*! Add all the IO topics for physical dVRK PSMs. */
    void add_topics_psm_io(mtsROSBridge & bridge,
                           const std::string & ros_namespace,
                           const std::string & arm_name);

    /*! This method connects all the required interfaces for the PSM's
        IOs, it must be used after add_topics_psm_io. */
    void connect_bridge_psm_io(const std::string & bridge_name,
                               const std::string & arm_name,
                               const std::string & io_component_name);

    /*! Add all the IO topics for physical dVRK ECMs. */
    void add_topics_ecm_io(mtsROSBridge & bridge,
                           const std::string & ros_namespace,
                           const std::string & arm_name);

    /*! This method connects all the required interfaces for the ECM's
        IOs, it must be used after add_topics_ecm_io. */
    void connect_bridge_ecm_io(const std::string & bridge_name,
                               const std::string & arm_name,
                               const std::string & io_component_name);

    /*! Add all the topics related to teleop PSM component. */
    void add_topics_teleop_psm(mtsROSBridge & bridge,
                               const std::string & ros_namespace,
                               const std::string & teleop_component_name);

    /*! This method connects all the required interfaces for a teleop
      PSM component, it must be used after add_topics_teleop. */
    void connect_bridge_teleop_psm(const std::string & bridge_name,
                                   const std::string & teleop_component_name);

    /*! Add all the topics related to teleop ECM component. */
    void add_topics_teleop_ecm(mtsROSBridge & bridge,
                               const std::string & ros_namespace,
                               const std::string & teleop_component_name);

    /*! This method connects all the required interfaces for a teleop
      ECM component, it must be used after add_topics_teleop. */
    void connect_bridge_teleop_ecm(const std::string & bridge_name,
                                   const std::string & teleop_component_name);

    /*! Add all the topics related to the setup joints (SUJ) */
    void add_topics_suj(mtsROSBridge & bridge,
                        const std::string & ros_namespace,
                        const std::string & arm_name);

    /*! This method connects all the required interfaces for a SUJ
        component, it must be used after add_topics_suj. */
    void connect_bridge_suj(const std::string & bridge_name,
                            const std::string & suj_component_name,
                            const std::string & arm_name);

    /*! This method adds topics from the IO level for the whole
      system. */
    void add_topics_io(mtsROSBridge & bridge,
                       const std::string & ros_namespace);

    /*! This method connects all the required interfaces for IOs, it
      must be used after add_topics_io. */
    void connect_bridge_io(const std::string & bridge_name,
                           const std::string & io_component_name);

    /*! This method adds topics from the IO level for a given arm.
      All the topics are publishers only, i.e. we do not allow direct
      control of the IO.  All commands sent to the dVRK must use the
      MTM, ECM or PSM topics to ensure that the system is properly
      initialized.  The topics added are mostly useful for low level
      data collection and debugging. */
    void add_topics_io(mtsROSBridge & bridge,
                       const std::string & ros_namespace,
                       const std::string & arm_name);

    /*! This method connects all the required interfaces for an arm
      IOs, it must be used after add_topics_io. */
    void connect_bridge_io(const std::string & bridge_name,
                           const std::string & io_component_name,
                           const std::string & arm_name);

    void add_tf_arm(mtsROSBridge & tf_bridge,
                    const std::string & arm_name);

    void connect_tf_arm(const std::string & tf_bridge_name,
                        const std::string & arm_name,
                        const std::string & arm_component_name,
                        const std::string & arm_interface_name);

    void add_tf_suj(mtsROSBridge & tf_bridge,
                    const std::string & arm_name);

    void connect_tf_suj(const std::string & tf_bridge_name,
                        const std::string & suj_component_name,
                        const std::string & arm_name);
}

#endif // _dvrk_add_topics_functions_h
