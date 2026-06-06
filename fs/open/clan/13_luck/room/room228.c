inherit ROOM;
void create() {
	set( "short", "鎖龍塔入口" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount6"  : 1,
	]) );
	set( "build", 10037 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room230",
		"west"      : "/open/clan/13_luck/room/room11.c",
	]) );
	set( "long", @LONG

                                  ◢
                            ◢  ◢█               ◢
█                        ◢█◢██              █
 ▉                   ◢██████             ██
██            ◢████████◤            ██
 ██         ◢█◤▌◢████◤◣           ███
█  █  ◢███████████◤ ▌         ███
 ███ █████████████◤▌       ████
  ███  ◥  ＼◥ ◥██████◤- ▌     █  ██
 ████▄▄▄ ＼   ██████◣─ ▌   ██  ██
███  ███       ██◥███◣─ ▌  ███  █
██  █  █   ◤  ██◤██◥─── ▌ ███  ██
    ████ ◤  ██◤ ██ ────▌ █████
  ██  ██ ◥█◤   ██▌────▌ ██████
█  █████      ███ ────▌ ███████
█  ██ ███   ███ ──── ▌ ███  ██  █   

『無  問  正  邪  ，  任  憑  諸  君  活  著  來  。』
『莫  論  是  非  ，  只  許  眾  魂  死  著  去  。』

LONG);
	setup();
	replace_program(ROOM);
}
