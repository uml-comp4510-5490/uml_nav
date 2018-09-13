##########################################################################
##
##
##
##########################################################################


include "sensors.inc"


define erratic position
(
  size [0.35 0.35 0.25]
  gui_nose 1
  drive "diff"
  name "robot"
  color "red"
  origin [-0.05 0 0 0]
  topurg(pose [ 0.050 0.000 0 0.000 ])
  velocity_bounds [-5.0 5.0 0 0 0 0 -90.0 90.0 ]
  acceleration_bounds [-5.0 5.0 0 0 0 0 -90 90.0 ]
)


define pioneer position
(
  size [0.75 0.75 0.5]
  gui_nose 1
  drive "diff"
  name "robot" 
  color "red"
  sicklms(pose [ 0.25 0.000 0 0.000 ])
  velocity_bounds [-5.0 5.0 0 0 0 0 -90.0 90.0 ]
  acceleration_bounds [-5.0 5.0 0 0 0 0 -90 90.0 ]
)


define junior position
(
  size [1.0 1.0 0.5]
  gui_nose 1
  drive "omni"
  name "robot" 
  color "red"
  sicklms(pose [ 0.25 0.000 0 0.000 ])
  velocity_bounds [-5.0 5.0 0 0 0 0 -90.0 90.0 ]
  acceleration_bounds [-5.0 5.0 0 0 0 0 -90 90.0 ]
)
