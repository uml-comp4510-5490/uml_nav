#!/usr/bin/env python

import sys
import termios
import contextlib

import rospy
from geometry_msgs.msg import Twist

@contextlib.contextmanager
def raw_mode(file):
    old_attrs = termios.tcgetattr(file.fileno())
    new_attrs = old_attrs[:]
    new_attrs[3] = new_attrs[3] & ~(termios.ECHO | termios.ICANON)
    try:
        termios.tcsetattr(file.fileno(), termios.TCSADRAIN, new_attrs)
        yield
    finally:
        termios.tcsetattr(file.fileno(), termios.TCSADRAIN, old_attrs)


def main():
    print 'exit with [CTRL]\\'
    
    pub = rospy.Publisher('/robot/cmd_vel', Twist, queue_size=1)
    msg = Twist()
    rospy.init_node('talker', anonymous=True)
    
    with raw_mode(sys.stdin):
        try:
            while True:
                msg.linear.x = 0.0
                msg.angular.z = 0.0
                key = sys.stdin.read(1)
                if not key or key == chr(4):
                    break

                if key == 'w':
                    #print "up"
                    msg.linear.x = 2.0
                elif key == 's':
                    #print "down"
                    msg.linear.x = -2.0
                elif key == 'd':
                        #print "right"
                        msg.angular.z = -2.0
                elif key == 'a':
                        #print "left"
                        msg.angular.z = 2.0
                
                if key == 'w' or key == 's' or key == 'd' or key == 'a':
                    pub.publish(msg)

        except (KeyboardInterrupt, EOFError):
            pass


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
