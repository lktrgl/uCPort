#include <port_stm8/impl/stm8_device_led.h>

#include <vent_ctrlr/custom_sensor_data.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

#include <stm8s.h>

/*---------------------------------------------------------------------------*/

#define LED_GPIO_PORT  (GPIOD)
#define LED_GPIO_PIN   (GPIO_PIN_6)

/*---------------------------------------------------------------------------*/

static int8_t s_device_led_init()
{
  /* Initialize I/Os in Output Mode */
  GPIO_Init ( LED_GPIO_PORT, ( GPIO_Pin_TypeDef ) LED_GPIO_PIN, GPIO_MODE_OUT_PP_LOW_FAST );
  GPIO_WriteLow ( LED_GPIO_PORT, ( GPIO_Pin_TypeDef ) LED_GPIO_PIN );

  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_led_open ( device_id_t id )
{
  ( void ) id;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_led_read ( void* dest, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_is_led ) <= len )
  {
    memcpy ( dest, &g_sensor_data.sensor_is_led, sizeof ( g_sensor_data.sensor_is_led ) );
    return sizeof ( g_sensor_data.sensor_is_led );
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_led_write ( const void* src, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_is_led ) >= len )
  {
    memcpy ( &g_sensor_data.sensor_is_led, src, len );

    if ( g_sensor_data.sensor_is_led )
    {
      GPIO_WriteHigh ( LED_GPIO_PORT, ( GPIO_Pin_TypeDef ) LED_GPIO_PIN );
    }
    else
    {
      GPIO_WriteLow ( LED_GPIO_PORT, ( GPIO_Pin_TypeDef ) LED_GPIO_PIN );
    }

    return len;
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_led_ioctl ( uint16_t operation, void* ptr )
{
  ( void ) operation;
  ( void ) ptr;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static void s_device_led_close ( device_id_t id )
{
  ( void ) id;

  GPIO_WriteLow ( LED_GPIO_PORT, ( GPIO_Pin_TypeDef ) LED_GPIO_PIN );
}

/*---------------------------------------------------------------------------*/

const device_descriptor_t g_stm8_device_led =
{
  .init = s_device_led_init,
  .open = s_device_led_open,
  .read = s_device_led_read,
  .write = s_device_led_write,
  .ioctl = s_device_led_ioctl,
  .close = s_device_led_close
};

