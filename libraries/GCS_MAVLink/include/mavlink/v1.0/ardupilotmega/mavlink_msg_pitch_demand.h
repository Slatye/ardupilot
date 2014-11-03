// MESSAGE PITCH_DEMAND PACKING

#define MAVLINK_MSG_ID_PITCH_DEMAND 183

typedef struct __mavlink_pitch_demand_t
{
 float pitch; ///< Pitch demanded
 uint8_t quality; ///< Quality of the optic flow data, 255 is best, 0 means no data
 uint8_t number; ///< Sequence number for this message
} mavlink_pitch_demand_t;

#define MAVLINK_MSG_ID_PITCH_DEMAND_LEN 6
#define MAVLINK_MSG_ID_183_LEN 6

#define MAVLINK_MSG_ID_PITCH_DEMAND_CRC 94
#define MAVLINK_MSG_ID_183_CRC 94



#define MAVLINK_MESSAGE_INFO_PITCH_DEMAND { \
	"PITCH_DEMAND", \
	3, \
	{  { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pitch_demand_t, pitch) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_pitch_demand_t, quality) }, \
         { "number", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_pitch_demand_t, number) }, \
         } \
}


/**
 * @brief Pack a pitch_demand message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pitch Pitch demanded
 * @param quality Quality of the optic flow data, 255 is best, 0 means no data
 * @param number Sequence number for this message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pitch_demand_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float pitch, uint8_t quality, uint8_t number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PITCH_DEMAND_LEN];
	_mav_put_float(buf, 0, pitch);
	_mav_put_uint8_t(buf, 4, quality);
	_mav_put_uint8_t(buf, 5, number);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#else
	mavlink_pitch_demand_t packet;
	packet.pitch = pitch;
	packet.quality = quality;
	packet.number = number;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PITCH_DEMAND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PITCH_DEMAND_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif
}

/**
 * @brief Pack a pitch_demand message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pitch Pitch demanded
 * @param quality Quality of the optic flow data, 255 is best, 0 means no data
 * @param number Sequence number for this message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pitch_demand_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float pitch,uint8_t quality,uint8_t number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PITCH_DEMAND_LEN];
	_mav_put_float(buf, 0, pitch);
	_mav_put_uint8_t(buf, 4, quality);
	_mav_put_uint8_t(buf, 5, number);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#else
	mavlink_pitch_demand_t packet;
	packet.pitch = pitch;
	packet.quality = quality;
	packet.number = number;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PITCH_DEMAND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PITCH_DEMAND_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif
}

/**
 * @brief Encode a pitch_demand struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pitch_demand C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pitch_demand_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pitch_demand_t* pitch_demand)
{
	return mavlink_msg_pitch_demand_pack(system_id, component_id, msg, pitch_demand->pitch, pitch_demand->quality, pitch_demand->number);
}

/**
 * @brief Encode a pitch_demand struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pitch_demand C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pitch_demand_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pitch_demand_t* pitch_demand)
{
	return mavlink_msg_pitch_demand_pack_chan(system_id, component_id, chan, msg, pitch_demand->pitch, pitch_demand->quality, pitch_demand->number);
}

/**
 * @brief Send a pitch_demand message
 * @param chan MAVLink channel to send the message
 *
 * @param pitch Pitch demanded
 * @param quality Quality of the optic flow data, 255 is best, 0 means no data
 * @param number Sequence number for this message
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pitch_demand_send(mavlink_channel_t chan, float pitch, uint8_t quality, uint8_t number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PITCH_DEMAND_LEN];
	_mav_put_float(buf, 0, pitch);
	_mav_put_uint8_t(buf, 4, quality);
	_mav_put_uint8_t(buf, 5, number);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND, buf, MAVLINK_MSG_ID_PITCH_DEMAND_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND, buf, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif
#else
	mavlink_pitch_demand_t packet;
	packet.pitch = pitch;
	packet.quality = quality;
	packet.number = number;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND, (const char *)&packet, MAVLINK_MSG_ID_PITCH_DEMAND_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND, (const char *)&packet, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PITCH_DEMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pitch_demand_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float pitch, uint8_t quality, uint8_t number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, pitch);
	_mav_put_uint8_t(buf, 4, quality);
	_mav_put_uint8_t(buf, 5, number);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND, buf, MAVLINK_MSG_ID_PITCH_DEMAND_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND, buf, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif
#else
	mavlink_pitch_demand_t *packet = (mavlink_pitch_demand_t *)msgbuf;
	packet->pitch = pitch;
	packet->quality = quality;
	packet->number = number;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND, (const char *)packet, MAVLINK_MSG_ID_PITCH_DEMAND_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND, (const char *)packet, MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PITCH_DEMAND UNPACKING


/**
 * @brief Get field pitch from pitch_demand message
 *
 * @return Pitch demanded
 */
static inline float mavlink_msg_pitch_demand_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field quality from pitch_demand message
 *
 * @return Quality of the optic flow data, 255 is best, 0 means no data
 */
static inline uint8_t mavlink_msg_pitch_demand_get_quality(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field number from pitch_demand message
 *
 * @return Sequence number for this message
 */
static inline uint8_t mavlink_msg_pitch_demand_get_number(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Decode a pitch_demand message into a struct
 *
 * @param msg The message to decode
 * @param pitch_demand C-struct to decode the message contents into
 */
static inline void mavlink_msg_pitch_demand_decode(const mavlink_message_t* msg, mavlink_pitch_demand_t* pitch_demand)
{
#if MAVLINK_NEED_BYTE_SWAP
	pitch_demand->pitch = mavlink_msg_pitch_demand_get_pitch(msg);
	pitch_demand->quality = mavlink_msg_pitch_demand_get_quality(msg);
	pitch_demand->number = mavlink_msg_pitch_demand_get_number(msg);
#else
	memcpy(pitch_demand, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PITCH_DEMAND_LEN);
#endif
}
