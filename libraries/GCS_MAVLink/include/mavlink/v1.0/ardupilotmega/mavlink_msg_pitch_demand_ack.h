// MESSAGE PITCH_DEMAND_ACK PACKING

#define MAVLINK_MSG_ID_PITCH_DEMAND_ACK 184

typedef struct __mavlink_pitch_demand_ack_t
{
 uint8_t number; ///< Sequence number for this message
 uint8_t state; ///< State of the pitch control system on the Autopilot (0 = not in pitch-controllable mode, 1 = armed, 2 = active)
} mavlink_pitch_demand_ack_t;

#define MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN 2
#define MAVLINK_MSG_ID_184_LEN 2

#define MAVLINK_MSG_ID_PITCH_DEMAND_ACK_CRC 237
#define MAVLINK_MSG_ID_184_CRC 237



#define MAVLINK_MESSAGE_INFO_PITCH_DEMAND_ACK { \
	"PITCH_DEMAND_ACK", \
	2, \
	{  { "number", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_pitch_demand_ack_t, number) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_pitch_demand_ack_t, state) }, \
         } \
}


/**
 * @brief Pack a pitch_demand_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param number Sequence number for this message
 * @param state State of the pitch control system on the Autopilot (0 = not in pitch-controllable mode, 1 = armed, 2 = active)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pitch_demand_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t number, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN];
	_mav_put_uint8_t(buf, 0, number);
	_mav_put_uint8_t(buf, 1, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#else
	mavlink_pitch_demand_ack_t packet;
	packet.number = number;
	packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PITCH_DEMAND_ACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif
}

/**
 * @brief Pack a pitch_demand_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param number Sequence number for this message
 * @param state State of the pitch control system on the Autopilot (0 = not in pitch-controllable mode, 1 = armed, 2 = active)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pitch_demand_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t number,uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN];
	_mav_put_uint8_t(buf, 0, number);
	_mav_put_uint8_t(buf, 1, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#else
	mavlink_pitch_demand_ack_t packet;
	packet.number = number;
	packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PITCH_DEMAND_ACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif
}

/**
 * @brief Encode a pitch_demand_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pitch_demand_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pitch_demand_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pitch_demand_ack_t* pitch_demand_ack)
{
	return mavlink_msg_pitch_demand_ack_pack(system_id, component_id, msg, pitch_demand_ack->number, pitch_demand_ack->state);
}

/**
 * @brief Encode a pitch_demand_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pitch_demand_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pitch_demand_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pitch_demand_ack_t* pitch_demand_ack)
{
	return mavlink_msg_pitch_demand_ack_pack_chan(system_id, component_id, chan, msg, pitch_demand_ack->number, pitch_demand_ack->state);
}

/**
 * @brief Send a pitch_demand_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param number Sequence number for this message
 * @param state State of the pitch control system on the Autopilot (0 = not in pitch-controllable mode, 1 = armed, 2 = active)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pitch_demand_ack_send(mavlink_channel_t chan, uint8_t number, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN];
	_mav_put_uint8_t(buf, 0, number);
	_mav_put_uint8_t(buf, 1, state);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK, buf, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK, buf, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif
#else
	mavlink_pitch_demand_ack_t packet;
	packet.number = number;
	packet.state = state;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK, (const char *)&packet, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK, (const char *)&packet, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pitch_demand_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t number, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, number);
	_mav_put_uint8_t(buf, 1, state);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK, buf, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK, buf, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif
#else
	mavlink_pitch_demand_ack_t *packet = (mavlink_pitch_demand_ack_t *)msgbuf;
	packet->number = number;
	packet->state = state;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK, (const char *)packet, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PITCH_DEMAND_ACK, (const char *)packet, MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PITCH_DEMAND_ACK UNPACKING


/**
 * @brief Get field number from pitch_demand_ack message
 *
 * @return Sequence number for this message
 */
static inline uint8_t mavlink_msg_pitch_demand_ack_get_number(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field state from pitch_demand_ack message
 *
 * @return State of the pitch control system on the Autopilot (0 = not in pitch-controllable mode, 1 = armed, 2 = active)
 */
static inline uint8_t mavlink_msg_pitch_demand_ack_get_state(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a pitch_demand_ack message into a struct
 *
 * @param msg The message to decode
 * @param pitch_demand_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_pitch_demand_ack_decode(const mavlink_message_t* msg, mavlink_pitch_demand_ack_t* pitch_demand_ack)
{
#if MAVLINK_NEED_BYTE_SWAP
	pitch_demand_ack->number = mavlink_msg_pitch_demand_ack_get_number(msg);
	pitch_demand_ack->state = mavlink_msg_pitch_demand_ack_get_state(msg);
#else
	memcpy(pitch_demand_ack, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PITCH_DEMAND_ACK_LEN);
#endif
}
