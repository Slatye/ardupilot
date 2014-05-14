// MESSAGE AERODYN_VARS PACKING

#define MAVLINK_MSG_ID_AERODYN_VARS 179

typedef struct __mavlink_aerodyn_vars_t
{
 float alpha; ///< Angle of attack (rad)
 float airspeed; ///< Airspeed (m/s)
 float beta; ///< Sideslip angle (rad)
} mavlink_aerodyn_vars_t;

#define MAVLINK_MSG_ID_AERODYN_VARS_LEN 12
#define MAVLINK_MSG_ID_179_LEN 12

#define MAVLINK_MSG_ID_AERODYN_VARS_CRC 54
#define MAVLINK_MSG_ID_179_CRC 54



#define MAVLINK_MESSAGE_INFO_AERODYN_VARS { \
	"AERODYN_VARS", \
	3, \
	{  { "alpha", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_aerodyn_vars_t, alpha) }, \
         { "airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_aerodyn_vars_t, airspeed) }, \
         { "beta", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_aerodyn_vars_t, beta) }, \
         } \
}


/**
 * @brief Pack a aerodyn_vars message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param alpha Angle of attack (rad)
 * @param airspeed Airspeed (m/s)
 * @param beta Sideslip angle (rad)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aerodyn_vars_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float alpha, float airspeed, float beta)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AERODYN_VARS_LEN];
	_mav_put_float(buf, 0, alpha);
	_mav_put_float(buf, 4, airspeed);
	_mav_put_float(buf, 8, beta);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#else
	mavlink_aerodyn_vars_t packet;
	packet.alpha = alpha;
	packet.airspeed = airspeed;
	packet.beta = beta;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AERODYN_VARS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AERODYN_VARS_LEN, MAVLINK_MSG_ID_AERODYN_VARS_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif
}

/**
 * @brief Pack a aerodyn_vars message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param alpha Angle of attack (rad)
 * @param airspeed Airspeed (m/s)
 * @param beta Sideslip angle (rad)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aerodyn_vars_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float alpha,float airspeed,float beta)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AERODYN_VARS_LEN];
	_mav_put_float(buf, 0, alpha);
	_mav_put_float(buf, 4, airspeed);
	_mav_put_float(buf, 8, beta);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#else
	mavlink_aerodyn_vars_t packet;
	packet.alpha = alpha;
	packet.airspeed = airspeed;
	packet.beta = beta;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AERODYN_VARS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AERODYN_VARS_LEN, MAVLINK_MSG_ID_AERODYN_VARS_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif
}

/**
 * @brief Encode a aerodyn_vars struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param aerodyn_vars C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aerodyn_vars_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_aerodyn_vars_t* aerodyn_vars)
{
	return mavlink_msg_aerodyn_vars_pack(system_id, component_id, msg, aerodyn_vars->alpha, aerodyn_vars->airspeed, aerodyn_vars->beta);
}

/**
 * @brief Encode a aerodyn_vars struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param aerodyn_vars C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aerodyn_vars_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_aerodyn_vars_t* aerodyn_vars)
{
	return mavlink_msg_aerodyn_vars_pack_chan(system_id, component_id, chan, msg, aerodyn_vars->alpha, aerodyn_vars->airspeed, aerodyn_vars->beta);
}

/**
 * @brief Send a aerodyn_vars message
 * @param chan MAVLink channel to send the message
 *
 * @param alpha Angle of attack (rad)
 * @param airspeed Airspeed (m/s)
 * @param beta Sideslip angle (rad)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_aerodyn_vars_send(mavlink_channel_t chan, float alpha, float airspeed, float beta)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AERODYN_VARS_LEN];
	_mav_put_float(buf, 0, alpha);
	_mav_put_float(buf, 4, airspeed);
	_mav_put_float(buf, 8, beta);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYN_VARS, buf, MAVLINK_MSG_ID_AERODYN_VARS_LEN, MAVLINK_MSG_ID_AERODYN_VARS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYN_VARS, buf, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif
#else
	mavlink_aerodyn_vars_t packet;
	packet.alpha = alpha;
	packet.airspeed = airspeed;
	packet.beta = beta;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYN_VARS, (const char *)&packet, MAVLINK_MSG_ID_AERODYN_VARS_LEN, MAVLINK_MSG_ID_AERODYN_VARS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYN_VARS, (const char *)&packet, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_AERODYN_VARS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_aerodyn_vars_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float alpha, float airspeed, float beta)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, alpha);
	_mav_put_float(buf, 4, airspeed);
	_mav_put_float(buf, 8, beta);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYN_VARS, buf, MAVLINK_MSG_ID_AERODYN_VARS_LEN, MAVLINK_MSG_ID_AERODYN_VARS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYN_VARS, buf, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif
#else
	mavlink_aerodyn_vars_t *packet = (mavlink_aerodyn_vars_t *)msgbuf;
	packet->alpha = alpha;
	packet->airspeed = airspeed;
	packet->beta = beta;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYN_VARS, (const char *)packet, MAVLINK_MSG_ID_AERODYN_VARS_LEN, MAVLINK_MSG_ID_AERODYN_VARS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AERODYN_VARS, (const char *)packet, MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE AERODYN_VARS UNPACKING


/**
 * @brief Get field alpha from aerodyn_vars message
 *
 * @return Angle of attack (rad)
 */
static inline float mavlink_msg_aerodyn_vars_get_alpha(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field airspeed from aerodyn_vars message
 *
 * @return Airspeed (m/s)
 */
static inline float mavlink_msg_aerodyn_vars_get_airspeed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field beta from aerodyn_vars message
 *
 * @return Sideslip angle (rad)
 */
static inline float mavlink_msg_aerodyn_vars_get_beta(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a aerodyn_vars message into a struct
 *
 * @param msg The message to decode
 * @param aerodyn_vars C-struct to decode the message contents into
 */
static inline void mavlink_msg_aerodyn_vars_decode(const mavlink_message_t* msg, mavlink_aerodyn_vars_t* aerodyn_vars)
{
#if MAVLINK_NEED_BYTE_SWAP
	aerodyn_vars->alpha = mavlink_msg_aerodyn_vars_get_alpha(msg);
	aerodyn_vars->airspeed = mavlink_msg_aerodyn_vars_get_airspeed(msg);
	aerodyn_vars->beta = mavlink_msg_aerodyn_vars_get_beta(msg);
#else
	memcpy(aerodyn_vars, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AERODYN_VARS_LEN);
#endif
}
