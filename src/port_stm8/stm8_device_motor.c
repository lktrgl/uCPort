#include <port_stm8/impl/stm8_device_motor.h>

#include <custom_sensor_data.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

#include <stm8s.h>

/*---------------------------------------------------------------------------*/

#define MOTOR_GPIO_PORT  (GPIOC)
#define MOTOR_GPIO_PIN   (GPIO_PIN_5)

/*---------------------------------------------------------------------------*/

static int8_t s_device_motor_init()
{
  /* Initialize I/Os in Output Mode */
  GPIO_Init ( MOTOR_GPIO_PORT, ( GPIO_Pin_TypeDef ) MOTOR_GPIO_PIN, GPIO_MODE_OUT_PP_LOW_FAST );
  GPIO_WriteLow ( MOTOR_GPIO_PORT, ( GPIO_Pin_TypeDef ) MOTOR_GPIO_PIN );

  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_motor_open ( device_id_t id )
{
  ( void ) id;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_motor_read ( void* dest, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_is_motor ) <= len )
  {
    memcpy ( dest, &g_sensor_data.sensor_is_motor, sizeof ( g_sensor_data.sensor_is_motor ) );
    return sizeof ( g_sensor_data.sensor_is_motor );
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_motor_write ( const void* src, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_is_motor ) >= len )
  {
    memcpy ( &g_sensor_data.sensor_is_motor, src, len );

    if ( g_sensor_data.sensor_is_motor )
    {
      GPIO_WriteHigh ( MOTOR_GPIO_PORT, ( GPIO_Pin_TypeDef ) MOTOR_GPIO_PIN );
    }
    else
    {
      GPIO_WriteLow ( MOTOR_GPIO_PORT, ( GPIO_Pin_TypeDef ) MOTOR_GPIO_PIN );
    }

    return len;
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_motor_ioctl ( uint16_t operation, void* ptr )
{
  ( void ) operation;
  ( void ) ptr;
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static void s_device_motor_close ( device_id_t id )
{
  ( void ) id;

  GPIO_WriteLow ( MOTOR_GPIO_PORT, ( GPIO_Pin_TypeDef ) MOTOR_GPIO_PIN );
}

/*---------------------------------------------------------------------------*/

const device_descriptor_t g_stm8_device_motor =
{
  .init = s_device_motor_init,
  .open = s_device_motor_open,
  .read = s_device_motor_read,
  .write = s_device_motor_write,
  .ioctl = s_device_motor_ioctl,
  .close = s_device_motor_close
};

