#pragma once

#include <frc/TimedRobot.h>
#include <frc/simulation/SingleJointedArmSim.h>
#include "utilities/ICSparkMax.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

  ICSparkMax spark{1, 20_A};

  static constexpr double GEARING = 15.0;
  static constexpr inline auto LENGTH = 0.5_m;
  static constexpr inline auto MASS = 1_kg;
  static constexpr inline auto MOI = frc::sim::SingleJointedArmSim::EstimateMOI(LENGTH, MASS);
  frc::sim::SingleJointedArmSim sim{frc::DCMotor::NEO(), GEARING, MOI, LENGTH, -1_tr, 1_tr, true, 0_tr};
};
