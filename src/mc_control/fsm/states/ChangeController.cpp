#include <mc_control/fsm/states/ChangeController.h>

namespace mc_control
{

namespace fsm
{

void ChangeController::configure(const mc_rtc::Configuration & config)
{
  config("nextController", nextControllerName_);
}

void ChangeController::start(mc_control::fsm::Controller &) {}


bool ChangeController::run(mc_control::fsm::Controller &)
{
  return true;
}

void ChangeController::teardown(mc_control::fsm::Controller & ctl)
{
  mc_rtc::log::info("[ChangeController] Switching to controller: {}", nextControllerName_);
  auto enableController = ctl.datastore().get<std::function<void(const std::string & )>>("Global::EnableController");
  enableController(nextControllerName_);
}

} // namespace fsm

} // namespace mc_control
  
EXPORT_SINGLE_STATE("ChangeController", mc_control::fsm::ChangeController)
