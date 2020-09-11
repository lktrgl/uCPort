#include <port_stm8/impl/stm8_device_light.h>

#include <vent_ctrlr/custom_sensor_data.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

static int8_t s_device_light_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_light_open ( device_id_t id )
{
  ( void ) id;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_light_read ( void* dest, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_light ) <= len )
  {
    memcpy ( dest, &g_sensor_data.sensor_light, sizeof ( g_sensor_data.sensor_light ) );
    return sizeof ( g_sensor_data.sensor_light );
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_light_write ( const void* src, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_light ) >= len )
  {
    memcpy ( &g_sensor_data.sensor_light, src, len );
    return len;
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_light_ioctl ( uint16_t operation, void* ptr )
{
  ( void ) operation;
  ( void ) ptr;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static void s_device_light_close ( device_id_t id )
{
  ( void ) id;

}

/*---------------------------------------------------------------------------*/

const device_descriptor_t g_stm8_device_light =
{
  .init = s_device_light_init,
  .open = s_device_light_open,
  .read = s_device_light_read,
  .write = s_device_light_write,
  .ioctl = s_device_light_ioctl,
  .close = s_device_light_close
};

