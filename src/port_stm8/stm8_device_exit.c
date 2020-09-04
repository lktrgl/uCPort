#include <port_stm8/impl/stm8_device_exit.h>

#include <custom_sensor_data.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

#include <stm8s.h>

/*---------------------------------------------------------------------------*/

static int8_t s_device_exit_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_exit_open ( device_id_t id )
{
  ( void ) id;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_exit_read ( void* dest, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_is_exit ) <= len )
  {
    memcpy ( dest, &g_sensor_data.sensor_is_exit, sizeof ( g_sensor_data.sensor_is_exit ) );
    return sizeof ( g_sensor_data.sensor_is_exit );
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_exit_write ( const void* src, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_is_exit ) >= len )
  {
    memcpy ( &g_sensor_data.sensor_is_exit, src, len );

    if ( g_sensor_data.sensor_is_exit )
    {
      WWDG_SWReset();
    }

    return len;
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_exit_ioctl ( uint16_t operation, void* ptr )
{
  ( void ) operation;
  ( void ) ptr;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static void s_device_exit_close ( device_id_t id )
{
  ( void ) id;

}

/*---------------------------------------------------------------------------*/

const device_descriptor_t g_stm8_device_exit =
{
  .init = s_device_exit_init,
  .open = s_device_exit_open,
  .read = s_device_exit_read,
  .write = s_device_exit_write,
  .ioctl = s_device_exit_ioctl,
  .close = s_device_exit_close
};

