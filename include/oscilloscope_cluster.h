#ifndef ATG_ENGINE_SIM_OSCILLOSCOPE_CLUSTER_H
#define ATG_ENGINE_SIM_OSCILLOSCOPE_CLUSTER_H

#include "ui_element.h"

#include "simulator.h"
#include "oscilloscope.h"

class OscilloscopeCluster : public UiElement {
    public:
        OscilloscopeCluster();
        virtual ~OscilloscopeCluster();

        virtual void initialize(EngineSimApplication *app);
        virtual void destroy();
        virtual void signal(UiElement *element, Event event);

        virtual void update(float dt);
        virtual void render();

        Simulator *m_simulator;

        Oscilloscope *getExhaustFlowOscilloscope() { return m_exhaustFlowScope; }
        Oscilloscope *getAudioWaveformOscilloscope() { return m_audioWaveformScope; }
        Oscilloscope *getIntakeValveLiftOscilloscope() { return m_intakeValveLiftScope; }
        Oscilloscope *getExhaustValveLiftOscilloscope() { return m_exhaustValveLiftScope; }
        Oscilloscope *getCylinderPressureScope() { return m_cylinderPressureScope; }
        Oscilloscope *getSparkAdvanceScope() { return m_sparkAdvanceScope; }

    protected:
        void renderScope(
            Oscilloscope *osc,
            const Bounds &bounds,
            const std::string &title,
            bool overlay=false);

        Oscilloscope
            *m_torqueScope,
            *m_hpScope,
            *m_exhaustFlowScope,
            *m_audioWaveformScope,
            *m_exhaustValveLiftScope,
            *m_intakeValveLiftScope,
            *m_cylinderPressureScope,
            *m_sparkAdvanceScope,
            *m_currentFocusScope0,
            *m_currentFocusScope1;
        float m_updatePeriod;
        float m_updateTimer;

        double m_torque;
        double m_hp;
};

#endif /* ATG_ENGINE_SIM_OSCILLOSCOPE_CLUSTER_H */