# Source files 
TARGET 	= main
SOURCES	= main.c util.c key_tap.c uart4313.c uart_helper.c

# Target MCU & fuses
MCU	= attiny2313
F_CPU	= 8000000UL
LFUSE	= 0xD4
HFUSE	= 0xDB
EFUSE   = 0xFF

# Compiler configuration
CC     = avr-gcc 
OPT    = s

CFLAGS = -Wall -DF_CPU=$(F_CPU) -O$(OPT)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -feliminate-unused-debug-types -ffunction-sections
CFLAGS += -Wa,-adhlns=$(<:.c=.s)

ALL_CFLAGS = -mmcu=$(MCU)  $(CFLAGS)

LDFLAGS    = -s -Wl,-Map=$(TARGET).map,--cref,--gc-sections,--relax

# Avrdude configuration
AVRDUDE_PROG	= usbasp
AVRDUDE_FLAGS   = -y -p $(MCU) -c $(AVRDUDE_PROG)

AVRDUDE_WRITE_FLASH  = -U flash:w:$(TARGET).hex
AVRDUDE_WRITE_EEPROM = -U eeprom:w:$(TARGET).eep

# Other tools
OBJCOPY = avr-objcopy
SIZE	= avr-size
AVRDUDE	= avrdude

# Targets
.PHONY: all
all: depend hex eeprom size

.PHONY: hex
hex: $(TARGET).hex

.PHONY: eeprom
eeprom: $(TARGET).eep

OBJECTS	= $(SOURCES:.c=.o)
ASM = $(SOURCES:.c=.s)

$(TARGET).elf: $(OBJECTS)
	@echo "LD  $(OBJECTS)";\
	$(CC) $(ALL_CFLAGS) $(OBJECTS) --output $@ $(LDFLAGS)

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(TARGET).eep: $(TARGET).elf
	-$(OBJCOPY) -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 $< $@
%.o : %.c
	@echo "CC  $< -o $@";\
	$(CC) -c $(ALL_CFLAGS) $< -o $@

# Programming with avrdude

.PHONY: program
program: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) $(AVRDUDE_WRITE_EEPROM)

.PHONY: fuses
fuses: lfuse hfuse efuse
.PHONY: lfuse
lfuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -i 10 -U lfuse:w:$(LFUSE):m
.PHONY: hfuse
hfuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -i 10 -U hfuse:w:$(HFUSE):m
.PHONY: efuse
efuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -i 10 -U efuse:w:$(EFUSE):m
.PHONY: reset
reset:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -i 10 -U lfuse:r:/dev/null:m

# Clean
.PHONY: clean
clean:
	rm -f $(TARGET).hex $(TARGET).eep $(TARGET).elf $(TARTGET).map
	rm -f $(OBJECTS)
	rm -f $(ASM)

# Display Size
.PHONY: size
size: $(TARGET).elf
	@echo -n "SIZE "; $(SIZE) -A $(TARGET).elf

# Display flags
.PHONY: cflags
cflags:
	@echo CFLAGS=$(CFLAGS)
.PHONY: ldflags
ldflags:
	@echo LDFLAGS=$(LDFLAGS)
.PHONY: all_cflags
all_cflags:
	@echo ALL_CFLAGS=$(ALL_CFLAGS)

# dependeny 
.PHONY: depend
depend:
	@echo "DEP $(SOURCES)"; $(CC) $(ALL_CFLAGS) -MM $(SOURCES) > .depend

ifeq (.depend,$(wildcard .depend)) 
include .depend
endif

