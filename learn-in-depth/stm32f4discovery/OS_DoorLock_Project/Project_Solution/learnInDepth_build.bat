
SET Oil_file=LearnInDepth_SW.oil


goil -t=cortex-m/armv7em/stm32f407/stm32f4discovery --templates=../../../goil/templates/ %Oil_file%

python build.py
copy LearnInDepth_SW.axf ..\..\