#include <port_stm8/stm8_device.h>

#include <port_stm8/impl/stm8_device_humidity.h>
#include <port_stm8/impl/stm8_device_temperature.h>
#include <port_stm8/impl/stm8_device_light.h>
#include <port_stm8/impl/stm8_device_time.h>
#include <port_stm8/impl/stm8_device_motor.h>
#include <port_stm8/impl/stm8_device_led.h>
#include <port_stm8/impl/stm8_device_exit.h>

#include <custom_sensor_data.h>

#include <ioapi/device.h>

#include <port_stm8/impl/stm8s_conf.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

static const device_descriptor_t* s_device_registry[/*DEV_COUNT+1*/] =
{
  /*[DEV_HUMIDITY] = */&g_stm8_device_humidity,
  /*[DEV_TEMPERATURE] = */&g_stm8_device_temperature,
  /*[DEV_LIGHT] = */&g_stm8_device_light,
  /*[DEV_TIME] = */&g_stm8_device_time,
  /*[DEV_MOTOR] = */&g_stm8_device_motor,
  /*[DEV_LED] = */&g_stm8_device_led,
  /*[DEV_EXIT] = */&g_stm8_device_exit,
  NULL
};

/*---------------------------------------------------------------------------*/

void install_stm8_device()
{
  /* assert */ ( DEVICE_OK == device_register ( s_device_registry ) );

  device_init_all();
}

/*---------------------------------------------------------------------------*/

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed ( uint8_t* file, uint32_t line )
{
  ( void ) file;
  ( void ) line;

  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while ( 1 )
  {
  }
}
#endif
