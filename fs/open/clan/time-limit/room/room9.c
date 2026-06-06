inherit ROOM;
void create() {
	set( "short", "$BGRN$霍格$BMAG$華茲$BBLU$大廳$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"amount3"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10120 );
	set( "exits", ([
		"up"        : "/open/clan/time-limit/room/room24",
		"south"     : "/open/clan/time-limit/room/room8.c",
		"down"      : "/open/clan/time-limit/room/room63.c",
		"east"      : "/open/clan/time-limit/room/room43.c",
		"out"       : "/open/clan/time-limit/room/room3.c",
		"west"      : "/open/clan/time-limit/room/room73.c",
		"north"     : "/open/clan/time-limit/room/room61.c",
	]) );
	set( "long", @LONG
霍格華茲大廳是學生們用餐也是集會的場所,天花板經過魔法修飾後
可以直接看到外面的天空, 海格正帶領著一年級的新生往這邊走來,
看到那些新生冷的發抖,還有人全身溼透,大概是划船過湖時掉下船去了吧
這些新生將由分類帽決定分發到哪個學院,不過據衛斯理雙胞胎的說法,這個過程
似乎會很痛!前方坐著校長'阿不思-鄧不利多',笑容滿面望著學生們,
副校長兼任葛來分多學院院長的'麥米奈娃'拿著分類帽走過來,一一叫著新生的名字,
這裡是霍格華茲的中心,可以通往學校的各個地方,因此四面八方都有出口

LONG);
	setup();
	replace_program(ROOM);
}
