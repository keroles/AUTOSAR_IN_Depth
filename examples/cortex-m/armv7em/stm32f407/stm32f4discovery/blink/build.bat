#goil -t=cortex-m/armv7em/stm32f407/stm32f4discovery --templates=../../../goil/templates/ blink.oil
path D:\courses\new_diploma\Diploma online\EmbeddedC\labs\unit3-lesson2\ARM\bin;%PATH%
del blink_exe.axf
python make.py 
copy blink_exe blink_exe.axf