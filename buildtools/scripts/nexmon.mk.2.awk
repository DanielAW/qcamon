{
	if ($2 == "PATCH")
    {
        split($5,file,"_");
		print "\t$(Q)$(CC)objcopy -O binary -j .text." $4 " $< gen/section.bin && dd if=gen/section.bin of="$5" bs=1 conv=notrunc seek=$$((" $1 " - 0x" file[2] "))\n\t$(Q)printf \"  PATCH " $4 " @ " $1 "\\n\"";
    }
	else if ($2 == "REGION")
    {
        split($5,file,"_");
		print "\t$(Q)$(CC)objcopy -O binary -j .text." $1 " $< gen/section.bin && dd if=gen/section.bin of="$5" bs=1 conv=notrunc seek=$$((0x" $4 " - 0x" file[2] "))\t$(Q)printf \"  REGION " $1 " @ " $4 "\\n\"";
    }
	else if ($2 == "TARGETREGION" && $4 != "")
    {
        split($5,file,"_");
		print "\t$(Q)$(CC)objcopy -O binary -j .text." $1 " $< gen/section.bin && dd if=gen/section.bin of="$5" bs=1 conv=notrunc seek=$$((0x" $4 " - 0x" file[2] "))\n\t$(Q)printf \"  TARGETREGION " $1 " @ " $4 "\\n\"";
    }
}
