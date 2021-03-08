#include <port_stm8/impl/stm8_device_temperature.h>

#include <vent_ctrlr/custom_sensor_data.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

static int8_t s_device_temperature_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_temperature_open ( const char* device_name )
{
  ( void ) device_name;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_temperature_read ( void* dest, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_temperature ) <= len )
  {
    memcpy ( dest, &g_sensor_data.sensor_temperature, sizeof ( g_sensor_data.sensor_temperature ) );
    return sizeof ( g_sensor_data.sensor_temperature );
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_temperature_write ( const void* src, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_temperature ) >= len )
  {
    memcpy ( &g_sensor_data.sensor_temperature, src, len );
    return len;
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_temperature_ioctl ( uint16_t operation, void* ptr )
{
  ( void ) operation;
  ( void ) ptr;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static void s_device_temperature_close ( device_id_t id )
{
  ( void ) id;

}

/*---------------------------------------------------------------------------*/

const device_descriptor_t g_stm8_device_temperature =
{
  .device_name = "/dev/temperature",
  .init = s_device_temperature_init,
  .open = s_device_temperature_open,
  .read = s_device_temperature_read,
  .write = s_device_temperature_write,
  .ioctl = s_device_temperature_ioctl,
  .close = s_device_temperature_close
};

