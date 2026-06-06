inherit ROOM;
void create() {
	set( "short", "$HBRED$葛來分多$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room191.c",
		"west"      : "/open/clan/time-limit/room/room24.c",
		"east"      : "/open/clan/time-limit/room/room189.c",
	]) );
	set( "long", @LONG
葛來分多的代表動物是獅,來自荒野,英勇無匹的葛來分多,創辦了葛來分多學
院,那裡有著蘊藏在內心深處的勇氣,他們的勇敢.活力和騎士精神,是葛來分多
特有的最大利器,葛來分多只挑選具有勇氣的學生,希望他的學生都能勇敢地面
對所有的挑戰

LONG);
	setup();
	replace_program(ROOM);
}
