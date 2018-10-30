#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

ros::Publisher twist_pub;


void outputCallback(const sensor_msgs::LaserScan info)
{
//Variables
float speedmulti = 1.2f;
float anglemulti = 0.75f;

//Speed control
float speed = 0.5;
//for(int i = 239 ; i < 279 ; i += 10){if ((info.ranges[i]/2) <= speed) speed = (info.ranges[i]/2);}
//speed += (speed*speedmulti);
//if (speed > 5.0f) speed = 5.0f;
//if(speed < 0.5) speed = -1;

//Turning control
float left = (info.ranges[99]+info.ranges[129]+info.ranges[159])/3.0f;
float right = (info.ranges[359]+info.ranges[389]+info.ranges[419])/3.0f;
float angle = (right - left) * anglemulti;


//Publishing
geometry_msgs::Twist command;
command.linear.x =  speed;
command.angular.z = angle;
twist_pub.publish(command);

ROS_INFO("\n\nRange[0]: %f |Range[259]: %f |Range[519] %f\nCurrent Speed: %f", info.ranges[0], info.ranges[259], info.ranges[519],speed);
}

int main (int argc, char **argv)
{
ros::init(argc,argv,"talker");
ros::NodeHandle p;
twist_pub = p.advertise<geometry_msgs::Twist>("/cmd_vel",100);

ros::Subscriber sub = p.subscribe("/nerpio/frontscan",100,outputCallback);
ros::spin();

return 0;
}
