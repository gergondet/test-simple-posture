#include "PostureTest_Initial.h"

#include "../PostureTest.h"

void PostureTest_Initial::configure(const mc_rtc::Configuration & config)
{
}

void PostureTest_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<PostureTest &>(ctl_);
}

bool PostureTest_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<PostureTest &>(ctl_);
  output("OK");
  return true;
}

void PostureTest_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<PostureTest &>(ctl_);
}

EXPORT_SINGLE_STATE("PostureTest_Initial", PostureTest_Initial)
