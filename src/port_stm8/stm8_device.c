#include <port_stm8/stm8_device.h>

#include <port_stm8/impl/stm8_device_humidity.h>
#include <port_stm8/impl/stm8_device_temperature.h>
#include <port_stm8/impl/stm8_device_light.h>
#include <port_stm8/impl/stm8_device_time.h>
#include <port_stm8/impl/stm8_device_exit.h>

#include <custom_sensor_data.h>

#include <ioapi/device.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

static const device_descriptor_t* s_device_registry[] =
{
  &g_stm8_device_humidity,
  &g_stm8_device_temperature,
  &g_stm8_device_light,
  &g_stm8_device_time,
  &g_stm8_device_exit,
  NULL
};

/*---------------------------------------------------------------------------*/

void install_stm8_device()
{
  /* assert */ ( DEVICE_OK == device_register ( s_device_registry ) );

  device_init_all();
}
