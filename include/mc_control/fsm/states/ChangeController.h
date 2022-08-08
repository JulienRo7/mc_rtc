#pragma once

#include <mc_control/fsm/Controller.h>
#include <mc_control/fsm/State.h>

namespace mc_control
{
namespace fsm
{

/** Switch to another state */ 
struct ChangeController : public mc_control::fsm::State
{
  void configure(const mc_rtc::Configuration & config) override;

  void start(mc_control::fsm::Controller & ctl) override;

  bool run(mc_control::fsm::Controller & ctl) override;

  void teardown  (mc_control::fsm::Controller & ctl) override;

 private:
  std::string nextControllerName_ = "CoM";
  
};
  
} // namespace fsm
 
} // namespace mc_control
