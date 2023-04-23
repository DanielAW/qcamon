MEMORY
{
	INCLUDE gen/memory.ld
}
SECTIONS
{
.text :
    {
        *(.literal)
    } >litpool
}
SECTIONS
{
	INCLUDE gen/nexmon.ld
}
