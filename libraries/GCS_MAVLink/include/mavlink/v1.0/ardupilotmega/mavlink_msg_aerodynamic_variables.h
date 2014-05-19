// MESSAGE AERODYNAMIC_VARIABLES PACKING

#define MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES 179

typedef struct __mavlink_aerodynamic_variables_t
{
 float alpha; ///< Angle of attack (rad)
 float airspeed; ///< Airspeed (m/s)
 float beta; ///< Sideslip angle (rad)
} mavlink_aerodynamic_variables_t;

#define MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN 12
#define MAVLINK_MSG_ID_179_LEN 12

#define MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_CRC 131
#define MAVLINK_MSG_ID_179_CRC 131



#define MAVLINK_MESSAGE_INFO_AERODYNAMIC_VARIABLES { \
	"AERODYNAMIC_VARIABLES", \
	3, \
	{  { "alpha", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_aerodynamic_variables_t, alpha) }, \
         { "airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_aerodynamic_variables_t, airspeed) }, \
         { "beta", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_aerodynamic_variables_t, beta) }, \
         } \
}


/**
 * @brief Pack a aerodynamic_variables message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param alpha Angle of attack (rad)
 * @param airspeed Airspeed (m/s)
 * @param beta Sideslip angle (rad)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aerodynamic_variables_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float alpha, float airspeed, float beta)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN];
	_mav_put_float(buf, 0, alpha);
	_mav_put_float(buf, 4, airspeed);
	_mav_put_float(buf, 8, beta);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#else
	mavlink_aerodynamic_variables_t packet;
	packet.alpha = alpha;
	packet.airspeed = airspeed;
	packet.beta = beta;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif
}

/**
 * @brief Pack a aerodynamic_variables message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param alpha Angle of attack (rad)
 * @param airspeed Airspeed (m/s)
 * @param beta Sideslip angle (rad)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aerodynamic_variables_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float alpha,float airspeed,float beta)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN];
	_mav_put_float(buf, 0, alpha);
	_mav_put_float(buf, 4, airspeed);
	_mav_put_float(buf, 8, beta);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#else
	mavlink_aerodynamic_variables_t packet;
	packet.alpha = alpha;
	packet.airspeed = airspeed;
	packet.beta = beta;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif
}

/**
 * @brief Encode a aerodynamic_variables struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param aerodynamic_variables C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aerodynamic_variables_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_aerodynamic_variables_t* aerodynamic_variables)
{
	return mavlink_msg_aerodynamic_variables_pack(system_id, component_id, msg, aerodynamic_variables->alpha, aerodynamic_variables->airspeed, aerodynamic_variables->beta);
}

/**
 * @brief Encode a aerodynamic_variables struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param aerodynamic_variables C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aerodynamic_variables_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_aerodynamic_variables_t* aerodynamic_variables)
{
	return mavlink_msg_aerodynamic_variables_pack_chan(system_id, component_id, chan, msg, aerodynamic_variables->alpha, aerodynamic_variables->airspeed, aerodynamic_variables->beta);
}

/**
 * @brief Send a aerodynamic_variables message
 * @param chan MAVLink channel to send the message
 *
 * @param alpha Angle of attack (rad)
 * @param airspeed Airspeed (m/s)
 * @param beta Sideslip angle (rad)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_aerodynamic_variables_send(mavlink_channel_t chan, float alpha, float airspeed, float beta)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN];
	_mav_put_float(buf, 0, alpha);
	_mav_put_float(buf, 4, airspeed);
	_mav_put_float(buf, 8, beta);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES, buf, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES, buf, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif
#else
	mavlink_aerodynamic_variables_t packet;
	packet.alpha = alpha;
	packet.airspeed = airspeed;
	packet.beta = beta;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES, (const char *)&packet, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES, (const char *)&packet, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_aerodynamic_variables_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float alpha, float airspeed, float beta)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, alpha);
	_mav_put_float(buf, 4, airspeed);
	_mav_put_float(buf, 8, beta);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES, buf, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES, buf, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif
#else
	mavlink_aerodynamic_variables_t *packet = (mavlink_aerodynamic_variables_t *)msgbuf;
	packet->alpha = alpha;
	packet->airspeed = airspeed;
	packet->beta = beta;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES, (const char *)packet, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES, (const char *)packet, MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE AERODYNAMIC_VARIABLES UNPACKING


/**
 * @brief Get field alpha from aerodynamic_variables message
 *
 * @return Angle of attack (rad)
 */
static inline float mavlink_msg_aerodynamic_variables_get_alpha(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field airspeed from aerodynamic_variables message
 *
 * @return Airspeed (m/s)
 */
static inline float mavlink_msg_aerodynamic_variables_get_airspeed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field beta from aerodynamic_variables message
 *
 * @return Sideslip angle (rad)
 */
static inline float mavlink_msg_aerodynamic_variables_get_beta(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a aerodynamic_variables message into a struct
 *
 * @param msg The message to decode
 * @param aerodynamic_variables C-struct to decode the message contents into
 */
static inline void mavlink_msg_aerodynamic_variables_decode(const mavlink_message_t* msg, mavlink_aerodynamic_variables_t* aerodynamic_variables)
{
#if MAVLINK_NEED_BYTE_SWAP
	aerodynamic_variables->alpha = mavlink_msg_aerodynamic_variables_get_alpha(msg);
	aerodynamic_variables->airspeed = mavlink_msg_aerodynamic_variables_get_airspeed(msg);
	aerodynamic_variables->beta = mavlink_msg_aerodynamic_variables_get_beta(msg);
#else
	memcpy(aerodynamic_variables, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AERODYNAMIC_VARIABLES_LEN);
#endif
}
