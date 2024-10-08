#include "utilities/ICSparkMax.h"

ICSparkMax::ICSparkMax(int deviceID, units::ampere_t currentLimit)
    : rev::CANSparkMax(deviceID, rev::CANSparkLowLevel::MotorType::kBrushless),
      ICSpark(this,
              GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor,
                         NEO_ENCODER_RESOLUTION),
              currentLimit) {}

void ICSparkMax::Set(double speed) { ICSpark::SetDutyCycle(speed); }

void ICSparkMax::SetVoltage(units::volt_t output) {
  ICSpark::SetVoltage(output);
}

double ICSparkMax::Get() const { return ICSpark::GetDutyCycle(); }

void ICSparkMax::StopMotor() { ICSpark::StopMotor(); }

void ICSparkMax::UseAlternateEncoder(int countsPerRev) {
  ICSpark::UseRelativeEncoder(CANSparkMax::GetAlternateEncoder(countsPerRev));
}