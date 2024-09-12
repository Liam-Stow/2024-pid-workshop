#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  frc::SmartDashboard::PutData("motor", &spark);
  spark.SetClosedLoopOutputRange(-0.3, 0.3);
  spark.SetConversionFactor(1.0/GEARING);
}
void Robot::RobotPeriodic() {
  spark.UpdateControls();
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {
  sim.SetInputVoltage(spark.CalcSimVoltage());
  sim.Update(20_ms);
  spark.UpdateSimEncoder(sim.GetAngle(), sim.GetVelocity());
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
