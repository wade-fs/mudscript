inherit ROOM;
void create() {
	set( "short", "$HIW$你丟下一把喚雲扇。$BLK$" );
	set( "exits", ([
		"down"      : "/open/clan/hell/room/room130",
	]) );
	set( "long", @LONG

$HIB$  ╓──╖╓──╖╓─╖╖╓╥─╖╓──╖╓──╖╓    ╖
$BLU$  ╟──╖╟──╢║  ║║  ║    ╟──╢╙──╖║    ║
$HIC$  ║      ║    ║║  ║║  ║    ║    ║      ║╙─╥╜
$CYN$  ╙      ╙    ╜╙  ╙╜  ╨    ╙    ╜╙──╜  ─╨  
$HIB$                                  ╓──╖╓──╮╓──╖╓──╖╓──╖
$BLU$                                  ╙──╖║    ║╟──╢║      ╟──╖
$CYN$                                        ║╟──╜║    ║║      ║      
$HIC$◆$HIW$────────────────$CYN$╙──╜╙      ╙    ╜╙──╜╙──╜$HIW$─$HIC$◆
$CYN$
由於你對真實世界的牽掛, 你將回到原來的世界。
但是, 希望你不要忘了自己的使命和你對這狂想空間夥伴們的承諾。
你離開狂想空間了。$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
