#include <port_test/test_device.h>

#include <vent_ctrlr/custom_sensor_data.h>

#include <ioapi/device.h>

#include <stddef.h>
#include <assert.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

static int8_t s_device_humidity_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_humidity_open ( const char* device_name )
{
  ( void ) device_name;
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

static const device_descriptor_t s_device_humidity =
{
  .init = s_device_humidity_init,
  .open = s_device_humidity_open,
  .read = s_device_humidity_read,
  .write = s_device_humidity_write,
  .ioctl = s_device_humidity_ioctl,
  .close = s_device_humidity_close
};

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

static const device_descriptor_t s_device_temperature =
{
  .device_name = "/dev/temperature",
  .init = s_device_temperature_init,
  .open = s_device_temperature_open,
  .read = s_device_temperature_read,
  .write = s_device_temperature_write,
  .ioctl = s_device_temperature_ioctl,
  .close = s_device_temperature_close
};

/*---------------------------------------------------------------------------*/

static int8_t s_device_light_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_light_open ( const char* device_name )
{
  ( void ) device_name;
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

static const device_descriptor_t s_device_light =
{
  .device_name = "/dev/light",
  .init = s_device_light_init,
  .open = s_device_light_open,
  .read = s_device_light_read,
  .write = s_device_light_write,
  .ioctl = s_device_light_ioctl,
  .close = s_device_light_close
};

/*---------------------------------------------------------------------------*/

static int8_t s_device_time_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_time_open ( const char* device_name )
{
  ( void ) device_name;
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

static const device_descriptor_t s_device_time =
{
  .device_name = "/dev/time",
  .init = s_device_time_init,
  .open = s_device_time_open,
  .read = s_device_time_read,
  .write = s_device_time_write,
  .ioctl = s_device_time_ioctl,
  .close = s_device_time_close
};

/*---------------------------------------------------------------------------*/

static int8_t s_device_motor_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_motor_open ( const char* device_name )
{
  ( void ) device_name;
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

}

/*---------------------------------------------------------------------------*/

static const device_descriptor_t s_device_motor =
{
  .device_name = "/dev/motor",
  .init = s_device_motor_init,
  .open = s_device_motor_open,
  .read = s_device_motor_read,
  .write = s_device_motor_write,
  .ioctl = s_device_motor_ioctl,
  .close = s_device_motor_close
};

/*---------------------------------------------------------------------------*/

static int8_t s_device_led_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_led_open ( const char* device_name )
{
  ( void ) device_name;
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

}

/*---------------------------------------------------------------------------*/

static const device_descriptor_t s_device_led =
{
  .device_name = "/dev/led",
  .init = s_device_led_init,
  .open = s_device_led_open,
  .read = s_device_led_read,
  .write = s_device_led_write,
  .ioctl = s_device_led_ioctl,
  .close = s_device_led_close
};

/*---------------------------------------------------------------------------*/

static int8_t s_device_exit_init()
{
  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

static int8_t s_device_exit_open ( const char* device_name )
{
  ( void ) device_name;
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

static const device_descriptor_t s_device_exit =
{
  .device_name = "/dev/exit",
  .init = s_device_exit_init,
  .open = s_device_exit_open,
  .read = s_device_exit_read,
  .write = s_device_exit_write,
  .ioctl = s_device_exit_ioctl,
  .close = s_device_exit_close
};

/*---------------------------------------------------------------------------*/

static const device_descriptor_t* s_device_registry[/*DEV_COUNT+1*/] =
{
  /*[DEV_HUMIDITY] = */&s_device_humidity,
  /*[DEV_TEMPERATURE] = */&s_device_temperature,
  /*[DEV_LIGHT] = */&s_device_light,
  /*[DEV_TIME] = */&s_device_time,
  /*[DEV_MOTOR] = */&s_device_motor,
  /*[DEV_LED] = */&s_device_led,
  /*[DEV_EXIT] = */&s_device_exit,
  NULL
};

/*---------------------------------------------------------------------------*/

void install_device_simulation()
{
  const int8_t reg_result = device_register ( s_device_registry );
  ( void ) reg_result;
  assert ( DEVICE_OK == reg_result );
  device_init_all();
}
