##########################################################################
##
##
##
##########################################################################


define topurg ranger
(
  sensor
  ( 			
    range [ 0.0  30.0 ]
    fov 270.25
    samples 1081
  )
  model
  (
    size [ 0.05 0.05 0.1 ]
    color "black"
  )
)


define sicklms ranger
(
  sensor
  (
    fov 180.0
    samples 180
  )
  model
  (
    size [ 0.25 0.25 0.1 ]
    color "black"
  )
)
