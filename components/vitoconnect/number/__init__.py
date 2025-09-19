import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import number
from esphome.const import CONF_ID, CONF_NAME, CONF_ADDRESS, CONF_LENGTH
from .. import vitoconnect_ns, VitoConnect, CONF_VITOCONNECT_ID

CONF_ADDRESS = "address"
CONF_LENGTH  = "length"

DEPENDENCIES = ["vitoconnect"]
OPTOLINKNumber = vitoconnect_ns.class_("OPTOLINKNumber", number.Number)

# first create your own additions
EXTRA_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(OPTOLINKNumber),
    cv.GenerateID(CONF_VITOCONNECT_ID): cv.use_id(VitoConnect),
    cv.Required(CONF_ADDRESS): cv.uint16_t,
    cv.Required(CONF_LENGTH): cv.uint8_t,
})

# then extend the base number schema with it
CONFIG_SCHEMA = number.number_schema().extend(EXTRA_SCHEMA)

async def to_code(config):
    var = await number.new_number(config, min_value = 0, max_value = 30, step = 1)

    # Add configuration to datapoint
    cg.add(var.setAddress(config[CONF_ADDRESS]))
    cg.add(var.setLength(config[CONF_LENGTH]))
    cg.add(var.setWrite(True))

    # Add number to component hub (VitoConnect)
    hub = await cg.get_variable(config[CONF_VITOCONNECT_ID])
    cg.add(hub.register_datapoint(var))
