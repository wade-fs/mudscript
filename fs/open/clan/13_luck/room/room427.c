inherit ROOM;
void create() {
	set( "short", "幻世錄2故事背景2" );
	set( "object", ([
		"amount5"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "owner", "dfyw" );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room443",
	]) );
	set( "long", @LONG

    但是，眾神的恩惠並沒有給這五個種族帶來任何的幸福，反而使
這五個種族在這片大地上製造更多的災禍與戰亂，雖然戰亂的起源以
久不可考，不過，在歷經近千年的爭執、戰亂之後，五個種族總算在
新的領導者的帶領下達成共識，願意停止戰火，協議暫時的維持和平
，才使得這近千年的混亂得以平息。但是災難並沒有就平息，反而變
成戰亂的開端.....

LONG);
	setup();
	replace_program(ROOM);
}
