#include<ros/ros.h>
#include <nav_msgs/Odometry.h>
#include<geometry_msgs/Quaternion.h>
#include<tf/tf.h>
#include<geometry_msgs/Point.h>

geometry_msgs::Twist v;
ros::Publisher twist_pub;

void callback(const nav_msgs::Odometry::ConstPtr &k)
{
    geometry_msgs::Quaternion qt;
    qt = k->pose.pose.orientation;
    double yaw = tf::getYaw(qt);
     
    geometry_msgs::Point gt;
    gt = k->pose.pose.position;
    double x = gt.x;
    double y = gt.y;
    
    
    double xf = 4;
    double yf = 1.5;
    
    
    double xr = xf-x;
    double yr = yf-y;
    
    double res = atan2(yr,xr) - yaw;
    
    
    
    
    
    if (res)
    {
        v.linear.x = 1;
        v.angular.z = 0;
    }
    else
    {
        v.linear.x = 0;
        v.angular.z = 0.5;
        
    }
    
}



int main (int argc, char **argv)
{
    
   ros::init(argc, argv,"point");
   
   ros::NodeHandle nh;
    
   ros::Subscriber sub = nh.subscribe ("/vrep/vehicle/odometry", 1, callback);
    
    
   twist_pub = nh.advertise geometry_msgs::Twist ("obstacle/twist", 1);
    
   ros::Rate loop_rate(50);
   
    
}