## sources and targets
TARGET		= main
SRC 		= main.c util.c key_tap.c uart88.c uart_helper.c
FORMAT		= ihex

## target hardware 
MCU		= atmega88p
F_CPU		= 8000000UL
LFUSE 		= 0xD2
HFUSE 		= 0xDD
EFUSE 	        = 0xF9

## avrdude configuration
AVRDUDE_PROG	= usbasp
AVRDUDE_FLAGS  = -y 

AVRDUDE_FLAGS += -p $(MCU) -c $(AVRDUDE_PROG)

AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex
AVRDUDE_WRITE_EEPROM = -U eeprom:w:$(TARGET).eep

## Compiler settings
CC		= avr-gcc 
OPT 		= s
DEBUG 		= dwarf-2
CSTANDARD 	= -std=gnu99

CFLAGS 		+= -g$(DEBUG) -g1
CFLAGS 		+= -O$(OPT)
CFLAGS 		+= -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -feliminate-unused-debug-types -ffunction-sections
CFLAGS 		+= -Wall 
CFLAGS 		+= -Wa,-adhlns=$(<:.c=.lst)
CFLAGS 		+= $(CSTANDARD)
CFLAGS 		+= -DF_CPU=$(F_CPU)

GENDEPFLAGS 	= -MD -MP -MF .dep/$(@F).d
ALL_CFLAGS 	= -mmcu=$(MCU) -I. $(CFLAGS) $(GENDEPFLAGS)

LDFLAGS 	= -s -Wl,-Map=$(TARGET).map,--cref,--gc-sections,--relax

## TOOLS
AVRDUDE 	= avrdude
SIZE		= avr-size
OBJCOPY 	= avr-objcopy
OBJDUMP 	= avr-objdump
NM 		= avr-nm
REMOVE 		= rm -f
SHELL 		= sh
COPY 		= cp

## INTERNAL 
OBJ 		= $(SRC:.c=.o)
LST 		= $(SRC:.c=.lst)

# Default target.
all: sizebefore build sizeafter

build: elf hex eep lss sym lst

elf: $(TARGET).elf
hex: $(TARGET).hex
eep: $(TARGET).eep
lss: $(TARGET).lss
sym: $(TARGET).sym
lst: $(LST)

# Display size of file.
HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex
ELFSIZE = $(SIZE) -A $(TARGET).elf
sizebefore:
	@if [ -f $(TARGET).elf ]; then echo; $(ELFSIZE); echo; fi

sizeafter:
	@if [ -f $(TARGET).elf ]; then echo; $(ELFSIZE); echo; fi

# Display compiler version information.
gccversion :
	@$(CC) --version

# Program the device.
program: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) $(AVRDUDE_WRITE_EEPROM)

# Create final output files (.hex, .eep) from ELF output file.
%.hex: %.elf
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

%.eep: %.elf
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 -O $(FORMAT) $< $@

# Create extended listing file from ELF output file.
%.lss: %.elf
	$(OBJDUMP) -h -S $< > $@

# Create a symbol table from ELF output file.
%.sym: %.elf
	$(NM) -n $< > $@

# Link: create ELF output file from object files.
.SECONDARY : $(TARGET).elf
.PRECIOUS : $(OBJ)

%.elf: $(OBJ)
	$(CC) $(ALL_CFLAGS) $(OBJ) --output $@ $(LDFLAGS)

# Compile: create object files from C source files.
%.o : %.c
	$(CC) -c $(ALL_CFLAGS) $< -o $@


# Compile: create assembler files from C source files.
%.s : %.c
	$(CC) -S $(ALL_CFLAGS) $< -o $@


lfuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -i 10 -U lfuse:w:$(LFUSE):m
hfuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -i 10 -U hfuse:w:$(HFUSE):m
efuse:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -i 10 -U efuse:w:$(EFUSE):m
fuses: lfuse hfuse efuse

reset:
	$(AVRDUDE) $(AVRDUDE_FLAGS) -i 10 -U lfuse:r:/dev/null

# Target: clean project.
clean: clean_list

clean_list :
	$(REMOVE) $(TARGET).hex
	$(REMOVE) $(TARGET).eep
	$(REMOVE) $(TARGET).obj
	$(REMOVE) $(TARGET).cof
	$(REMOVE) $(TARGET).elf
	$(REMOVE) $(TARGET).map
	$(REMOVE) $(TARGET).obj
	$(REMOVE) $(TARGET).a90
	$(REMOVE) $(TARGET).sym
	$(REMOVE) $(TARGET).lnk
	$(REMOVE) $(TARGET).lss
	$(REMOVE) $(OBJ)
	$(REMOVE) $(LST)
	$(REMOVE) $(SRC:.c=.s)
	$(REMOVE) $(SRC:.c=.o)
	$(REMOVE) $(SRC:.c=.d)
	$(REMOVE) .dep/*



# Include the dependency files.
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)


# Listing of phony targets.
.PHONY : all sizebefore sizeafter gccversion \
build elf hex eep lss sym coff extcoff \
clean clean_list program lst \
lfuse hfuse efuse fuses reset
