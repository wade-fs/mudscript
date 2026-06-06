inherit ROOM;
void create() {
	set( "short", "$HIY$獅  王  巢  穴$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"amount4"  : 48,
		"file5"    : "/obj/stone/jiao",
		"amount10" : 189,
		"file1"    : "/obj/stone/powder",
		"file10"   : "/open/ping/obj/poison_pill",
		"file2"    : "/open/mon/obj/mon-pill",
		"file9"    : "/open/killer/memory/static",
		"amount5"  : 1,
		"amount8"  : 51,
		"amount2"  : 55,
		"amount9"  : 1,
		"file4"    : "/obj/stone/powder",
		"amount6"  : 1,
		"amount3"  : 45,
		"file3"    : "/obj/stone/suipian",
		"amount1"  : 405,
		"amount7"  : 1,
		"file8"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/ghost-hole/obj/light-spirit",
	]) );
	set( "item_desc", ([
		"catt" : @ITEM
    這裡空曠毫無一物，僅有一張會客桌，希望來者能不嫌棄，
雖然只有幾杯熱茶招待，顯見小峰平時用"心"待人，而非注重
表面之人。   以下為小峰平時練內功之裝備:
      ( 1) 夕霞紅紗(sun_red_cloth)
      ( 2) 魔法盾(magic shield)
      ( 3) 妖幻披掮(ghost cloak)
      ( 4) 妖幻頭帶(ghost helmet)
      ( 5) 狂龍翔天破(crazy dragon)
      ( 6) 陽炎臂環 (Sun Fire Armband)
      ( 7) 妖幻護膝(ghost legging)
      ( 8) 混沌腰帶(chaos belt)
      ( 9) 羅剎女飾(gem)
      (10) 幸運草環(lucky grasslink)
ITEM,
		"eat mass" : @ITEM
drink tea
ITEM,
	]) );
	set( "build", 10029 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room616.c",
		"down"      : "/open/clan/ou-cloud-club/room/room619.c",
		"south"     : "/open/clan/ou-cloud-club/room/room439.c",
		"north"     : "/open/clan/ou-cloud-club/room/room611.c",
		"east"      : "/open/clan/ou-cloud-club/room/room614.c",
	]) );
	set( "long", @LONG

                    ◣                        ◢
                   ║■■■■■■■■■■■■■■║
                ◢═════════════════◣
                 ║田田║田田║  田田  ║田田║田田║
        ◢■■■■■■■■■■■■■■■■■■■■■■■■■◣
         ▕════════════════════════▏
          ▔█田田田田田田  獅  王  巢  穴  田田田田田田█▔
             █|田田田田田田田田田田田田田田田田田田田|█
              █│     ∥∥                 ∥∥      █
              █│ 田  ║║ 田 │▉▉│ 田  ║║  田  █
              █│     ▉▉    │▉▉│     ▉▉      █

LONG);
	setup();
	replace_program(ROOM);
}
