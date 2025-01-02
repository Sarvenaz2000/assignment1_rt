#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float32.h>
#include <turtlesim/Pose.h>
#include <cmath>

// Declare global publishers and position variables
ros::Publisher stop_pub1;
ros::Publisher stop_pub2;
ros::Publisher distance_pub;

// Store the position of turtle1 globally with new names to avoid conflict
float turtle1_x, turtle1_y;

// Distance threshold for stopping turtles
float threshold = 1.0;

void turtle1PoseCallback(const turtlesim::Pose::ConstPtr& msg) {
    // Store the position of turtle1
    turtle1_x = msg->x;
    turtle1_y = msg->y;
}

void turtle2PoseCallback(const turtlesim::Pose::ConstPtr& msg) {
    // Get the position of turtle2
    float x2 = msg->x;
    float y2 = msg->y;

    // Calculate the distance between turtle1 and turtle2
    float distance = std::sqrt(std::pow(x2 - turtle1_x, 2) + std::pow(y2 - turtle1_y, 2));

    // Publish the distance
    std_msgs::Float32 dist_msg;
    dist_msg.data = distance;
    distance_pub.publish(dist_msg);

    // Check if turtles are too close or near boundaries
    if (distance < threshold || x2 > 10.0 || y2 > 10.0 || x2 < 1.0 || y2 < 1.0) {
        geometry_msgs::Twist stop_msg;
        stop_pub1.publish(stop_msg);
        stop_pub2.publish(stop_msg);
        ROS_WARN("Turtles are too close or near boundaries. Stopping.");
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "distance_node");
    ros::NodeHandle nh;

    // Subscribe to the poses of turtle1 and turtle2
    ros::Subscriber sub1 = nh.subscribe("turtle1/pose", 10, turtle1PoseCallback);
    ros::Subscriber sub2 = nh.subscribe("turtle2/pose", 10, turtle2PoseCallback);

    // Initialize the publishers for stopping turtles and publishing distance
    stop_pub1 = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
    stop_pub2 = nh.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 1);
    distance_pub = nh.advertise<std_msgs::Float32>("distance", 1);

    ros::spin();

    return 0;
}

