#include <port_stm8/impl/stm8_device_humidity.h>

#include <custom_sensor_data.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

static int8_t s_device_humidity_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_humidity_open ( device_id_t id )
{
  ( void ) id;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_humidity_read ( void* dest, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_humidity ) <= len )
  {
    memcpy ( dest, &g_sensor_data.sensor_humidity, sizeof ( g_sensor_data.sensor_humidity ) );
    return sizeof ( g_sensor_data.sensor_humidity );
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_humidity_write ( const void* src, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_humidity ) >= len )
  {
    memcpy ( &g_sensor_data.sensor_humidity, src, len );
    return len;
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_humidity_ioctl ( uint16_t operation, void* ptr )
{
  ( void ) operation;
  ( void ) ptr;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static void s_device_humidity_close ( device_id_t id )
{
  ( void ) id;

}

/*---------------------------------------------------------------------------*/

const device_descriptor_t g_stm8_device_humidity =
{
  .init = s_device_humidity_init,
  .open = s_device_humidity_open,
  .read = s_device_humidity_read,
  .write = s_device_humidity_write,
  .ioctl = s_device_humidity_ioctl,
  .close = s_device_humidity_close
};
