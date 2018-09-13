#!/usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan

def callback(msg):
    pub.publish(msg);
    
def main():
    global pub
    pub = rospy.Publisher('/scan', LaserScan, queue_size=10)
    rospy.init_node('remap_laser', anonymous=True)
    rospy.Subscriber("/robot/base_scan", LaserScan, callback)
    rospy.spin()

if __name__ == '__main__':
    main()
