import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import number
from esphome.const import CONF_ID, CONF_NAME, CONF_ADDRESS
from .. import vitoconnect_ns, VitoConnect, CONF_VITOCONNECT_ID

DEPENDENCIES = ["vitoconnect"]
OPTOLINKNumber = vitoconnect_ns.class_("OPTOLINKNumber", number.Number)

CONFIG_SCHEMA = number.NUMBER_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(OPTOLINKNumber),
    cv.GenerateID(CONF_VITOCONNECT_ID): cv.use_id(VitoConnect),
    cv.Required(CONF_ADDRESS): cv.uint16_t,
})

async def to_code(config):
    var = await number.new_number(config, min_value = 0, max_value = 1, step = 1)

    # Add configuration to datapoint
    cg.add(var.setAddress(config[CONF_ADDRESS]))
    cg.add(var.setLength(1))
    cg.add(var.setWrite(True))

    # Add number to component hub (VitoConnect)
    hub = await cg.get_variable(config[CONF_VITOCONNECT_ID])
    cg.add(hub.register_datapoint(var))
