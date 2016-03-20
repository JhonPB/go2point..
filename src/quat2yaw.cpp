#include<ros/ros.h>
#include<nav_msgs/Odometry.h>
#include<tf/tf.h>
#include<geometry_msgs/Quaternion.h>


void odomcallback (const nav_msgs::Odometry::ConstPtr &romulo)
{
    
   geometry_msgs::Quaternion qt;
    qt = romulo->pose.pose.orientation;
    double yaw = tf::getYaw(qt);
    std::cout << "Yaw" <<
    yaw*180/M_PI << std::endl;
    
    
}


int main(int argc, char **argv)
{
    
    ros::init (argc, argv, "quat2yaw");
    
    ros::NodeHandle nh;
    
    ros::Subscriber odom_sub = nh.subscribe("/vrep/vehicle/odometry", 1, odomcallback);
    
    ros::spin();
    
}