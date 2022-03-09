#include "PostureTest.h"

PostureTest::PostureTest(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::fsm::Controller(rm, dt, config)
{

  mc_rtc::log::success("PostureTest init done ");
}

bool PostureTest::run()
{
  auto pt = getPostureTask(robot().name());
  if(pt->iterInSolver() == 2)
  {
    pt->target({{"panda_joint1", {1.5}}});
  }
  if(pt->iterInSolver() == 3 * (1 / solver().dt()))
  {
    pt->target({{"panda_joint1", {-1.5}}});
  }
  if(pt->iterInSolver() == 6 * (1 / solver().dt()))
  {
    std::exit(1);
  }
  return mc_control::fsm::Controller::run();
}

void PostureTest::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::fsm::Controller::reset(reset_data);
}


