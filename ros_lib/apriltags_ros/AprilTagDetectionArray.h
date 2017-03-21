#ifndef _ROS_apriltags_ros_AprilTagDetectionArray_h
#define _ROS_apriltags_ros_AprilTagDetectionArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "apriltags_ros/AprilTagDetection.h"

namespace apriltags_ros
{

  class AprilTagDetectionArray : public ros::Msg
  {
    public:
      uint8_t detections_length;
      apriltags_ros::AprilTagDetection st_detections;
      apriltags_ros::AprilTagDetection * detections;

    AprilTagDetectionArray():
      detections_length(0), detections(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = detections_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < detections_length; i++){
      offset += this->detections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t detections_lengthT = *(inbuffer + offset++);
      if(detections_lengthT > detections_length)
        this->detections = (apriltags_ros::AprilTagDetection*)realloc(this->detections, detections_lengthT * sizeof(apriltags_ros::AprilTagDetection));
      offset += 3;
      detections_length = detections_lengthT;
      for( uint8_t i = 0; i < detections_length; i++){
      offset += this->st_detections.deserialize(inbuffer + offset);
        memcpy( &(this->detections[i]), &(this->st_detections), sizeof(apriltags_ros::AprilTagDetection));
      }
     return offset;
    }

    const char * getType(){ return "apriltags_ros/AprilTagDetectionArray"; };
    const char * getMD5(){ return "93c0a301ed9e6633dc34b8117d49ebd4"; };

  };

}
#endif