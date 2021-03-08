#include <port_stm8/impl/stm8_device_time.h>

#include <vent_ctrlr/custom_sensor_data.h>

#include <stm8s.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

#define TIM1_INTERVAL_MS    (100U)
#define HSI_FREQ            (((uint32_t)16000000UL)/2U)
#define TIM1_FREQ_SOURCE    (500U)
#define TIM1_PRESCALER      (HSI_FREQ/TIM1_FREQ_SOURCE-1)
#define TIME1_RELOAD_VALUE  (TIM1_FREQ_SOURCE*TIM1_INTERVAL_MS/1000U)

/*---------------------------------------------------------------------------*/

static void s_TIM1_Config ( void )
{
  /* TIM1 Peripheral Configuration */
  TIM1_DeInit();
  TIM1_InternalClockConfig();

  /* Time Base configuration */
  TIM1_TimeBaseInit ( TIM1_PRESCALER, TIM1_COUNTERMODE_DOWN, TIME1_RELOAD_VALUE, 1 );
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_time_init()
{
  s_TIM1_Config();

  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_time_open ( const char* device_name )
{
  ( void ) device_name;

  /* TIM1 counter enable */
  TIM1_Cmd ( ENABLE );
  TIM1_ITConfig ( TIM1_IT_UPDATE, ENABLE );

  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_time_read ( void* dest, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_tick_counter ) <= len )
  {
    /* critical section */
    disableInterrupts();
    const uint32_t sensor_tick_counter = g_sensor_data.sensor_tick_counter;
    enableInterrupts();

    memcpy ( dest, &sensor_tick_counter, sizeof ( sensor_tick_counter ) );
    return sizeof ( sensor_tick_counter );
  }

  return 0;
}

/*---------------------------------------------------------------------------*/

static int16_t s_device_time_write ( const void* src, uint16_t len )
{
  if ( sizeof ( g_sensor_data.sensor_tick_counter ) >= len )
  {
    uint32_t sensor_tick_counter = 0;
    memcpy ( &sensor_tick_counter, src, len );

    /* critical section */
    disableInterrupts();
    g_sensor_data.sensor_tick_counter = sensor_tick_counter;
    enableInterrupts();

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

  /* TIM1 counter disable */
  TIM1_Cmd ( DISABLE );
  TIM1_ITConfig ( TIM1_IT_UPDATE, DISABLE );
}

/*---------------------------------------------------------------------------*/

const device_descriptor_t g_stm8_device_time =
{
  .device_name = "/dev/time",
  .init = s_device_time_init,
  .open = s_device_time_open,
  .read = s_device_time_read,
  .write = s_device_time_write,
  .ioctl = s_device_time_ioctl,
  .close = s_device_time_close
};

