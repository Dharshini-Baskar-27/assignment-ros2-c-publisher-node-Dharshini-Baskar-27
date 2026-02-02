#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node
{
public:
    PublisherNode()
        : Node("publisher_node"), count_(0)
    {
        // Create publisher to topic "/chatter"
        publisher_ = this->create_publisher<std_msgs::msg::String>("/chatter", 10);
        
        // Create timer that triggers every 500ms
        timer_ = this->create_wall_timer(
            500ms,
            std::bind(&PublisherNode::timer_callback, this)
        );
        
        RCLCPP_INFO(this->get_logger(), "Publisher node started. Publishing to /chatter every 500ms");
    }

private:
    void timer_callback()
    {
        // Create message with format "Count: X"
        auto message = std_msgs::msg::String();
        message.data = "Count: " + std::to_string(count_++);
        
        // Log using RCLCPP_INFO
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        
        // Publish the message
        publisher_->publish(message);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;
}
