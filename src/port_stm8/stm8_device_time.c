#include <port_stm8/impl/stm8_device_time.h>

#include <custom_sensor_data.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

static int8_t s_device_time_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_time_open ( device_id_t id )
{
  ( void ) id;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_time_read ( void* dest, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_tick_counter ) <= len )
  {
    memcpy ( dest, &g_sensor_data.sensor_tick_counter, sizeof ( g_sensor_data.sensor_tick_counter ) );
    return sizeof ( g_sensor_data.sensor_tick_counter );
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_time_write ( const void* src, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_tick_counter ) >= len )
  {
    memcpy ( &g_sensor_data.sensor_tick_counter, src, len );
    return len;
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_time_ioctl ( uint16_t operation, void* ptr )
{
  ( void ) operation;
  ( void ) ptr;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static void s_device_time_close ( device_id_t id )
{
  ( void ) id;

}

/*---------------------------------------------------------------------------*/

const device_descriptor_t g_stm8_device_time =
{
  .init = s_device_time_init,
  .open = s_device_time_open,
  .read = s_device_time_read,
  .write = s_device_time_write,
  .ioctl = s_device_time_ioctl,
  .close = s_device_time_close
};

