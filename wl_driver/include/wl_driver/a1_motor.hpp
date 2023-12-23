#pragma once

namespace wl_driver
{
class A1Motor
  {
  public:
    //void a1_set();
    //void a1_analyze();

    // output data
    int Kp;
    int Pos_W;
    int Kd;
    int W_W;
    int T_W;

    // input data
    int Pos;
    int W;
    int LW;
    int T;

  private:
    // output data
    int Kp_data;
    int Pos_W_data;
    int Kd_data;
    int W_W_data;
    int T_W_data;

    // input data
    int Pos_data;
    int W_data;
    int LW_data;
    int T_data;
  };
}